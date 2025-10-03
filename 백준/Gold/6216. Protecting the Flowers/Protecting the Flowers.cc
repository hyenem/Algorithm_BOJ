#include <iostream>
using namespace std;


struct cow{
    int T;
    int D;
};

static cow tmp[100000];

void merge(cow *arr, int left, int mid, int right){
    int i = left, j = mid+1, k = left;

    while(i<=mid && j<= right){
        if(arr[i].T*arr[j].D<=arr[j].T*arr[i].D) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }

    while(i<=mid) tmp[k++]=arr[i++];
    while(j<=right) tmp[k++]=arr[j++];

    for(int t = left; t<=right; t++) arr[t] = tmp[t];
}

void mergeSort(cow *arr, int left, int right){
    if(left>=right) return;
    int mid = (left+right)/2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main(){
    int N;
    cin >> N;

    cow cows[N];
    int amount = 0;

    for(int i = 0; i<N; i++){
        cin >> cows[i].T >> cows[i].D;
        amount += cows[i].D;
    }


    long long ans = 0;
    mergeSort(cows, 0, N-1);

    for(int i = 0; i<N; i++){
        amount -= cows[i].D;
        ans += amount*1ll*cows[i].T*2;
    }
    cout << ans;
    
}