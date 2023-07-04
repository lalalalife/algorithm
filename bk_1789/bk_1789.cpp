#include <iostream>
using namespace std; 

long long s;

int main()
{
    cin >> s; 
    
    long long sum = 0; 
    long long num = 0;

    while (true) {
        sum += ++num; 

        if (sum > s) {
            cout << --num << endl; 
            return 0; 
        }
        else if (sum == s) {
            cout << num << endl; 
            return 0; 
        }
    }
}
