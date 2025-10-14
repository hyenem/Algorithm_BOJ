#include <iostream>
using namespace std;

static int arr[200002];
static int tree[800008];
static int MAXN = 100000;

void update(int idx, int num, int left, int right){
    if(left==right) {
        tree[idx] += 1;
        return;
    }

    int mid = left + (right - left) / 2;
    if(num<=mid) update(idx*2, num, left, mid);
    else update(idx*2+1, num, mid+1, right);
    tree[idx] = tree[idx*2] + tree[idx*2+1];
}

int query(int idx, int num, int left, int right){
    if(num<left) return 0;
    if(right<=num) return tree[idx];

    int mid = left + (right - left) / 2;
    int res = query(idx*2, num, left, mid);
    if(mid<num) res += query(idx*2+1, num, mid+1, right);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;

    long long ans = 0;

    for(int i = 0; i<N; i++){
        cin >> arr[i];
        if(arr[i]>=X) arr[i] = 1;
        else arr[i] = -1; 

        if(i) arr[i] += arr[i-1];
        if(arr[i]>=0) ans++;

        ans += query(1, arr[i], -MAXN, MAXN);
        update(1, arr[i], -MAXN, MAXN);
    }

    cout << ans;
}