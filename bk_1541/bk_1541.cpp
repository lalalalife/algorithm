#include <iostream>
using namespace std; 

char arr[51]; 

int main()
{
	cin >> arr; 
	int len = strlen(arr); 

	int isMinus = false; 
	string num; 
	int result = 0; 

	for (int i = 0; i <= len; i++) {
		
		if (arr[i] == '+' || arr[i] == '-' || i == len) {

			if (isMinus) {
				result -= atoi(num.c_str());
			}
			else {
				result += atoi(num.c_str());
			}

			if (arr[i] == '-')
				isMinus = true;

			num = ""; 			
		}
		else {
			num += arr[i]; 
		}
	}

	cout << result << '\n'; 
}
