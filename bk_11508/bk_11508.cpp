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

    int result = 0; 

    for (int i = 0; i < n; i++) {
        if (i % 3 == 2)
            continue; 
        result += arr[i]; 
    }

    cout << result << endl; 
}

