#include <iostream>
using namespace std;

struct Edge{
    int dst;
    Edge *next;

    Edge(int dst, Edge *next):dst(dst), next(next){}
};
Edge* adj[123457];
struct Land{
    char t;
    long long a, p;
};
Land lands[123457];

void add_edge(int src, int dst){
    adj[src] = new Edge(dst, adj[src]);
}

long long dfs(int idx){
    long long res = 0;
    if(lands[idx].t=='S') res = lands[idx].a;
    for(Edge* e = adj[idx]; e; e=e->next){
        res += dfs(e->dst);
    }
    if(lands[idx].t=='W') res = res-lands[idx].a;
    return (res>0)?res:0;
}

int main(){
    int N;
    cin >> N;

    char t;
    long long a, p;
    for(int i = 2; i<=N; i++){
        cin >> lands[i].t >> lands[i].a >> lands[i].p;
        add_edge(lands[i].p, i);
    }

    cout << dfs(1);
}