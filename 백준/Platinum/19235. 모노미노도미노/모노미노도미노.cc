#include <vector>
#include <iostream>
using namespace std;

vector<pair<int, int>> dxdy = {{0, -1}, {0, 1}};

void clear_row(vector<vector<int>> &color, int row){
    for(int i = row; i > 0; --i){
        color[i].swap(color[i-1]); // 복사 대신 swap
    }
    fill(color[0].begin(), color[0].end(), 0);
}

void gravity(vector<vector<int>> &color, int &ans){
    for(int i = 0; i<5; i++){
        for(int j = 0; j<4; j++){
            if(color[i][j]!=0 && color[i+1][j]==0){
                vector<pair<int, int>> blocks = {{i, j}};
                for(int d = 0; d<2; d++){
                    int nx = i + dxdy[d].first;
                    int ny = j + dxdy[d].second;
                    if(nx<0 || nx>5 || ny<0 || ny>3) continue;
                    if(color[nx][ny]==color[i][j]){
                        blocks.push_back({nx, ny});
                        break;
                    }
                }
                        
                int tmp = color[i][j];
                for(pair<int, int> block : blocks){
                    int bx = block.first;
                    int by = block.second;
                    if(color[bx+1][by]==0 || color[bx+1][by]==color[i][j]) continue;
                    goto notfall;
                }
                
                for(pair<int, int> block : blocks){
                    int bx = block.first;
                    int by = block.second;
                    color[bx][by] = 0;
                }
                for(pair<int, int> block : blocks){
                    int bx = block.first;
                    int by = block.second;
                    color[bx+1][by] = tmp;
                }

                notfall:;
            }

        }
    }
}

void drop(vector<vector<int>> &color, int type, int y, int &ans, int round){
    vector<int> check;
    if(type==2) check = {y, y+1};
    else check = {y};

    int end = 1;
    while(end<5){
        for(int c : check){
            if(color[end+1][c]!=0){
                goto block_stop;
            }
        }
        end ++;
    }
    block_stop:;
    

    for(int c : check){
        color[end][c] = round;
    }
    if(type==3){
        for(int c : check){
            color[end-1][c] = round;
        }
    }
    
    int isFall = 1;
    while(isFall){
        isFall = 0;

        for(int i = 2; i<6; i++){
            int cnt=0;
            for(int j = 0; j<4; j++){
                if(color[i][j]!=0) cnt++;
                else break;
            }
            if(cnt==4){
                ans++;
                clear_row(color, i);
                isFall = 1;
            }
        }

        gravity(color, ans);
    }

    for(int repeat = 0; repeat<2; repeat++){
        for(int j = 0; j<4; j++){
            if(color[1][j]!=0){
                clear_row(color, 5);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    vector<vector<int>> blue(6, vector<int>(4));
    vector<vector<int>> green(6, vector<int>(4));

    int ans = 0;
    int N;
    cin >> N;

    for(int round = 1; round <= N; round++){
        int type, x, y;
        cin >> type >> x >> y;

        drop(green, type, y, ans, round);
        if(type==1) drop(blue, type, x, ans, round);
        else drop(blue, 5-type, x, ans, round);

    }

    cout << ans << '\n';

    int count = 0;
    for(int i = 0; i<6; i++){
        for(int j = 0; j<4; j++){
            if(green[i][j]!=0){
                count ++;
            }
            if(blue[i][j]!=0){
                count ++;
            }
        }
    }

    cout << count <<'\n';
}