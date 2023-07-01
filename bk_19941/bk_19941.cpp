#include <iostream>
#include <string>
using namespace std; 

char arr[200001]; 
int n, k; 

int main()
{
    cin >> n >> k; 
    getchar();

    memset(arr, 'X', sizeof(arr)); 

    for (int i = 1; i <= n; i++) {
        scanf_s("%c", &arr[i]);         
    }

    int cnt = 0; 

    for (int i = 1; i <= n; i++) {

        if (arr[i] == 'P') {

            int s = max(0, i - k); 
            int e = min(200001, i + k);

            for (int j = s; j <= e; j++) {
                if (arr[j] == 'H') {
                    arr[j] = 'X'; 
                    cnt++; 
                    break; 
                }
            }
        }
    }

    cout << cnt << endl; 
}
