#include <iostream>
using namespace std;


struct edge{
    int s, e, w;
};
static edge edges[1000000];
static edge tmp[1000000];

void swap(edge& e1, edge& e2){
    edge tmp = e1;
    e1 = e2;
    e2 = tmp;
}
void merge(int left, int right){
    int mid = (left+right)/2;
    int i = left, j = mid+1, k = left;
    while(i<=mid && j<=right){
        if(edges[i].w<=edges[j].w) tmp[k++] = edges[i++];
        else tmp[k++] = edges[j++];
    }
    while(i<=mid) tmp[k++] = edges[i++];
    while(j<=right) tmp[k++] = edges[j++];

    for(int i = left; i<=right; i++){
        edges[i] = tmp[i];
    }
}

static int parent[1000000];
static int sizee[1000000];
int find(int u){
    if(parent[u]==u) return u;

    parent[u] = find(parent[u]);
    return parent[u];
}
void unionn(int u, int v){
    int pu = find(u);
    int pv = find(v);
    if(sizee[pu]<sizee[pv]) {
        parent[pu] = pv;
        sizee[pv] += sizee[pu];
    } else {
        parent[pv] = pu;
        sizee[pu] += sizee[pv];
    }
}
void mergeSort(int left, int right){
    if(left>=right) return;

    int mid = (left+right)/2;
    mergeSort(left, mid);
    mergeSort(mid+1, right);
    merge(left, right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i<M; i++){
        int A, B, C;
        cin >> A >> B >> C;

        edges[i] = edge{A, B, C};
    }

    for(int i = 1; i<=N; i++){
        parent[i] = i;
        sizee[i] = 1;
    }
    mergeSort(0, M-1);

    int ans = 0;
    int cnt = 0;
    for(int i = 0; i<M; i++){
        if(cnt==N-2) break;

        edge& ed = edges[i];
        int u = ed.s, v = ed.e, w = ed.w;
        if(find(u)==find(v)) continue;

        cnt++;
        ans+=w;
        unionn(u, v);
    }

    cout << ans;
}