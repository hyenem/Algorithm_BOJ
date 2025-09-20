#include <queue>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<pair<int, int>> dxdy = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int N;
    cin >> N;

    vector<vector<int>> mapp(N, vector<int>(N));
    pair<int, int> shark;
    int sharksize = 2;
    int ate = 0;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            int num;
            cin >> num;
    
            if(num==9) shark = {i, j};
            else {
                mapp[i][j] = num;
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> candidate;
    queue<pair<int, int>> q;
    queue<pair<int, int>> next;
    int mom = 0;
    
    int ans = 0;

    while(!mom){

        mom = 1;

        vector<vector<int>> visited(N, vector<int>(N));
        q.push(shark);
        visited[shark.first][shark.second] = 1;
        int x, y;
        int nx, ny;
        
        int time = 0;
    
        while(!q.empty()){
            time ++;
            while(!q.empty()){
    
                x = q.front().first;
                y = q.front().second;
                q.pop();
                                    
                for(int d = 0; d < 4; d++){
                    nx = x + dxdy[d].first;
                    ny = y + dxdy[d].second;
                    
                    if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                    if(mapp[nx][ny]>sharksize) continue;
                    if(visited[nx][ny]) continue;
    
                    if(mapp[nx][ny]>0 && mapp[nx][ny]<sharksize){
                        candidate.push(pair<int, int> {nx, ny});
                    }
                    next.push(pair<int, int> {nx, ny});
                    visited[nx][ny] = 1;
                }
    
            }

            if(candidate.empty()){
                

                while(!next.empty()){
                    q.push(next.front());
                    next.pop();
                }
            
                continue;
            }

            shark = candidate.top();
            mapp[shark.first][shark.second] = 0;
            ate ++;
            if(ate==sharksize) {
                ate = 0;
                sharksize++;
            }
            mom = 0;
            ans += time;
            
            while(!candidate.empty()){
                candidate.pop();
            }
            while(!q.empty()){
                q.pop();
            }
            while(!next.empty()){
                next.pop();
            }
            break;
        }
    }
    cout << ans;
}