#include <iostream>
using namespace std;

int lazy[100000*4];
int tree[100000*4];

void lazyDown(int pos, int left, int right){
    if(!lazy[pos]) return;
    tree[pos] = right - left + 1 - tree[pos];
    if(left!=right){
        lazy[pos*2] = 1 - lazy[pos*2];
        lazy[pos*2 + 1] = 1 - lazy[pos*2 + 1];
    }
    lazy[pos] = 0;
}
void update(int s, int e, int pos, int left, int right){
    lazyDown(pos, left, right);
    if(s>right || left>e) return;
    if(s<=left && right <= e){
        lazy[pos] = 1 - lazy[pos];
        lazyDown(pos, left, right);
        return;
    }

    int mid = (left+right)/2;
    update(s, e, pos*2, left, mid);
    update(s, e, pos*2+1, mid+1, right);

    tree[pos] = tree[pos*2] + tree[pos*2+1];
}
int query(int s, int e, int pos, int left, int right){
    lazyDown(pos, left, right);
    if(s>right || left>e) return 0;
    if(s<=left && right <= e){
        return tree[pos];
    }

    int mid = (left+right)/2;
    int ans = query(s, e, pos*2, left, mid) + query(s, e, pos*2+1, mid+1, right);
    
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i<M; i++){
        int o, s, t;
        cin >> o >> s >> t;
        if(o) cout << query(s, t, 1, 1, N)<< '\n';
        else update(s, t, 1, 1, N);
    }
}