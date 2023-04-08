#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m; 
int start; 
int d[100001]; 
vector<pair<int, int>> graph[100001]; 

int main()
{
	cin >> n >> m; 
	cin >> start; 

	for (int i = 0; i < m; i++) {
		int a, b, c; 
		cin >> a >> b >> c; 

		graph[a].push_back({ b, c }); 
	}

	fill_n(d, 100001, 987654321); 
	d[start] = 0; 
	
	priority_queue<pair<int, int>> pq; 
	pq.push({ 0, start }); 

	while (!pq.empty()) {
		int dist = -pq.top().first; 
		int now = pq.top().second; 
		pq.pop(); 

		if (d[now] < dist)
			continue; 

		for (int i = 0; i < graph[now].size(); i++) {
			
			pair<int, int> tmp = graph[now][i];

			int cost = dist + tmp.second;

			if (cost < d[tmp.first]) {
				d[tmp.first] = cost;
				pq.push({ -cost, tmp.first });
			}
		}
	}
	

	for (int i = 1; i <= n; i++) {
		cout << d[i] << endl; 
	}
}

