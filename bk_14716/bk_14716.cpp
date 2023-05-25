#include <iostream>
#include <vector>
using namespace std; 

int n, m; 
int board[250][250]; 
bool visited[250][250];

int dx[] = { -1, 1, 0, 0, -1, 1, 1, -1 }; 
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 }; 

void dfs(int x, int y)
{
    for (int i = 0; i < 8; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y; 

        if (nx < 0 || nx >= m || ny < 0 || ny >= n )
            continue; 
        
        if (visited[nx][ny] || board[nx][ny] == 0)
            continue; 

        visited[nx][ny] = true; 
        dfs(nx, ny); 
    }
}

int main()
{
    cin >> m >> n; 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; 
        }
    }

    int cnt = 0; 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            
            if (board[i][j] == 1 && !visited[i][j]) {

                visited[i][j] = true; 
                dfs(i, j); 
                cnt++; 
            }
        }
    }

    cout << cnt << '\n'; 
}
