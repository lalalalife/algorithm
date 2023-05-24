#include <iostream>
using namespace std; 

int board[500][500]; 
bool visited[500][500];
int n, m; 
int width, maxWidth;

int dx[] = { -1, 1, 0, 0 }; 
int dy[] = { 0, 0, -1, 1 }; 

void dfs(int x, int y)
{
	visited[x][y] = true;
	width++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 

		if (visited[nx][ny])
			continue; 

		if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 1) {
			dfs(nx, ny); 
		}
	}	
}

int main()
{		
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j]; 
		}
	}

	int cnt = 0;	// 그림갯수

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			if (!visited[i][j] && board[i][j] == 1) {				
				cnt++;
				width = 0; 
				dfs(i, j); 
				maxWidth = max(width, maxWidth);				
			}
		}
	}
	
	cout << cnt << '\n' << maxWidth << endl;
}

