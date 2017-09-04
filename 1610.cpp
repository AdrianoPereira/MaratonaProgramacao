#include <bits/stdc++.h>

using namespace std;

class Grafo{
	int V;
	list<int> *adj;
public:
	Grafo(int V);
	void addEdge(int a, int b);
	bool dfs(int root);
	bool temCiclo(int root);
};

Grafo::Grafo(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Grafo::addEdge(int a, int b){
	adj[a].push_back(b);
}

bool Grafo::dfs(int root){
	stack<int> pilha;
	bool visitados[V], pilha_de_rec[V];

	for(int x=0; x<V; x++) visitados[x] = pilha_de_rec[x] = false;

	while(true){
		bool achou_vizinho = false;
		list<int>::iterator it;

		if(!visitados[root]){
			pilha.push(root);
			visitados[root] = pilha_de_rec[root] = true;
		}

		for(it = adj[root].begin(); it != adj[root].end(); ++it){
			if(pilha_de_rec[*it]){
				return true;
			}
			if(!visitados[*it]){
				achou_vizinho = true;
				break;
			}
		}

		if(!achou_vizinho){
			pilha_de_rec[pilha.top()] = false; // marca que saiu da pilha
			pilha.pop(); // remove da pilha
			if(pilha.empty())
				break;
			root = pilha.top();
		}else{
			root = *it;
		}

	}
	return false;
}

bool Grafo::temCiclo(int root){
	for(int x=0; x<V; x++){
		if(dfs(x)) return true;
	}
	return false;
}


int main(){
	int t;

	cin>>t;

	while(t--){
		int tarefas, dependencias;
		int v1, v2;
		
		cin>>tarefas>>dependencias;

		Grafo grafo(tarefas);

		for(int x=0; x<dependencias; x++){
			cin>>v1>>v2;
			grafo.addEdge(v1-1, v2-1);
		}

		cout << ( (grafo.temCiclo(0)) ? "SIM" : "NAO" ) << endl;

	}

	return 0;
}

/*
3

2 1
	1 2

2 2
	1 2
	2 1

4 4
	2 3
	3 4
	4 2
	1 3
*/
