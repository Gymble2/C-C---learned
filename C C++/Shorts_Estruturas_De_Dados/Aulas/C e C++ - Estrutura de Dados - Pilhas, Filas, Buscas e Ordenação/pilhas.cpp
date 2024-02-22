#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void imprime_vetor(int vetor[TAM], int topo){

    //Auxiliar contador
    int cont;

    cout << "\n";

     //Imprime o vetor
    for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
    }

    cout << "Topo: " << topo;

}

//Caso a pilha esteja vazia
bool pilha_vazia(int topo){
    if(topo == -1){
        return true;
    }else{
        return false;
    }
}

//Confere se a pilha está cheia
bool pilha_cheia(int topo){
     if(topo == TAM - 1){
        return true;
    }else{
        return false;
    }
}


int pilha_tamanho(int topo){
    return topo + 1;
}

//Retorna o ultimo valor da pilha
int pilha_get(int pilha[TAM], int *topo){
    if(pilha_vazia(*topo)){
        cout << "A pilha esta vazia";
        return 0;
    }else{
        return pilha[*topo];
    }
}

//Adiciona um valor na pilha
void pilha_push(int pilha[TAM],int valor, int *topo){

    //Caso não possa colocar mais valores
    if(pilha_cheia(*topo)){
        cout << "Pilha cheia!";
    }else{
        *topo = *topo + 1;
        pilha[*topo] = valor;
    }

}

//Remove um valor da pilha
void pilha_pop(int pilha[TAM], int *topo){

    if(pilha_vazia(*topo)){
        cout << "A Pilha ja esta vazia";
    }else{
        cout << "Valor Removido:" << pilha[*topo];
        pilha[*topo] = 0;
        *topo = *topo -1;
    }

}

//Cria uma pilha e limpa ela
void pilha_construtor(int pilha[TAM], int *topo){

    //Coloca o topo negativo para indicar uma pilha vazia
    *topo = -1;

    //Auxiliar contador
    int cont;

     //Imprime o vetor
    for(cont = 0; cont < TAM; cont++){
       pilha[cont] = 0;
    }

}



int main(){

    int pilha[TAM];
    int topo, valorRetirado ;                                 //Topo da pilha

    pilha_construtor(pilha, &topo);

    imprime_vetor(pilha, topo);

    pilha_push(pilha, 5, &topo);
    imprime_vetor(pilha, topo);

    cout << "Ultimo valor da pilha" << pilha_get(pilha, &topo);
    cout << "Tamanho da Pilha:" << pilha_tamanho(topo);

    pilha_push(pilha, 7, &topo);
    pilha_push(pilha, 7, &topo);
    pilha_push(pilha, 7, &topo);
    pilha_push(pilha, 7, &topo);
    pilha_push(pilha, 7, &topo);
    pilha_push(pilha, 7, &topo);
    pilha_push(pilha, 7, &topo);
    pilha_push(pilha, 7, &topo);
    pilha_push(pilha, 7, &topo);
    imprime_vetor(pilha, topo);

    pilha_pop(pilha, &topo);
    imprime_vetor(pilha, topo);

}
