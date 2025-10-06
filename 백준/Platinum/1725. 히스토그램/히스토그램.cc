#include <iostream>
using namespace std;

int max(int x, int y) {
    return x > y? x : y;
}

struct Pair{
    int idx;
    int height;
};
int main(){
    int N;
    cin >> N;

    int ans = 0;
    Pair stack[100000];
    stack[0] = Pair{-1, 0};
    int size = 1;

    for(int i = 0; i<N; i++){
        int num;
        cin >> num;

        while(size>1 && num<stack[size-1].height){
            ans = max(ans, (i-stack[size-2].idx-1)*stack[size-1].height);
            size --;
        }
        stack[size++] = Pair{i, num};
    }


    while(size>1){
        ans = max(ans, (N-stack[size-2].idx-1)*stack[size-1].height);
        size --;
    }

    cout << ans;
}