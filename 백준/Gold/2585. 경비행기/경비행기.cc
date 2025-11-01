#include <iostream>
#include <utility>
#include <math.h>
using namespace std;

int N, K;
int x[1002];
int y[1002];

struct Node{
    int idx, x, y, acc, cnt;
    Node() {}
    Node(int idx, int x, int y, int acc, int cnt) : idx(idx), x(x), y(y), acc(acc), cnt(cnt) {}
} q[500000];
int front, rear;
int visited[500000][2];
int calcdist(int x1, int y1, int x2, int y2){
    double d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return (int)ceil(d/10);
}
bool check(int l){
    front = rear = 0;
    for(int i = 0; i<=N+1; i++) {
        visited[i][0] = K+1;
        visited[i][1] = l+1;
    }
    visited[0][0] = visited[0][1] = 0;
    q[rear++] = Node(0, 0, 0, 0, 0);
    while(front<rear){
        int bi = q[front].idx;
        int bx = q[front].x;
        int by = q[front].y;
        int bd = q[front].acc;
        int bc = q[front++].cnt;
        if(bx==10000 && by==10000) {
            return true;
        }
        
        if(visited[bi][0]<bc || (visited[bi][0]==bc && visited[bi][1]<bd)) continue;

        for(int i = 1; i<=N+1; i++){
            int nx = x[i], ny = y[i];
            int d = calcdist(bx, by, nx, ny);
            if(d>l) continue;

            int nacc = bd+d;
            int ncnt = bc;
            if(nacc>l){
                nacc = d;
                ncnt += 1;
            }
            if(ncnt>K) continue;
            if(visited[i][0]<ncnt) continue;
            if(visited[i][0]==ncnt && visited[i][1]<=nacc) continue;
            visited[i][0] = ncnt;
            visited[i][1] = nacc;
            q[rear++] = Node(i, nx, ny, nacc, ncnt);
        }
    }
    return false;
}
int main(){
    cin >> N >> K;
    x[0] = y[0] = 0;
    for(int i = 1; i<N+1; i++){
        cin >> x[i] >> y[i];
    }
    x[N+1] = y[N+1] = 10000;

    int left = 0, right = 20000;
    while(left < right){
        int mid = (left+right)/2;
        if(!check(mid)) left = mid+1;
        else right = mid;
    }

    cout << right;
}