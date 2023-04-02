#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool compare(int x, int y)
{
	return x > y; 
}

int main()
{
	int n; 
	cin >> n; 

	vector<int> v(n); 

	for (int i = 0; i < n; i++) {
		int m; 
		cin >> m; 
		v.push_back(m); 
	}
	
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' '; 
	}
}
