#include <iostream>
#include <algorithm>
using namespace std; 

int n; 
int tree[100000]; 
int tmp[100000]; 

bool comp(int a, int b) {
    return a > b;
}

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> tree[i]; 
    }
    sort(tree, tree + n, comp); 

    for (int i = 0; i < n; i++) {
        tmp[i] = (i + 1) + tree[i];         // ✔ 심을 수 있는 날짜에서 다 자라는 날짜 
    }
    
    sort(tmp, tmp + n, comp); 

    cout << tmp[0] + 1 << endl; 
}
