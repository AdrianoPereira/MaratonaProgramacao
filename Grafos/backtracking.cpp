#include <bits/stdc++.h>

using namespace std;

int cops;

class Coordenada{
public:
	int x, y;
	bool visitado;
};

bool tour(vector <vector <int> > labirinto, vector < vector <Coordenada> > coordenadas, int x, int y ){
	if(x>=0 && x<5 && y>=0 && y<5 && !cops){
		coordenadas[x][y].visitado = true;
		
		if(x == 4 && y == 4){
			cops = 1;
		}else{
			if(x+1 < 5 && labirinto[x+1][y] == 0 && !coordenadas[x+1][y].visitado)
				tour(labirinto, coordenadas, x+1, y);
			if(x-1 >=0 && labirinto[x-1][y] == 0 && !coordenadas[x-1][y].visitado)
				tour(labirinto, coordenadas, x-1, y);

			if(y+1 < 5 && labirinto[x][y+1] == 0 && !coordenadas[x][y+1].visitado)
				tour(labirinto, coordenadas, x, y+1);
			if(y-1 >=0 && labirinto[x][y-1] == 0 && !coordenadas[x][y-1].visitado)
				tour(labirinto, coordenadas, x, y-1);
		}
	}
}

int main(){
	int t;

	cin>>t;

	while(t--){
		vector< vector <int> > labirinto(5);
		vector< vector <Coordenada> >  coordenadas(5);

		for(int x=0; x<5; x++){
			labirinto[x].resize(5);
			coordenadas[x].resize(5);
		}

		for(int x=0; x<5; x++){
			for(int y=0; y<5; y++){
				int e;
				
				cin>>e;

				labirinto[x][y] = e;
				coordenadas[x][y].x = x;
				coordenadas[x][y].y = y;
				coordenadas[x][y].visitado = false;
			}
		}

		cops = 0;
		tour(labirinto, coordenadas, 0, 0);

		cout << ((cops) ? "COPS" : "ROBBERS") << endl;


	}

	return 0;
}
