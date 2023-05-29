#include <iostream>
using namespace std; 

int n, k; 
int type[10];

int main()
{
	cin >> n >> k; 
	for (int i = 0; i < n; i++) {
		cin >> type[i]; 
	}

	int cnt = 0; 
	int num = k; 

	for (int i = n-1; i >= 0; i--) {
		if (type[i] > num)
			continue; 

		int mok = num / type[i];
		cnt += mok; 

		num = num % type[i]; 
	}

	cout << cnt << endl; 
}

