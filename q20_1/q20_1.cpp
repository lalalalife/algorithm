#include <iostream>
#include<vector>
#include<algorithm>
using namespace std; 

int n; 
char board[6][6]; 
vector<pair<int, int>> teachers; 
vector<pair<int, int>> spaces; 
bool found ;

// 위, 왼, 아래, 오
int dx[] = { -1, 0, 1, 0 }; 
int dy[] = { 0, -1, 0, 1 }; 

bool watch(int x, int y, int direction)
{	
	// 위
	if (direction == 0) {
		while (x >= 0) {
			if (board[x][y] == 'S')
				return true; 
			if (board[x][y] == 'O')
				return false; 
			x -= 1; 
		}
	}

	// 아래
	if (direction == 2) {
		while (x < n) {
			if (board[x][y] == 'S')
				return true;
			if (board[x][y] == 'O')
				return false;
			x += 1;
		}
	}

	// 왼
	if (direction == 1) {
		while (y >= 0) {
			if (board[x][y] == 'S')
				return true;
			if (board[x][y] == 'O')
				return false;
			y -= 1;
		}
	}

	// 오	
	if (direction == 3) {
		while (y < n) {
			if (board[x][y] == 'S')
				return true;
			if (board[x][y] == 'O')
				return false;
			y += 1;
		}
	}
	return false;
}

bool process()
{
	for (int i = 0; i < teachers.size(); i++) {
		int x = teachers[i].first; 
		int y = teachers[i].second; 
		
		for (int j = 0; j < 4; j++) {
			if (watch(x, y, j)) {
				return true; 
			}
		}
	}

	return false; 
}

int main()
{
	cin >> n; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {			
			cin >> board[i][j];

			if (board[i][j] == 'T')
				teachers.push_back({ i, j });
			else if (board[i][j] == 'X')
				spaces.push_back({ i, j }); 
		}
	}

	vector<bool> binary(spaces.size()); 	
	fill(binary.end() - 3, binary.end(), true); 

	do {
		// 장애물 설치
		for (int i = 0; i < spaces.size(); i++) {
			if (binary[i]) {
				int x = spaces[i].first; 
				int y = spaces[i].second; 
				board[x][y] = 'O'; 
			}
		}
		
		if (!process()) {
			found = true; 
			break; 
		}


		// 장애물 제거
		for (int i = 0; i < spaces.size(); i++) {
			if (binary[i]) {
				int x = spaces[i].first;
				int y = spaces[i].second;
				board[x][y] = 'X';
			}
		}

		cout << "test" << endl; 

	} while (next_permutation(binary.begin(), binary.end())); 

	if (found)
		cout << "YES" << endl;
	else
		cout << "NO" << endl; 
}
