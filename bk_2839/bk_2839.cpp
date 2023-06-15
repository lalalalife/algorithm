#include <iostream>
using namespace std; 

int n; 

int main()
{
    cin >> n; 

    int result = 0; 

    while (n > 0) {

        if (n % 5 == 0) {            
            result += n / 5; 
            n = 0;
            break;             
        }

        n -= 3; 
        result++; 
    }

    if (n != 0)
        result = -1; 

    cout << result << endl;
    
}
