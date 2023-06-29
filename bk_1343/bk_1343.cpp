#include <iostream>
using namespace std; 

char arr[50]; 

int main()
{
    string s; 
    cin >> s; 

    string result = ""; 

    int xCnt = 0; 
    for (int i = 0; i < s.length(); i++) {
        
        if (s[i] == 'X')
            xCnt++; 

        if (s[i] == '.') {
            result += "."; 

            if (xCnt % 2 == 1) {
                break; 
            }
            xCnt = 0; 
        }

        if (xCnt == 2 && s[i + 1] != 'X') {
            result += "BB"; 
            xCnt = 0; 
        }
        else if (xCnt == 4) {
            result += "AAAA"; 
            xCnt = 0;
        }
    }    

    if (xCnt % 2 == 1)
        result = "-1"; 

    cout << result << endl; 
}
