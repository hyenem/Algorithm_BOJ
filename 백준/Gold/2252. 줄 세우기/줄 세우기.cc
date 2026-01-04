#include <iostream>
using namespace std;

#define MAXN 32001

int indegree[MAXN];
struct Node{
    int end;
    Node* next;
    Node(int end, Node* next):end(end), next(next){}
}*adj[MAXN];
void addNode(int first, int second){
    adj[first] = new Node(second, adj[first]);
    ++indegree[second];
}
bool visited[MAXN];

void pick(int idx){
    cout << idx << ' ';
    visited[idx] = true;

    for(Node* n = adj[idx]; n; n=n->next){
        if(visited[n->end]) continue;

        if(indegree[n->end]>0) --indegree[n->end];
        if(!indegree[n->end]) pick(n->end);
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    int A, B;
    for(int i = 0; i<M; ++i){
        cin >> A >> B;
        addNode(A, B);
    }

    for(int i = 1; i<=N; ++i){
        if(visited[i]) continue;
        if(!indegree[i]){
            pick(i);
        }
    }
}