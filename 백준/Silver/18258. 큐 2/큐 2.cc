#include <queue>
#include <string>
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    queue<int> q;
    for(int tc = 0; tc < N; tc++){
        string cmd; 
        cin >> cmd;

        if(cmd == "push"){
            int num; cin >> num;
            q.push(num);
        } else if(cmd == "pop"){
            if(q.empty()) cout << -1 << '\n';
            else { cout << q.front() << '\n'; q.pop(); }
        } else if(cmd == "size"){
            cout << q.size() << '\n';
        } else if(cmd == "empty"){
            cout << (q.empty() ? 1 : 0) << '\n';
        } else if(cmd == "front"){
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        } else if(cmd == "back"){
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
    return 0;
}
