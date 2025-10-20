#include <iostream>
using namespace std;

using ll = long long;
struct Node{
    int idx;
    Node* next;
    Node(int idx, Node* next) : idx(idx), next(next) {}
};
Node* adj[100001];
int w[100001];
int r[100001];
int visited[100001];
static ll ans = 0;

int max(int x, int y){
    return x>y? x: y;
}

void dfs(int cidx){
    visited[cidx] = 1;
    for(Node* n = adj[cidx]; n; n = n->next){
        if(visited[n->idx]) continue;
        dfs(n->idx);
        r[cidx] = max(w[n->idx], r[cidx]);
        w[cidx] = max(0, w[cidx]-r[n->idx]);
    }
    w[cidx] = max(0, w[cidx]-r[cidx]);

    ans += r[cidx];
}

int main(){
    int N, M;
    cin >> N >> M;

    for(int i = 1; i<=N; i++) cin >> w[i];

    for(int i = 0; i<M; i++){
        int u, v;
        cin >> u >> v;
        adj[u] = new Node(v, adj[u]);
        adj[v] = new Node(u, adj[v]);
    }


    dfs(1);
    ans += w[1];

    cout << ans;
}