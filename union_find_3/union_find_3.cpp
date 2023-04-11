#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e; 
int parent[1000]; 

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
    cin >> v >> e; 

    for (int i = 1; i <= v; i++) {
        parent[i] = i; 
    }

    bool isCycle = false; 
    for (int i = 0; i < e; i++) {
        int a, b; 
        cin >> a >> b; 

        //
        if (findParent(a) == findParent(b)) {
            isCycle = true; 
            break; 
        }
        else {
            unionParent(a, b); 
        }            
    }

    if (isCycle)
        cout << "사이클발생 함" << endl; 
    else 
        cout << "사이클발생 안함" << endl;
}

