#include <bits/stdc++.h>

using namespace std;
#define INF 999999
#define MAX 501
#define lli long long int

int v, a;
int matrix[MAX][MAX];

int dijkstra(int origem, int destino){
	int custo_minimo, vertice_atual;
	bool visitados[v];
	int distancias[v];

	for(int x=0; x<v; x++){
		visitados[x] = false;
		distancias[x] = INF;
	}

	vertice_atual = origem;
	distancias[origem] = 0;

	while(vertice_atual != destino){
		for(int x=0; x<v; x++){
			//Relaxamento
			if(distancias[x] > (distancias[vertice_atual] + matrix[vertice_atual][x])){
				distancias[x] = distancias[vertice_atual] + matrix[vertice_atual][x];

			}
		}
		custo_minimo = INF;
		visitados[vertice_atual] = true;
		for(int x=0; x<v; x++){
			if((distancias[x] < custo_minimo) && (!visitados[x])){
				custo_minimo = distancias[x];
				vertice_atual = x;
			}
		}
		if(custo_minimo == INF) return INF;
	}
	return distancias[destino];
}

int main(){
	int consultas;
	int v1, v2, p;

	while(cin>>v>>a, v&&a){
		for(int x=0; x<v; x++){
			for(int y=0; y<v; y++){
				matrix[x][y] = INF;
			}
		}

		for(int x=0; x<a; x++){
			cin>>v1>>v2>>p;
			if(matrix[v2-1][v1-1] != INF){
				matrix[v1-1][v2-1] = 0;
				matrix[v2-1][v1-1] = 0;
			}else{
				matrix[v1-1][v2-1] = p;
			}
		}

		cin>>consultas;

		for(int x=0; x<consultas; x++){
			cin>>v1>>v2;
			lli ans = dijkstra(v1-1, v2-1);
			if(ans != INF){
				cout << ans << endl;
			}else{
				cout << "Nao e possivel entregar a carta" << endl;
			}
		}
		cout << endl;
	}
		
	return 0;
}

/*
4 5
1 2 5
2 1 10
3 4 8
4 3 7
2 3 6
5
1 2
1 3
1 4
4 3
4 1
*/