# Pretende-se neste trabalho ter um primeiro contacto  de programação com sockets em C. O código desenvolvido será re-utilizado posteriormente no trabalho final.  O trabalho deve ser demonstrado a funcionar na próxima aula prática (dentro de 15 dias).

1. observe o serviço de "Internet Time Service (ITS)" do NIST através do comando "telnet time.nist.gov 13" para obter uma resposta deste serviço basta conectar com o porto 13 dum servidor com este serviço ativo. Não é necessário enviar nenhum pedido em concreto, basta conectar (fazer a ligação) para receber a informação. 

2. Pretende-se replicar este serviço implementando um cliente minimal com sockets. Fazer a ligação para  "time.nist.gov" no porto 13 e receber os dados (e imprimí-los) no std output.(se tiver coriusidade pode consultar detalhes sobre o ITS em https://www.nist.gov/time-distribution/internet-time-service-its)

3. Sobre os sockets pode e deve consultar informação: nas páginas "man" do unix; e online.   

4. Dicas: um cliente minimalista poderá ser feito com as funções:

```c
getaddrinfo(...,......);  // ler informação sobre o servidor
sock_x = socket(...); // criar o socket defina o domain para IP (IPv4 Internet protocols)
connect(sock_x, ...,...);  // fazer ligação
num_bytes = recv(sockfd, buffer_de_saida,...,...);  // receber os dados do servidor
printf("Os dados recebidos são: %s \n",buffer_de_saida);
```

5. Note que um programa completo deverá ter algumas verificações de possíveis erros que podem ocorrer.
