#include <iostream>
using namespace std;

#define MAXN 100001

typedef long long ll;
typedef __int128_t i128;

ll a[MAXN];
ll b[MAXN];
int deque[MAXN];
int front = 0, back = -1;
ll dp[MAXN];

void addline(int i){
    while(back - front >= 1){
        int first = deque[back-1], second = deque[back];
        i128 lhs = (i128)(dp[second]-dp[first])*(b[first]-b[i]);
        i128 rhs = (i128)(dp[i]-dp[first])*(b[first]-b[second]);
        if(lhs<rhs) break;
        --back;
    }
    deque[++back] = i;
}

ll calcdp(int i){
    int first = deque[front];
    ll res = b[first]*a[i] + dp[first];
    while(back - front >= 1){
        int second = deque[front+1];
        ll tmp = b[second]*a[i] + dp[second];
        if(res < tmp) break;
        
        res = tmp;
        ++front;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for(int i = 0; i<N; ++i) cin >> a[i];
    for(int i = 0; i<N; ++i) cin >> b[i];

    addline(0);
    for(int i = 1; i<N; ++i){
        dp[i] = calcdp(i);
        addline(i);
    }
    cout << dp[N-1];
}