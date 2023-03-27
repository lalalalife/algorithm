#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void greedy03()
{    
    int n, m;
    int arr[100][100];

    int minimum = 1e9;
    int result = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            minimum = min(minimum, arr[i][j]);
        }
        result = max(result, minimum);
    }

    cout << result << endl;
}

void greedy04()
{
    //1) N-1
    //2) if(N%K == 0)  N/K 9 

    int n, k; 
    cin >> n >> k; 
    int count = 0; 
    while (n>=k) {
        if (n % k == 0) {
            n = n / k; 
        }
        else {
            n--; 
        }
        count++; 
    }

    while (n > 1) {
        n--; 
        count++; 
    }

    cout << count << endl; 
}

void greedy04_2()
{
    int n, k;
    cin >> n >> k;
    int result = 0;

    while (true) {
        int target = (n / k) * k;       // n이 k가 배수가 되도록 만든후, 나누기 위함
        result += (n - target);         // -1을 수행할 연산횟수 
        n = target; 

        if (n < k)
            break;      // 나눌 수 없다면 탈출

        result++;                       // 나누기 연산횟수 
        n /= k; 
    }

    result += (n - 1);  // ✔ 남은수에 대해 1씩 뺀다...

    cout << result << endl; 
}

int main()
{
    //greedy03(); 
    //greedy04(); 
    greedy04_2();
}
