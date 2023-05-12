#include <iostream>
#include <vector>
#include <cstring>
using namespace std; 

int n; 
char board[100][100]; 
char board_rg[100][100];
bool visited[100][100]; 

void dfs(int x, int y, const char c, char board[100][100])
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return; 
    
    if (board[x][y] == c && visited[x][y] == false) {
        visited[x][y] = true; 

        dfs(x, y - 1, c, board);
        dfs(x, y + 1, c, board);
        dfs(x - 1, y, c, board);
        dfs(x + 1, y, c, board);
    }    
}

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j]; 

            if (board[i][j] == 'R')
                board_rg[i][j] = 'G'; 
            else
                board_rg[i][j] = board[i][j]; 
        }
    }

    // 1. 
    int cnt = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == false) {
                dfs(i, j, board[i][j], board);
                cnt++; 
            }
        }
    }
    cout << cnt << '\n';

    // 2.  R, G 같이 
    cnt = 0;
    memset(visited, false, sizeof(visited)); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == false) {
                dfs(i, j, board_rg[i][j], board_rg);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';

    
}