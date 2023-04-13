#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int v; 
vector<int> graph[501]; 
int indegree[501]; 
int times[501]; 


int main()
{
    // 위상정렬
    cin >> v; 

    for (int i = 1; i <= v; i++) {
        int x; 
        cin >> x; 
        times[i] = x;

        while (true) {
            cin >> x; 
            if (x == -1)
                break; 

            indegree[i] += 1; // 진입차수 
            graph[x].push_back(i);             
        }
    }

    // 진입차수 0인 노드 큐에서 꺼내서, 
    // 해당노드와 연결된 간선 제거 (-> 연결된 노드의 진입차수를 마이너스)
    // 노드의 진입차수가 0이라면, 큐에 넣기, 
    vector<int> result(501); 
    for (int i = 1; i <= v; i++) {
        result[i] = times[i]; 
    }


    queue<int> q; // 진입차수가 0인 노드번호 
    for (int i = 1; i <= v; i++) {
        if (indegree[i] == 0) {
            q.push(i); 
        }
    }

    while (!q.empty()) {
        int now = q.front(); 
        q.pop(); 

        //cout << now << ' ';
        
        for (int i = 0; i < graph[now].size(); i++) {

            result[graph[now][i]] = result[now] + times[graph[now][i]]; 
            //result[graph[now][i]] = max(result[graph[now][i]], result[now] + times[graph[now][i]]);  // ✔

            indegree[graph[now][i]] -= 1; 
            if (indegree[graph[now][i]] == 0)
                q.push(graph[now][i]); 
        }
    }

    for (int i = 1; i <= v; i++) {
        cout << result[i] << endl; 
    }
}

