#include <iostream>
using namespace std;

static long long tree[4000000];

void update(int idx, long long num, int pos, int left, int right){
    if(left==right) {
        tree[idx] = num;
        return;
    }

    int mid = (left+right)/2;
    if(pos<=mid) update(idx*2, num, pos, left, mid);
    else update(idx*2+1, num, pos, mid+1, right);

    tree[idx] = tree[2*idx]+tree[2*idx+1];
}

long long query(int idx, int start, int end, int left, int right){
    if(start<=left && end>=right) return tree[idx];
    if(end<left || start>right) return 0;

    long long res = 0;
    int mid = (left+right)/2;
    if(start<=mid) res += query(2*idx, start, end, left, mid);
    if(end>mid) res += query(2*idx+1, start, end, mid+1, right);

    return res;
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    long long num;
    for(int i = 0; i<N; i++){
        cin >> num;
        update(1, num, i, 0, N-1);
    }

    int a, b;
    long long c;
    for(int i = 0; i<M+K; i++){
        cin >> a >> b >> c;
        if(a==1) update(1, c, b-1, 0, N-1);
        else cout << query(1, b-1, c-1, 0, N-1) <<'\n';
    }
}