// q24.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main()
{
    int n; 
    vector<int> v; 
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int m; 
        cin >> m;
        v.push_back(m); 
    }

    sort(v.begin(), v.end()); 

    cout << v[(n - 1) / 2] << endl;
    
}
