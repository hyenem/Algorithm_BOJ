#include <iostream>
using namespace std;

#define MAXN 100001

int x[MAXN];
int y[MAXN];

int tmp[MAXN];
int sorted[MAXN];

int stack[MAXN];
int stacksize = 0;
void push(int i){ stack[stacksize++] = i; }

void swapWith0(int i){
    swap(x[0], x[i]);
    swap(y[0], y[i]);
}
long long dist(int i){
    return 1ll*(x[i]-x[0])*(x[i]-x[0]) + 1ll*(y[i]-y[0])*(y[i]-y[0]);
}

bool compareByXY(int i, int j){
    return (x[i] - x[j])*1ll*80001 + y[i] - y[j] < 0;
}
bool compareByCCW(int i, int j){
    int x1 = x[i]-x[0], y1 = y[i] - y[0];
    int x2 = x[j]-x[0], y2 = y[j] - y[0];
    long long cp = 1ll*x1*y2 - 1ll*x2*y1;
    return (cp == 0) ? (dist(i) < dist(j)) : (cp > 0);
}
long long checkCCW(int i, int j, int k){
    int u1 = x[j] - x[i], v1 = y[j] - y[i];
    int u2 = x[k] - x[j], v2 = y[k] - y[j];
    return 1ll*u1*v2 - 1ll*u2*v1; 
}

void merge(bool (*compare)(int, int), int left, int right){
    int mid = (left+right)/2;
    int i = left, j = mid+1, k = left; 
    
    while(i<=mid && j<=right){
        if(compare(tmp[i], tmp[j])) sorted[k++] = tmp[i++];
        else sorted[k++] = tmp[j++];
    }
    while(i<=mid) sorted[k++] = tmp[i++];
    while(j<=right) sorted[k++] = tmp[j++];

    for(int i = left; i<=right; ++i) tmp[i] = sorted[i];
}

void mergeSort(bool (*compare)(int, int), int left, int right){
    if(left>=right) return;

    int mid = (left+right)/2;
    mergeSort(compare, left, mid);
    mergeSort(compare, mid+1, right);
    merge(compare, left, right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for(int i = 0; i<N; ++i){
        tmp[i] = i;
        cin >> x[i] >> y[i];
    }
    mergeSort(compareByXY, 0, N-1);
    swapWith0(sorted[0]);

    for(int i = 0; i<N; ++i) tmp[i] = i;
    push(0);

    mergeSort(compareByCCW, 1, N-1);
    push(sorted[1]);

    for(int i = 2; i<N; ++i){
        while(stacksize>=2 && checkCCW(stack[stacksize-2], stack[stacksize-1], sorted[i])<=0){
            --stacksize;
        }
        push(sorted[i]);
    }
    cout << stacksize;
}