#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std; 


bool binary_search(vector<int> v, int start, int end, int target)
{    
    while (start <= end) {

        int mid = (start + end) / 2;

        if (v[mid] == target)
            return true; 

        if (v[mid] > target)
            end = mid - 1;
        else
            start = mid + 1; 
    }
    return false; 
}

void binary_search_main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
    }

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b[i] = x;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < m; i++) {
        if (binary_search(a, 0, n - 1, b[i]))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}

void count_sort()
{
    int n, m;
    cin >> n;

    vector<int> v(1000000);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x] = 1;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        if (v[x] >= 1)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}

void find_search()
{
    int n, m;
    cin >> n;

    set<int> s; 

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x); 
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;

        if( s.find(target) != s.end())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}

int main()
{
    // 이진탐색
    // binary_search_main(); 

    // 계수정렬
    //count_sort(); 

    // 집합자료형 
    find_search(); 
}