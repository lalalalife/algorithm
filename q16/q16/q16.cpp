// q16.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n, m;
int arr[8][8]; 
int temp[8][8]; 

int dx[] = {0, 0, -1, 1 }; 
int dy[] = {-1, 1, 0, 0 }; 

int result; 

void virus(int x, int y) {
    for (int i = 0; i < 4; i++) {       // 상하좌우좌표에 바이러스 전파 
        int nx = x + dx[i]; 
        int ny = y + dy[i]; 
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (temp[nx][ny] == 0) {
                temp[nx][ny] = 2; 
                virus(nx, ny);      // 현재의 nx, ny가 2가 되었으니, 다시 상하좌우에 바이러스 전파 
            }
        }
    }
}

int getScore() {
    int score = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0)
                score++; 
        }
    }

    return score;
}

void dfs(int count) {

    if (count == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[i][j] == arr[i][j];        // 벽 3개 설치한값을 temp 에 복사 
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (temp[i][j] == 2)
                    virus(i, j);            // 바이러스 전파 
            }
        }

        // 안전영역 최대값
        result = max(result, getScore()); 
        return; 
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {           // 바이러스가 이동할 수 있는 곳만 벽을 치는게 아니고 모든 빈칸을 벽으로? 
                arr[i][j] = 1; 
                count++; 
                dfs(count); 
                arr[i][j] = 0;      // 벽 3개 설치하고 나면 최대값 저장해놓고, 다시 다음 벽 세우기 위해 arr, count 초기화 
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

    dfs(0); 

    cout << result << endl;
}
