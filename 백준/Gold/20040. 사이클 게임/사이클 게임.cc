#include <iostream>
using namespace std;

static int rankk[500000];
static int root[500000];

int find(int x){
    if(root[x]==x) return x;
    else{
        root[x] = find(root[x]);
        return root[x];
    }
}

void unionn(int x, int y){
    x = find(x);
    y = find(y);

    if(x==y) return;

    if(rankk[x]<rankk[y]) root[x] = y;
    else{
        root[y] = x;
        if(rankk[x]==rankk[y]) rankk[x]++;
    }
}


int main(){

    int N, M;
    cin >> N >> M;

    for(int i = 0; i<N; i++) {
        root[i] = i;
        rankk[i] = 0;
    }

    for(int i = 0; i<M; i++){
        int x, y;
        cin >> x >> y;

        if(find(x)==find(y)){
            cout << i+1;
            return 0;
        }
        unionn(x, y);
    }

    cout <<0;
    return 0;
}