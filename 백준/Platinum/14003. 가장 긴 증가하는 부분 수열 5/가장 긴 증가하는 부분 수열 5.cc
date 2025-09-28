#include <iostream>
#include <cstdlib>
using namespace std;

int idx = 0;
void binary(int i, int *arr, int *inum, int *iidx, int *parent, int left, int right){
    int x = arr[i];

    if(left==right){
        inum[right]=x;
        iidx[right]=i;
        if(right!=0) parent[i] = iidx[right-1];
    } else {
        int mid = (left+right)/2;
        if(x>inum[mid]) binary(i, arr, inum, iidx, parent, mid+1, right);
        else binary(i, arr, inum, iidx, parent, left, mid);
    }
}

int main(){
    int N;
    cin >> N;

    int *arr = (int*)malloc(sizeof(int)*N);
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }

    int *inum = (int*)malloc(sizeof(int)*N);
    int *iidx = (int*)malloc(sizeof(int)*N);
    int *parent = (int*)malloc(sizeof(int)*N);

    inum[0]=arr[0];
    for(int i = 0; i<N; i++){
        parent[i] = -1;
        iidx[i] = -1;
    }
    iidx[0]=0;

    for(int i = 1; i<N; i++){
        if(arr[i]>inum[idx]){
            parent[i] = iidx[idx];
            inum[++idx] = arr[i];
            iidx[idx] = i;
        } else {
            binary(i, arr, inum, iidx, parent, 0, idx);
        }
    }

    cout << idx+1 << '\n';
    int *ans = (int*)malloc(sizeof(int)*(idx+1));
    ans[idx] = inum[idx];
    int aidx = idx-1;
    int p = parent[iidx[idx]];
    while(p!=-1){
        ans[aidx--] = arr[p];
        p = parent[p];
    }

    for(int i = 0; i<=idx; i++){
        cout << ans[i] << ' ';
    }

    return 0;
}