#include <iostream>
using namespace std; 
#include <vector>
#include <algorithm>

int n; 
vector<int> v; 

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x; 
        v.push_back(x); 
    }
    sort(v.begin(), v.end()); 

    int mid = n / 2; 
    int remain = n % 2; 

    int result = v[mid + remain - 1]; 
    cout << result << endl;
}
