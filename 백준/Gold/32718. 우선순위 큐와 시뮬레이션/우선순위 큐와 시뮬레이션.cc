#include <iostream>
using namespace std;

static int arr[200000];
static int tmp[200000];
void merge(int left, int right){
    int mid = (left+right)/2;
    int i = left, j = mid+1, k = left;
    
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }

    while(i<=mid) tmp[k++] = arr[i++];
    while(j<=right) tmp[k++] = arr[j++];

    for(int t = left; t<=right; t++){
        arr[t] = tmp[t];
    }
}
void mergeSort(int left, int right){
    if(left>=right) return;
    
    int mid = (left+right)/2;
    mergeSort(left, mid);
    mergeSort(mid+1, right);
    merge(left, right);
}

int binary(int num, int left, int right, int N){
    if(left>right) return right==-1? arr[N-1] : arr[right];

    int mid = (left+right)/2;
    if(arr[mid]>num) return binary(num, left, mid-1, N);
    else return binary(num, mid+1, right, N);

}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K, T;
    cin >> N >> K >> T;

    for(int i = 0; i<N; i++) {
        cin >> arr[i];
        arr[i] %= K;
    }
    mergeSort(0, N-1);

    int acc = 0;
    for(int t = 0; t<T; t++){
        int num;
        cin >> num;
        acc = (acc+num)%K;

        cout << (binary(K-1-acc, 0, N-1, N)+acc)%K <<' ';
    }
}