#include <iostream>
using namespace std;

#define MAXN 40001

struct Node{
    int end;
    int dist;
    Node* next;
    Node(int end, int dist, Node* next) : end(end), dist(dist), next(next){}
}*adj[MAXN];
void addNode(int s, int e, int d){
    adj[s] = new Node(e, d, adj[s]);
    adj[e] = new Node(s, d, adj[e]);
}

bool visited[MAXN];
int parent[MAXN][16];
int dist2root[MAXN];
int depth[MAXN];

void dfs(int pidx){
    for(Node* e = adj[pidx]; e; e= e->next){
        int cidx = e->end;
        if(visited[cidx]) continue;

        visited[cidx] = 1;
        depth[cidx] = depth[pidx]+1;
        dist2root[cidx] = dist2root[pidx] + e->dist;
        
        parent[cidx][0] = pidx;
        for(int i = 1; i<16; ++i){
            parent[cidx][i] = parent[parent[cidx][i-1]][i-1];
        }
        dfs(cidx);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int s, e, d;
    for(int i = 0; i<N-1; ++i) {
        cin >> s >> e >> d;
        addNode(s, e, d);
    }

    visited[1] = true;
    dfs(1);

    int M;
    cin >> M;
    int a, b, ans;
    for(int i = 0; i<M; ++i){
        cin >> a >> b;
        ans = dist2root[a] + dist2root[b];

        if(depth[a] < depth[b]){
            int tmp = a;
            a = b;
            b = tmp;
        }

        int dist = depth[a]-depth[b];
        if(dist){
            for(int i = 0; i<16; ++i){
                if(dist & (1<<i)){
                    a = parent[a][i];
                }
            }
        }

        if(a!=b){
            for(int i = 15; i>=0; --i){
                if(parent[a][i]==parent[b][i]) continue;
                a = parent[a][i];
                b = parent[b][i];
            }
            b = parent[b][0];
        }

        ans -= 2*dist2root[b];
        cout << ans <<'\n';
    }
}