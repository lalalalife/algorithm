// q19.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std; 

int n; 
vector<int> v; 
int add, sub, mul, divi;

int maxValue = -1e9;
int minValue = 1e9;

void dfs(int i, int now) 
{
    if (i == n)
    {
        minValue = min(minValue, now); 
        maxValue = max(maxValue, now); 
    }
    else
    {
        // 연산자 사용하고, 재귀가 끝나면 다시 연산자 개수를 ++... 
        if (add > 0) {
            add -= 1; 
            dfs(i + 1, now + v[i]); 
            add += 1; 
        }
        if (sub > 0) {
            sub -= 1;
            dfs(i + 1, now - v[i]);
            sub += 1;
        }
        if (mul > 0) {
            mul -= 1;
            dfs(i + 1, now * v[i]);
            mul += 1;
        }
        if (divi > 0) {
            divi -= 1;
            dfs(i + 1, now / v[i]);
            divi += 1;
        }
    }
}

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++)
    {
        int x; 
        cin >> x; 
        v.push_back(x);        
    }
    
    cin >> add >> sub >> mul >> divi; 

    dfs(1, v[0]); 

    cout << maxValue << endl << minValue << endl;
}
