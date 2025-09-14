#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    vector<vector<int>> acc(26);
    for(int i = 0; i<26; i++){
        acc[i].resize(str.size());
    }

    acc[str[0]-'a'][0] = 1;
    for(int i = 1; i<str.size(); i++){
        for(int j = 0; j<26; j++){
            acc[j][i] = acc[j][i-1];
        }
        char c = str[i] - 'a';
        acc[c][i] += 1;
    }

    int N;
    cin >> N;
    for (int n = 0; n<N; n++){
        char alpha;
        int s, e;
        cin >> alpha >> s >> e;
        alpha -= 'a';
        if(s==0){
            cout << acc[alpha][e]<<'\n';
        } else {
            cout << acc[alpha][e] - acc[alpha][s-1] << '\n';
        }
    }

    return 0;
}