#include <utility>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int x, y;
    vector<pair<int, int>> v;

    for(int tc=0; tc<N; tc++){
        cin >> x >> y;
        pair<int, int> xy = {x, y};
        v.push_back(xy);
    }

    sort(v.begin(), v.end());
    for(pair<int, int> p:v){
        cout<<p.first<<' '<<p.second<<'\n';
    }
    return 0;
}