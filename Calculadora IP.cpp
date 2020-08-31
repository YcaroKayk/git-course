
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

void classIpAddress(char, int*);
void classBroadcastAddress(char, int*);
void classFinalIp(char, int*);
void classHostNumber(char);
void decimalMask(char);
void classInitialIp(int*);
void classCIDR(char);
bool validIp(int*);
void strToInt(string, int*);
string ipInput();
char ipClass(int*);

int main() {
	int * ipInt=NULL, x = 0;
	char classeIpMain ='0';
	string ipString,maskString="";
	bool ver = true;

	ipInt = new int[4];
	//ipString = new string();
	

	while(true){
		cout << "Calculadora IPV4."<< endl;
		cout << "Redes de Computadores II." << endl;
		cout << "Aluno: Ycaro Kayk Fernandes Ferreira dos Santos" << endl;
		cout << "Opções:" << endl;
		cout << "1 - Calcular IP com classes." << endl;
		cout << "2 - Calcular IP sem classes e notação CIDR." << endl;
		cout << "3 - Calcular IP sem classes e notação decimal." << endl;
		cout << "4 - Sair." << endl;
		cout << "Informe a opção desejada:";
		cin >> x;

		//Parte-1:Endereçamento com classes.
		switch (x) {
		case 1:
			do {
				cout << "Calcular IP com classes." << endl;
				ipString=ipInput();
				strToInt(ipString, ipInt);
				ver = validIp(ipInt);
			} while (ver == true);
			classeIpMain = ipClass(ipInt);
			cout << "Endereço IP:" << ipString << endl;
			cout << "Classe:" << classeIpMain << endl;
			decimalMask(classeIpMain);
			classCIDR(classeIpMain);
			classHostNumber(classeIpMain);
			classIpAddress(classeIpMain,ipInt);
			classBroadcastAddress(classeIpMain, ipInt);
			classInitialIp(ipInt);
			classFinalIp(classeIpMain, ipInt);
			break;
		case 2:
			do {
				cout << "Calcular IP sem classe e notação CIDR." << endl;
				//ipInput(ipString);
				//pause
				strToInt(ipString, ipInt);
				ver = validIp(ipInt);
			} while (ver == true);
			break;
		case 4:
			return 0;
		break;
		default:
		break;
		}
	}
	system("PAUSE");
	return 0;
}
	

//Funções.
void classIpAddress(char classeIpAux,int *ipIntAux) {	
	if (classeIpAux == 'A') {
		cout << "Endereço de rede:" << ipIntAux[0] << "." << "0" << "." << "0" <<"."<<"0"<< endl;
	}
	if (classeIpAux == 'B') {
		cout << "Endereço de rede:" << ipIntAux[0] << "." << ipIntAux[1] << "." << "0" << "." << "0" << endl;
	}
	if (classeIpAux == 'C') {
		cout << "Endereço de rede:" << ipIntAux[0] << "." << ipIntAux[1] << "." << ipIntAux[2] << "." << "0" << endl;
	}
}
void classBroadcastAddress(char classeIpAux, int *ipIntAux) {
	if (classeIpAux == 'A') {
		cout << "Endereço de broadcast:" << ipIntAux[0] << "." << "255" << "." << "255" << "." << "255" << endl;
	}
	if (classeIpAux == 'B') {
		cout << "Endereço de broadcast:" << ipIntAux[0] << "." << ipIntAux[1] << "." << "255" << "." << "255" << endl;
	}
	if (classeIpAux == 'C') {
		cout << "Endereço de broadcast:" << ipIntAux[0] << "." << ipIntAux[1] << "." << ipIntAux[2] << "." << "255" << endl;
	}
}
void classFinalIp(char classeIpAux, int	*ipIntAux) {
	if (classeIpAux == 'A') {
		cout << "Endereço de broadcast:" << ipIntAux[0] << "." << "255" << "." << "255" << "." << "254" << endl;
	}
	if (classeIpAux == 'B') {
		cout << "Endereço de broadcast:" << ipIntAux[0] << "." << ipIntAux[1] << "." << "255" << "." << "254" << endl;
	}
	if (classeIpAux == 'C') {
		cout << "Endereço de broadcast:" << ipIntAux[0] << "." << ipIntAux[1] << "." << ipIntAux[2] << "." << "254" << endl;
	}
}
void classHostNumber(char classeIpAux) {
	if (classeIpAux == 'A') {
		cout << "Numero de Hosts:16777214" << endl;
	}
	if (classeIpAux == 'B') {
		cout << "Numero de Hosts:65534" << endl;
	}
	if (classeIpAux == 'C') {
		cout << "Numero de Hosts:254" << endl;
	}
	if (classeIpAux == 'D') {
		cout << "Endereço reservado para multicast." << endl;
	}
	if (classeIpAux == 'E') {
		cout << "Endereço reservado para uso futuro." << endl;
	}
}

void decimalMaskInput(string *maskStringAux) {
	cout << "Digite a mascara na notação decimal:";
	getline(cin,*maskStringAux);
}
void decimalMask(char classeIpAux) {
	if (classeIpAux == 'A') {
		cout << "Mascara Decimal:255.0.0.0" << endl;
	}
	if (classeIpAux == 'B') {
		cout << "Mascara Decimal:255.255.0.0" << endl;
	}
	if (classeIpAux == 'C') {
		cout << "Mascara Decimal:255.255.255.0" << endl;
	}
	if (classeIpAux == 'D') {}
	else {
		cout << "Não foi possivel identificar a mascara." << endl;
	}
}
void classInitialIp(int *ipIntAux) {
	cout << "Endereço IP inicial utilizavel:" << ipIntAux[0] << "." << ipIntAux[1] << "." << ipIntAux[2] << "." << ipIntAux[0]+1 << endl;
}
void classCIDR(char classeIpAux) {
	if (classeIpAux == 'A') {
		cout << "CIDR:/8." << endl;
	}
	if (classeIpAux == 'B') {
		cout << "CIDR:/16." << endl;
	}
	if (classeIpAux == 'C') {
		cout << "CIDR:/24." << endl;
	}
}
bool validIp(int *ipIntAux) {
	for (int i = 0; i < 3; i++) {
		if (ipIntAux[i] > 255 || ipIntAux[i] < 0) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}
void strToInt(string ipStringAux,int *ipIntAux) {
	string auxStr = "0";
	auxStr = ipStringAux[0] + ipStringAux[1] + ipStringAux[2];
	cout << auxStr << endl;
	ipIntAux[0] = std::stoi(auxStr);
	auxStr = ipStringAux[4] + ipStringAux[5] + ipStringAux[6];
	ipIntAux[1] = stoi(auxStr);
	auxStr = ipStringAux[8] + ipStringAux[9] + ipStringAux[10];
	ipIntAux[2] = stoi(auxStr);
	auxStr = ipStringAux[12] + ipStringAux[13] + ipStringAux[14];
	ipIntAux[3] = stoi(auxStr);
}
string ipInput() {
	string ipStringAux="";
	cout << "Digite um IP valido:";
	cin >>ipStringAux;
	cout <<ipStringAux;
	return ipStringAux;
}
char ipClass(int *ipIntAux) {
	if (ipIntAux[0] >= 1 && ipIntAux[3] <= 127) {
		return 'A';
	}
	if (ipIntAux[0] >= 128 && ipIntAux[3] <= 191) {
		return 'B';
	}
	if (ipIntAux[0] >= 192 && ipIntAux[3] <= 223) {
		return 'C';
	}
	if (ipIntAux[0] >= 224 && ipIntAux[3] <= 239) {
		return 'D';
	}
	if (ipIntAux[0] >= 240 && ipIntAux[3] <= 255) {
		return 'E';
	}
	return 'X';
}
