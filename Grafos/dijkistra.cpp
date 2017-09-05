#include <bits/stdc++.h>

using namespace std;

#define INF 10000000

class Grafo{
	int V;
	list< pair<int, int> > *adj;

public:
	Grafo(int V){
		this->V = V;
		adj = new list< pair<int, int> >[V];
	}

	int adicionar_aresta(int v1, int v2, int c){
		adj[v1].push_back(make_pair(v2, c));
	}

	int dijkstra(int origem, int destino){
		int distancia[V];
		bool visitados[V];
		priority_queue< pair <int, int>, vector< pair <int, int> >, greater < pair <int, int> > > pq;

		for(int x=0; x<V; x++){
			visitados[x] = false;
			distancia[x] = INF;
		}

		distancia[origem] = 0;

		pq.push(make_pair(distancia[origem], origem));

		while(!pq.empty()){
			pair<int, int> aux = pq.top();
			int topo = aux.second;
			pq.pop();

			if(visitados[topo] == false){
				visitados[topo] = true;

				list< pair <int, int> >::iterator it;

				for(it = adj[topo].begin(); it != adj[topo].end(); ++it){
					int vertice_adj = it->first;
					int custo = it->second;
				
					if(distancia[vertice_adj] > distancia[topo] + custo){
						distancia[vertice_adj] = distancia[topo] + custo;
						pq.push(make_pair(distancia[topo], vertice_adj));
					}
				}
			}
		}
		return distancia[destino];
	}
};

int main(){
	Grafo g(5);

	g.adicionar_aresta(0, 1, 4);
	g.adicionar_aresta(0, 2, 2);
	g.adicionar_aresta(0, 3, 5);
	g.adicionar_aresta(1, 4, 1);
	g.adicionar_aresta(2, 1, 1);
	g.adicionar_aresta(2, 3, 2);
	g.adicionar_aresta(2, 4, 1);
	g.adicionar_aresta(3, 4, 1);

	cout << g.dijkstra(0, 4) << endl;
	return 0;
}