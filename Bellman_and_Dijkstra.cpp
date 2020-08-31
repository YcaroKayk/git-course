#include <iostream>
#include <stdlib.h>

using namespace std;

//Struct Vertices
typedef struct{
	int pesoVertice,pai;
}vertices;

//Struct Arestas
typedef struct{
	int inicioAresta,fimAresta,pesoAresta;
}arestas;

//Inicializa as variaveis geradas
void inicializar(vertices *objVertice,arestas *objAresta){
	for(int i=0;i<5;i++){
		*objVertice[i].pesoVertice=(2147483647/2);
		*objVertice[i].pai=-1;
	}
	for(i=0;i<10;i++){
		*objAresta[i].inicioAresta=-1;
		*objAresta[i].fimAresta=-1;
		*objAresta[i].pesoAresta=0;
	}
	*objVertice[0].pesoVertice=0;
}

//Funcao de relaxamento utilizando enderecos
void relaxamento(vertices *verticeIni,vertice *verticeFin,arestas *arestaAtual){
	if(*verticeFin.pesoVertice>(*verticeIni.pesoVertice+*arestaAtual.pesoAresta)){
		*verticeFin.pesoVertice=(*verticeIni.pesoVertice+*arestaAtual.pesoAresta);
		*verticeFin.pai=*arestaAtual.inicioAresta;
	}
}

//Algoritmo de Bellman-Ford
bool bellmanFord(vetices *objVertice,arestas *objAresta){
	for(int i=0;i<4;i++){
		for(int j=0;j<10;j++){
			relaxamento(&objVertice[*objAresta[j].inicioAresta],&objVertice[*objAresta[j].fimAresta],&objAresta[j]);
		}
	}
	for(i=0;i<10;i++){
		if(*objVertice[*objAresta[i].fimAresta].pesoVertice>(*objVertice[*objAresta[i].inicioAresta].pesoVertice+*objAresta[i].pesoAresta)){
			return false;
			}
		}
	return true;
}

//Algoritmo de Dijkstra
bool dijkstra(vertices *listaVertices,vertices *listaResultante,arestas *objAresta){
	int auxCode=0,cont=0;
	do{
		auxCode=min(&listaVertices);
		if(auxCode!=-1){
			for(int i=0;i<10;i++){
				if(auxCode==*objAresta[i].verticeIni){
					relaxamento(&listaVertices[auxCode],&listaVertices[*objAresta[i].verticeFin],&objAresta[i]);
				}
			}
			listaVertices[auxCode]=nullptr;
			*listaResultante[cont].pai=auxCode;
			cont++;
		}
	}while(auxCode!=-1);
}

int min(vertices *listaVertices){
	int auxMenor=0,auxPeso=-1;
	for(int i=0;i<5;i++){
		if(auxPeso>*objVertice[i].pesoVertice && *objVertice[i]!=nullptr){
			auxPeso=*objVertice[i].pesoVertice;
			auxMenor=i;
		}
		if(auxPeso==-1){
			return auxPeso;
		}
	}
	return auxMenor;
}

//Algoritmo de impressão
void printPath(vertices *objVertice,int origem,int destino){
	if(origem==destino){
		cout<<origem<<endl;
	}
	if(*objVertice[destino].pai==-1){
		cout<<"Não existe um trajeto"<<endl;
	}
	else{
		printPath(&objVertice,origem,*objVertice[destino].pai);
	}
	cout<<destino<<endl;
}

//Funcao principal
int main(void){
	arestas *objAresta[10];
	vertices *objVertice[5],*listaResultante[5];
	objAresta=new arestas;
	objVertice=new vertices;
	listaResultante=new vertices;
	int auxCode=0,auxCode2=0;

	while(true){
		inicializar(objVertice,objAresta);
		cout<<"=====Menu====="<<endl;
		cout<<"1.Bellman-Ford."<<endl;
		cout<<"2.Dijkstra."<<endl;
		cout<<"3.Sair."<<endl;
		cin>>x;

		switch(x){
			case 1://Bellmanford
				cout<<"Informe os vertices de saida e entrada e o peso das 10 arestas existentes:"<<endl;
				cout<<"/nOs vertices são: 0,1,2,3,4."<<endl;
				for(int i=0;i<10;i++){
					cout<<"/nVertice Inicial:";
					cin>>auxCode;
					*objAresta[i].inicioAresta=auxCode;
					cout<<"/nVertice Final:";
					cin>>auxCode;
					*objAresta[i].fimAresta=auxCode;
					cout<<"/nPeso da Aresta:";
					cin>>auxCode;
					*objAresta[i].pesoAresta=auxCode;
				}
				if(bellmanFord(&objVertice,&objAresta)==true){
					cout<<"Foi encontrado um caminho."<<endl;
					cout<<"Os vertices são: 0,1,2,3,4."<<endl;
					cout<<"Selecione o vertice de origem e de destino para verificar seu menor caminho."<<endl;
					cout<<"Vertice de origem:";
					cin>>auxCode;
					cout<<"/nVertice de destino:";
					cin>>auxCode2;
					printPath(&objVertice,auxCode,auxCode2);
				}
				else{
					cout<<"Não foi encontrado um caminho ótimo."<<endl;
				}
			break;
			case 2:
				cout<<"Informe os vertices de saida e entrada e o peso das 10 arestas existentes:"<<endl;
				cout<<"/nOs vertices são: 0,1,2,3,4."<<endl;
				for(int i=0;i<10;i++){
					cout<<"/nVertice Inicial:";
					cin>>auxCode;
					*objAresta[i].inicioAresta=auxCode;
					cout<<"/nVertice Final:";
					cin>>auxCode;
					*objAresta[i].fimAresta=auxCode;
					cout<<"/nPeso da Aresta:";
					cin>>auxCode;
					*objAresta[i].pesoAresta=auxCode;
				}
				if(dijkstra(&objVertice,&listaResultante,&objAresta)==true){
					cout<<"Foi encontrado um melhor caminho caminho."<<endl;
					for(int x=0;x<5;x++){
						cout<<*listaResultante[x].pai;
						cout<<"-";
					}
				}
				else{
					cout<<"Não houve um melhor caminho"<<endl;
				}
			break;
			case 3://Sair do programa.
				delete objAresta;
				delete objVertice;
				delete listaResultante;
				system("PAUSE");
				return 0;
			break;
			default://Opcao não Existe.
				cout<<"A opcão selecionada não existe, tente novamente."<<endl;
		}
	}
	return 0;
}
//End.