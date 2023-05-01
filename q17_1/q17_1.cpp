#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std; 

class Virus
{
public:
	int index; 
	int second; 
	int x;
	int y; 
	
	Virus(int index, int second, int x, int y) {
		this->index = index; 
		this->second = second; 
		this->x = x; 
		this->y = y; 
	}
	bool operator <(Virus& other) {
		return this->index < other.index; 
	}
};

int n, k, s, resultX, resultY; 
int arr[200][200]; 
vector<Virus> viruses; 

int dx[] = { -1, 0, 1, 0 }; 
int dy[] = { 0, 1, 0, -1 }; 

int main()
{
	cin >> n >> k; 
	int type; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j]; 	
			if (arr[i][j] != 0) {
				viruses.push_back(Virus(arr[i][j], 0, i, j)); 
			}
		}
	}
	cin >> s >> resultX >> resultY; 

	sort(viruses.begin(), viruses.end()); 
	queue<Virus> q; 
	for (int i = 0; i < viruses.size(); i++) {
		q.push(viruses[i]); 
	}

	// 너비우선탐색..
	while (!q.empty()) {
		Virus virus = q.front(); 
		q.pop(); 

		if (virus.second == s)
			break; 

		for (int i = 0; i < 4; i++) {
			int nx = virus.x + dx[i]; 
			int ny = virus.y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (arr[nx][ny] == 0) {
					arr[nx][ny] = virus.index; 
					q.push(Virus(virus.index, virus.second + 1, nx, ny)); 
				}
			}
		}
	}


	cout << arr[resultX-1][resultY-1] << endl; 
}
