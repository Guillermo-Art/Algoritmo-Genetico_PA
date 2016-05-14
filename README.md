# Algoritmo-Genetico_PA
Proyecto final de programación avanzada

Para compilar el archivo fuente genetico.c se debe agregar la bandera -lm

Para compilar el archivo fuente main.c es necesario utilizar las banderas -fopenmp -lm

Un ejemplo de corrida sería el siguiente:
*Ver en RAW, por el formato.

Numero de individuos para cada iteracion:
4

Numero de iteraciones a realizar:
5

Poblacion inicial:
01110
10010
10010
11001

Iteracion: 0


#        Poblacion       X       F(X)

0       01110            14      196
1       01001            9       81
2       01001            9       81
3       10011            19      361

Maximo: 361

Iteracion: 1
00010, 00101, 00101, 10010, 00101, 00101, 00010, 10111, 00101, 00001, 00100, 10110, 10110, 00010, 00110, 00110, 00000, 00110, 00110, 00000, 01111, 00110, 00111, 01101, 01101, 10000, 11101, 11101, 10010, 11101, 11101, 10010, 01001, 11101, 11100, 11100, 10110, 11100, 10110, 01001, 11000,

#        Poblacion       X       F(X)

4       11100            28      784
5       10110            22      484
6       01001            9       81
7       11000            24      576

Maximo: 784

Iteracion: 2
10111, 10111, 01100, 10101, 10101, 11100, 11111, 11111, 11101, 11110, 11110, 11100, 11110, 11110, 11100, 11110, 11110, 11110, 11110, 11100, 11110, 11100, 11110, 00111,

#        Poblacion       X       F(X)

8       11110            30      900
9       11100            28      784
10      11110            30      900
11      00111            7       49

Maximo: 900

Iteracion: 3
11111, 01011, 01011, 01011, 10110, 11011, 11011, 10010, 11011, 11011, 10010, 01100, 01011, 01011, 00001, 01111, 01010, 01010, 10101, 00010, 00010, 10001, 00010, 00010, 10001, 11110, 00010, 01010, 01100, 01100, 10011, 11100, 11100, 10010, 11100, 11100, 10010, 11111, 11100, 11101, 11101, 10011, 11101, 10011, 11111, 10100,

#        Poblacion       X       F(X)

12      11101            29      841
13      10011            19      361
14      11111            31      961
15      10100            20      400

Maximo: 961

Iteracion: 4
11101, 01001, 01001, 01101, 01001, 00101, 00101, 01101, 00100, 00100, 01100, 00100, 00100, 01100, 11100, 10100, 10100, 11101, 11100, 10110, 10110, 11100, 10110, 11100, 11100, 11101,

#        Poblacion       X       F(X)

16      10110            22      484
17      11100            28      784
18      11100            28      784
19      11101            29      841

Maximo: 841

Despues de la iteracion: 4 el valor maximo es: 31

--------------------------------
Process exited after 4.387 seconds with return value 0
