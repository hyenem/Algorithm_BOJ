#include <iostream>
using namespace std;

static int tmp[100000];

void merge(int *arr, int left, int mid, int right){
    int i = left, j = mid+1, k = left;

    while(i<=mid && j<= right){
        if(arr[i]<=arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }

    while(i<=mid) tmp[k++]=arr[i++];
    while(j<=right) tmp[k++]=arr[j++];

    for(int t = left; t<=right; t++) arr[t] = tmp[t];
}

void mergeSort(int *arr, int left, int right){
    if(left>=right) return;
    int mid = (left+right)/2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main() {
    int N, K;
    cin >> N >> K;

    int ans = N;
    int times[N];
    int idx = 0;

    int before;
    cin >> before;
    K--;

    for(int i = 0; i<N-1; i++){
        int next;
        cin >> next;

        if(before+1!=next){
            times[idx++] = next-before-1;
        }
        before = next;
    }

    if(idx>K){
        mergeSort(times, 0, idx-1);
    
        for(int i = 0; i<idx-K; i++){
            ans += times[i];
        }
    }

    cout << ans;
}