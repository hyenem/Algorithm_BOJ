#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main(){

    stack<int> stk;

    int N;
    cin>>N;

    for(int tc = 0; tc<N; tc++){
        string cmd;
        cin >> cmd;

        if(cmd=="push"){
            int K;
            cin >> K;

            stk.push(K);
        } else if(cmd=="pop"){
            int cnt = stk.size();
            if(cnt==0){
                cout << -1 << endl;
            } else {
                cout << stk.top() << endl;
                stk.pop();
            }
        } else if(cmd=="size"){
            int cnt = stk.size();
            cout << cnt << endl;
        } else if(cmd=="empty"){
            cout << stk.empty() << endl;;
        } else if(cmd=="top"){
            if(stk.empty()==1){
                cout<< -1<<endl;
            } else {
                cout<< stk.top()<<endl;
            }
        }
    }

    return 0;
}