// q27.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std; 

int n, x; 
vector<int>v; 

int binary_search()
{
    vector<int>::iterator itStart = lower_bound(v.begin(), v.end(), x); 
    vector<int>::iterator itEnd = upper_bound(v.begin(), v.end(), x); 
    return itEnd - itStart; 
}

int main()
{
    cin >> n >> x; 
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m; 
        v.push_back(m); 
    }
    
    int count = binary_search(); 
    if (count == 0)
        cout << "-1" << endl;
    else
        cout << count << endl; 
}

