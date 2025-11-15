#include <iostream>
using namespace std;

#define MAXN    5000001

struct Node{
    int idx, num;
} deque[MAXN];

int front = 0, back = 0;
int N, L;

void decrease(int& num){ num = (num+MAXN-1)%MAXN; }
void increase(int& num){ num = (num+1)%MAXN; }
int before(int num){ return (num+MAXN-1)%MAXN; }

void push_front(int idx, int num){
    decrease(front);
    deque[front].idx = idx;
    deque[front].num = num;
}
void push_back(int idx, int num){
    deque[back].idx = idx;
    deque[back].num = num;
    increase(back);
}

Node peek_front(int now){
    while(front!=back){
        if(now - deque[front].idx >= L){
            increase(front);
            continue;
        }
        return deque[front];
    }
    return Node{-1, -1};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L;

    for(int i = 0; i<N; ++i){
        int num;
        cin >> num;
        Node n = peek_front(i);

        if(front==back || n.idx==-1){
            push_back(i, num);
            cout << num << ' ';
            continue;
        }

        if(n.num>num){
            push_front(i, num);
            cout << num << ' ';
            continue;
        }

        while(front!=back && deque[before(back)].num > num) decrease(back);
        push_back(i, num);
        cout << n.num << ' ';
    }
}