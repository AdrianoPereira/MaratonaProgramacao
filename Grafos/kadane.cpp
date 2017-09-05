#include <bits/stdc++.h>

using namespace std;

int kadane(int vet[], int n, int gastos){
	int atual = 0, total = -1;

	for(int x=0; x<n; x++){
		atual += (vet[x])-gastos;

		if(atual < 0) atual = 0;

		if(atual > total) total = atual;
	}

	return total;
}

int main(){
	int n;

	while(cin>>n){
		int gastos;
		int vet[n];

		cin>>gastos;

		for(int x=0; x<n; x++) cin>>vet[x];
			
		cout << kadane(vet, n, gastos) << endl;

	}	

	return 0;
}
