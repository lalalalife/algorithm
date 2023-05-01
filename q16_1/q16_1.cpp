#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 


int n, m; 
int arr[8][8]; 
int temp[8][8];     // 벽 설치한 뒤의 맵 

int dx[] = { -1, 0, 1, 0 }; 
int dy[] = { 0, 1, 0, -1 }; 

int result; 

void virus(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + x; 
        int ny = dy[i] + y; 

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (temp[nx][ny] == 0) {
                temp[nx][ny] = 2;
                virus(nx, ny); 
            }
        }
    }
}

int getScore() {

    int score = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) {
                score++; 
            }
        }
    }
    return score; 
}

void dfs(int count)
{
    if (count == 3) {
        // 3개 벽이 설치되었으면 바이러스 퍼뜨리고
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[i][j] = arr[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j] == 2) {
                    virus(i, j); 
                }
            }
        }

        // 안전영역 계산
        result = max(result, getScore()); 
        return; 
    }

    // 벽 설치 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = 1; 
                count++; 

                dfs(count);             
                arr[i][j] = 0;  // ✔  차례대로 벽을 세워본다
                count--; 
            }
        }
    }
}
int main()
{
    cin >> n >> m; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j]; 
        }
    }

    // 벽 3군데 세우는 모든 경우의 수 
    // 바이러스 퍼뜨리고
    // 안전영역 계산하고 

    dfs(0); 
    cout << result << endl; 
}
