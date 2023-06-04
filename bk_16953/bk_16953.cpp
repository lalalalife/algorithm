#include <iostream>
using namespace std; 

long a, b; 

int main()
{
	cin >> a >> b; 

	int cnt = 0; 
	while (true) {
		
		if (a == b) {
			cnt++;
			break; 
		}
		if (a > b) {
			cnt = -1; 
			break; 
		}
			

		if (b % 2 == 0) {
			b /= 2;			
		}
		else if (b % 10 == 1) {
			b--; 
			b /= 10; 
		}
		else {
			cnt = -1; 
			break; 
		}

		cnt++; 
	}
	
	cout << cnt << endl; 
}
