#include <stdio.h>
#include <stdlib.h>

void main(){

    //criando a String
    char palavra[10];

    //instrução
    printf("Digite uma palavra: ");

    //limpa o buffer
    setbuf(stdin, 0);

    //Lê a String
    fgets(palavra, 10, stdin);

    //Limpa as casas não utilizadas
    palavra[strlen(palavra)-1] = '\0';


     //Imprime na tela
    printf("\n%s ", palavra);

    //Pausa o programa após executar
    system("pause");






}
