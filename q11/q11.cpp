#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

int n, k, l; 

int arr[101][101];  // 맵 정보
vector<pair<int, int>> info;	// 회전정보 

// 동 남 서 북
int dx[] = { 0, 1, 0, -1 }; 
int dy[] = { 1, 0, -1, 0 }; 


int turn(int direction, char c)
{
	if (c == 'L') {
		direction = direction == 0 ? 3 : direction - 1; 
	}
	else {
		//direction = direction == 3 ? 0 : direction + 1; 
		direction = (direction + 1) % 4; 
	}

	return direction; 
}


int main()
{
	cin >> n >> k; 
	for (int i = 0; i < k; i++) {
		int x, y; 
		cin >> x >> y; 
		arr[x][y] = 1; // 사과있는곳 1로 표시		
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		int t;
		char c; 
		cin >> t >> c;
		info.push_back({ t, c }); 		
	}

	// 풀이
	int x = 1, y = 1;		// 뱀 머리위치
	arr[x][y] = 2;			// 뱀이 있는위치는 2로 표시 

	int direction = 0;		// 처음에는 동쪽
	int time = 0; 
	int index = 0;			// 다음 회전정보 
	
	queue<pair<int, int>> q;	// 뱀이 차지하고 있는 위치정보
	q.push({ x, y }); 
	

	while (true) {
		int nx = x + dx[direction];
		int ny = y + dy[direction];

		// 이동한 위치가 맵안이고, 뱀의 몸통이 없는곳이라면 
		if (1 <= nx && nx <= n && 1 <= ny && ny <= n && arr[nx][ny] != 2) {

			// 사과가 없으면 이동 후, 꼬리제거 
			if (arr[nx][ny] == 0) {
				arr[nx][ny] = 2; // 뱀 이동 

				q.push({ nx, ny });		// 뱀이 이동된 좌표넣고, 
				int px = q.front().first; 
				int py = q.front().second; 
				q.pop();
				arr[px][py] = 0;				// 꼬리가 있던 좌표는 제거 
			}

			// 사과있으면 꼬리 그대로 
			if (arr[nx][ny] == 1) {
				arr[nx][ny] = 2; 
				q.push({ nx, ny });		// 뱀이 이동된 좌표넣고, (꼬리좌표는 그대로)
			}
		}
		else
		{
			// 맵밖이거나 몸통과 부딪히면, 종료
			time += 1; 
			break; 
		}

		// 다음위치로 머리 이동 
		x = nx;
		y = ny;
		time += 1;

		if (index < l && time == info[index].first) {
			direction = turn(direction, info[index].second); 
			index += 1; 			
		}		
	}

	cout << time << endl; 
}
