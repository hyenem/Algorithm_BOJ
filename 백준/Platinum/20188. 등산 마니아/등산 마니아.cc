#include <iostream>
using namespace std;

#define MAXN    300001
#define ll long long

struct Edge{
    int end;
    Edge* next;
    Edge(){}
    Edge(int end, Edge* next) : end(end), next(next) {}
};
Edge* adj[MAXN];
bool visited[MAXN];
int tsize[MAXN];

void add(int s, int e){
    adj[s] = new Edge(e, adj[s]);
}
int N;
ll res = 0;
ll nC2(int i){
    return (1L*i*(i-1))/2;
}
void dfs(int n){
    tsize[n] = 1;
    visited[n] = true;
    for(Edge* c = adj[n]; c; c = c->next){
        if(visited[c->end]) continue;
        dfs(c->end);
        int M = tsize[c->end];
        res += nC2(N) - nC2(N-M);
        tsize[n] += tsize[c->end];
    }
}
int main(){
    cin >> N;

    for(int i = 0; i<N-1; i++){
        int s, e;
        cin >> s >> e;
        add(s, e);
        add(e, s);
    }

    dfs(1);

    cout << res;
}