#include <iostream>
#include <queue>
using namespace std;

int n, m; 

vector<pair<int, int>> graph[20001]; 
int d[20001]; 
int start = 1; 

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq; 
    // 시작노드와 비용
    pq.push({ 0, start }); 
    d[start] = 0; 

    while (!pq.empty()) {
        int dist = -pq.top().first; 
        int now = pq.top().second; 
        pq.pop(); 

        if (dist > d[now])
            continue; 

        // 현재노드와 연결된 노드 확인 ✔
        for (int i = 0; i < graph[now].size(); i++) {

            // 현재 노드를 거쳐 다른 노드로 가기 위한 비용
            int cost = dist + graph[now][i].second;
            
            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost; 
                pq.push({ -cost, graph[now][i].first }); 
            }
        }
    }
}

int main()
{
    cin >> n >> m; 
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b; 
        graph[a].push_back({ b, 1 }); // a <-> b 비용 1 
        graph[b].push_back({ a, 1 }); // 양방향
    }

    fill(d, d + 20001, 1e9); 

    dijkstra(start); 

    int maxNode = 0; 
    int maxDistance = 0; 
    vector<int> result; 

    for (int i = 1; i <= n; i++) {
        if (maxDistance < d[i]) {
            maxNode = i; 
            maxDistance = d[i];     // 헛간까지의 거리
            result.clear(); 
            result.push_back(maxNode); 
        }
        else if (maxDistance == d[i]) {
            result.push_back(maxNode);   
        }
    }

    cout << maxNode << ' ' << maxDistance << ' ' << result.size() << '\n'; 
}

