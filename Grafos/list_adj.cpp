#include <bits/stdc++.h>

using namespace std;

class Grafo{
	int V;
	list<int> *adj;
public:
	Grafo(int V);
	void adicionar_aresta(int v, int w);
	void bfs(int v);
	void dfs_aux(int v, bool visitados[]);
	void dfs(int v);
};

Grafo::Grafo(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Grafo::adicionar_aresta(int v, int w){
	adj[v].push_back(w);
}

void Grafo::bfs(int v){
	queue<int> auxiliar;
	bool visitados[V];

	for(int x=0; x<V; x++) visitados[x] = false;
	
	cout << "Visitando: " << (v)	 << endl;
	visitados[v] = true;

	while(true){
		list<int>::iterator it;

		for(it = adj[v].begin(); it != adj[v].end(); ++it){
			if(!visitados[*it]){
				cout << "Visitando: " << (*it)	 << endl;
				visitados[*it] = true;
				auxiliar.push(*it);
			}
		}

		if(!auxiliar.empty()){
			v = auxiliar.front();
			auxiliar.pop();
		}else{
			break;
		}
	}
}

void Grafo::dfs_aux(int v, bool visitados[]){
	cout << "Visitado: " << v << endl;
	visitados[v] = true;

	list<int>::iterator it;

	for(it = adj[v].begin(); it != adj[v].end(); ++it){
		if(!visitados[*it])
			dfs_aux(*it, visitados);
	}
}

void Grafo::dfs(int v){
	bool visitados[V];

	for (int i = 0; i < V; ++i) visitados[i] = false;

	dfs_aux(v, visitados);

}

int main(){
	Grafo grafo(8);
	grafo.adicionar_aresta(0, 1);
	grafo.adicionar_aresta(0, 4);
	grafo.adicionar_aresta(1, 2);
	grafo.adicionar_aresta(1, 3);
	grafo.adicionar_aresta(4, 5);
	grafo.adicionar_aresta(4, 6);
	grafo.adicionar_aresta(6, 7);

	cout << "Busca em largura" << endl;
	grafo.bfs(0);

	cout << "Busca em profundidade" << endl;
	grafo.dfs(0);
	return 0;
}