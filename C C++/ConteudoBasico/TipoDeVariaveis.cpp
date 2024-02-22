#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#define TAM 3

using namespace std;

int main(){

    int vetor[3], cont = 0,i, j;

    //passsando valores para o vetor
    vetor[0] = 10;
    vetor[1] = 20;
    vetor[2] = 30;


    for(cont = 0 ; cont<TAM ; cont++){
        cout << vetor[cont] << "\n";
    }

    //Reinicia o contador
    cont = 0;

    while (cont< TAM ){
        cout << vetor[cont] <<"\n";
        cont++;

    }

    //Definindo Matrizes
    int matriz[TAM][TAM] = {1,2,3,4,5,6,7,8,9};

    //Imprimindo valores do vetor
    for(i = 0; i < TAM; i++){
        for(j = 0; j < TAM; j++){
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;

}
