#include <iostream>
#include <algorithm>
using namespace std; 

int n, m; 
int minSet = 987654321;
int minOne = 987654321;

int main()
{
	cin >> n >> m; 
	for (int i = 0; i < m; i++) {
		int a, b; 
		cin >> a >> b; 

		minSet = min(minSet, a); 
		minOne = min(minOne, b); 
	}
	
	int result = 0; 
	if (n <= 6) {
		int tmp = 987654321;

		tmp = minOne * n; 
		result = min(tmp, minSet); 
	}
	else {
		if (minOne * 6 <= minSet) {
			result = minOne * n; 
		}
		else {
			int tmp = 987654321; 

			int mok = n / 6; 
			int na = n % 6; 
			tmp = minSet * mok;
			tmp += minOne * na;

			// or 
			result = min(tmp, minSet * (mok + 1)); 
			//result = minSet * (mok + 1); 
		}
	}

	cout << result << endl; 
}
