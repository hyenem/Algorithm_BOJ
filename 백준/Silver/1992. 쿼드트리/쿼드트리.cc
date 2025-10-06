#include <iostream>
using namespace std;

static int arr[64][64];

void compute(int x1, int x2, int y1, int y2){

    int key = arr[x1][y1];
    int flag = 1;
    for(int i = x1; i<=x2; i++){
        for(int j = y1; j<=y2; j++){
            if(arr[i][j]!=key){
                flag = 0;
                break;
            }
        }
        if(!flag) break;
    }

    if(flag) cout << key;
    else{
        cout<<'(';
        int xm = (x1+x2)/2, ym = (y1+y2)/2;
        compute(x1, xm, y1, ym);
        compute(x1, xm, ym+1, y2);
        compute(xm+1, x2, y1, ym);
        compute(xm+1, x2, ym+1, y2);
        cout << ')';
    }

}

int main(){
    int N;
    cin >> N;

    for(int i = 0; i<N; i++){
        char num[N];
        cin >> num;
        for(int j = 0; j<N; j++){
            arr[i][j] = num[j]-'0';
        }
    }

    compute(0, N-1, 0, N-1);
}