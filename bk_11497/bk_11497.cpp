#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int c, n; 
vector<int> v; 

int solution(int n, vector<int> v)
{
    // 2 4 5 7 9

    sort(v.begin(), v.end()); 
    int result = 0; 

    for (int i = 0; i < n - 2; i++) {
        result = max(result, abs(v[i] - v[i + 2]));         // ✔ i+2 인 이유를..
    }
    
    return result; 
}

int main()
{
    cin >> c; 
    for (int i = 0; i < c; i++) {
        cin >> n; 
        v.clear(); 

        for (int j = 0; j < n; j++) {
            int x; 
            cin >> x;             
            v.push_back(x);             
        }

        cout << solution(n, v) << endl; 
    }
}
