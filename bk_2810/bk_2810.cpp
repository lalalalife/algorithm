#include <iostream>
using namespace std; 

int n; 
char board[50]; 

int main()
{
    int coupleCount = 0; 
    int cupCount = 0; 

    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> board[i]; 

        if (board[i] == 'L') {
            coupleCount++; 

            if (coupleCount % 2 == 0)
                cupCount++;
        }
        else if (board[i] == 'S') {
            cupCount++; 
        }
    }
    cupCount++; 
    if (cupCount > n)
        cout << n << endl; 
    else
        cout << cupCount << endl; 
}
