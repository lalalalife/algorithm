#include <iostream>
#include <algorithm>
using namespace std; 

int n; 
int arr[100000]; 

bool comp(int a, int b) {
    return a > b; 
}

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

    sort(arr, arr + n, comp); 

    long long result = 0; 
    for (int i = 0; i < n; i++) {
        int tip = arr[i] - i; 
        if(tip > 0)
            result += tip; 
    }

    cout << result << endl; 
}
