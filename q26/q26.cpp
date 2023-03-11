// q26.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std; 

int n; 
priority_queue<int> pq; 

int main()
{
    cin >> n;     
    for (int i = 0; i < n; i++) {
        int m; 
        cin >> m; 
        pq.push(-m); 
    }

    int result = 0; 
    while (pq.size() != 1) {
        int first = -pq.top(); 
        pq.pop(); 
        int second = -pq.top(); 
        pq.pop(); 

        int sum = first + second; 
        result += sum; 
        pq.push(-sum);
    }

    cout << result << endl;
}