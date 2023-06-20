#include <iostream>
using namespace std; 
#include <queue>

int t; 
int k; 

priority_queue<long long, vector<long long>, greater<long long>> pq;

long long solve()
{
    long long result = 0;
    
    while (!pq.empty()) {
        if (pq.size() == 1)
            break; 

        long long c1 = pq.top();
        pq.pop(); 

        long long c2 = pq.top();
        pq.pop(); 

        result += c1 + c2;         

        pq.push(c1 + c2);
    }

    return result; 
}

int main()
{
    cin >> t; 
    for (int i = 0; i < t; i++) {

        cin >> k; 

        for (int j = 0; j < k; j++) {
            int x; 
            cin >> x; 
            pq.push(x); 
        }

        cout << solve() << endl;

        while (!pq.empty())
            pq.pop();
    }
}
