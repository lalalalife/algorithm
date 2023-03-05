// q18.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std; 

bool isCorrect(string str, int* pos) {
    
    bool ret = true; 
    stack<char> mystack; 
    int open =0 , close = 0; 

    for (int i = 0; i < str.length(); i++) {

        if (str[i] == '(') {
            open++; 
            mystack.push('('); 
        }
        else {
            close++; 
            if (mystack.empty())
                ret = false;
            else
                mystack.pop(); 
        }

        if (open == close) {        // () 개수가 같은 지점이 되면 반환 
            *pos = i + 1; 
            return ret; 
        }
    }
    return true; 
}

string solution(string p) {
    
    if (p.empty())
        return p; 

    int pos; 
    bool correct = isCorrect(p, &pos); 
    string u = p.substr(0, pos); 
    string v = p.substr(pos, p.length() - pos);

    if (correct) {
        return u + solution(v); 
    }

    string answer = "";
    answer = "(" + solution(v) + ")"; 

    for (int i = 1; i < u.length() - 1; i++) {
        if (u[i] == '(')
            answer += ")"; 
        else
            answer += "(";
    }

    return answer; 
}

int main()
{
    //cout << solution(")(") << endl; 
    cout << solution("()))((()") << endl;
}
