#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std; 

int n; 
int board[101]; 
int visited[101]; 
vector<int> v; 

void dfs(int index, int target)
{
    int nextIndex = board[index]; 
    visited[index] = true; 

    if (board[nextIndex] == target)
    {
        v.push_back(nextIndex); 
        return; 
    }
    if(!visited[nextIndex])
        dfs(nextIndex, target);
}

int main()
{
    cin >> n;  
    for (int i = 1; i <= n; i++) {
        cin >> board[i];
    }

    for (int i = 1; i <= n; i++) {
        dfs(i, i); 

        memset(visited, false, sizeof(visited)); 
    }

    sort(v.begin(), v.end()); 

    cout << v.size() << endl; 
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl; 
    }
}
