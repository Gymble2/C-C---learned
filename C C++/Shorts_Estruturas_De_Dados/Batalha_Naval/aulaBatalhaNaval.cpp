#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

void menuInicial();

void limpaTela(){
    system("CLS");
}

void exibeMapa(){

    int cont;

    for (cont = 0; cont< 10; cont++){
            if (cont == 0){
                 cout << "   ";
            }
       cout << cont <<" ";
    }
    cout<< "\n";

    for (cont = 0; cont< 10; cont++){
            if (cont == 0){
                 cout << "   ";
            }
       cout << "| ";
    }
    cout<< "\n";

}

void exibeTabuleiro(char tabuleiro [10][10],char mascara[10][10],bool mostraGabarito){

    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };

    int linha, coluna;

    for(linha = 0; linha<10;linha++){
        cout << linha << "-";
        for(coluna = 0; coluna<10; coluna++){

            switch(mascara[linha][coluna]){
                case 'A':
                        cout<< blue <<" "<< mascara[linha][coluna]<< normal;
                    break;
                case 'P':
                    cout<< green <<" "<< mascara[linha][coluna]<< normal;

                    break;
                default:
                    cout<< " "<< mascara[linha][coluna]<< normal;
                    break;
                    }
                }
                cout<< "\n";
        }

    if (mostraGabarito == true){
            exibeMapa();
                for(linha = 0; linha<10;linha++){
                cout << linha << "-";
                for(coluna = 0; coluna<10; coluna++){
                    cout<<" "<<tabuleiro[linha][coluna];
                }
            cout<< "\n";
        }

    }
}

void defineTabuleiro(char tabuleiro [10][10],char mascara[10][10]){

    int linha, coluna;
    //Popula o tabuleiro
    for(linha = 0; linha<10;linha++){
        for(coluna = 0; coluna<10; coluna++){
                tabuleiro[linha][coluna] = 'A';
                mascara[linha][coluna] = '*';

            }
    }


}

void posicionaBarcos(char tabuleiro [10][10]){

    int cont,quantidade = 10, quantidadePosicionada =0 ;

    while(quantidadePosicionada < quantidade){
        int linhaBarco = rand()%10;
        int colunaBarco = rand()%10;

            if (tabuleiro [linhaBarco][colunaBarco] == 'A'){
                tabuleiro[linhaBarco][colunaBarco] = 'P';
                quantidadePosicionada++;
            }
    }
}

void verificaTiro(char tabuleiro [10][10],int linhaJogada, int colunaJogada,int *pontos,string *mensagem){

    switch(tabuleiro[linhaJogada][colunaJogada]){
                case 'P':
                    *pontos = *pontos + 10;
                    *mensagem = "Voce acertou um barco normal!!";

                break;
                case 'A':
                    *mensagem = "Voce acertou  a agua.";
                break;
            }

}

void jogo(string nomeDoJogador){

        //Espaço de palavra
        string palavras;

        ///variaveis principais
        int cont, linha, coluna, linhaJogada,colunaJogada,estadoDeJogo=1, pontos = 0;
        int tentativas = 0, maximoDeTentativas = 5,opcao;
        char tabuleiro [10][10], mascara[10][10];
        //bool ;
        string mensagem = "Comecou a batalha!!";

        defineTabuleiro(tabuleiro,mascara);

        //posiciona barcos
        posicionaBarcos(tabuleiro);

        while(tentativas < maximoDeTentativas){

            limpaTela();

            exibeMapa();

            exibeTabuleiro(tabuleiro,mascara,true);

            cout<< "\nPontos: " << pontos;
            cout << "\n" << mensagem;
            cout<< "\nTentativas restantes:" << maximoDeTentativas-tentativas;

            //verificacao de dados
            linhaJogada = -1;
            colunaJogada = -1;

                while ((linhaJogada < 0 || colunaJogada < 0) || (linhaJogada > 9 || colunaJogada > 9)){
                    cout<<"\n" << nomeDoJogador <<" Digite uma linha: ";
                    cin>> linhaJogada;
                    cout<<"\n" << nomeDoJogador <<" Digite uma coluna: ";
                    cin>> colunaJogada;
                }


            verificaTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem);

            mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];

            tentativas++;
        }

        limpaTela();

        cout << "\n" << nomeDoJogador << " Acabou o jogo !!!!\n";
        cout << "\nJogar de novo?";
        cout << "\n1- S\n";
        cout << "\n2- N\nOpcao: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                jogo(nomeDoJogador);
                break;

            case 2:
                menuInicial();
                break;
        }
}

void menuInicial(){

    int  opcao = 0;

    string nomeDoJogador;

    //menu do jogo
    while (opcao < 1 || opcao > 3 ){
        limpaTela();
        cout << "Bem vindo ao Jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair\nEscolha:";
        cin >> opcao;

        //opções escolhidas
        switch(opcao){
            case 1:
                //INICIA O JOGO
                cout << "Qual seu nome: ";
                cin >> nomeDoJogador;
                jogo(nomeDoJogador);
                break;



            case 2:
                //DA AS INFORMAÇÕES DO JOGO
                limpaTela();
                cout << "Informacoes do Jogo:";
                cout<< "\nJogo gayzao";
                cout << "\n1 - Voltar";
                cout << "\n2 - Sair\n";
                cin >> opcao;
                if (opcao == 1){
                    menuInicial();
                }
                break;

            case 3:
                //SAI DO JOGO
                cout<<"Ate mais!!";
                break;
            }
        }
    }


int main(){

    srand( (unsigned)time(NULL));


    menuInicial();
    return 0;
}
