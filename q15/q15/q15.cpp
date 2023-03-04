// q15.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

int n, m, k, x; 
vector<int> graph[300001];      // 도시 - 연결된 도시 정보 
vector<int> d(300001, -1);      // 모든 도시에 대한 최단거리

int main()
{
    cin >> n >> m >> k >> x; 
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b; 
        graph[a].push_back(b);      // 배열 인덱스는 도시(노드)번호, push된 값은 연결된 도시 번호 
    }

    d[x] = 0;       // 출발하는 도시 x 의 최단거리는 0 

    // BFS 너비우선탐색 수행
    // 1. 탐색 시작 노드를 큐에 삽입하고 방문 처리 
    // 2. 큐에서 노드를 꺼내 해당노드의 인접노드중 방문하지 않은 노드를 모두 큐에 삽입하고 방문처리
    // 3. 2 반복 

    queue<int> q; 
    q.push(x);      // 1. 탐색 시작 노드를 큐에 삽입

    while (!q.empty()) {
        int now = q.front();        // 큐에서 노드를 꺼내
        q.pop(); 

        // 큐에서 꺼낸 노드와 인접한 노드 확인
        for (int i = 0; i < graph[now].size(); i++) {
            int nextNode = graph[now][i]; 
            
            if (d[nextNode] == -1) {        // 인접한 노드를 아직 방문하지 않았다면, 

                d[nextNode] = d[now] + 1;   // 방문처리 및 최단거리값 갱신
                q.push(nextNode);           // 큐에 삽입
            }
        }
    }

    bool check = false; 
    for (int i = 1; i <= n; i++) {
        if (d[i] == k) {
            cout << i << '\n'; 
            check = true; 
        }
    }

    if (!check)
        cout << -1 << '\n'; 

}
