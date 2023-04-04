#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int x; 
	cin >> x; 

	// index가 되려는 수, 그 수가되기 위해 수행해야 하는 연산 횟수가 value, 
	// vector<int> v(x, 0);   	
	int v[30000] = { 0, }; 

	// 바텀업
	for (int i = 2; i <= x; i++) {

		v[i] = v[i - 1] + 1; 

		if (i % 2 == 0) {
			v[i] = min(v[i], v[i / 2] + 1);
		}

		if (i % 3 == 0) {
			v[i] = min(v[i], v[i / 3] + 1) ;
		}

		if (i % 5 == 0) {
			v[i] = min(v[i], v[i / 5] + 1) ;
		}
	}

	cout << v[x]; 

}

