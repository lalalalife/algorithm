#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k; 
vector<int> v; 

bool compare(int x, int y) {
    return x > y; 
}
int main()
{
    cin >> n >> m >> k; 
    for (int i = 0; i < n; i++) {
        int tmp; 
        cin >> tmp; 
        v.push_back(tmp); 
    }

    sort(v.begin(), v.end(), compare); 

    int first = v[0];       // 가장큰수
    int second = v[1];      // 두번째큰수

    int result = 0;

    /*    
    * 단순하게 풀기 
    int count = 0; 
    for (int i = 0; i < m; i++) {       // m번 더하기
        if (count < k) {
            result += first; 
            count++; 
        }
        else {
            result += second; 
            count = 0; 
        }
    }
    */

    // 반복되는 수열에 대해 파악, 계산식 이용하여 풀기 
    int count = (m / (k + 1)) * k + (m % (k + 1));  // 가장큰수가 더해질 횟수
    result = count * first; 
    result += (m - count) * second; 

    cout << result << endl; 
}

