#include <bits/stdc++.h>

using namespace std;
#define MAX 1000

int v, a;
int matriz[MAX][MAX];
int ans;

int dfs(int v1){
    ans++;
    bool visitados[v];
    for(int x=0; x<v; x++){
        visitados[x] = false;
    }
    for(int x=0; x<v; x++){
        if(matriz[v1][x] == 1 && !visitados[x]){
            //cout << x+1 << endl;
            visitados[x] = true;
            dfs(x);
        }
    }
}

int main(){
    int v1, v2;
    int q;

    ans = 0;
    cin>>v>>a;
    
    for(int x=0; x<v; x++){
        for(int y=0; y<v; y++){
            matriz[x][y] = 0;
        }
    }
    for(int x=0; x<a; x++){
        cin>>v1>>v2;
        matriz[v1-1][v2-1] = 1;   
    }
    cin>>q;

    dfs(q-1);

    cout << ans << endl;
    return 0;
}
/*
5 3
1 3
3 5
2 4
1

3 1
1 2
3
*/