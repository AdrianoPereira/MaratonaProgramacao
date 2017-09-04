#include <bits/stdc++.h>
using namespace std;

// #define MAX 5

void adicionar_aresta(vector< vector<int> >& mat, int a, int b){
	//mat[b-1][a-1] = 1;
	mat[a][b] = 1;
}
 
void bfs(vector< vector<int> >& mat, int root){
	vector<bool> visitados(mat.size(), false);
	queue<int> fila;
	fila.push(root);

	cout << "Visitando: " << root << endl;

	while(!fila.empty()){
		int top = fila.front();
		fila.pop();

		for(int x=0; x<mat.size(); x++){
			if(mat[top][x] != 0 && !visitados[x]){
				cout << "Visitando: " << x << endl;
				fila.push(x);
			}
		}
	}
}
int main(){
	int MAX = 7;
		
	vector< vector <int> > matrix(MAX, vector<int>(MAX));
	
	
	
	for(int x=0; x<MAX; x++){
		for(int y=0; y<MAX; y++){
			cout << matrix[x][y] << " ";
		}
		cout << endl;
	}
	
	cout << "Grafo com arestas adicionadas:" << endl;

	adicionar_aresta(matrix, 0, 1);
	adicionar_aresta(matrix, 0, 3);
	adicionar_aresta(matrix, 1, 2);
	adicionar_aresta(matrix, 1, 5);
	adicionar_aresta(matrix, 3, 4);
	adicionar_aresta(matrix, 4, 6);

	for(int x=0; x<MAX; x++){
		for(int y=0; y<MAX; y++){
			cout << matrix[x][y] << " ";
		}
		cout << endl;
	}

	cout << "Executando BFS...\n";

	bfs(matrix, 0);
	
	return 0;
}