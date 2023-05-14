#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std; 

int r, c;
char board[20][20]; 
bool alphabet[26]; 

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 }; 

int maxcount; 

void dfs(int x, int y, int count)
{    
    maxcount = max(count, maxcount);     // ✔
    
    for (int i = 0; i < 4; i++) {
        
        int nx = x + dx[i]; 
        int ny = y + dy[i]; 

        if (nx >= 0 && nx < r && ny >= 0 && ny < c) {

            if (!alphabet[board[nx][ny] - 'A']) {

                alphabet[board[nx][ny] - 'A'] = true;  // 방문처리

                dfs(nx, ny, count + 1); 

                alphabet[board[nx][ny] - 'A'] = false;      // ✔
            }
        }
    }
}

int main()
{
    cin >> r >> c; 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j]; 
        }
    }
    
    alphabet[board[0][0]- 'A'] = true;
    dfs(0, 0, 1);   

    cout << maxcount << endl; 
}
