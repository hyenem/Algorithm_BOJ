#include <iostream>
using namespace std;

int max(int x, int y) {return x>y? x: y;}

int DP[10001][2];
int weight[10001];
int visited[10001];
struct Edge{
    int end;
    Edge* next;
    Edge(int end, Edge* next) : end(end), next(next) {}
};
Edge* adj[10001];
void add(int s, int e){
    adj[s] = new Edge(e, adj[s]);
    adj[e] = new Edge(s, adj[e]);
}
void dfs(int n){
    visited[n] = true;
    for(Edge* e = adj[n]; e; e = e->next){
        if(visited[e->end]) continue;
        dfs(e->end);

        DP[n][0] += DP[e->end][1];
        DP[n][1] += max(DP[e->end][0], DP[e->end][1]);
    }
    DP[n][0] += weight[n];
}

int fvisited[10001];
bool use[10001];
void findroot(int n, bool before){
    fvisited[n] = true;

    if(!before && DP[n][0]>DP[n][1]){
        use[n] = true;
    }
    for(Edge* e = adj[n]; e; e = e->next){
        if(fvisited[e->end]) continue;
        findroot(e->end, use[n]);
    }
}
int main(){
    int N;
    cin >> N;
    for(int i = 1; i<=N; i++) cin >> weight[i];
    for(int i = 0; i<N-1; i++){
        int s, e;
        cin >> s >> e;
        add(s, e);
    }

    dfs(1);
    int ans = max(DP[1][0], DP[1][1]);
    cout << ans <<'\n';

    findroot(1, false);
    for(int i = 1; i<=N; i++){
        if(use[i]) cout << i <<' ';
    }
}