#include <stdio.h>
#include <stdlib.h>

int* criaTamanhoVetor(tamanho){

    int *aux;

    aux = (int*) malloc(tamanho*sizeof(int));

    return aux;

}



int main(){

    int *vetor,tamanho,cont;


    //le o tamanho do vetor
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tamanho);

    vetor = criaTamanhoVetor(tamanho);

    for(cont = 0; cont < tamanho; cont++){

        vetor[cont] = 90;

    }

    for(cont=0;cont < tamanho;cont++){
        printf("%d\n", vetor[cont]);
    }

    return 0;

}
