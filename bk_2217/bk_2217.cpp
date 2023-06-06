#include <iostream>
#include <algorithm>
using namespace std; 

int n; 
int arr[100000]; 

int main()
{
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + n); 

	int maxW = 0; 

	for (int i = 0; i < n; i++) {		
		maxW = max(maxW, arr[i] * (n - i)); 
	}
	cout << maxW << endl; 
}

