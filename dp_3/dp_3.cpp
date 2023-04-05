#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; 
    vector<int> k; 
    int dp[100] = { 0, };        // n-1, n-2한 값의 결과가 누적 
    cin >> n; 

    for (int i = 0; i < n; i++) {
        int m; 
        cin >> m; 
        k.push_back(m); 
    }

    dp[0] = k[0]; 
    dp[1] = max(k[0], k[1]); 

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + k[i]); 
    }

    cout << dp[n - 1] << endl; 
}
