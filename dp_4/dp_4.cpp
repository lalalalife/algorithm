#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; 
    cin >> n; 

    // 세로 x 가로
    // 1x2, 2x1, 2x2 
    // 2xn 

    int dp[1000]; 

    dp[1] = 1; 
    dp[2] = 3; 

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2]; 
    }

    cout << dp[n] << endl; 
}
