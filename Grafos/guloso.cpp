#include <bits/stdc++.h>

using namespace std;


int guloso(vector <int>& blocos, int comprimento){
	int ans = 0;

	for(int x=blocos.size()-1; x>=0; x--){
		int aux = comprimento/blocos[x];
		comprimento -= aux * blocos[x];
		ans += aux;
	}

	return ans;
}

int main(){
	int t;

	cin>>t;

	while(t--){
		int tipos, comprimento;
		cin>>tipos>>comprimento;

		vector<int> blocos(tipos);

		for(int x=0; x<tipos; x++){
			cin>>blocos[x];
		}
		sort(blocos.begin(), blocos.end());
		cout << guloso(blocos, comprimento) << endl;
	}
	
	return 0;
}