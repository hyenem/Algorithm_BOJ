#include <iostream>
using namespace std;

#define MAXN    100001
#define ll      long long

ll min(ll x, ll y){ return x>y? y: x; }
int max(int x, int y){ return x>y? x: y; }

int N, K;
int deque[MAXN];
int front = 0, back = 1;

void push_back(int idx){
    deque[back] = idx;
    back = (back+1)%MAXN;
}


ll DP[MAXN];
ll effecience[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    ll sum = 0;
    for(int i = 1; i<=N; ++i){
        cin >> effecience[i];
        sum += effecience[i];

        while(front<back && i - deque[front] > K+1){
            ++front;
        }
        DP[i] = DP[deque[front]] + effecience[i];

        while(front<back && DP[deque[back-1]] >= DP[i]) --back;
        push_back(i);
    }
    
    ll minus = sum;
    for(int i = max(1, N-K); i<=N; ++i){
        minus = min(minus, DP[i]);
    }
    cout << sum - minus;
}