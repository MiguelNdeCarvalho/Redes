# Lab 2

1. Deverá implementar um esquema de byte styffing e de-stuffing funções:

```c
void bytestuff(char * input_string, char * output_string)
void bytedestuff(char * input_string, char * output_string)
```
que garantam que o padrão "HH" (que corresponde a um hipotético cabeçalho) nunca existirá dentro da mensagem

2. Deverá implementar um esquema de codificação e descodificação de Hamming  (4 bits de dados, e 3 de check bits) nas funções:

```c
void hcode(char * input_string, char * output_string)
void hdecode(char * input_string, char * output_string)
```

de modo a recuperar de erros em bits isolados.

As funções devem ser testadas  usando a função `canal()` que está implementada e simula a occorrência de erros no canal de comunicação. Pode ver esta função no exemplo de código `canal.c`

No exemplo `skeleton.c` pode ver um possível esqueleto do programa a desenvolver que deverá mostrar as mensagens entre cada bloco:


`a --> hamming code -- b --> byte stuffing -- c--> canal (com erros) -- d --> byte destuffing -- e -- > hamming decode -- > f` 

Dicas:

- a mensagem nunca tem mais de 100 carateres e é constituída por letras, algarismos, espaços, e sinais matemáticos (apenas caracteres ascii com códigos de 32 a 127)

- use a operação xor "^"  para aceder e/ou alterar os bites de cada caracter

- para o código de hamming divida cada byte em duas partes (4 bits mais 4 bits)  de modo que cada um seja codificado com código de hamming num caracter
