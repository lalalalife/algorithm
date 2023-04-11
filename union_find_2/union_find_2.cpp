#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e; 
int parent[1000]; 

int findParent(int x)
{
    // 부모값이 루트노드가 아니라면 찾을때까지 재귀호출 
    if (x == parent[x]) return x;
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
    cin >> v >> e; 
    
    for (int i = 1; i <= v; i++) {
        parent[i] = i; 
    }

    for (int i = 0; i < e; i++) {
        int a, b; 
        cin >> a >> b; 
        unionParent(a, b); 
    }

    //
    for (int i = 1; i <= v; i++) {
        cout << findParent(i) << ' ';
    }
    cout << '\n';

    // 
    for (int i = 1; i <= v; i++) {
        cout << parent[i] << ' ';
    }
    cout << '\n';

}
