#include <iostream>
using namespace std;

#define ll  long long

ll lazy[1000000*4];
ll tree[1000000*4];

void updateLazy(int pos, int left, int right){
    if(!lazy[pos]) return;

    tree[pos] += (right - left + 1)*lazy[pos];
    if(left!=right) {
        lazy[pos*2] += lazy[pos];
        lazy[pos*2+1] += lazy[pos];
    }

    lazy[pos] = 0;
}

void update(int s, int e, ll num, int pos, int left, int right){
    updateLazy(pos, left, right);

    if(s > right || e < left) return;
    if(s<=left && right<=e) {
        lazy[pos] += num;
        updateLazy(pos, left, right);
        return;
    }
    
    int mid = (left+right)/2;
    update(s, e, num, pos*2, left, mid);
    update(s, e, num, pos*2+1, mid+1, right);

    tree[pos] = tree[pos*2] + tree[pos*2+1];
}

ll query(int s, int e, int pos, int left, int right){
    updateLazy(pos, left, right);

    if(s > right || e < left) return 0;
    if(s<=left && right<=e) {
        return tree[pos];
    }

    ll ans = 0;
    int mid = (left+right)/2;
    ans += query(s, e, pos*2, left, mid);
    ans += query(s, e, pos*2+1, mid+1, right);

    tree[pos] = tree[pos*2] + tree[pos*2 + 1];

    return ans;
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    for(int i = 1; i<=N; i++){
        ll num;
        cin >> num;
        update(i, i, num, 1, 1, N);
    }


    for(int i = 0 ; i<K+M ; i++){
        int cmd, s, e;
        ll n;
        cin >> cmd;
        if(cmd==1){
            cin >> s >> e >> n;
            update(s, e, n, 1, 1, N);
        } else {
            cin >> s >> e;
            cout << query(s, e, 1, 1, N)<<'\n';
        }
    }
}