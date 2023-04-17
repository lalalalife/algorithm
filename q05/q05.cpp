#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m; 
vector<int> v; 

int main()
{
    int arr[11] = { 0, };
    int result = 0;

    cin >> n >> m;     
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x; 
        arr[x] += 1; 
    }

    for (int i = 1; i <= m; i++) {
        n -= arr[i];        // A가 선택한 볼링공의 갯수 빼기 
        result += arr[i] * n;   // A가 선택한 볼링공의 갯수 * B가 선택하는 경우의 수
    }

    /*
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x; 
        v.push_back(x); 
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {            
            if (v[i] != v[j]) {                
                result++;
            }
        }
    }*/

    cout << result << endl; 
}

