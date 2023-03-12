// q29.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int n, c; 
vector<int> v; 

int main()
{
    cin >> n >> c; 
    for (int i = 0; i < n; i++)
    {
        int x; 
        cin >> x; 
        v.push_back(x); 
    }

    sort(v.begin(), v.end()); 

    int start = 1; 
    int end = v[n - 1] - v[0]; 
    int result = 0; 

    while (start <= end) {
        int mid = (end - start) / 2; 
        int value = v[0];   // 첫번째 집은 공유기 무조건 설치
        int cnt = 1;        // 공유기 설치개수 
        for (int i = 1; i < n; i++) {
            if (v[i] >= value + mid) {      // 갭을 더한값보다 크거나 같으면 이동 
                value = v[i];
                cnt++; 
            }
        }

        if (cnt >= c) {
            start = mid + 1; 
            result = mid; 
        }
        else {
            end = mid - 1; 
        }
    }

    cout << result << endl; 
}


