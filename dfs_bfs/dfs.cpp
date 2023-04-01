#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n, m; 
//int graph[1000][1000];
vector<int> graph[1000];

bool dfs(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false; 

    if (graph[x][y] == 0) {
        graph[x][y] = 1; 

        dfs(x - 1, y); 
        dfs(x + 1, y); 
        dfs(x, y - 1); 
        dfs(x, y + 1); 

        return true; 
    }
    return false; 
}


int main()
{
    cin >> n >> m; 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {            
            scanf_s("%1d", &graph[i][j]);
        }
    }

    int result = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            if (dfs(i, j)) {
                result++; 
            }
        }
    }

    cout << result << endl;
}
