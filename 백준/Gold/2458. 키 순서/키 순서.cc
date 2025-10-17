#include <iostream>
using namespace std;

int adj[501][501];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int u, v;
    for(int i = 0; i<M; i++){
        cin >> u >> v;
        adj[u][v] = 1;
    }
    
    for(int v = 1; v<= N; v++){
        for(int i = 1; i<= N; i++){
            for(int j = 1; j<=N; j++){
                if(adj[i][v]&&adj[v][j]) adj[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i<=N; i++){
        int cnt = 0;
        for(int j = 1; j<=N; j++){
            if(adj[i][j]) cnt++;
            if(adj[j][i]) cnt++;
        }
        if(cnt==N-1) ans++;
    }

    cout << ans;
}