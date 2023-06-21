#include <iostream>
using namespace std; 
#include <vector>
#include <algorithm>

int n; 
vector<pair<int, int>> v; 

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int a, b;         
        cin >> a >> b; 
        v.push_back({ a, 1 }); 
        v.push_back({ b, 1 });
    }
    sort(v.begin(), v.end()); 
    
    int cnt = 0; 
    int result = 0; 
    for (int i = 0; i < v.size(); i++) {

        cnt += v[i].second; 
        result = max(result, cnt);
    }

    cout << result << endl; 
}
