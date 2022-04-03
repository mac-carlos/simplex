# Algoritmo Simplex

Implementação do algoritmo Simplex em ```C``` para a disciplina de Programação Linear.

## Como funciona

O vetor ```z``` armazena os valores (coeficientes) da função objetivo.

A matriz ```a``` armazena os valores do lado esquerdo das desigualdades.

O vetor ```b``` armazena os valores do lado esquerdo das desigualdades.

Exemplo de problema:

```
Maximize: z = 10a + 20b + 30c 

Sujeito a:

2a + 2b + 4c < 300 
4b + 3c < 200
a < 20
4a + 3b < 50

com: a, b, c > 0
```

A resolução do problema acima está [neste vídeo](https://youtu.be/7qOdbo-xPaA).

***Importante:** a implementação assume que todas as restrições são desigualdades*

O restante segue como o algoritmo:

```
1. Adicionar as variáveis de folga;
2. Transformar os valores de z em negativos;
3. Enquanto algum dos valores de z for negativo faça:
    3.1. Encontrar a coluna pivô (valor mais negativo de z);
    3.2. Encontrar a linha pivô (menor valor da divisão entre o valor de b e o coeficiente da coluna pivô naquela linha);
    3.3. Escalonar a tabela a partir do pivô; 
```

Pseudo código completo completo [aqui](https://pt.wikipedia.org/wiki/Algoritmo_simplex#Algoritmo_com_um_Tableau).
## Licença

Este projeto está sobre a [licença MIT](LICENSE).
