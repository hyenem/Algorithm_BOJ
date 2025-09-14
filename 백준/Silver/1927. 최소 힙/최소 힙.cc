#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int, vector<int>, greater<int>> heap;
    int N, num;
    cin >> N;

    for(int tc=0; tc<N; tc++){
        cin >> num;

        if(num){
            heap.push(num);
        } else if(heap.empty()){
            cout<< 0 << '\n';
        } else {
            cout << heap.top() << '\n';
            heap.pop();
        }
    }

    return 0;
}