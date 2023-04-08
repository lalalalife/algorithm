#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std; 

int main()
{
	// 프로로이드 워셜 알고리즘 
	int n, m; 
	cin >> n >> m; 	

	int d[100][100]; 

	// 비용 최대값으로 초기화 
	for (int i = 0; i < 100; i++) {
		//fill(d[i], d[i] + 100, 987654321); 
		fill_n(d[i], 100, 987654321); 
	}

	// 자기자신에게 가는 비용 0
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				d[i][j] = 0;
		}
	}

	// 간선정보 입력 
	for (int i = 0; i < m; i++) {
		int a, b, c; 
		cin >> a >> b >> c; 
		d[a][b] = c; 
	}

	// 점화식 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
			}
		}
	}

	// 결과
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << d[i][j] << ' '; 
		}
		cout << endl; 
	}
}
