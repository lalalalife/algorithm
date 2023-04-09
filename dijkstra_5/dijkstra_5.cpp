#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, c; 
vector<pair<int, int>> graph[30001]; 
int d[30001]; 

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;

	d[start] = 0; 
	pq.push({ 0, start }); 

	while (!pq.empty()) {
		int dist = -pq.top().first; 
		int now = pq.top().second; 
		pq.pop(); 

		if (d[now] < dist)
			continue; 

		for (int i = 0; i < graph[now].size(); i++) {
			
			// 현재노드를 거쳐 다른 노드로 가는 비용
			pair<int, int> otherNode; 
			otherNode = graph[now][i]; 

			int cost = dist + otherNode.second; 

			if( cost < d[otherNode.first])
			{
				d[otherNode.first] = cost; 

				pq.push({ -cost, otherNode.first });
			}
			
		}
	}
}

int main()
{
	cin >> n >> m >> c; 

	//d 정보 최대값으로 초기화 
	fill(d, d + 30001, 987654321); 

	// 간선정보 입력 
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c; 
		graph[a].push_back({ b, c }); 
	}

	// 다익스트라 알고리즘 
	dijkstra(c); 

	// 출력
	int count = 0; 
	int maxDistance = 0; 
	for (int i = 1; i <= n; i++) {
		if (d[i] != 987654321) {
			count++; 
			maxDistance = max(maxDistance, d[i]); 
		}
	}

	cout << count - 1 << ' ' << maxDistance << endl;
}
