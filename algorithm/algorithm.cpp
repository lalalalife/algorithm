#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void exam4_1()
{
	int n; 
	string plan; 
	// L, R, U, D 
	int dx[] = { 0, 0, -1, 1 };
	int dy[] = { -1, 1, 0, 0 };
	char moves[] = { 'L', 'R', 'U', 'D' }; 

	cin >> n;
	cin.ignore(); 
	getline(cin, plan); 


	int x = 1, y = 1; 
	for (int i = 0; i < plan.size(); i++) {
		
		int nx = -1; 
		int ny = -1; 

		for (int j = 0; j < 4; j++) {
			if (plan[i] == moves[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
				break; 
			}
		}		

		if (nx >= 1 && ny >= 1 && nx <= n && ny <= n) {
			x = nx; 
			y = ny; 
		}
	}

	cout << x << ' ' << y << endl; 
}

void exam4_2()
{
	int n; 
	cin >> n; 

	// 00:00:00 ~ N:59:59
	int result = 0; 

	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= 59; j++) {
			for (int k = 0; k <= 59; k++) {
				if (i / 10 == 3 || i % 10 == 3 || j / 10 == 3 || j % 10 == 3 || k / 10 == 3 || k % 10 == 3) {
					result++; 
				}
			}
		}
	}

	cout << result << endl; 
}

void exam4_3()
{	
	//a1 
	string n; 
	cin >> n; 

	int x = n[0] - 'a' + 1; 
	int y = n[1] - '0';

	int step[8][2] = { {1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1} }; 

	int result = 0; 
	for (int i = 0; i < 8; i++) {
		int nx = x + step[i][0]; 
		int ny = y + step[i][1]; 

		if (nx > 0 && ny > 0 && nx <= 8 && ny <= 8) {
			result++; 
		}
	}
	cout << result << endl; 
}

int n, m;
int x, y, d;

void turn_left()
{
	d--; 
	if (d < 0)
		d = 3; 		
}

void exam4_4()
{
	
	int arr[50][50]; 

	cin >> n >> m; 	
	cin >> x >> y >> d; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j]; 
		}
	}

	// 북서남동 이동좌표
	int dx[] = { -1, 0, 1, 0 }; 
	int dy[] = { 0, -1, 0, 1 }; 

	arr[x][y] = 2; // 처음위치한곳 1로 바꾸고 시작 

	int cnt = 0; 
	int turn_time = 0; 

	while (true) {

		turn_left(); 
		int nx = x + dx[d]; 
		int ny = y + dy[d]; 

		if (arr[nx][ny] == 0) {
			arr[nx][ny] = 2;	// 방문표시
			x = nx; 
			y = ny; 
			cnt++; 

			turn_time = 0; 
			continue; 
		}
		else {
			turn_time++; 
		}

		if (turn_time == 4) {
			// 한칸뒤로 
			nx = x - dx[d]; 
			ny = y - dy[d]; 

			if (arr[nx][ny] == 1) {
				break; 
			}
			else {
				x = nx; 
				y = ny; 
				cnt++;
			}

			turn_time = 0; 
		}
	}
		
	cout << cnt << endl; 
}

int main()
{
	//exam4_1(); 
	//exam4_2();

	//exam4_3(); 
	exam4_4(); 
}
