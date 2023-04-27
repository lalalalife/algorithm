#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std; 

int n, m; 
int arr[50][50]; 
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int getSum(vector<pair<int, int>> candidates) {

	int result = 0; 
	for (int i = 0; i < house.size(); i++) {

		int hx = house[i].first; 
		int hy = house[i].second; 

		// 이 집과 가장 가까운 치킨집 
		int temp = 1e9; 

		for (int j = 0; j < candidates.size(); j++) {

			int cx = candidates[j].first; 
			int cy = candidates[j].second; 

			temp = min(temp, abs(hx - cx) + abs(hy - cy));		// 어느치킨집과 가장 가까운지
		}

		result += temp; 
	}

	return result; 
}

int main()
{	
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j]; 

			if (arr[i][j] == 1)
				house.push_back({ i, j });
			else if (arr[i][j] == 2)
				chicken.push_back({ i, j }); 
		}
	}

	// 최대 M 개의 치킨집
	vector<bool> binary(chicken.size()); 
	fill(binary.end() - m, binary.end(), true);			// ✔ m개만 true로 

	int result = 1e9; // 전체 치킨거리 최소 합 

	do {

		vector<pair<int, int>> now; 
		for (int i = 0; i < chicken.size(); i++) {
			if (binary[i]) {
				int cx = chicken[i].first;
				int cy = chicken[i].second;
				now.push_back({ cx, cy }); 
			}
		}
		result = min(result, getSum(now));		// 이 치킨집 조합으로 계산해보고, 그중 작은거 찾기 

	} while (next_permutation(binary.begin(), binary.end()));		// 다른 치킨집 조합도 해보고


	cout << result << endl; 
}

