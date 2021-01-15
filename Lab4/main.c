#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <time.h>        

#define PORT 1300
#define BUFSIZE 256

int main(int argc, char const *argv[]) 
{
  fd_set all_fds;   // master file descriptor list
  fd_set sel_fds;   // temp file descriptor list for select()
  int maxfd;        // maximum file descriptor number
  
  int server_fd, new_socket; 
  struct sockaddr_in address;
  
  int opt = 1;      // for setsockopt() SO_REUSEADDR, below
  int addrlen = sizeof(address); 
  char buffer[BUFSIZE];
  int bytes;

  // Creating socket file descriptor 
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
    perror("socket failed"); 
    exit(EXIT_FAILURE); 
  } 
  
  // Forcefully attaching socket to the port 1300 
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                 &opt, sizeof(opt))) { 
    perror("setsockopt failed"); 
    exit(EXIT_FAILURE); 
  } 
  address.sin_family = AF_INET; 
  address.sin_addr.s_addr = INADDR_ANY; 
  address.sin_port = htons( PORT ); 
  
  // Bind the socket to the network address and port
  if (  bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0  ) { 
    perror("bind failed"); 
    exit(EXIT_FAILURE); 
  } 
  if (listen(server_fd, 3) < 0) { 
    perror("listen failed"); 
    exit(EXIT_FAILURE); 
  }

  FD_ZERO(&all_fds);            // clear the master and temp sets
  FD_SET(server_fd, &all_fds);  // add socket to set of fds

  maxfd = server_fd;            // for now, the max is this one
  
  while(1) {  // Server loop
    int i;
    
    sel_fds = all_fds; // copy set of fds (because select() changes it)
    
    // Wait for data in ONE or MORE sockets
    if ( select(maxfd+1, &sel_fds, NULL, NULL, NULL) == -1 ) {
      perror("select failed");
      exit(EXIT_FAILURE);
    }

    // If we got here, there's data somewhere...
    // Let's find where

    for(i=0; i<=maxfd; i++) {
      if (FD_ISSET(i, &sel_fds)) { // we got one!!!
        // Now if it's the main socket, a client is connecting
        // If not, a client must have sent data (or disconnected)

        if (i == server_fd) {
          // A connection is ready to be accept()ed
          if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                                   (socklen_t*)&addrlen))<0) { 
            perror("accept failed"); 
            exit(EXIT_FAILURE); 
          }

          printf("Client connected.\n");

          // But now we have to monitor this socket too
          FD_SET(new_socket, &all_fds);

          // and update the maxfd, if necessary
          maxfd = new_socket > maxfd ? new_socket : maxfd;          
        }
        else {
          // here, we have data in one client, must recv() it
          bzero(buffer, BUFSIZE);
          
          bytes = recv(i, buffer, BUFSIZE-1, 0);

          if ( bytes == 0 ) { // client disconnected, too bad...
            FD_CLR(i, &all_fds);
            // nevermind the maxfd...
          }
          else {
            printf("Client says: '%s'\n", buffer);
            send(i, buffer, strlen(buffer), 0 );
            printf("Replied to client\n");

            if ( strncmp(buffer, "quit", 4) == 0 ) {
              // client wants to quit, let it
              close(i);
              FD_CLR(i, &all_fds);              
            }      
          }
        }
      }
    }
  }
  
  return 0; 
}
