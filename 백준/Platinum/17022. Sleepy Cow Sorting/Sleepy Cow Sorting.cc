#include <iostream>
using namespace std;

int cows[100000];
int tree[400004];
void update(int idx, int num, int left, int right){
    if(left==right){
        tree[idx] = 1-tree[idx];
        return;
    }

    int mid = (left+right)/2;
    if(num<=mid) update(idx*2, num, left, mid);
    else update(idx*2+1, num, mid+1, right);

    tree[idx] = tree[idx*2] + tree[idx*2+1];
}
int find(int idx, int num, int left, int right){
    if(left==right || right<num) return tree[idx];
    
    int mid = (left+right)/2;
    int res = find(idx*2, num, left, mid);
    if(num > mid) res += find(idx*2+1, num, mid+1, right);

    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> cows[i];
        cows[i]--;
    }

    int move = 0;
    for(int i = N-1; i>0; i--){
        if(cows[i-1]>cows[i]){
            move = i;
            break;
        }
    }
    cout << move << '\n';

    int complete = N - move;
    for(int i = move; i<N; i++){
        update(1, cows[i], 0, N-1);
    }

    for(int i = 0; i<move; i++){
        cout << find(1, cows[i], 0, N-1)+(N-complete-1) << ' ';
        update(1, cows[i], 0, N-1);
        complete++;

    }

}