#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

void dfs(int v, vector<vector<int>>& adj, vector<int>& visited){
    cout<< v+1 << ' ';
    for(int next : adj[v]){
        if(visited[next]){
            continue;
        } else {
            visited[next]=1;
            dfs(next, adj, visited);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;
    V -= 1;

    vector<vector<int>> adj(N);
    for(int m=0; m<M; m++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int n = 0; n<N; n++){
        sort(adj[n].begin(), adj[n].end());
    }

    vector<int> visitedDFS(N);
    vector<int> visitedBFS(N);
    
    visitedDFS[V]=1;
    dfs(V, adj, visitedDFS);
    cout << '\n';
    
    queue<int> q;
    q.push(V);
    visitedBFS[V]=1;
    int now;

    while(!q.empty()){
        now = q.front();
        q.pop();
        cout << now+1 << ' ';

        for(int next:adj[now]){
            if (visitedBFS[next]){
                continue;
            } else {
                visitedBFS[next]=1;
                q.push(next);
            }
        }

    }
}