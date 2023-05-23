#include <iostream>
#include <vector>
using namespace std; 

int n, m; 
vector<int> v[1001]; 
bool visited[1001]; 

void dfs(int index)
{
	for (int i = 0; i < v[index].size(); i++) {
		int nextIndex = v[index][i]; 
		if (!visited[nextIndex]) {
			visited[nextIndex] = true; 
			dfs(nextIndex); 
		}
	}
}

int main()
{
	cin >> n >> m; 
	for (int i = 1; i <= m; i++) {
		int a, b; 
		cin >> a >> b; 
		v[a].push_back(b); 
		v[b].push_back(a); 
	}

	int cnt = 0; 
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i]) {
			dfs(i); 
			cnt++; 
		}
	}

	cout << cnt << endl; 
}
