#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

string s; 

bool comp(char a, char b) {
	return a > b; 
}

int main()
{
	cin >> s; 
	sort(s.begin(), s.end(), comp); 

	long long sum = 0; 
	bool isZero = false; 

	string result = ""; 
	for (int i = 0; i < s.length(); i++) {
		int n = s[i] - '0'; 
		sum += n; 
		if (n == 0)
			isZero = true; 
		result += s[i]; 
	}

	// 각 자리의 합이 3의 배수인지, 
	if (sum % 3 == 0 && isZero) {
		cout << result << endl; 
	}
	else {
		cout << "-1" << endl;
	}
}
