#include <stdio.h>
#include <string.h>
#include <math.h>


void canal( char* in, char* out ){
int i = 1, erro=0;
  while (*in != '\0')
	{
    erro=0;      
		i=(i+5)%7;
		if(i>3)
    {
      erro=0;
    }
    else
    {
      erro=pow(2,i);
    }
		*out = (*in)^(char)(erro);
		out++;
		in++;
		i++;
	}
	*out = '\0';
}	

 
void hcode(char* input_string, char* output_string)
{
  int j=0;
	char hex_1, hex_2, c_bit1, c_bit2, c_bit3, c_hexbit1, c_hexbit2, c_hexbit3, aux_1, aux_2;
	for(int i=0; input_string[i]!='\0'; i++, j+=2)
	{
		hex_1 = input_string[i] >> 4;
		hex_2 = input_string[i] & 0b00001111;
		
		c_bit1 = ((( 0b1000 & hex_1 ) >>3 ) ^ (( 0b0100 & hex_1 ) >>2 ) ^ ( 0b0001 & hex_1 )) <<6;
		c_bit2 = ((( 0b1000 & hex_1 ) >>3 ) ^ (( 0b0010 & hex_1 ) >>1 ) ^ ( 0b0001 & hex_1 )) <<5;
		c_bit3 = ((( 0b0100 & hex_1 ) >>2 ) ^ (( 0b0010 & hex_1 ) >>1 ) ^ ( 0b0001 & hex_1 )) <<4;
		aux_1 = c_bit1 | c_bit2 | c_bit3 | hex_1;
		
		c_hexbit1 = ((( 0b1000 & hex_2 ) >>3 ) ^ (( 0b0100 & hex_2 ) >>2 ) ^ ( 0b0001 & hex_2 )) <<6;             
    c_hexbit2 = ((( 0b1000 & hex_2 ) >>3 ) ^ (( 0b0010 & hex_2 ) >>1 ) ^ ( 0b0001 & hex_2 )) <<5;             
    c_hexbit3 = ((( 0b0100 & hex_2 ) >>2 ) ^ (( 0b0010 & hex_2 ) >>1 ) ^ ( 0b0001 & hex_2 )) <<4;
    aux_2 = c_hexbit1 | c_hexbit2 | c_hexbit3 | hex_2;

		output_string[j] = aux_1;
		output_string[j+1] = aux_2;
	}			
	output_string[j] = '\0';
}

void bytestuff(char* input_string, char* output_string)
{
	int i=0,j=0;

    while(input_string[i]!='\0')
    {
        output_string[j] = input_string[i];
        
        if(input_string[i]=='H')
        {
            j++;
            output_string[j]='0';

        }

        i++;
        j++;
    }
    
    output_string[j]='\0';
}


void bytedestuff(char* input_string, char* output_string)
{
	int i=0,j=0;

    while(input_string[i]!='\0')
    {
        if (input_string[i] == '0' && input_string[i-1] == 'H')
        {
            i++;
            continue;
        }
        output_string[j]= input_string[i];
        i++;
        j++;
    }

    output_string[j]='\0';	
}

void hdecode(char* input_string, char* output_string)
{
  int j=0;
  char aux_1, aux_2;
  for (int i = 0; input_string[i]!='\0'; i+=2, ++j) {
     aux_1 = (input_string[i] << 4);
     aux_2 = (input_string[i+1] & 0b00001111);
     output_string[j] = aux_1 | aux_2;
  }  
  output_string[j] = '\0';
}

void main()
{
  char a[100], b[100], c[100], d[100], e[100], f[100];

  strcpy ( a , "ABCDEFGHHHHHIJKLMNOPQR1234567890abcdefghijklmnopqrstuvxyz  :-))))))");
  
  hcode(a,b);
  bytestuff(b,c);
  canal(c,d);
  bytedestuff(d,e);
  hdecode(e,f);

  printf("\n a %s",a);
  printf("\n b %s",b);
  printf("\n c %s",c);
  printf("\n d %s",d);
  printf("\n e %s",e);
  printf("\n f %s",f);
}
