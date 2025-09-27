#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(){
    int N;
    cin >> N;

    int arr[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            arr[i][j] = 0;

    vector<unordered_set<int> > likes(N*N+1);
    for(int i = 0; i<N*N; i++){
        int num, l1, l2, l3, l4;
        cin >> num >> l1 >> l2 >> l3 >> l4;
        likes[num].insert({l1, l2, l3, l4});

        int gx = -1;
        int gy = -1;
        int gecnt = -1;
        int glcnt = -1;

        for(int x=0; x<N; x++){
            for (int y = 0; y<N; y++){
                if(arr[x][y]!=0) continue;
                int ecnt = 0;
                int lcnt = 0;
                for(int d=0; d<4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(0>nx || nx>=N || ny<0 || ny>=N) continue;
                    if(arr[nx][ny]==0) ecnt++;
                    if(likes[num].find(arr[nx][ny])!=likes[num].end()) lcnt ++;
                }

                if (glcnt<lcnt){
                    glcnt = lcnt;
                    gecnt = ecnt;
                    gx = x;
                    gy = y;
                } else if(glcnt==lcnt && gecnt<ecnt){
                    gecnt = ecnt;
                    gx = x;
                    gy = y;
                }
            }

        }

        arr[gx][gy]=num;
    }

    int ans = 0;
    for(int x = 0; x<N; x++){
        for(int y = 0; y<N; y++){
            int cnt = 0;
            for(int d= 0; d<4; d++){
                int nx = x+dx[d];
                int ny = y+dy[d];

                if(0>nx || nx>=N || ny<0 || ny>=N) continue;
                if(likes[arr[x][y]].find(arr[nx][ny])!=likes[arr[x][y]].end()) cnt ++;

            }

            int increase = 1;
            for(int repeat = 0; repeat<cnt; repeat++) increase*=10;
            ans += increase/10;
        }
    }

    cout << ans;
}