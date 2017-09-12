#include <bits/stdc++.h>

using namespace std;


void guloso(int moedas[], int troco, int tam){
	int total_moedas = 0;

	for(int x=tam-1; x>=0; x--){
		int qtd_moed_atual = troco / moedas[x];
		troco -= qtd_moed_atual * moedas[x];
		cout << qtd_moed_atual << " Moedas de " << moedas[x] << " centavos" << endl;
		total_moedas += qtd_moed_atual;
	}
	cout << "Total de Moedas: " << total_moedas << endl;
}

int main(){
	int moedas[] = {1, 2, 5, 10, 20};
	int troco = 23;
	int tam = 5;

	guloso(moedas, troco, tam);
	
	return 0;
}