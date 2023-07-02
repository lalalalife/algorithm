#include <iostream>
using namespace std; 
#include <vector>
#include <algorithm>

int n; 
vector<int> v; 

bool comp(int a, int b) {
    return a > b; 
}

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x; 
        v.push_back(x); 
    }

    sort(v.begin(), v.end(), comp); 

    for (int i = 0; i < n - 2; i++) {
        if (v[i] < v[i + 1] + v[i + 2]) {
            cout << v[i] + v[i + 1] + v[i + 2] << endl; 
            return 0; 
        }
    }

    cout << "-1\n"; 
    return 0; 
}
