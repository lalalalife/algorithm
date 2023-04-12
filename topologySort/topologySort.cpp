#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int v, e;
vector<int> graph[100001]; 

// 각 노드에 대한 진입차수
int indegree[100001] = { 0, };

void topologySort()
{
    vector<int> result;     // 큐에서 꺼낼때마다 결과저장 
    queue<int> q; 

    for (int i = 1; i <= v; i++) {
        if (indegree[i] == 0)
            q.push(i);      // 진입차수 0 인 노드 큐에 넣기
    }

    while (!q.empty()) {
        int now = q.front(); 
        q.pop(); 
        result.push_back(now); 

        for (int i = 0; i < graph[now].size(); i++) {
            indegree[graph[now][i]] -= 1; 

            if (indegree[graph[now][i]] == 0) {
                q.push(graph[now][i]); 
            }
        }
    }

    // 출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' '; 
    }
    cout << endl; 
}

int main()
{
    // 위상정렬 알고리즘

    cin >> v >> e; 
    for (int i = 0; i < e; i++) {
        int a, b; 
        cin >> a >> b; 
        graph[a].push_back(b); 
        indegree[b] += 1;   // 진입차수 
    }

    topologySort(); 
}
