#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    string s; 
    cin >> s; 

    int result = s[0]-'0';

    for (int i = 1; i < s.length(); i++) {
        int n = s[i]-'0'; 

        if (result >= 2 && n >= 2) {
            result *= n; 
        }
        else {
            result += n; 
        }
    }

    cout << result << endl; 
}

