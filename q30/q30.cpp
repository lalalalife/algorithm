#include <iostream>
#include <vector>
#include<algorithm>
#include <regex>

using namespace std;

vector<string> arr[10001]; 
vector<string> reversed_arr[10001]; 

int countByRange(vector<string>& v, string leftValue, string rightValue) {
    vector<string>::iterator itRightIndex = upper_bound(v.begin(), v.end(), rightValue); 
    vector<string>::iterator itLeftIndex = lower_bound(v.begin(), v.end(), leftValue); 

    return itRightIndex - itLeftIndex; 
}

string replaceAll(string str, string from, string to) {
    string res = str; 
    int pos = 0; 
    while ((pos = res.find(from, pos)) != string::npos) {
        res.replace(pos, from.size(), to); 
        pos += to.size(); 
    }
    return res; 
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    for (int i = 0; i < words.size(); i++) {
        string word = words[i]; 
        arr[words[i].size()].push_back(word);       // arr[배열크기] = 단어

        // 문자열 뒤집어서
        reverse(word.begin(), word.end()); 
        reversed_arr[words[i].size()].push_back(word); 
    }

    // 정렬
    for (int i = 0; i < 10001; i++) {
        sort(arr[i].begin(), arr[i].end()); 
        sort(reversed_arr[i].begin(), reversed_arr[i].end()); 
    }

    // 이게 왜 이진탐색이지?
    for (int i = 0; i < queries.size(); i++) {
        string query = queries[i]; 
        int res = 0; 
        if (query[0] != '?') {
            // arr
            // fro?? , fr???             
            res = countByRange(arr[query.size()], replaceAll(query, "?", "a"), replaceAll(query, "?", "z"));
        }
        else {
            //reverse_arr
            // ???o, 
            reverse(query.begin(), query.end());        // 쿼리도 뒤집
            res = countByRange(reversed_arr[query.size()], replaceAll(query, "?", "a"), replaceAll(query, "?", "z"));
        }
        answer.push_back(res); 
    }

    return answer;
}

int main()
{
    vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" }; 
    
    vector<int> result = solution(words, queries); 
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " "; 

}
