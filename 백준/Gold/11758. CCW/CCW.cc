#include <iostream>
using namespace std;

int main(){
    int x0, y0, x1, y1, x2, y2;
    cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    x1 -= x0;
    x2 -= x0;
    y1 -= y0;
    y2 -= y0;

    int lhs = x1*y2;
    int rhs = x2*y1;
    if(lhs<rhs) cout << -1;
    else if(lhs>rhs) cout << 1;
    else cout << 0;
}