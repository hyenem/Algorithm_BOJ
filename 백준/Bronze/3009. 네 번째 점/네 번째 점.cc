#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int c, d;
    for(int i = 0; i<2; ++i){
        cin >> c >> d;
        a ^= c;
        b ^= d;
    }
    cout << a << ' '<< b;
}