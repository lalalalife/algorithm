#include <iostream>
#include <vector>
using namespace std;

int g, p; 
int parent[100001]; 

int findParent(int x) {
    if (x == parent[x])
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
    cin >> g >> p;

    for (int i = 1; i <= g; i++) {
        parent[i] = i; 
    }

    int result = 0; 
    for (int i = 0; i < p; i++) {
        int x; 
        cin >> x; 
       
        int root = findParent(x);   // 현재 비행기의 탑승구 루트
        if (root == 0)
            break; 
        unionParent(root, root - 1); 
        result += 1; 
    }

    cout << result << endl; 
}
