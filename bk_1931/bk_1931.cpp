#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n; 
vector<pair<int, int>> v; 

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first; 

    return a.second < b.second; 
}

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int a, b; 
        cin >> a >> b; 

        v.push_back({ a, b }); 
    }

    sort(v.begin(), v.end(), comp); 

    int endTime = v[0].second; 
    int count = 1; 

    for (int i = 1; i < n; i++) {
        if (v[i].first >= endTime) {
            count++; 
            endTime = v[i].second; 
        }
    }

    cout << count << endl; 
}
