#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n; 
vector<pair<int, int>> v; 

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int a, b; 
        cin >> a >> b; 
        v.push_back({ a, b }); 
    }

    sort(v.begin(), v.end()); 

    int result = 0; 

    for (int i = 0; i < v.size(); i++) {
        int start = v[i].first; 
        int cost = v[i].second; 

        if (start >= result) {
            result = start + cost; 
        }
        else {
            result = result + cost; 
        }
    }

    cout << result << '\n'; 

}
