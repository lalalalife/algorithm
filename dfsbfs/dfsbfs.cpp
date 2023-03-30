#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

void recursive(int i)
{
    if (i == 10)
        return;

    cout << i << "번째 호출 " << endl; 
    recursive(i+1);

    cout << i << "번째 호출 종료" << endl;
}

bool visited[9];
vector<int> graph[9];

void dfs_exam1_dfs(int x)
{    
    visited[x] = true; // 노드 방문처리
 
    cout << x << ' ';       // 노드 방문 순서 

    // 현재노드와 연결된 다른 노드 방문
    for (int i = 0; i < graph[x].size(); i++) {
        int y = graph[x][i]; 
        if (!visited[y])
            dfs_exam1_dfs(y); 
    }
}

void dfs_exam1()
{    
    // 그럼 이건 인접행렬?
    graph[1].push_back(2); 
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

    dfs_exam1_dfs(1); 
}



void bfs_exam1_bfs(int start)
{
    // bfs 큐에 넣고 방문처리 

    queue<int> q; 
    q.push(start); 
    visited[start] = true;

    while (!q.empty()) {
        int x = q.front(); 
        q.pop(); 
    
        cout << x << ' '; 

        for (int i = 0; i < graph[x].size(); i++) {
            int y = graph[x][i]; 
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

void bfs_exam1()
{
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    graph[2].push_back(1);
    graph[2].push_back(7);

    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);
    graph[4].push_back(5);

    graph[5].push_back(3);
    graph[5].push_back(4);

    graph[6].push_back(7);

    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    graph[8].push_back(1);
    graph[8].push_back(7);

    bfs_exam1_bfs(1);
}

int main()
{
    //recursive(1); 
    //dfs_exam1(); 

    bfs_exam1(); 
}
