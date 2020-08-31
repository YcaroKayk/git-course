class node{
private:
  int verticeReceptor,verticeSaida,pesoAresta,numero;
  node * proximo;
public:
  node(){
    proximo=NULL;
    verticeReceptor=pesoVertice=0;
  }
  void setNumero(int auxNumero){
    this->numero=auxNumero;
  }
  void setVerticeReceptor(int auxVerticeReceptor){
    this->verticeReceptor=auxVerticeReceptor;
  }
  void setVerticeSaida(int auxVerticeSaida){
    this->verticeSaida=auxVerticeSaida;
  }
  void setPesoAresta(int auxPesoAresta){
    this->pesoAresta=auxPesoAresta;
  }
  void setProximo(node * auxProximo){
    this->proximo=auxProximo;
  }
  int getVerticeReceptor(){
    return this->verticeReceptor;
  }
  int getVerticeReceptor(){
    return this->verticeSaida;
  }
  int getPesoAresta(){
    return this->pesoAresta;
  }
  node * getProximo(){
    return this->proximo;
  }
  int getNumero(){
    return this->numero;
  }
}
