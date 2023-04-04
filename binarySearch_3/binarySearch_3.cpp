#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void search()
{
	// 순차탐색 but.. 시간초과
	int n, m;
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int len = v.size() - 1;

	while (true)
	{
		int cut = v[len];
		int remain = 0;

		for (int i = 0; i < n; i++) {
			if (v[i] > cut)
				remain += v[i] - cut;
		}

		if (remain >= m) {
			cout << cut << endl;
			break;
		}

		len--;
	}
}

int binary_search(vector<int> v, int start, int end, int target)
{
	int result = 0; 

	while (start <= end) {
		int mid = (start + end) / 2; 

		int sum = 0; 
		for (int i = 0; i < v.size(); i++) {
			if(v[i] > mid)
				sum += v[i] - mid; 
		}

		if (sum < target)
			end = mid - 1;
		else {
			result = mid; 
			start = mid + 1;			
		}
	}

	return result; 
}

int main()
{
	int n, m;
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int end = 1e9; 

	cout << binary_search(v, 0, end, m) << endl; 
}

