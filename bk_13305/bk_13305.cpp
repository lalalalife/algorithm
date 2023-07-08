#include <iostream>
using namespace std; 

int n; 
int dist[100000]; 
int cost[100000];

int main()
{    
    cin >> n; 
    for (int i = 1; i < n; i++) {
        cin >> dist[i]; 
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    long long totalCost = 0;

    int nowCost = cost[0]; 
    totalCost = nowCost * dist[1];
    
    for (int i = 1; i < n; i++) {
        if (nowCost > cost[i]) {
            nowCost = cost[i];
        }
                    
        totalCost += nowCost * dist[i + 1];        
    }

    cout << totalCost << endl; 
}
