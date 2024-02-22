#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavraAleatoria(){

    //define as palavras pr�-prontas
    string palavra [3] = {"abacaxi", "manga" , "morango"};

    //randomiza as letras
    int indicaAleatorio = rand();
    int aleatorio = indicaAleatorio % 3;

    return palavra[aleatorio];
}

string retornaPalavraComMascara(string palavra,int tamanhoPalavra){

    int cont = 0;
    string palavraComMascara;

    //define a palavra com mascara com base no tamanho
    while (cont < tamanhoPalavra){
        palavraComMascara += "_";
        cont++;
    }
    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoPalavra, int tentativasRestantes,string letrasJaArriscadas,string mensagem){

    //exibe informa��es p�s tentativas
    cout << mensagem;
    cout << "\nPalavra " << palavraComMascara << "  (tamanho:" << tamanhoPalavra << ")\n";
    cout << "\nTentativas restantes: " <<  tentativasRestantes << "\n";

    //informa letras ja arriscadas
    int cont;
    cout << "\nLetras arriscadas:";

    //separa as letras ja arriscadas por unidade
    for(cont =0; cont<letrasJaArriscadas.size();cont++){
        cout << letrasJaArriscadas[cont]<<", ";
    }
}

int jogar(int numeroDeJogadores){

    //Espa�o de palavra
    string palavras;

    //jogar em dupla ou sozinho
    if (numeroDeJogadores == 1 ){
        palavras = retornaPalavraAleatoria();

    }else{
        cout<<" \nDigite uma palavra: ";
        cin>>palavras;

    }

    //define tamanho da palavra
    int tamanhoPalavra = palavras.size();

    //palavra com a mascara de "_"
    string palavraComMascara = retornaPalavraComMascara(palavras,tamanhoPalavra);


    ///variaveis principais
    int tentativas = 0 , maximoDeTentativas = 10,opcao ;
    int cont = 0;
    char letra;
    bool jaDigitou = false, acertouLetra = false;
    string letrasJaArriscadas,palavraArriscada,mensagem;

    //mostra os status e depois o espa�o de escolha das letras ou palavras
    while( palavras != palavraComMascara && maximoDeTentativas - tentativas >0 ){

        limpaTela();

        //status do exibe status
        exibeStatus(palavraComMascara,tamanhoPalavra,maximoDeTentativas - tentativas,letrasJaArriscadas,mensagem);

        //espa�o das escolhas de letras ou palavras
        cout<< "\nDigite uma letra (ou digite 1 para arriscar a palavra): ";
        cin >> letra;

        //caso a pessoa arrisque uma palavra inteira
        if(letra == '1'){

                cin >>  palavraArriscada;

                if(palavraArriscada == palavras){
                    palavraComMascara = palavraArriscada;

                }else{
                    tentativas = maximoDeTentativas;
                }

        }


        //caso a letra seja repetida
        for(cont = 0; cont < tentativas; cont++){
            if(letrasJaArriscadas[cont]== letra ){

                mensagem = "Essa letra ja foi digitada!!\n";

                jaDigitou= true;
            }

        }


        //caso a letran�o seja repetida
        if (jaDigitou == false){

            //adiciona letras minusculas as letras ja arriscadas
            letrasJaArriscadas += tolower(letra);

            //percorre a palavra real se a letra existir muda a palavra com mascara
            for (cont = 0; cont < tamanhoPalavra; cont ++){
                if (palavras[cont] == tolower(letra)){

                //adiciona as letras novas digitadas a palavra com mascara
                palavraComMascara[cont] = palavras[cont];
                acertouLetra = true;
                }

        }

        //se a letra digitada for errada avisa e caso erre avisa tambem
        if(acertouLetra == false){

            mensagem = "Voce errou uma letra;";
            cout<< "Voce errou uma letra!\n";
        }
        else{
            cout<< "Voce acertou uma letra!\n";
            acertouLetra = false;
        }

        //Diminui as tentativas
        tentativas ++;
        }

        //reinicias strings booleanas
        jaDigitou= false;
        acertouLetra = false;
    }

    //se voc� ganhar ou perder te da op��o de voltar do come�o
    if(palavras == palavraComMascara){
        limpaTela();
        cout << "\nParabens voce venceu!!!!\n";
        cout << "\nJogar de novo?";
        cout << "\n1- S\n";
        cout << "\n2- N\n Opcao: ";
        cin >> opcao;
        return opcao;
    }
    else{
        limpaTela();
        cout<< "\nSeu boneco morreu enforcado :(\n";
        cout << "\n - Jogar de novo?";
        cout << "\n 1- S";
        cout << "\n 2- N\n";
        cin >> opcao;
        return opcao;
    }

}

void menuInicial(){

    int  opcao = 0;

    //menu do jogo
    while (opcao < 1 || opcao > 3 ){
        limpaTela();
        cout << "Bem vindo ao Jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Jogar em dupla";
        cout << "\n3 - Sobre";
        cout << "\n4 - Sair";
        cout << "\nEscolha a opcao: ";
        cin >> opcao;

        //op��es escolhidas
        switch(opcao){
            case 1:
                //INICIA O JOGO
                if(jogar(1) == 1){
                    menuInicial();
                }break;

            case 2:
                //INICIA O JOGO EM DUPLA
                if(jogar(2) == 1){
                    menuInicial();
                }break;

            case 3:
                //DA AS INFORMA��ES DO JOGO
                cout << "Informacoes do Jogo:";
                limpaTela();
                cout<< "Jogo gayzao";
                cout << "\n1 - Voltar";
                cout << "\n2 - Sair\n";
                cin >> opcao;
                if (opcao == 1){
                    menuInicial();
                }
                break;

            case 4:
                //SAI DO JOGO
                cout<<"Ate mais!!";
                break;
        }
    }
}

int main(){

    srand( (unsigned)time(NULL));

    menuInicial();

}
