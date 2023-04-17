#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int n; 
    vector<int> arr; 
     
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x; 
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end()); 

    int target = 1; 
    for (int i = 0; i < arr.size(); i++) {

        if (target < arr[i])        //targe 보다 추가된 화폐가 크면 nope. 
            break; 
        target += arr[i];       // target 이 다음화폐 더한값으로?

    }

    cout << target << endl; 

}
