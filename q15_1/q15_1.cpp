#include <iostream>
#include<vector>
#include<queue>

using namespace std; 

int n, m, k, x; 
vector<int>graph[300001];		// 간선정보
vector<int>d(300000, -1);		// 최단거리정보

int main()
{
	cin >> n >> m >> k >> x; 

	for (int i = 0; i < n; i++) {
		int a, b; 
		cin >> a >> b; 
		graph[a].push_back(b); 
	}

	d[x] = 0; 

	// 너비우선탐색(BFS)
	queue<int> q; 
	q.push(x); 

	while (!q.empty()) {
		int now = q.front(); 
		q.pop(); 

		// 현재도시에서 이동할 수 있는 도시 확인
		for (int i = 0; i < graph[now].size(); i++) {
			int nextNode = graph[now][i]; 
			if (d[nextNode] == -1) {
				// 최단거리 
				d[nextNode] = d[now] + 1; 
				q.push(nextNode); 
			}
		}
	}
	bool check = false; 
	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			cout << i << endl; 
			check = true; 
		}
	}

	if (!check)
		cout << -1 << endl; 
}

