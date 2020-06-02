# Fila-De-Prioridade

Deverá ser realizada a automação de filas bancárias considerando que os bancos utilizam a seguinte
codificação:
N1000, N1001, N1002, N1003, ... N seguido de um número inteiro começando por 1000 para indicar
fila de pessoas com atendimento normal.
I2000, I2001, I2002, I2003, ... I seguido de um número inteiro começando por 2000 para indicar fila
de pessoas idosas.
D3000, D3001, D3002, D3003, ... D seguido de um número inteiro começando por 3000 para indicar
fila de pessoas deficientes.
G4000, G4001, G4002, G4003, ... G seguido de um número inteiro começando por 4000 para indicar
fila de pessoas gestantes.

O banco considera como prioritário o atendimento a pessoas deficientes, enquanto houver pessoas
deficientes na fila estas devem ser atendidas. Se não houver nenhuma pessoa deficiente na fila deve
ser verificado se existe alguém na fila de pessoas idosas. Todas as pessoas deficientes e pessoas idosas
devem ser atendidas para que seja atendida a primeira pessoa da fila de gestantes. Por fim, quando
não existir mais ninguém em filas prioritárias as pessoas com atendimento normal são chamadas.
Para exemplificar, considere que chegaram ao banco 2 pessoas deficientes, 1 pessoa gestante e 3
pessoas com atendimento sem prioridade. A ordem de atendimento seria:
D3000 D3001 G4000 N1000 N1001 N1002
Considere que neste momento chegou um idoso, a ordem de atendimento ficará:
D3000 D3001 I2000 G4000 N1000 N1001 N1002.
Caso uma nova gestante entre na fila a ordem ficará:
D3000 D3001 I2000 G4000 G4001 N1000 N1001 N1002
E assim por diante.

Para resolver este problema deve ser criada uma estrutura de dados chamada fila_de_prioridade
composta por um vetor de filas. Na posição zero (0) do vetor ficarão as pessoas com mais alta
prioridade; na posição um (1) do vetor as pessoas com prioridade um pouco menor, e assim por diante.
O método para inserir na fila deve receber como parâmetro também a prioridade e o método para
remover deve verificar o primeiro elemento da fila de maior prioridade; se não existir analisa a fila
seguinte e assim por diante.



Crie um programa principal com as opções:

1 – Retirar senha – atendimento normal
2 – Retirar senha – idoso

3 – Retirar senha – gestante

4 – Retirar senha – deficiente

5 – Chamar

6 – Mostrar fila

7 – Sair

