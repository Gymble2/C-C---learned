#include <stdio.h>
#include <stdlib.h>
#include <new>
#include <iostream>
#include <string>

using namespace std;

int main(){

    //Tamanho a ser criado
    int tamanho,i;

    //Lendo o tamanho do vetor
    cout << "Digite o tamanho:";
    cin >> tamanho;

    //Mostrando o tamanho lido
    cout << "Tamanho:" << tamanho;

    //Criando um ponteiro que recebe o novo vetor vazio
    int *vetor = new int[tamanho];

    //Passa valores para o vetor e os imprime na tela
    for(i = 0; i < tamanho; i++){
        vetor[i] = i;
        cout << "\n" << vetor[i];
    }

    return 0;
}
