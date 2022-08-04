#include <iostream>
#include <fstream>
#include <sstream>
#include <string>]
#include "tabela_simbolos.h"
#include "arvore_huff.h"

using namespace std;

int main()
{
    TlistaHuff lista1;
    inicializa_lista_Huff(lista1);

    string frase = "TRABALHO DE ESTRUTURAS";
    cout<<"FRASE: "<<frase<<endl;
    char letra;

    for (int i=0; i<frase.length(); ++i)
    {
        letra = frase.at(i);
        insere_dado_inicio_huff(lista1,letra);
    }

    imprimir_lista_Huff(lista1);
    ordernar_freq_Huff(lista1);
    imprimir_lista_Huff(lista1);

    cout<<endl<<"\t||INICIA A CONSTRUCAO DA ARVORE||" <<endl;
    arvore_Huff(lista1);

    cout<<endl<<"\t||IMPRESSAO DA ARVORE||" <<endl<<endl;
    imprimir_prefixo(lista1.inicio,0);

    tabelaSimbolos tabela;
    inicializa_tabelaSimbolos(tabela);
    preenche_tabela(tabela,lista1.inicio,"");

    imprime_tabela(tabela);

    cout<<endl<<"\t||CODIFICACAO DA FRASE EM HUFFMAN||" <<endl<<endl;
    for (int i=0;i<frase.length();++i){
        letra = frase.at(i);
        cout<<codificacao_huff(tabela,letra)<<" ";
    }
    cout<<endl;
    return 0;

}
