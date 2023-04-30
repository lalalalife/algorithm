#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int solution(int n, vector<int> weak, vector<int> dist) {
    
    int length = weak.size(); 
    for (int i = 0; i < length; i++) {
        weak.push_back(weak[i] + n); 
    }

    int answer = dist.size() + 1; 

    // 0 ~ length-1 까지를 시작위치로 설정
    for (int start = 0; start < length - 1; start++) {

        do {
            int cnt = 1; 
            int position = weak[start] + dist[cnt - 1];  // 해당친구가 점검가능한 마지막 위치

            for (int index = start; index < start + length; index++) {                
                // 점검위치를 지나쳤다면 투입친구수 +1
                // 
                if (position < weak[index]) {
                    cnt++; 
                    if (cnt > dist.size()) {
                        break;
                    }         

                    position = weak[index] + dist[cnt - 1]; // ✔... 
                }
            }
            answer = min(answer, cnt); 

        } while (next_permutation(dist.begin(), dist.end())); // 섞기 
    }

    if (answer > dist.size())
        return -1; 

    return answer; 
}


int main()
{
    int n = 12;
    vector<int> weak = { 1, 5, 6, 10 }; 
    vector<int> dist = { 1, 2, 3, 4 }; 

    cout << solution(n, weak, dist) << endl; 
}
