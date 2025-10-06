#include <iostream>
using namespace std;

static int height[100000];
int max(int x, int y){
    return x>y? x:y;
}
int min(int x, int y){
    return x>y? y: x;
}

int divide(int left, int right){
    if(left>=right) return height[left];

    int mid = (left+right)/2;
    int ans = height[mid];
    int l = mid, r = mid;
    int minheight = height[mid];
    while(l>left && r<right){
        if(height[l-1]>height[r+1]) minheight = min(minheight, height[--l]);
        else minheight = min(minheight, height[++r]);
        ans = max(ans, (r-l+1)*minheight);
    }

    while(l>left){
        minheight = min(minheight, height[--l]);
        ans = max(ans, (r-l+1)*minheight);
    }
    while(r<right){
        minheight = min(minheight, height[++r]);
        ans = max(ans, (r-l+1)*minheight);
    }

    ans = max(divide(left, mid-1), ans);
    ans = max(divide(mid+1, right), ans);
    return ans;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> height[i];
    }

    cout << divide(0, N-1);
}