#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
    return a > b; 
}

int main()
{
    int n, k; 
    cin >> n >> k; 
    vector<int> a(n); 
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        int m; 
        cin >> m;
        a[i] = m; 
    }

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        b[i] = m;
    }

    sort(a.begin(), a.end()); 
    sort(b.begin(), b.end(), compare); 

    for (int i = 0; i < k; i++) {
        if (a[i] < b[i])
            swap(a[i], b[i]);
        else
            break; 
    }

    int result = 0; 
    for (int i = 0; i < n; i++) {
        result += a[i]; 
    }

    cout << result << endl; 
}
