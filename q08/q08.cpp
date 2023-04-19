#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    string str; 
    cin >> str; 

    int sum = 0; 
    vector<char> v; 

    for (int i = 0; i < str.length(); i++) {
        
        // isalpha(str[i]) oh.. 

        if ('0' <= str[i] && str[i] <= '9') {
            sum += str[i] - '0'; 
        }
        else {
            v.push_back(str[i]); 
        }
    }
    sort(v.begin(), v.end()); 
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << sum << endl; 
}
