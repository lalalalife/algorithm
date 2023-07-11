#include <iostream>
using namespace std; 

int n, m, c; 
int arr[11]; 

int main()
{
    cin >> n >> m; 
    cin >> c; 
    for (int i = 1; i <= c; i++) {
        cin >> arr[i]; 
    }

    int basketStart = 1; 
    int basketEnd = basketStart + (m-1); 
    int result = 0; 

    for (int i = 1; i <= c; i++) {
        if (basketStart <= arr[i] && arr[i] <= basketEnd)
            continue; 

        if (arr[i] > basketEnd) {
            int gap = arr[i] - basketEnd; 
            result += gap; 
            basketEnd += gap; 
            basketStart += gap; 
        }
        else if (arr[i] < basketStart) {
            int gap = basketStart - arr[i]; 
            result += gap; 
            basketEnd -= gap;
            basketStart -= gap;
        }
    }

    cout << result << endl; 
}