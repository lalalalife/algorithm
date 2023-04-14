#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main()
{
    int n; 
    vector<int> v; 
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x; 
        v.push_back(x); 
    }

    sort(v.begin(), v.end()); 

    int result = 0;     // 그룹수
    int count = 0;      // 현재 그룹에 속한 인원수 

    for (int i = 0; i < v.size(); i++) {
        count++; 
        if (v[i] <= count) {
            // 현재그룹에 속한 인원수가 현재사람의 공포도보다 같거나 크다면, 그룹 한개 생성완료
            result++; 
            count = 0; 
        }
    }

    cout << result << endl; 
}

