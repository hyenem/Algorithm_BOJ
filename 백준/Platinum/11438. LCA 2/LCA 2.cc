#include <iostream>
using namespace std;

#define MAXN 100001

struct Node{
    int idx;
    Node* next;
    Node(int idx, Node* next) : idx(idx), next(next) {}
}*adj[MAXN];
void addNode(int s, int e){
    adj[s] = new Node(e, adj[s]);
    adj[e] = new Node(s, adj[e]);
}
bool visited[MAXN];

int depth[MAXN];
int dp[MAXN][17];

void dfs(int p){
    for(Node* c = adj[p]; c; c = c->next){
        int cidx = c->idx;
        if(visited[cidx]) continue;
        visited[cidx] = true;

        depth[cidx] = depth[p]+1;
        dp[cidx][0] = p;
        for(int i = 1; i<17; ++i){
            dp[cidx][i] = dp[dp[cidx][i-1]][i-1];
        }

        dfs(cidx);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int a, b;
    for(int i = 0; i<N-1; ++i){
        cin >> a >> b;
        addNode(a, b);
    }

    visited[1] = true;
    dfs(1);

    int M;
    cin >> M;
    for(int i = 0; i<M; ++i){
        cin >> a >> b;
        if(depth[a] > depth[b]){
            int tmp = a;
            a = b;
            b = tmp;
        }

        int dist = depth[b] - depth[a];
        if(dist){
            for(int i = 0; i < 17; ++i){
                if(dist & (1 << i)){
                    b = dp[b][i];
                }
            }
        }

        if(a==b) {
            cout << a <<'\n';
            continue;
        }
        
        for(int i = 16; i>=0; --i){
            if(dp[a][i]==dp[b][i]) continue;
            a = dp[a][i];
            b = dp[b][i];
        }
        cout << dp[a][0] <<'\n';
    }
}