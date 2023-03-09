#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second)
        return a.first < b.first; 

    return a.second > b.second; 
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int length = stages.size(); 
    vector<pair<int, double>> v; 


    // 스테이지에 머물러 있는 사람 수 
    // 스테이지에 있는 모든 플레이어 수 = 전체길이 - 이전 스테이지에 머물러 있는 수 
    // 실패율 = 도달했으나, 클리어하지 못한 수  / 스테이지에 도달한 사람 수 

    for (int i = 1; i <= N; i++) {
        // 스테이지에 머물러 있는 사람 수 
        int cnt = count(stages.begin(), stages.end(), i); 

        double fail = 0; 
        if(length > 0)
            fail = cnt / length;

        // 실패율저장
        v.push_back({ i, fail }); 

        // 다음 스테이지 플레이어 수 계산
        length -= cnt; 
    }

    sort(v.begin(), v.end(), compare); 

    for (int i = 0; i < v.size(); i++) {
        answer.push_back(v[i].first);
    }

    return answer;
}

int main()
{
    int n = 5; 
    vector<int> v = { 2, 1, 2, 6, 2, 4, 3, 3 }; 
    solution(n, v); 
}

