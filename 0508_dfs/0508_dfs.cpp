#include <iostream>
#include <vector>
using namespace std; 

int n, m; 
int board[1000][1000]; 

int dx[] = { -1, 1, 0, 0 }; 
int dy[] = { 0, 0, -1, 1 }; 

void dfs(int x, int y)
{    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i]; 
        int ny = y + dy[i]; 

        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (board[nx][ny] == 0) {
                board[nx][ny] = 2;      // visited 
                dfs(nx, ny); 
            }
        }        
    }
}
    
int main()
{
    cin >> n >> m; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &board[i][j]); 
            
        }
    }

    int count = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 2;                 
                dfs(i, j); 
                count++; 
            }
        }
    }

    cout << count << endl; 
}
