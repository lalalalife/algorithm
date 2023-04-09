#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;



int main()
{	
	int n, m;
	int graph[101][101];


	// 간선정보 입력
	cin >> n >> m;

	// 무한값초기화
	for (int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, 987654321);
	}

	// 자기자신으로 가는 비용 0
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				graph[i][j] = 0; 
		}
	}

	
	for (int i = 0; i < m; i++) {
		int a, b; 
		cin >> a >> b; 

		graph[a][b] = 1; 
		graph[b][a] = 1; 
	}

	// 거쳐갈 k와 최종도착지 x
	int k, x; 
	cin >> x >> k; 

	// 플로이드워셜 알고리즘
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			for (int c = 1; c <= n; c++) {
				graph[a][b] = min(graph[a][b], graph[a][c] + graph[c][b]); 
			}
		}
	}

	// 출력
	int distance = graph[1][k] + graph[k][x];
	cout << distance << endl; 

}

