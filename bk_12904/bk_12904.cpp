#include <iostream>
#include <algorithm>
using namespace std; 

string s, t; 

int main()
{
    cin >> s >> t;
    
    // s -> t 
    // 문자열의 뒤에 A를 추가
    // 문자열을 뒤집고 뒤에 B를 추가 

    // t -> s 
    // t 의 마지막 문자열이 A 이면, A를 제거
    //                      B 이면, B를 제거하고 문자열 뒤집, 

    int result = 0; 
    while (true) {
        if (s.size() == t.size()) {

            if (s == t)
                result = 1; 
            
            break;
        }            
        
        if (t[t.size() - 1] == 'A') {
            t.pop_back();
        }
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }

        /*  이건 왜 오류지.. 
        t.pop_back();

        if (t[t.size() - 1] == 'B') {
            reverse(t.begin(), t.end());
        }
        */
    }

    cout << result << endl; 
}

