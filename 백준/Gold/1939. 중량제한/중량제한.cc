#include <iostream>
using namespace std;

long long min(long long x, long long y){
    return x>y? y:x;
}
struct Edge{
    int dst;
    long long w;
    Edge* next;
    Edge(int dst, long long w, Edge* next) : dst(dst), w(w), next(next){}
};
Edge* adj[10001];
struct Node{
    int dst;
    long long w;
    Node(int dst, long long w) : dst(dst), w(w){}
};

long long maxweight[10001];
Node* pq[400004];
static int sizee = 0;
void swap(int i, int j){
    Node* tmp = pq[i];
    pq[i] = pq[j];
    pq[j] = tmp;
}

void push(Node* e){
    pq[++sizee] = e;
    int idx = sizee;

    while(idx>1){
        if(pq[idx/2]->w < pq[idx]->w) {
            swap(idx/2, idx);
            idx /= 2;
        } else break;
    }
}

Node* pop(){
    Node* res = pq[1];
    pq[1] = pq[sizee--];

    int idx = 1;
    while(true){
        int left = idx*2, right = left+1, best = idx;
        if(left<=sizee && pq[left]->w > pq[best]->w) best = left;
        if(right<=sizee && pq[right]->w > pq[best]->w) best = right;
        if(idx==best) break;

        swap(idx, best);
        idx = best;
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int A, B;
    long long C;
    for(int i = 0; i<M; i++){
        cin >> A >> B >> C;
        adj[A] = new Edge(B, C, adj[A]);
        adj[B] = new Edge(A, C, adj[B]);
    }

    int start, end;
    cin >> start >> end;

    for(Edge* e = adj[start]; e; e = e->next){
        push(new Node(e->dst, e->w));
        maxweight[e->dst] = e->w;
    }
    while(sizee){
        Node* curN = pop();
        int cur = curN->dst;

        if(maxweight[cur]>curN->w) continue;
        if(cur==end) break;

        for(Edge* e = adj[cur]; e; e = e->next){
            if(maxweight[e->dst] >= min(e->w, curN->w)) continue;
            maxweight[e->dst] = min(e->w, curN->w);
            push(new Node(e->dst, maxweight[e->dst]));
        }
        delete curN;
    }

    cout << maxweight[end];
}