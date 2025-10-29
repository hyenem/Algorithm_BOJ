#include <iostream>
#include <utility>
using namespace std;

int max(int x, int y){ return x>y? x: y;}
struct Edge{
    int end, dist;
    Edge* next;
    Edge(int end, int dist, Edge* next) : end(end), dist(dist), next(next) {}
};
Edge* adj[10001];
void add(int s, int e, int d){
    adj[s] = new Edge(e, d, adj[s]);
}
int maxlength[10001];
int ans = 0;
void dfs(int n){
    int first = 0, second = 0;
    for(Edge* c = adj[n]; c; c= c->next){
        dfs(c->end);
        maxlength[c->end] += c->dist;

        if(maxlength[c->end]>first){
            second = first;
            first = maxlength[c->end];
        } else if(maxlength[c->end] > second){
            second = maxlength[c->end];
        }
        maxlength[n] = max(maxlength[n], maxlength[c->end]);
    }
    ans = max(ans, first+second);
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N-1; i++){
        int s, e, d;
        cin >> s >> e >> d;
        add(s, e, d);
    }
    dfs(1);

    cout << ans;
}