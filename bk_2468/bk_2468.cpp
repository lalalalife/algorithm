#include <iostream>
#include <vector>
using namespace std; 

int n; 
int board[100][100]; 
bool safezone[100][100];
bool visited[100][100];

void initSafeZoen()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			safezone[i][j] = true; 			
			visited[i][j] = false; 
		}
	}
}

void getSafeZone(int height)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] - height <= 0) {
				safezone[i][j] = false; 
			}
		}
	}
}

void dfs(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < n)
	{
		if (!visited[x][y] && safezone[x][y]) {
			visited[x][y] = true; 

			dfs(x - 1, y);
			dfs(x + 1, y);
			dfs(x, y - 1);
			dfs(x, y + 1);
		}		
	}

}

int main()
{
	int maxHeight = 0; 
	int maxCity = 0; 

	cin >> n; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j]; 
			maxHeight = max(maxHeight, board[i][j]);
		}
	}
	
	for (int h = 0; h < maxHeight; h++) {

		initSafeZoen(); 
		getSafeZone(h); 
		
		int sum = 0; 
		//
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (!visited[i][j] && safezone[i][j]) {
					dfs(i, j);
					sum++; 					
				}
			}
		}
 		maxCity = max(maxCity, sum);
	}

	cout << maxCity << endl; 

}
