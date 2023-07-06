#include <iostream>
#include <algorithm>
using namespace std; 

int n, l; 
int arr[1000]; 

int main()
{
	cin >> n >> l; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + n); 
	
	for (int i = 0; i < n; i++) {
		if (l >= arr[i]) {
			l++; 
		}
	}

	cout << l << endl; 
	return 0; 
}
