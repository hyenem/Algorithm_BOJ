#include <iostream>
using namespace std;

#define MAXN    1000001

int N, T, K;
int height[MAXN];
int DP[MAXN];
int deque[MAXN];
int front, back;

void compute(){

    front = 0, back = 1;
    deque[0] = 1;

    for(int i = 2; i<=N; ++i){
        while(front<back && i - deque[front] > K) ++front;

        int bestidx = deque[front];
        DP[i] = DP[bestidx] + (height[bestidx]<=height[i]? 1 : 0);

        while(front<back){
            int worstidx = deque[back-1];
            if(DP[worstidx]>DP[i]||(DP[worstidx]==DP[i] && height[worstidx]<=height[i])) --back;
            else break;
        }
        deque[back++] = i;
    }
    cout << DP[N] <<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 1; i<=N; ++i) cin >> height[i];
    cin >> T;
    for(int tc = 1; tc<=T; ++tc){
        cin >> K;
        compute();
    }
}