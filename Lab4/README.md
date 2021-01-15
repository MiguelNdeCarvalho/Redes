# Pretende-se neste trabalho implementar um serviço de rede com sockets em C. O código desenvolvido será re-utilizado posteriormente no trabalho final.  O trabalho deve ser demonstrado a funcionar na próxima aula prática (dentro de 15 dias).

1. O objetivo é implementar um server TCP que imite o comportamento do  "time.nist.gov" no port 13: (neste caso use o porto 1300)

2. O servidor deve:

    2.1 Aceitar conexões no porto 1300

    2.2 Enviar a data e hora para o cliente

    2.3 Em seguida  fechar a conexão (close)

3. Teste o seu servidor local com "telnet localhost 1300".

4. Modifique o cliente do trabalho anterior de modo a testar o seu servidor.

5. Pesquise e observe as diferenças entre utilizar o protocolo TCP e o protocolo UDP.

6. Crie novas  versões do cliente e servidor de modo a usarem o protocolo UDP em vez de TCP. Quais são a principais diferenças entre um socket com e sem conexão?

7. (Trabalho para casa) Modifique o servidor (TCP) para um  "servidor echo", que simplesmente espera por uma string do cliente e devolve a mesma string de volta para o cliente.

