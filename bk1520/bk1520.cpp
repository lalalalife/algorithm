#include <iostream>
using namespace std; 

int m, n; 
int board[500][500]; 
bool visited[500][500];
int dp[500][500]; 

int dx[] = { -1, 1, 0, 0 }; 
int dy[] = { 0, 0, -1, 1 }; 

int result = 0; 

int dfs(int x, int y)
{   
    if (x == m - 1 && y == n - 1)
        return 1; 
    if (dp[x][y] != -1)
        return dp[x][y]; 

    dp[x][y] = 0; 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {

            if (board[x][y] > board[nx][ny]) {

                dp[x][y] = dp[x][y] + dfs(nx, ny);
            }
        }
    }
    
    return dp[x][y]; 
}

int main()
{
    cin >> m >> n; 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; 
            dp[i][j] = -1; 
        }
    }
        
    cout << dfs(0, 0) << endl; 
}

