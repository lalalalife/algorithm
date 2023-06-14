#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int n, m; 
vector<int> crane; 
vector<int> box; 

bool compare(int a, int b) {
    return a > b; 
}

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x; 
        crane.push_back(x);         
    }

    cin >> m; 
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x; 
        box.push_back(x); 
    }

    sort(crane.begin(), crane.end(), compare);
    sort(box.begin(), box.end(), compare);

    int result = 0; 
    
    if (box[0] > crane[0]) {
        cout << "-1" << endl; 
        return 0; 
    }

    while (!box.empty()) {

        result++; 

        for (int i = 0; i < crane.size(); i++) {
            
            for (int j = 0; j < box.size(); j++) {

                if (crane[i] >= box[j]) {
                    box.erase(box.begin() + j); 
                    break; 
                }
            }
        }
    }

    cout << result << endl; 
}
