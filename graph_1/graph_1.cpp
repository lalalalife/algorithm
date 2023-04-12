#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m; 
int parent[100001]; 

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
        int op, a, b;
        cin >> op >> a >> b; 

         if (op == 0) {
            // 합치기
            unionParent(a, b); 
        }
        else if(op == 1) {
            // 같은팀 여부 출력
            if (findParent(a) == findParent(b))
                cout << "YES" << endl; 
            else
                cout << "NO" << endl;
        }
    }
}
