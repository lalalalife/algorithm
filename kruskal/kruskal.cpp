#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e; 
int parent[1000]; 

vector<pair<int, pair<int, int>>> graph; 

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return true; 
    return false; 
}

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
    // 최소비용신장트리
    cin >> v >> e; 
    
    for (int i = 1; i <= v; i++) {
        parent[i] = i; 
    }

    int result = 0; 
    

    for (int i = 0; i < e; i++) {
        int a, b, cost; 
        cin >> a >> b >> cost; 

        graph.push_back({ cost, {a, b} }); 
    }

    // 최소 비용의 간선정보부터 알고리즘을 수행하기 위해, 
    sort(graph.begin(), graph.end()); 

    for (int i = 0; i < graph.size(); i++) {
        
        int a = graph[i].second.first; 
        int b = graph[i].second.second; 
        int cost = graph[i].first; 

        // 사이클이 발생하지 않는다면, 집합에 포함(union)한다. 
        // 집합에 포함된 노드들은 연결된다는 것, 
        if (findParent(a) != findParent(b)) {
            unionParent(a, b);
            result += cost;
        }

    }

    cout << result << endl; 
    
}
