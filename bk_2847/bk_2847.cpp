#include <iostream>
using namespace std; 

int n; 
int arr[100]; 

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

    int result = 0; 

    for (int i = n-1; i > 0; i--) {
        if (arr[i] <= arr[i - 1]) {
            int tmp = arr[i - 1]; 
            arr[i - 1] = arr[i] - 1; 
            result += tmp - arr[i - 1]; 
        }
    }

    cout << result << endl; 
}

