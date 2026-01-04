#include <iostream>
using namespace std;

#define MAXN 200001

struct Node{
    int end;
    Node* next;
    Node(int end, Node* next):end(end), next(next){}
};
Node* adjs[MAXN];
Node* adjr[MAXN];
void addNode(int s, int e){
    adjs[s] = new Node(e, adjs[s]);
    adjr[e] = new Node(s, adjr[e]);
}
int visited[MAXN];
int stack[MAXN];
int pointer = -1;
int cnt;

void dfsfirst(int idx){
    visited[idx] = 1;
    for(Node* n = adjs[idx]; n; n=n->next){
        if(visited[n->end]==1) continue;
        dfsfirst(n->end);
    }
    stack[++pointer] = idx;
}
void dfssecond(int idx){
    visited[idx] = 2;
    ++cnt;
    for(Node* n = adjr[idx]; n; n = n->next){
        if(visited[n->end]==2) continue;
        dfssecond(n->end);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, s, e;
    cin >> N >> M;
    for(int i = 0; i<M; ++i){
        cin >> s >> e;
        addNode(s, e);
    }

    for(int i = 1; i<=N; ++i){
        if(visited[i]==1) continue;
        dfsfirst(i);
    }
    dfssecond(stack[pointer]);
    if(cnt==N) cout << "Yes";
    else cout << "No";
}