#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int n, m; 
int arr[20][20]; 
int dp[20][20]; 

int dx[] = {1, 1, 1};
int dy[] = {0, -1, 1};

int main()
{
    int c;
    cin >> c; 
    for (int i = 0; i < c; i++) {
        cin >> n >> m; 
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                cin >> arr[x][y]; 
                dp[x][y] = arr[x][y]; 
            }
        }

        // 케이스별로 
        for (int y = 1; y < m; y++) {
            for (int x = 0; x < n; x++) {
                int left, leftUp, leftDown; 
                // 왼쪽위
                if (x == 0)
                    leftUp = 0;
                else
                    leftUp = dp[x][y] + dp[x - 1][y - 1]; 
                // 왼쪽
                left = dp[x][y] + dp[x][y - 1]; 
                // 왼쪽아래
                if (y == n - 1)
                    leftDown = 0;
                else
                    leftDown = dp[x][y] + dp[x + 1][y - 1]; 

                dp[x][y] = max(leftUp, max(leftDown, left)); 
            }
        }

        int result = 0; 
        for (int x = 0; x < n; x++)
        {
            result = max(result, dp[x][m - 1]);  // 마지막 열의 값중 가장 큰것 
        }

        cout << result << endl;

    }
}

