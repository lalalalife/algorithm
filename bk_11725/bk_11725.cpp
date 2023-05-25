#include <iostream>
#include <vector>
using namespace std; 

int n;  // 2 <= n <= 100,000
vector<int> v[100001]; 
int parent[100001]; 

void dfs(int index)
{            
    for (int j = 0; j < v[index].size(); j++) {

        int next = v[index][j]; 
        if (parent[next] == 0) {
            parent[next] = index; 
            dfs(next); 
        }        
    }    
}

int main()
{
    cin >> n; 
    for (int i = 0; i < n-1; i++) {
        int a, b; 
        cin >> a >> b; 
        v[a].push_back(b); 
        v[b].push_back(a);
    }
    
    dfs(1); 

    for (int i = 2; i <= n; i++)
        cout << parent[i] << endl; 
        
}
