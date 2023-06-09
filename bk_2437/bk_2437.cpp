#include <iostream>
using namespace std; 
#include <algorithm>

int n; 
int arr[1000]; 

int main()
{
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + n); 

	int result = 1; 

	for (int i = 0; i < n; i++) {
		if (arr[i] > result)		// ✔ 다음추의 무게가 지금까지의 누적합보다 크다면, 
			break; 

		result += arr[i]; 
	}

	cout << result << endl; 

}
