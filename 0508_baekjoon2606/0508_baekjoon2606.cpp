#include <iostream>
#include <vector>
using namespace std; 

int n, m; 
vector<int> v[101];
bool visited[101]; 
int result = 0; 

void dfs(int x)
{
    for (int i = 0; i < v[x].size(); i++) {
        int next = v[x][i]; 
        if (!visited[next]) {
            visited[next] = true;
            result++;
            dfs(next); 
        }
    }
}

int main()
{
    cin >> n >> m; 

    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b; 
        v[a].push_back(b); 
        v[b].push_back(a);
    }
    
    visited[1] = true; 
    dfs(1); 

    cout << result << endl; 
}
