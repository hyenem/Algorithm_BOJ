#include <iostream>
using namespace std;

int min(int x, int y){return x>y? y: x;}

int main(){
    int D, N;
    cin >> D >> N;

    int oven[D];
    cin >> oven[0];
    for(int i = 1; i<D; i++){
        cin >> oven[i];
        oven[i] = min(oven[i-1], oven[i]);
    }

    int idx = D-1;
    for(int i = 0; i<N; i++){
        int pizza;
        cin >> pizza;
        while(idx>=0){
            if(oven[idx]>=pizza) {
                --idx;
                break;
            }
            --idx;
        }
        if(idx<0) {
            cout << 0;
            return 0;
        }
    }
    cout << idx+2;
}