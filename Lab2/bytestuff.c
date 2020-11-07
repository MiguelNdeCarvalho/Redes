#include <stdio.h>
#include <string.h>

void bytestuff(char *input_string, char *output_string)
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

void bytedestuff(char *input_string, char *output_string)
{
    int i=0,j=0;

    while(input_string[i]!='\0')
    {
        if (input_string[i] == '0')
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

int main(){

    char input_string[7] = "H123HH";
    char output_bytestuff[100], output_destuff[100];

    bytestuff(input_string, output_bytestuff);
    bytedestuff(output_bytestuff, output_destuff);

    printf("String bytestuff: %s, String bytedestuff: %s!\n", output_bytestuff, output_destuff);

    return 0;
}
