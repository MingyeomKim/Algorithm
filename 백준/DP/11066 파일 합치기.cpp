#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[501][501];
int input[501];
int n;

int findMin(int i, int j) {
    if (i == j) return 0;
    int& ret = dp[i][j]; 
    if (ret != -1) return ret; 

    int sum = 0; 
    for (int k = i; k <= j; k++) {
        sum += input[k]; 
    }
    for (int k = i; k < j; k++) {
        int cand = findMin(i, k) + findMin(k + 1, j) + sum; 
        if (ret == -1 || ret > cand) ret = cand; 
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL); cin.tie(NULL); 
    int t; cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> input[i]; 
        cout << findMin(1, n) << endl;
    }
    return 0;
}