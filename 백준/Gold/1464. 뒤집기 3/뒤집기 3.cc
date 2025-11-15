#include <iostream>
using namespace std;

char deque[105];
int front = 50, back = 50;

int main(){
    char arr[51];
    cin >> arr;

    deque[back++] = arr[0];
    for(int i = 1; arr[i]; ++i){
        char now = arr[i];
        if(deque[front] >= now) deque[--front] = now;
        else deque[back++] = now;
    }
    while(front<back){
        cout << deque[front++];
    }
}