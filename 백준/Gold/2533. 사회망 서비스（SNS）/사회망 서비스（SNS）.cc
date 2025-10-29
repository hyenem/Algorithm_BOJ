#include <iostream>
using namespace std;

struct Edge{
    int end;
    Edge* next;
    Edge(int end, Edge* next) : end(end), next(next) {}
};
Edge* adj[1000001];
bool visited[1000001];
bool early[1000001];
int ans = 0;

void add(int s, int e){
    adj[s] = new Edge(e, adj[s]);
    adj[e] = new Edge(s, adj[e]);
}
void dfs(int n){
    visited[n] = true;
    for(Edge* e = adj[n]; e; e = e->next){
        if(visited[e->end]) continue;
        dfs(e->end);
        if(!early[n] && !early[e->end]){
            early[n] = true;
            ++ans;
        }
    }
}
int main(){
    int N;
    cin >> N;

    for(int i = 0; i<N-1; i++){
        int s, e;
        cin >> s >> e;
        add(s, e);
    }

    dfs(1);
    cout << ans;
}