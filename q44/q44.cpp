#include <iostream>
#include <queue>

using namespace std;

int n; 
int parent[100001]; 
vector<pair<int, pair<int, int>>> v; 
int result; 

int findParent(int x) {
    if (parent[x] == x)
        return x; 
    return parent[x] = findParent(parent[x]); 
}

void unionParent(int a, int b) {
    a = findParent(a); 
    b = findParent(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b; 
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<pair<int, int>> x;
    vector<pair<int, int>> y;
    vector<pair<int, int>> z;

    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back({ a, i });
        y.push_back({ b, i });
        z.push_back({ c, i });
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    // x , x+1 사이의 비용
    for (int i = 0; i < n - 1; i++) {
        v.push_back({ x[i + 1].first - x[i].first, {x[i].second, x[i + 1].second} });
        v.push_back({ y[i + 1].first - y[i].first, {y[i].second, y[i + 1].second} });
        v.push_back({ z[i + 1].first - z[i].first, {z[i].second, z[i + 1].second} });
    }

    // 비용순으로 정렬 
    sort(v.begin(), v.end());

    //
    for (int i = 0; i < v.size(); i++) {
        int cost = v[i].first; 
        int a = v[i].second.first; 
        int b = v[i].second.second; 

        if (findParent(a) != findParent(b)) {
            unionParent(a, b); 
            result += cost; 
        }
    }

    cout << result << endl; 

}
