#ifndef ARVORE_HUFF_H_INCLUDED
#define ARVORE_HUFF_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct noHuffman{
    char dado;
    int freq;
    noHuffman *prox;
    noHuffman *esq;
    noHuffman *dir;
};

struct TlistaHuff{
    noHuffman * inicio;
};

void inicializa_lista_Huff(TlistaHuff &l){
    l.inicio=nullptr;
}

void insere_inicio_huff(TlistaHuff &l, noHuffman *novo){
    novo->prox = l.inicio;
    l.inicio = novo;
}

void insere_dado_inicio_huff(TlistaHuff &l, char dado){
    int i=0;

    if(l.inicio!=nullptr){
        for(noHuffman *nav = l.inicio;
            nav!=nullptr;
            nav=nav->prox,i++){
                if(nav->dado == dado){

                    nav->freq++;
                    return;
                }
            }
    }
    noHuffman *novo = new noHuffman;
    novo->dado = dado;
    novo->dir = nullptr;
    novo->esq = nullptr;
    novo->freq = 1;
    novo->prox = nullptr;
    insere_inicio_huff(l,novo);
}

noHuffman *remove_no_lista(TlistaHuff &l){
    noHuffman *retirar;
    retirar = l.inicio;
    l.inicio = l.inicio->prox;
    return retirar;
}

void imprimir_prefixo(noHuffman *no,int altura){
    if(no != nullptr){
        int i=0;
        while(i<altura){
            cout<<"####|";
            i++;
        }
        if(altura==0) cout<<"RAIZ:";
        cout<<no->dado<<">"<<no->freq<<endl;
        altura++;
        imprimir_prefixo(no->esq,altura);
        imprimir_prefixo(no->dir,altura);
    }
}

void imprimir_lista_Huff( TlistaHuff l){
    cout<<endl<<"\t||IMPRIMINDO LISTA||" <<endl;
    if(l.inicio == nullptr){
        cout<<" ||lista vazia|| ";
    }else{
        int i = 0;
        for (noHuffman*nav = l.inicio; nav!=NULL; nav = nav->prox){
            cout<< "letra[" << i++ << "] " << nav->dado <<" freq:"<<nav->freq<<endl;
        }
    }
}

void ordernar_freq_Huff( TlistaHuff &l){
    bool ordenado = false;
    noHuffman *aux = new noHuffman;
    cout<<endl<<"\t||ORDENANDO LISTA DE MANEIRA\n\t  CRESCENTE PELA FREQUENCIA||"<<endl;
    while(ordenado!=true){
        ordenado = true;
        for (noHuffman*nav = l.inicio; nav!=NULL; nav = nav->prox){
            for(noHuffman*nav2 = nav->prox; nav2!=NULL;nav2 = nav2->prox){
                if(nav2->freq < nav->freq){
                        aux->dado = nav2->dado;
                        aux->freq = nav2->freq;

                        nav2->dado = nav->dado;
                        nav2->freq = nav->freq;

                        nav->dado = aux->dado;
                        nav->freq = aux->freq;
                        ordenado = false;
                }
            }
        }
    }
}

void arvore_Huff(TlistaHuff &l){
    noHuffman *no1 = new noHuffman;
    noHuffman *no2 = new noHuffman;

    noHuffman *nav;

    while(l.inicio->prox!=nullptr){ ///PERMANECE NO LAÇO ENQUANTO A LISTA TIVER MAIS DE UM ELEMENTO

        ///RETIRA OS DOIS PRIMEIROS NÓS DA LISTA
        no1 = remove_no_lista(l);
        no2 = remove_no_lista(l);

        ///CRIA O PAI DAS DUAS FOLHAS RETIRADAS
        noHuffman *novo = new noHuffman;

        novo->dado = '-';
        novo->freq = no1->freq + no2->freq;
        novo->esq = no1;
        novo->dir = no2;

        ///INICIA NAVEGADOR PARA INSERIR O PAI
        nav=l.inicio;
        while(true){
            ///INSERE ELE DE ACORDO COM A FREQUENCIA

            ///ULTIMO ELEMENTO DA LISTA
            if(nav==nullptr){
                l.inicio = novo;
                novo->prox = nullptr;
                break;

            ///INSERÇÃO DO ELEMENTO COM MAIOR VALOR
            } else if (nav->prox == nullptr){
                novo->prox = nav->prox;
                nav->prox = novo;
                imprimir_lista_Huff(l);
                break;

            ///INSERÇÃO NA POSIÇÃO ANTERIOR AO VALOR MAIOR
            }else if(nav->prox->freq >= novo->freq){
                novo->prox = nav->prox;
                nav->prox = novo;
                imprimir_lista_Huff(l);
                break;
            }
            nav=nav->prox;
        }
    }
    imprimir_lista_Huff(l);
}

#endif // ARVORE_HUFF_H_INCLUDED
