#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>
using namespace std;


void control(vector<vector<int>> &pizza){
    vector<vector<int>> change(pizza.size());
    for(int i = 0; i<pizza.size(); i++){
        change[i] = vector<int>(pizza[i].size());
    }
    for(int i = 0; i<pizza.size(); i++){
        for(int j = 0; j<pizza[i].size(); j++){
            //좌우
            if(j+1<pizza[i].size()){
                if(pizza[i][j]<pizza[i][j+1]){
                    int d = (pizza[i][j+1]-pizza[i][j])/5;
                    change[i][j] += d;
                    change[i][j+1] -= d;
                } else {
                    int d = (pizza[i][j]-pizza[i][j+1])/5;
                    change[i][j] -= d;
                    change[i][j+1] += d;
                }
            }

            //상하
            if(i+1<pizza.size()){
                if(pizza[i][j]<pizza[i+1][j]){
                    int d = (pizza[i+1][j]-pizza[i][j])/5;
                    change[i][j] += d;
                    change[i+1][j] -= d;
                } else {
                    int d = (pizza[i][j]-pizza[i+1][j])/5;
                    change[i][j] -= d;
                    change[i+1][j] += d;
                }
            }
        }
    }
    for(int i = 0; i<change.size(); i++){
        for(int j = 0; j<change[i].size(); j++){
            pizza[i][j] += change[i][j];
        }
    }
}

vector<int> line(vector<vector<int>> &pizza){
    vector<int> npizza;

    for(int j = 0; j<pizza[0].size(); j++){
        for(int i = pizza.size()-1; i>=0; i--){
            npizza.push_back(pizza[i][j]);
        }
    }
    for(int j = pizza[0].size(); j<pizza[pizza.size()-1].size(); j++){
        npizza.push_back(pizza[pizza.size()-1][j]);
    }

    return npizza;
}

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> pizza(N);
    for(int i = 0; i<N; i++) cin >> pizza[i];

    int ans = 0;
    while(true){

        // 조건 만족 여부 채크
        int mn = 10001;
        int mx = 0;
        for(int i = 0; i<N; i++){
            if(mn>pizza[i]) mn = pizza[i];
            if(mx<pizza[i]) mx = pizza[i];
        }
        if(mx-mn<=K) break;

        ans++;

        for(int i = 0; i<N; i++){
            if(pizza[i]==mn) pizza[i]++;
        }

        vector<vector<int>> next(1, {pizza[0]});
        int pidx = 1;

        //돌돌말기
        while(true){

            // 더 이상 말 수 없으면 끝내기
            if(next.size()+1>N-pidx-next[0].size()){
                vector<int> npizza;
                for(int i = pidx; i<N; i++){
                    npizza.push_back(pizza[i]);
                }
                next.push_back(npizza);
                break;
            }

            vector<vector<int>> tmp(next[0].size(), vector<int>(next.size()+1));
            for(int i = 0; i<tmp.size(); i++){
                tmp[i][0] = pizza[pidx++];
            }
            for(int i = 0; i<tmp.size(); i++){
                for(int j = 0; j<tmp[0].size()-1; j++){
                    tmp[i][j+1] = next[next.size()-1-j][i];
                }
            }

            next = tmp;

        }

        control(next);
        pizza = line(next);

        //접어 올리기
        next = vector<vector<int>>(4, vector<int>(N/4));
        for(int i = 0; i<N/4; i++){
            next[0][N/4-i-1] = pizza[i+N/2];
            next[1][i] = pizza[i+N/4];
            next[2][N/4-i-1] = pizza[i];
            next[3][i] = pizza[i+(N/4)*3];
        }

        control(next);
        pizza = line(next);
    }

    cout << ans;


}