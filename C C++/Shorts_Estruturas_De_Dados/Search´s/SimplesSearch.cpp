#include <stdio.h>
#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#define TAM 10

using namespace std;

void escreveVetor(int vetor[TAM]){

    int cont;

    for(cont=0; cont<TAM;cont++){
        cout << vetor[cont]<< "-";

    }
}

int simplesSearch(int vetor[TAM], int valorprocurado, int* posicaoencontrada){

    int cont;


    bool valorFoiEncontrado;


    for(cont= 0; cont<TAM ; cont++){
        if(vetor[cont] == valorprocurado){
            valorFoiEncontrado = true;
            *posicaoencontrada = cont;
        }

    }

    if (valorFoiEncontrado){
        return 1;
    }else{
        return -1;
    }


}

int main(){

    int vetor [TAM] = {1,56,23,14,45,87,56,152,51,124};
    int valorProcurado;
    int posicao,posicaoEncontrada;

    int cont;

    escreveVetor(vetor);


    printf("Qual numero deseja encontrar?");
    scanf("%d", &valorProcurado);


    if(simplesSearch(vetor,valorProcurado,&posicaoEncontrada)==1){
        cout << "O valor foi encontrado na posicao:" << posicaoEncontrada;
    }else{
        cout << "Valor nao encontrado";
    }


    return 0;

}
