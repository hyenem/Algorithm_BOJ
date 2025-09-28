#include <iostream>
using namespace std;

static int N, C;
static int tmp[200000];
static int house[200000];

void merge(int left, int mid, int right){
    int i = left, j = mid+1, k = left;

    while(i<=mid && j<=right){
        if(house[i]<=house[j]) tmp[k++] = house[i++];
        else tmp[k++] = house[j++];
    }

    while(i<=mid) tmp[k++] = house[i++];
    while(j<=right) tmp[k++] = house[j++];

    for(int t = left; t<=right; t++) house[t] = tmp[t];
}

void mergesort(int left, int right){
    if(left>=right) return;
    int mid = (left+right)/2;
    mergesort(left, mid);
    mergesort(mid+1, right);
    merge(left, mid, right);
}

int check(int mid){
    int cnt = 1, acc = 0;
    for(int i = 1; i<N; i++){
        acc += house[i] - house[i-1];
        if(acc>=mid){
            if(++cnt>=C) return 1;
            acc = 0;
        }
    }
    return 0;
}

int binary(int left, int right){
    if(left>right) return right;

    int mid = (left+right)/2;
    if(check(mid)) return binary(mid+1, right);
    else return binary(left, mid-1);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C;
    for(int i = 0; i<N; i++) cin >> house[i];
    mergesort(0, N-1);

    int ans = binary(0, house[N-1]);

    cout << ans;
}