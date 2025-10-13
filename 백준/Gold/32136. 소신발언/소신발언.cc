#include <iostream>
using namespace std;

long long min(long long x, long long y){
    return x<y? x: y;
}
long long max(long long x, long long y){
    return x<y? y: x;
}

int check(long long t, int N, int* arr){
    int left = 0, right = N-1;
    for(int i = 0 ;i<N; i++){
        long long d = t/(1LL*arr[i]);
        left = max(left, i*1LL-d);
        right = min(right, i*1LL+d);
        if(left>right) return 0;
    }
    return 1;
}

int main(){
    int N;
    cin >> N;

    int arr[N];
    for(int i = 0; i<N; i++) cin>>arr[i];

    long long left = 0, right = 500000LL*150000;
    while(left < right){
        long long mid = (left+right)/2;
        if(check(mid, N, arr)) right = mid;
        else left = mid+1;
    }
    cout << left;
}