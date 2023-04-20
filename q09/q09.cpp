#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int solution(string s) {
    int answer = s.length();     

    for(int step=1; step<= s.length() / 2; step++)
    {
        string compressed; 

        // step 만큼 문자열 추출
        string prev = s.substr(0, step); 
        int count = 1;

        // step만큼 증가하며 이전문자열과 비교

        for (int i = step; i < s.length(); i += step) {
        
            if (prev == s.substr(i, step))
                count++; 

            else {                
                if (count == 1) {
                    compressed += prev;
                }
                else {
                    compressed += to_string(count) + prev;                    
                }

                prev = s.substr(i, step);
                count = 1;
            }
        }
        compressed += (count == 1) ? prev : to_string(count) + prev; 

        cout << compressed << endl; 

        answer = min(answer, (int)compressed.length());
    }

    return answer;
}

int main()
{
    /*
    "aabbaccc"	7
    "ababcdcdababcdcd"	9
    "abcabcdede"	8
    "abcabcabcabcdededededede"	14
    "xababcdcdababcdcd"	17
    */

    cout << solution("abcabcabcabcdededededede") << endl; 
}
