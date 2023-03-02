// q13.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n, m; 
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int arr[50][50]; 

int getSum(vector<pair<int, int>> candidates) {
    int result = 0; 

    for (int i = 0; i < house.size(); i++) {
        int hx = house[i].first;
        int hy = house[i].second; 

        int temp = 1e9; 
        for (int j = 0; j < candidates.size(); j++) {
            int cx = candidates[j].first;
            int cy = candidates[j].second;

            temp = min(temp, abs(hx - cx) + abs(hy - cy));      // 집별로 가까운 치킨집 거리 
        }
        result += temp; // 치킨집 거리 합 
    }

    return result; 
}

void test()
{      
    vector<bool> v(4);
    fill(v.begin(), v.begin() + 2, true);  // 0, 1 은 true, 나머지는 false; 
    
do {

        for (int i = 0; i < 4; i++) {
            cout << v[i] << " ";
        }

        cout << '\n';

    } while (prev_permutation(v.begin(), v.end()));     // 순열 섞어주기 

}

int main()
{
    //순열
    test(); 
    // 
    cin >> n >> m; 
    
    int countChicken = 0; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 1)
                house.push_back({ i, j });

            if (arr[i][j] == 2)
                chicken.push_back({ i, j }); 
        }
    }

    vector<bool> binary(chicken.size()); 
    fill(binary.end() - m, binary.end(), true);     // m개의 치킨집뽑기

    int result = 1e9; 

    do {
        vector<pair<int, int>> now; 
        for (int i = 0; i < chicken.size(); i++) {      // m개 치킨집 좌표  
            if (binary[i]) {
                int cx = chicken[i].first; 
                int cy = chicken[i].second; 
                now.push_back({ cx, cy }); 
            }
        }

        result = min(result, getSum(now));      // m개 치킨 집 케이스 하나, 

    } while (next_permutation(binary.begin(), binary.end()));       // 다음 케이스 구하기 

    cout << result << '\n'; 
}
