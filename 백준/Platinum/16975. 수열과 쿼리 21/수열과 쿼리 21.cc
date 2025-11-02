#include <iostream>
using namespace std;

#define ll long long

ll tree[100000*4];
int N;

void update(int s, int e, int num, int pos, int left, int right){
    if(s>right || e<left) return;
    if(s <= left && right <= e){
        tree[pos] += num;
        return;
    }

    int mid = (left + right)/2;
    update(s, e, num, pos*2, left, mid);
    update(s, e, num, pos*2 + 1, mid + 1, right);
}
ll query(int pos){
    ll ans = 0;
    int idx = 1, left = 1, right = N;
    while(left<right){
        
        ans += tree[idx];
        int mid = (left+right)/2;
        idx *= 2;
        if(pos<=mid) right = mid;
        else left = mid+1, idx += 1;
    }
    ans += tree[idx];
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for(int i = 1; i<=N; i++){
        int num;
        cin >> num;
        update(i, i, num, 1, 1, N);
    }

    int M;
    cin >> M;
    for(int i = 0; i<M; i++){
        int cmd, a, b, c;
        cin >> cmd;
        if(cmd==1){
            cin >> a >> b >> c;
            update(a, b, c, 1, 1, N);
        } else {
            cin >> a;
            cout << query(a) << '\n';
        }
    }
}