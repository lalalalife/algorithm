
#include <iostream>
#include <vector>
using namespace std;

int n, m; 
int graph[101][101]; 

int main()
{
    cin >> n >> m; 
    
    for (int i = 0; i < 101; i++) {
        fill(graph[i], graph[i] + 101, 1e9);    // 초기비용은 무한값
    }

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if(a == b)
                graph[a][b] = 0;        // 자기자신으로 가는 비용은 0
        }
    }

    for (int i=0; i < m; i++) {
        int a, b, c; 
        cin >> a >> b >> c; 
        if (c < graph[a][b])
            graph[a][b] = c;    // 기존에 입력된 비용보다 새로 입력받은값이 작으면 대체 , 최소비용으로 저장 
    }

    // 점화식 ab = min(ab, ak+kb)
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]); 
            }
        }
    }

    // 출력
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (graph[a][b] == 1e9) {
                cout << 0 << ' '; 
            }
            else {
                cout << graph[a][b] << ' '; 
            }
        }
        cout << '\n';
    }    
}

