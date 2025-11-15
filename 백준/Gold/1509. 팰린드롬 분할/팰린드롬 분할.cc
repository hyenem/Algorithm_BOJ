#include <iostream>
using namespace std;

int N;
bool isSymmetric[2500][2500];
char str[2501];
int dp[2500];

void checkSymmetric() {
    N = 0;
    while (str[N]) {
        isSymmetric[N][N] = true;
        if (N != 0 && str[N-1] == str[N]) isSymmetric[N-1][N] = true;
        ++N;
    }

    for (int len = 3; len <= N; ++len) {
        for (int end = len-1; end < N; ++end) {
            int start = end - len + 1;
            if (!isSymmetric[start+1][end-1]) continue;
            if (str[start] == str[end]) isSymmetric[start][end] = true;
        }
    }
}

int main() {
    cin >> str;
    checkSymmetric();

    for (int i = 0; i < N; ++i) {
        dp[i] = 2501;
        for (int j = 0; j <= i; ++j) {
            if (isSymmetric[j][i]) {
                if (j == 0) dp[i] = 1;
                else dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }
    }
    cout << dp[N-1];
}
