#include <bits/stdc++.h>

using namespace std;

void guloso(int moedas[], int troco, int tam){
	int total = 0;

	for(int x=tam-1; x>=0; x--){
		int qtd_atual = troco/moedas[x];
		troco -= qtd_atual*moedas[x];
		total += qtd_atual;

		cout << qtd_atual << " Moedas de " << moedas[x] << endl;
	}

	cout << "Total de moedas: " << total << endl;
}

int main(){
	int moedas[] = {1, 2, 5, 10, 20};
	int troco = 49;
	int tam = sizeof moedas / 4;

	guloso(moedas, troco, tam);

	return 0;
}