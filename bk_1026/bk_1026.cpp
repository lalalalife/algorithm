#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n; 
vector<int> a; 
vector<int> b; 

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        a.push_back(x); 
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }

    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end(), greater<int>()); 
    
    int result = 0; 
    for (int i = 0; i < n; i++) {
        result += a[i] * b[i]; 
    }

    cout << result << endl; 
}