#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    // 럭키 스트레이트 

    string str; 
    cin >> str; 
        
    int len = str.length() / 2; 

    int leftSum = 0; 
    int rightSum = 0; 
    for (int i = 0; i < len; i++) {
        leftSum += str[i] - '0'; 
        rightSum += str[i + len] - '0'; 
    }

    if (leftSum == rightSum)
        cout << "LUCKY" << endl; 
    else 
        cout << "READY" << endl;
}

