#include <stdio.h>
#include <string.h>
#include <math.h>

void canal( char* in, char* out ){
int i = 1, erro=0;
while (*in != '\0')
	{
        	erro=0;      
		i=(i+5)%7;
		if(i>3){erro=0;}else{erro=pow(2,i);} //função que gera os erros
		*out = (*in)^(char)(erro);
		out++;
		in++;
		i++;
	}
	*out = '\0';
}	
// definir as funções 
// hcode(char*, char*);
// bytestuff(char*, char*);
// bytedestuff(char*, char*);
// hdecode(char*, char*);

void main(){
char a[100], b[100], c[100], d[100], e[100], f[100];

strcpy ( a , "ABCDEFGHHHHHIJKLMNOPQR1234567890abcdefghijklmnopqrstuvxyz  :-))))))");
...

hcode(a,b);
bytestuff(b,c);
canal(c,d);
bytedestuff(d,e);
hdecode(e,f)

printf("\n a %s",a);
printf("\n b %s",b);
printf("\n c %s",c);
printf("\n d %s",d);
printf("\n e %s",e);
printf("\n f %s",f);
}



