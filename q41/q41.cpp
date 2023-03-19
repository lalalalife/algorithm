#include <iostream>
#include <vector>
using namespace std; 

int n, m; 
int parent[501]; 

int findParent(int x)
{
    if (x == parent[x])
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
        parent[i] = i;      // 부모를 자기자신으로 초기화
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; 
            cin >> x; 
            if (x == 1) {
                unionParent(i + 1, j + 1); // 연결된 도시라면 
            }
        }
    }

    // 
    vector<int> plan; 
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x; 
        plan.push_back(x); 
    }

    // 노드의 루트를 모두 비교
    bool result = true; 
    for (int i = 0; i < m - 1; i++) {
        if (findParent(plan[i]) != findParent(plan[i + 1])) {
            result = false; 
        }
    }

    if (result)
        cout << "YES" << endl;
    else
        cout << "NO" << endl; 
}
