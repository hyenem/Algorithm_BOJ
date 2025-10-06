#include <iostream>
using namespace std;

int cows[100000];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> cows[i];
    }

    int move = 0;
    for(int i = N-1; i>0; i--){
        if(cows[i-1]>cows[i]){
            move = i;
            break;
        }
    }
    cout << move << '\n';
}