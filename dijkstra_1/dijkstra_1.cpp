#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, start;
vector < pair<int, int>> v[100001];
int dp[100001];			// cost 
bool visited[100001];

int getSmallNode()
{
	// 방문하지 않은 노드중, 가장 작은 비용을 갖고 있는 노드구하기 
	int node = 987654321; 
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false)
		{
			if (dp[i] < node)
				node = i; 
		}
	}

	return node; 
}

int main()
{	
	cin >> n >> m; 
	cin >> start; 

	for (int i = 0; i < m; i++) {
		int x, y, z; 
		cin >> x >> y >> z; 
		v[x].push_back({ y, z });
	}

	//초기화
	fill_n(dp, 100001, 987654321); 	
	dp[start] = 0; 
	visited[start] = true; 

	// start 에서 갈 수 있는 노드의 비용
	for (int i = 0; i < v[start].size(); i++) {
		dp[v[start][i].first] = v[start][i].second; 
	}

	// 시작노드제외한 노드갯수만큼
	for (int i = 0; i < n - 1; i++) {

		// 최소비용을 갖고 있는 노드구하기, 
		int now = getSmallNode();
		visited[now] = true;

		for (int j = 0; j < v[now].size(); j++)
		{
			int node = v[now][j].first; 
			int cost = dp[now] + v[now][j].second;

			if (cost < dp[node])
				dp[node] = cost; 
		}
	}
	
	
	// 출력 
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << endl; 
	}
}
