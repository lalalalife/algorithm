#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m; 
    cin >> n >> m; 

    int dp[10001] = { 0, };
    int unit[101] = { 0, };

    fill_n(dp, 10001, 10001); 
    dp[0] = 0; 

    for (int i = 0; i < n; i++) {
        cin >> unit[i]; 
    }

    // 점화식 
    // a[i] = min(a[i], a[i-k]+1)

    /*for (int i = 0; i < n; i++) {
        int k = unit[i]; 

        for (int j = 1; j <= m; j++) {

            if (j - k >= 0) {

                dp[j] = min(dp[j], dp[j - k] + 1); 
            }
        }
    }*/

    for (int i = 0; i < n; i++) {        

        int k = unit[i]; 

        for (int j = k; j <= m; j++) {

            if( dp[j-k] != 10001 )
            {
                dp[j] = min(dp[j], dp[j - k] + 1);
            }
        }
    }



    if(dp[m] >= 10001)
        cout << "-1" << endl;
    else
        cout << dp[m] << endl; 
}
