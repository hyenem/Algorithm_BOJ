#include <iostream>
using namespace std;

#define MOD     1000000007

int min(int x, int y){ return x>y? y: x;}
int endPoint[200001];

int main(){
    int N;
    cin >> N;
    

    for(int i = 0; i<N; i++) {
        int end;
        cin >> end;
        endPoint[min(N, end+i+1)] += 1;
    }

    int ans = 1;
    int acc = 0;
    for(int i = 0; i<N; i++){
        acc -= endPoint[i];
        ans = (1LL*ans*(acc+1))%MOD;
        acc += 1;
    }

    cout << ans;
}