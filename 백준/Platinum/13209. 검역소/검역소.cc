#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N   100001
#define ll      long long

int max(int x, int y){return x>y? x: y;}

int N, K;
int population[MAX_N];
struct Edge{
    int end;
    Edge* next;
    Edge(int end, Edge* next) : end(end), next(next) {}
};
Edge* adj[MAX_N];
void addEdge(int s, int e){
    adj[s] = new Edge(e, adj[s]);
    adj[e] = new Edge(s, adj[e]);
}

ll dp[MAX_N];
bool visited[MAX_N];
int dfs(int idx, ll limit){
    visited[idx] = true;

    int res = 0;
    dp[idx] = population[idx];

    vector<ll> stack;
    for(Edge* e = adj[idx]; e; e = e->next){
        if(visited[e->end]) continue;

        res += dfs(e->end, limit);
        stack.push_back(dp[e->end]);
    }
    sort(stack.begin(), stack.end(), greater<ll>());
    while(!stack.empty() && dp[idx]+stack.back()<=limit){
        dp[idx] += stack.back();
        stack.pop_back();
    }
    return res + stack.size();
}
bool check(ll p){
    for(int i = 0; i<=N; i++) visited[i] = false;
    int res = dfs(1, p);
    return res <= K;
}

void clearGraph(){
    for(int i = 1; i <= N; i++){
        for(Edge* e = adj[i]; e; ){
            Edge* nxt = e->next;
            delete e;
            e = nxt;
        }
        adj[i] = nullptr;
    }
}

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc<=T; tc++){
        cin >> N >> K;
        clearGraph();
        ll maxp = 0, sump = 0;
        for(int i = 1; i<=N; i++){
            cin >> population[i];
            maxp = max(maxp, population[i]);
            sump += population[i];
        }
        for(int i = 0; i<N-1; i++){
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        }

        ll left = maxp, right = sump;
        while(left < right){
            ll mid = (left+right)/2;
            if(check(mid)) right = mid;
            else left = mid + 1;
        }
        cout << right << '\n';
    }
}