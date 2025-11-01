#include <iostream>
using namespace std;

#define ll  long long

struct Edge{
    int start, end;
    Edge(){}
    Edge(int start, int end) : start(start), end(end) {}
};
int p[100001];
int Size[100001];
int Find(int u){
    if(p[u]==u) return u;
    return p[u] = Find(p[u]);
}
void Union(int u, int v){
    int pu = Find(u), pv = Find(v);
    if(pu==pv) return;

    if(Size[pu]<Size[pv]){
        p[pu] = pv;
        Size[pv] += Size[pu];
    } else {
        p[pv] = pu;
        Size[pu] += Size[pv];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    Edge edges[M+1];

    for(int i = 1; i<=M ; i++){
        int s, e;
        cin >> s >> e;
        edges[i].start = s;
        edges[i].end = e;
    }

    bool unUsed[M+1];
    for(int i = 0; i<M+1; i++) unUsed[i] = false;
    int stack[Q];
    for(int i = 0; i<Q; i++){
        cin >> stack[i];
        unUsed[stack[i]] = true;
    }

    for(int i = 0; i<=N; i++) {
        p[i] = i;
        Size[i] = 1;
    }
    for(int i = 1; i<=M; i++){
        if(unUsed[i]) continue;
        Union(edges[i].start, edges[i].end);
    }

    ll ans = 0;
    for(int i = Q-1; i>=0; i--){
        int u = edges[stack[i]].start;
        int v = edges[stack[i]].end;

        int pu = Find(u), pv = Find(v);
        if(pu==pv) continue;
        ans += 1LL*Size[pu]*Size[pv];
        Union(pu, pv);
    }

    cout << ans;
}