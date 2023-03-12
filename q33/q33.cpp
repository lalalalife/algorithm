// q33.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std; 

int n; 
vector<int> t; 
vector<int> p; 
int dp[16]; 
int maxValue; 

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int x, y; 
        cin >> x >> y; 
        t.push_back(x); 
        p.push_back(y); 
    }

    // 리스트 뒤에서부터 확인
    for (int i = n - 1; i >= 0; i--) {
        int time = t[i] + i;   // ✔ (상담이 종료되는 날짜)
        if (time <= n) {
            dp[i] = max(p[i] + dp[time], maxValue);  // ✔ 점화식
            maxValue = dp[i]; 
        }
        else {
            dp[i] = maxValue; 
        }
    }

    cout << maxValue << '\n'; 

}
