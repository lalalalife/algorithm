#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

bool Pillar[102][102]; 
bool Bar[102][102]; 

bool checkPillar(int x, int y) {
	// -- 기둥을 설치할 수 있는 좌표인지 확인
	// 바닥위에 있거나, 
	// 보의 한쪽 끝부분위에 있거나, 
	// 다른 기둥위에 있거나, 
	if (y == 0)
		return true; 

	if(Bar[x][y] || (x > 0 && Bar[x-1][y]))
		return true; 

	if (Pillar[x][y - 1])
		return true; 

	return false; 
}

bool checkBar(int x, int y) {
	// -- 보를 설치할 수 있는 좌표인지 확인
	// 한쪽끝이 기둥위에 있거나
	// 양쪽끝이 다른보와 동시에 연결되거나 
	
	if (y > 0 && (Pillar[x][y - 1] || Pillar[x + 1][y - 1]))
		return true; 

	if ( (x > 0 && Bar[x - 1][y]) && Bar[x + 1][y])
		return true; 

	return false; 
}

bool canDelete(int x, int y)
{
	// 주변 영향받는 영역에 대해 확인
	for (int i = max(0, x - 1); i <= x + 1; ++i) {
		for (int j = y; j <= y; ++j) {

			if (Pillar[i][j] && checkPillar(i, j) == false)
				return false; 

			if (Bar[i][j] && checkBar(i, j) == false)
				return false;
		}
	}

	return true; 
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	memset(Pillar, 0, sizeof(Pillar)); 
	memset(Bar, 0, sizeof(Bar)); 

	for (auto build : build_frame) {
		int x = build[0];
		int y = build[1]; 
		int type = build[2];	// 기둥, 보 
		int cmd = build[3];		// 설치, 삭제

		if (type == 0) {
			// 기둥
			if (cmd == 1) {				
				if (checkPillar(x, y)) {
					Pillar[x][y] = true;
				}				
			}
			else {
				Pillar[x][y] = false;	// 삭제 해보고 
				if (canDelete(x, y) == false) {
					Pillar[x][y] = true; 
				}
			}
		}
		else {

			if (cmd == 1) {
				if( checkBar(x, y)) {
					Bar[x][y] = true;
				}
			}
			else {
				Bar[x][y] = false; 
				if (canDelete(x, y) == false) {
					Bar[x][y] = true;
				}
			}
		}
	}

	for (int x = 0; x <= n; x++) {
		for (int y = 0; y <= n; y++) {
			if (Pillar[x][y])
				answer.push_back({ x, y, 0 }); 
			if (Bar[x][y])
				answer.push_back({ x, y, 1 }); 
		}
	}

	return answer; 
}
int main()
{
	int n = 5; 

	vector<vector<int>> build_frame = {
		{1, 0, 0, 1},
		{1, 1, 1, 1},
		{2, 1, 0, 1},
		{2, 2, 1, 1},
		{5, 0, 0, 1},
		{5, 1, 0, 1},
		{4, 2, 1, 1},
		{3, 2, 1, 1}
	}; 

	vector<vector<int>> answer;
	answer = solution(n, build_frame); 

	for (auto a : answer) {
		cout << a[0] << a[1] << a[2] << endl; 
	}
}

