#include <iostream>
#include <stack>

using namespace std; 

bool isCorrect(string str, int* pos)
{
    // 올바른 문자열인지 판단 ✔

    bool ret = true; 
    int left = 0, right = 0; 
    stack<char> myStack; 

    for (int i = 0; i < str.length(); i++) {

        if (str[i] == '(') {
            left++; 
            myStack.push('('); 
        }
        else {
            right++; 
            if (myStack.empty())
                ret = false;
            else
                myStack.pop(); 
        }

        if (left == right) {
            *pos = i + 1;   // v위치, 
            return ret; 
        }
    }

    return true; 
}

string solution(string p) {
    string answer = "";

    if (p.empty())
        return ""; 

    int pos; 
    bool correct = isCorrect(p, &pos); 

    string u = p.substr(0, pos); 
    string v = p.substr(pos, p.length() - pos); 

    if (correct) {
        return u + solution(v); 
    }
    
    // 
    answer = "("; 
    answer += solution(v); 
    answer += ")";

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
    /*
    "(()())()"	"(()())()"
    ")("	    "()"
    "()))((()"	"()(())()"
    */
    string p = "()))((()"; 
    
    cout << solution(p); 
}
