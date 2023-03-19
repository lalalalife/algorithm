#include <iostream>
#include <queue>

using namespace std; 

int n, m; 
vector < pair<int, pair<int, int>>> v; 
int parent[200001]; 
int result; 

int findParent(int x) {
    if (parent[x] == x)
        return x; 
    return parent[x] = findParent(parent[x]); 
}

void unionParent(int a, int b) {
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
    for (int i = 1; i < m; i++) {
        parent[i] = i; 
    }

    for (int i = 0; i < m; i++) {
        int a, b, c; 
        cin >> a >> b >> c;         
        v.push_back({ c, {a, b} }); 
    }
    sort(v.begin(), v.end()); 
    int total = 0; // 전체비용

    for (int i = 0; i < v.size(); i++) {
        int cost = v[i].first; 
        int a = v[i].second.first; 
        int b = v[i].second.second; 
        total += cost;  // 모든간선에 대한 전체 비용 누적

        // 사이클이 발생하지 않는 경우 == 부모가 같지 않은 경우
        if (findParent(a) != findParent(b)) {
            unionParent(a, b); 
            result += cost;  // 사용비용
        }
    }

    cout << total - result << endl; 
}
