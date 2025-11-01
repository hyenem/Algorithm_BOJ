#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define MAX_N 101
#define MAX_K 101

int N, K;
struct Node{
    int idx, time, pos;
    Node(int idx, int time, int pos) : idx(idx), time(time), pos(pos) {}
};
Node* Using[MAX_K];
Node* pq[MAX_N];
int pqSize=0;
void swap(int x, int y){
    Node* tmp = pq[x];
    pq[x] = pq[y];
    pq[y] = tmp;

    pq[x]->pos = x;
    pq[y]->pos = y;
}
void up(int pos){
    while(pos>1){
        int p = pos/2;
        if(pq[pos]->time > pq[p]->time) swap(pos, p);
        else break;

        pos /= 2;
    }
}
void down(int pos){
    while(true){
        int lc = pos*2, rc = lc+1, best = pos;
        if(lc<=pqSize && pq[best]->time < pq[lc]->time) best = lc;
        if(rc<=pqSize && pq[best]->time < pq[rc]->time) best = rc;
        if(best == pos) break;

        swap(best, pos);
        pos = best;
    }
}
int ans = 0;
Node* pop(){
    ans += 1;

    Node* res = pq[1];
    Using[res->idx] = nullptr;
    pq[1] = pq[pqSize--];
    if(pqSize>=1){
        pq[1]->pos = 1;
        down(1);
    }
    return res;
}
void push(int idx, int time){
    if(Using[idx]){
        Node* n = Using[idx];
        n->time = time;
        up(n->pos);
    } else {
        if(pqSize>=N) pop();
        ++pqSize;
        pq[pqSize] = new Node(idx, time, pqSize);
        Using[idx] = pq[pqSize];
        up(pqSize);
    }
}
queue<int> timee[MAX_K];
int lst[MAX_K];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for(int i = 0; i<K; i++){
        int idx;
        cin >> idx;
        timee[idx].push(i);
        lst[i] = idx;
    }
    for(int i = 0; i<K+1; i++){
        timee[i].push(MAX_K+1);
    }

    for(int i = 0; i<K; i++){
        int idx = lst[i];
        timee[idx].pop();
        push(idx, timee[idx].front());
    }
    cout <<ans;
}