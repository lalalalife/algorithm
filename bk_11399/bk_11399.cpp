#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n; 
vector<int> v; 

int main()
{
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x; 
		v.push_back(x);
	}

	int minSum = 987654321; 

	sort(v.begin(), v.end()); 

	do {

		int sum = 0; 

		int s[1000]; 
		memset(s, 0, sizeof(s)); 

		for (int i = 0; i < v.size(); i++) {
			
			if(i == 0 )
				s[i] = v[i]; 
			else {
				s[i] = s[i - 1] + v[i]; 
			}

			sum += s[i]; 
		}

		minSum = min(sum, minSum); 

	} while (next_permutation(v.begin(), v.end())); 

	cout << minSum << endl;
}
