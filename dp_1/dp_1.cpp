#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fibo(int x)
{
    cout << "x : " << x << endl; 

    if (x == 1 || x == 2)
        return 1; 

    return fibo(x - 1) + fibo(x - 1); 

}

long long n[100] = { 0, }; 

long long fibo_memoization(int x)
{
    // 탑다운, 메모이제이션 이용
    cout << "x : " << x << endl;

    if (x == 1 || x == 2)
        return 1;

    if (n[x] != 0)
        return n[x]; 

    n[x] = fibo_memoization(x - 1) + fibo_memoization(x - 1);
    return n[x]; 
}


int main()
{
    //cout << fibo(5) << endl; 
    // cout << fibo_memoization(6) << endl;

    // 바텀업, dp 테이블 이용
    int d[100] = { 0, }; 
    d[1] = 1; 
    d[2] = 1; 
    int n = 6; 

    for (int i = 3; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2]; 
    }

    cout << d[n] << endl; 
    
}

