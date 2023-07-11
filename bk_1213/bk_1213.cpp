#include <iostream>
#include <algorithm>
using namespace std; 

string s; 
int arr[26]; 

int main()
{
    cin >> s; 
    for (int i = 0; i < s.length(); i++) {
        arr[s[i] - 'A'] += 1;
    }

    string result = ""; 
    string mid = ""; 
    int oddCnt = 0; 

    for (int i = 0; i < 26; i++) {
        if (arr[i] == 0)
            continue; 

        if (arr[i] == 1 || arr[i] % 2 == 1) {
            oddCnt++; 
            mid = i + 'A'; 
        }

        //else if (arr[i] % 2 == 0) {
        if(arr[i] > 1) {
            int cnt = arr[i] / 2; 
            for (int j = 0; j < cnt; j++) {
                result += i + 'A'; 
            }
        }
    }

    if (oddCnt > 1) {
        result = "I'm Sorry Hansoo"; 
    }
    else {
        string tmp = result; 
        reverse(tmp.begin(), tmp.end()); 
        if (mid.length() == 1) {
            result += mid; 
        }
        result += tmp; 
    }

    cout << result << endl; 
}

