#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int v, e;
int parent[100];
vector<pair<int, int>> graph;

int findParent(int x)
{
    if (x == parent[x])
        return x; 

    return findParent(parent[x]); 
}

void unionParent(int a, int b)
{
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b; 
}

int main()
{    
    cin >> v >> e; 
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b; 
        graph.push_back({ a, b }); 
    }

    for (int i = 1; i <= v; i++) {
        parent[i] = i; 
    }

    for (int i = 0; i < graph.size(); i++) {
        int a = findParent(graph[i].first);
        int b = findParent(graph[i].second);

        unionParent(a, b); 
    }

    // v가 속한 집합
    for (int i = 1; i <= v; i++) {
        cout << findParent(i) << ' '; 
    }
    cout << '\n'; 

    // 부모테이블
    for (int i = 1; i <= v; i++) {
        cout << parent[i] << ' '; 
    }

}