#include <iostream>
using namespace std;

#define MAXN 100001

int min(int x, int y){return x < y? x : y; }
int max(int x, int y){return x > y? x : y; }

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
int parent[MAXN][17];
int mindist[MAXN][17];
int maxdist[MAXN][17];
int depth[MAXN];

int minans, maxans;

void dfs(int pidx){
    for(Node* e = adj[pidx]; e; e= e->next){
        int cidx = e->end;
        if(visited[cidx]) continue;

        visited[cidx] = 1;
        depth[cidx] = depth[pidx]+1;

        parent[cidx][0] = pidx;
        mindist[cidx][0] = e->dist;
        maxdist[cidx][0] = e->dist;
        for(int i = 1; i<17; ++i){
            parent[cidx][i] = parent[parent[cidx][i-1]][i-1];
            mindist[cidx][i] = min(mindist[parent[cidx][i-1]][i-1], mindist[cidx][i-1]);
            maxdist[cidx][i] = max(maxdist[parent[cidx][i-1]][i-1], maxdist[cidx][i-1]);
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
    int a, b, lca;
    for(int i = 0; i<M; ++i){
        cin >> a >> b;
        minans = 1000000, maxans = 0;

        if(depth[a] < depth[b]){
            int tmp = a;
            a = b;
            b = tmp;
        }

        int dist = depth[a]-depth[b];
        if(dist){
            for(int i = 0; i<17; ++i){
                if(dist & (1<<i)){
                    minans = min(minans, mindist[a][i]);
                    maxans = max(maxans, maxdist[a][i]);
                    a = parent[a][i];
                }
            }
        }

        if(a!=b){
            for(int i = 16; i>=0; --i){
                if(parent[a][i]==parent[b][i]) continue;
                minans = min(minans, mindist[a][i]);
                maxans = max(maxans, maxdist[a][i]);
                minans = min(minans, mindist[b][i]);
                maxans = max(maxans, maxdist[b][i]);
                a = parent[a][i];
                b = parent[b][i];
            }
            minans = min(minans, mindist[a][0]);
            maxans = max(maxans, maxdist[a][0]);
            minans = min(minans, mindist[b][0]);
            maxans = max(maxans, maxdist[b][0]);
            lca = parent[b][0];
        }

        cout << minans << ' '<< maxans << '\n';
    }
}