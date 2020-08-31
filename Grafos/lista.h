#include "node.h"
//refazer lista inteira
class lista{
private:
  node * aresta,*manipudalor,*aux;
  int numero,peso;
public:
  lista(){
    aresta=manipulador=aux=NULL;
    numero=peso=0;
  }
  void setNumero(int auxNumero){
    this->numero=auxNumero;
  }
  void setPeso(int auxPeso){
    this->peso=auxPeso;
  }
  void setProximo(){
    aux=aux->getProximo();
  }
  node * getNodeLista(){
    return this->aux;
  }
  int getPeso(){
    return this->peso;
  }
  int getNumero(){
    return this->numero;
  }
  int getVertice(){
    return aux->getVerticeReceptor();
  }
  void resetAux(){
    aux=aresta;
  }
  //modificar para armazenar arestas nao direcionadas.
  void insert(int auxVerticeReceptor,int auxVerticeSaida,int auxSetPesoAresta){
    node * auxAresta=new aresta;
    auxAresta->setVerticeSaida(auxVerticeSaida);
    auxAresta->setVerticeReceptor(auxVerticeReceptor);
    auxAresta->setPeso(auxSetPesoAresta);
    if(arestaVazia()==true){
      manipulador=aresta=auxAresta;
    }
    else{
      manipulador->setProximo(auxAresta);
      manipulador=auxAresta;
    }
  }
  bool arestaVazia(){
    if(aresta==NULL){
      return true;
    }
    else{
      return false;
    }
  }
  bool buscarAresta(int auxVerticeSaida,int auxVerticeReceptor){
    while(aux!=NULL){
      if(aux->getVerticeSaida()==auxVerticeSaida && aux->getVerticeReceptor()==auxVerticeReceptor){
        return true;
      }
      else{
        return false;
      }
      setProximoLista();
    }
  }
  bool removerAresta(int auxVerticeSaida,int auxVerticeReceptor){
    while(aux!=NULL){
      if(aux->getVerticeSaida()==auxVerticeSaida && aux->getVerticeReceptor()==auxVerticeReceptor){
        aux2=aresta;
        while(aux2->getProximo()!=aux){
          aux2=aux2->getProximo();
        }
        aux2->setProximo(aux->getProximo());
        aux->setProximo(NULL);
        delete aux;
        return true;
      }
      else{
        aux->setProximoLista();
      }
    }
    return false
  }
  void insertNode(node * auxNode){
    if(arestaVazia==true){
      aresta=auxNode;
    }
    else{
      manipulador->setProximo(auxNode);
      manipulador=auxNode;
    }
  }
  void orderList(){
    while(aux_verific==1){
      aux=aresta;
      aux_second=aux->getProximo();
      while(aux_second!=NULL){
        aux_verifi=0;
        //verificar integridade.
        if(aux->getPesoAresta()>aux_second->getPesoAresta()){
          aux=aux_second->getProximo();
          aux_second->setProximo(aux);
          aux_verific=1;
          if(aux==aresta){
            aresta=aux_second;
          }
        }
      }
    }
  }
}
