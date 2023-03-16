#include <iostream>
#include <queue>
using namespace std; 

int t, n;
int graph[125][125], d[125][125]; 
int dx[] = { -1, 0, 1, 0 }; 
int dy[] = { 0, -1, 0, 1 }; 

int main()
{    
    cin >> t; 
    for (int i = 0; i < t; i++) {
        cin >> n; 
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                cin >> graph[x][y];
            }
        }
        // 테스트 케이스별

        for (int i = 0; i < n; i++) {
            fill(d[i], d[i] + 125, 1e9);
        }

        int x = 0, y = 0; // 시작위치
        priority_queue < pair<int, pair<int, int>>> pq;   // 비용, 좌표
        pq.push({ -graph[x][y], {x, y} }); 
        d[x][y] = graph[x][y]; 

        while (!pq.empty()) {
            // 비용이 가장 적은 노드 정보 꺼내기 
            int dist = -pq.top().first; 
            int x = pq.top().second.first; 
            int y = pq.top().second.second; 
            pq.pop(); 

            // 처리된적이 있는 노드라면 무시 
            if (d[x][y] < dist)
                continue; 

            // 현재노드를 거쳐 이동가능한 다른 노드 확인
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i]; 
                int ny = y + dy[i]; 

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue; 

                int cost = dist + graph[nx][ny]; 
                if (cost < d[nx][ny]) {
                    d[nx][ny] = cost; 
                    pq.push({ -cost, {nx, ny} }); 
                }
            }
        }

        cout << d[n - 1][n - 1] << endl; 
    }
}
