//Aluno:Ycaro Kayk Fernandes Ferreira dos Santos.
#include <iostream>
#include <stdlib.h>
#include "grafo.h"
#include "lista.h"
#include "node.h"

using namespace std;

//verificar busca em profundiade.//fila
void buscaEmProfundidade(lista list_aux,int * listaAdj,int auxSpride,int cont){
  while(list_aux[auxSpride]->getNode()!=NULL){
    *listaAdj[auxSpride]=cont;
    cont++;
    auxSpride=list_aux[auxSpride]->getVerticeReceptor();
    buscaEmProfundidade(list_aux,listaAdj,auxSpride,cont);
  }
}
void buscaEmLargura(lista list_aux,int * listaAdj,fila *fila,int auxSpride,int cont){
  while(list_aux[auxSpride]->getNode()!=NULL){
    *fila->insert(list_aux[auxSpride]->getVerticeReceptor());
    list_aux->setProximo();
  }
  *listaAdj[auxSpride]=cont;
  cont++;
  while(*fila->filaVazia()!=true){
    auxRemove=*fila->remove();
    if(verificarExistenciaVisitados(auxRemove->getNumero(),*listaAdj)==false){
      buscaEmLargura(list_aux,*listaAdj,*fila,auxRemove->getNumero(),cont);
    }
  }
}

bool verificarExistenciaVisitados(int auxValor,int *listaAdj){
  for(int i=0;i<10;i++){
    if(*listaAdj[i]==auxValor){
      return true;
    }
  }
  return false;
}

int main(void){
  //reduzir variaveis.
  grafo varGrafo[5];
  lista * auxLista;
  int numeroGrafo=0,verticeReceptor=0,verticeSaida=0,x=0,escolha=0,pesoVertice=0,pesoAresta=0,*listaAdj[10]={},*filaAux[10]={};
  char auxFlag='n';

  while(true){
    cout<<"Menu:"<<endl;
    cout<<"1.Inserir aresta."<<endl;
    cout<<"2.Procurar aresta."<<endl;
    cout<<"3.Obter lista de vertices adjacentes a um vertice."<<endl;
    cout<<"4.Remover aresta."<<endl;
    cout<<"5.Busca em profundidade."<<endl;
    cout<<"6.Busca em largura."<<endl;
    cout<<"7.Fortemente Connectados."<<endl;
    cout<<"8.Arvore Geradora Minima - Kruskal."<<endl;
    //lembrar do comando de saida do programa
    cout<<"Escolha:";
    cin>>escolha;

    switch(escolha){
      case 1:
      cout<<"Informe suas ligacoes."<<end;
      cout<<"Vertice Receptor:";
      cin>>verticeReceptor;
      cout<<"/n Vertice Saida:";
      cin>>verticeSaida;
      cout<<"/n Peso do vertice:";
      cin>>pesoVertice;
      cout<<"/n Peso aresta:";
      cin>>pesoAresta;
      list[verticeSaida]->insert(verticeReceptor,verticeSaida,pesoVertice,pesoAresta);
      cout<<"Inserido."<<endl;
      break;
      case 2:
      cout<<"Insira qual o verticeSaida e o verticeReceptor da aresta a ser encontrada:"
      cout<<"VerticeSaida:";
      cin>>verticeSaida;
      cout<<"/n VerticeReceptor:";
      cin>>verticeReceptor;
      existeAresta=list[verticeSaida]->buscarAresta(verticeSaida,verticeReceptor);
      if(existeAresta==true){
        cout<<"Aresta encontrada."<<endl;
      }
      else{
        cout<<"Aresta nao encontrada."<<endl;
      }
      break;
      case 3:
      //Gerar copia da lista para nao influenciar nos dados.
      cout<<"Informe o vertice para verificar sua adjacencia:"<<endl;
      cout<<"Numero Vertice:";
      cin>>verticeSaida;
      for(int i=0;i<10;i++){
        cout<<"/n Vertices adjacentes:"<<endl;
        if(list2[i]->arestaVazia()!=true){
          if(verticeSaida=i){
            while(list2[i]->getAresta()!=NULL){
              cout<<list2[i]->getVerticeReceptor()<<endl;
              list2[i]->setProximoLista();
            }
            list2[i]->resetAux();
          }
          else{
            while(auxFlag!='s'){
              if(list2[i]->getNode()!=NULL){
                if(list2[i]->getVerticeReceptor()==verticeSaida){
                  cout<<i<<endl;
                  auxFlag='s';
                }
                else{
                  list2[i]->setProximo();
                }
              }
            }
          }
        }
      }
      delete list2;
      break;
      case 4:
      cout<<"Informe o vertice inicial e final:"<<endl;
      cout<<"Vertice Inicial:";
      cin>>verticeSaida;
      cout<<"/n Vertice Final:";
      cin>>verticeReceptor;
      if(list[verticeSaida]->removerAresta(verticeSaida,verticeReceptor)==true){
        cout<<"Aresta deletada."<<endl;
      }
      else{
        cout<<"Aresta Inexistente."<<endl;
      }
      break;
      case 5:
      lista list2=new lista;
      lista2=lista;
      buscaEmProfundidade(Lista2,listaAdj,0,1);
      cout<<"Lista adj:"<<endl;
      for(int i=0;i<10;i++){
        cout<<*listaAdj[i]<<endl;
      }
      delete list2;
      break;
      case 6:
      cout<<"Verificar busca em largura:"<<endl;
      lista list2=new lista;
      lista2=lista;
      buscaEmLargura(lista2,*listaAdj,fila,0,1);
      cout<<"Lista Adj:"<<endl;
      for(int i=0;i<10;i++){
        cout<<*listaAdj[i]<<endl;
      }
      delete list2;
      break;
      case 7:
      cout<<"Grafos fortemente conectados."<<endl;
      break;
      case 8:
      cout<<"Arvore geradora minima."<<endl;
      lista list2=new list;
      while()


      default:
      cout<<"Comando nao encontrado. Tente novamente."<<endl;
      break;
    }
  }
  return 0;
}
