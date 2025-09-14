#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> lst;
    int num;

    for(int tc=0; tc<N; tc++){
        cin>>num;
        lst.push_back(num);
    }

    sort(lst.begin(), lst.end());
    for(int k : lst){
        cout<<k<<'\n';
    }
}