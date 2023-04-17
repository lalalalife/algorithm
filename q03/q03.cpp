#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    string str; 
    cin >> str; 
        
    int count1 = 0;     // 모두 1로 뒤집을때, 
    int count0 = 0;     //      0으로 뒤집을때, 횟수

    if (str[0] == '1')
        count0++;
    else
        count1++; 

    for (int i = 0; i < str.length()-1; i++) {
        
        if (str[i] != str[i + 1]) {
            if (str[i + 1] == '1')
                count0++;
            else
                count1++; 
        }
    }

    cout << min(count1, count0) << endl;
}
