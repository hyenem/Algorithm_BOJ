#include <iostream>
using namespace std;

struct star{
    double x, y;
};
star stars[100];
int visited[100];
struct edge{
    int s, e;
    double d;
};
edge pq[5000];
int pidx = 1;
void swap(int i, int j){
    edge tmp = pq[i];
    pq[i] = pq[j];
    pq[j] = tmp;
}
void push(const edge& e){
    pq[pidx] = e;

    int i = pidx++;
    while(i>1){
        int p = i/2;
        if(pq[i].d>=pq[p].d) break;
        swap(i, p);
        i = p;
    }
}
edge pop(){
    edge res = pq[1];
    pq[1] = pq[--pidx];

    int idx = 1;
    while(true){
        int l = idx*2, r = l+1, next = idx;
        if(l<pidx && pq[l].d<pq[next].d) next = l;
        if(r<pidx && pq[r].d<pq[next].d) next = r;
        if(idx==next) break;

        swap(next, idx);
        idx = next;
    }
    return res;
}

double pow(double x){
    return x*x;
}
double sqrt(double x){
    if(!x) return x;
    double res = x;
    for(int i = 0; i<50; i++){
        res = 0.5 * (res + x/res);
    }
    return res;
}
double dist(int i, int j){
    double x1 = stars[i].x, y1 = stars[i].y;
    double x2 = stars[j].x, y2 = stars[j].y;
    return sqrt(pow(x1-x2)+pow(y1-y2));
}
int main(){
    int N;
    cin >> N;

    for(int i = 0; i<N; i++){
        double x, y;
        cin >> x >> y;
        stars[i] = star{x, y};
    }

    visited[0] = 1;
    for(int i = 1; i<N; i++){
        push(edge{0, i, dist(0, i)});
    }
    int cnt = 1;
    double ans = 0;
    while(cnt<N && pidx>1){
        edge cur = pop();
        if(visited[cur.e]) continue;

        visited[cur.e] = 1;
        cnt ++;
        ans += cur.d;
        for(int i = 0; i<N; i++){
            if(visited[i]||i==cur.e) continue;
            push(edge{cur.e, i, dist(i, cur.e)});
        }
    }

    cout << ans;
}