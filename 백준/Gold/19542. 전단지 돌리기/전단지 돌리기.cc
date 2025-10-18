#include <iostream>
using namespace std;

int maxx(int x, int y){
    return x>y? x: y;
}
struct node{
    int idx;
    node* next;
    node(int idx, node *next) : idx(idx), next(next) {}
};
node* adj[100001];
int visited[100001];
static int cnt = 0;
static int D = 0;
int dfs(int idx, int depth){
    visited[idx] = 1;
    node* now = adj[idx];

    int maxdepth = depth;
    while(now->idx!=-1){
        if(visited[now->idx]) {
            now = now->next;
            continue;
        }
        maxdepth = maxx(dfs(now->idx, depth+1), maxdepth);
        now = now->next;
    }
    
    if(maxdepth-depth>=D) cnt ++;
    return maxdepth;
}

int main(){
    int N, S;
    cin >> N >> S >> D;

    for(int i = 1; i<N+1; i++){
        adj[i] = new node(-1, nullptr);
    }

    int u, v;
    for(int i = 0; i<N-1; i++){
        cin >> u >> v;
        node* ndu = new node(v, adj[u]);
        node* ndv = new node(u, adj[v]);
        adj[u] = ndu;
        adj[v] = ndv;
    }


    dfs(S, 0);


    cout << maxx(2*cnt-2, 0);

}