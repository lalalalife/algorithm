#include <iostream>
using namespace std; 

int n, m, k; 
int board[101][101]; 
bool visited[101][101]; 

int dx[] = { -1, 1, 0, 0 }; 
int dy[] = { 0, 0, -1, 1 }; 

int cnt;
int maxcnt; 

void dfs(int x, int y)
{
    cnt++; 

    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y; 

        if (nx <= 0 || nx > n || ny <= 0 || ny > m)
            continue; 

        if (visited[nx][ny] || board[nx][ny] != 1)
            continue;

        visited[nx][ny] = true; 
        dfs(nx, ny); 
    }
}

int main()
{
    cin >> n >> m >> k; 
    for (int i = 0; i < k; i++) {
        int x, y; 
        cin >> x >> y; 
        board[x][y] = 1; //
    }

    cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            
            if (!visited[i][j] && board[i][j] == 1) {
                visited[i][j] = true; 
                dfs(i, j); 

                maxcnt = max(cnt, maxcnt); 
                cnt = 0;
            }
        }
    }

    cout << maxcnt << endl; 
}
