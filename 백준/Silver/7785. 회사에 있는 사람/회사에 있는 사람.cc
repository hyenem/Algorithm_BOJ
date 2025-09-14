#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_set<string> in;

    for(int tc=0; tc<N; tc++){
        string name, cmd;
        cin >> name >> cmd;

        if(cmd=="enter"){
            in.insert(name);
        }else {
            in.erase(name);
        }
    }

    vector<string> people(in.begin(), in.end());
    sort(people.begin(), people.end(), greater<string>());

    for(string n : people){
        cout << n << '\n';
    }

    return 0;
}