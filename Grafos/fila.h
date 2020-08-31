class fila{
  private:
    node * visitor,*auxVisitor;
  public:
    node * remove(){
      node * auxNode;
      auxNode=visitor;
      visitor=visitor->getProximo();
      auxNode->setProximo(NULL);
      //implementar delete.
      return auxNode;
    }
    void insert(int auxNumero){
      node * auxNode;
      auxNode=new node;
      auxNode->setNumero(auxNumero);
      if(visitor!=NULL){
        auxVisitor->setProximo(auxNode);
        auxVisitor=auxNode;
      }
      else{
        auxVisitor=auxNode;
      }
    }
}
