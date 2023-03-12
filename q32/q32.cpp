#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int n;
int dp[500][500];

int main()
{
    cin >> n;     
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            cin >> dp[i][j];            
        }        
    }

    for (int x = 1; x < n; x++) {
        for (int y = 0; y < x+1; y++) {     // ✔
            int up, leftUp; 
            //위쪽에서 오는 경우 
            if (y == x) // ✔
                up = 0; 
            else
                up = dp[x - 1][y]; 

            // 왼쪽위에서 오는 경우 
            if (y == 0)
                leftUp = 0;
            else
                leftUp = dp[x - 1][y - 1]; 

            dp[x][y] = dp[x][y] + max(up, leftUp); 
        }
    }
    int result = 0; 
    for (int i = 0; i < n; i++) {
        result = max(result, dp[n - 1][i]); 
    }

    cout << result << endl; 
    //
}
