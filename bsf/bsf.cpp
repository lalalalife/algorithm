#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, m; 
//vector<int> v[201];
int v[201][201]; 

int dx[] = { -1, 1, 0, 0 }; 
int dy[] = { 0, 0, -1, 1 }; 

void bfs(int x, int y)
{
    queue<pair<int, int>> q; 
    q.push({ x, y }); 

    while (!q.empty()) {
        x = q.front().first; 
        y = q.front().second; 
        q.pop(); 
    
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; 
            int ny = y + dy[i]; 

            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (v[nx][ny] == 1) {
                    v[nx][ny] = v[x][y] + 1;
                    q.push({ nx, ny }); 
                }
            }            
        }
        
    }
}

int main()
{
    cin >> n >> m; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &v[i][j]); 
        }
    }

    bfs(0, 0); 
    
    cout << v[n - 1][m - 1] << endl;
}
