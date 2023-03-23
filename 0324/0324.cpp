#include <iostream>
#include <vector>
using namespace std; 

bool isPrimeNumber(int x)
{
    double d = sqrt(x); 
    for (int i = 2; i <= d; i++) {
        if (x % i == 0)
            return false; 
    }
    return true; 
}

vector<bool> getPrimeNumbers(int x)
{
    // 에라토스테네스의 체 알고리즘 

    vector<bool> v(x+1, true); 
    v[0] = false; 
    v[1] = false; 

    double d = sqrt(x); 
    for (int i = 2; i <= d; i++) {
        // i를 제외한 i의 배수를 지운다. (true => false)
        if (v[i] == true) {

            // 배수, *2, *3, *4 ....
            int j = 2; 

            while (i * j <= x) {
                v[i * j] = false; 
                j++; 
            }
        }
    }

    return v; 
}

int main()
{
    int n; 
    cin >> n; 
    //cout << isPrimeNumber(n) << endl; 


    vector<bool> v = getPrimeNumbers(n); 
    for (int i = 0; i < v.size(); i++) {
        if (v[i]) {
            cout << i << ' '; 
        }
    }
    cout << endl; 
}

