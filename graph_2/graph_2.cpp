#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m; 
int parent[100001]; 
vector < pair<int, pair<int, int>>> graph; 

int findParent(int x)
{
    if (parent[x] == x)
        return x; 
    return parent[x] = findParent(parent[x]); 
}

void unionParent(int a, int b)
{
    a = findParent(a); 
    b = findParent(b); 
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b; 
}

int main()
{
    cin >> n >> m; 

    for (int i = 1; i <= n; i++) {
        parent[i] = i; 
    }

    for (int i = 0; i < m; i++) {
        int a, b, cost; 
        cin >> a >> b >> cost; 
        graph.push_back({ cost, {a, b} }); 
    }

    sort(graph.begin(), graph.end()); 

    int totalCost = 0; 
    int maxCost = 0; 

    for (int i = 0; i < graph.size(); i++) {
        int cost = graph[i].first; 
        int a = graph[i].second.first; 
        int b = graph[i].second.second;

        if (findParent(a) != findParent(b)) {
            unionParent(a, b); 
            totalCost += cost; 
            maxCost = cost;         // 정렬해놨으므로, 
        }
    }
    
    cout << totalCost - maxCost << endl; 
}
