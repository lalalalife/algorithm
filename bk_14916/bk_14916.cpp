#include <iostream>
using namespace std; 

int n; 
int main()
{
    cin >> n; 

    int cnt = 0; 
    
    if (n % 5 == 0) {
        cout << n / 5 << endl; 
    }
    else {
        while (n > 0) {
            n -= 2; 
            cnt++; 
            if (n % 5 == 0) {    
                cnt += n / 5;                 
                cout << cnt << endl;                
                break; 
            }
        }
    }

    if (n < 0)
        cout << "-1" << endl;
    
    return 0; 
}
