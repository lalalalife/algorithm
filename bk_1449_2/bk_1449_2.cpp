#include <iostream>
#include <algorithm>
using namespace std; 

int n, l; 
int arr[1001]; 

int main()
{
	cin >> n >> l; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + n); 

	int s = 0; 
	int e = 0; 
	int cnt = 0; 

	for (int i = 0; i < n; i++) {

		if (e >= arr[i]) {
			continue; 
		}

		s = arr[i] - 0.5; 
		e = s + l;
		cnt++; 
	}

	cout << cnt << endl; 
}

