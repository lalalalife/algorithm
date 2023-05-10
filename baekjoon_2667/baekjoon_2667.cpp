#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n; 
int board[25][25] = { 0, };
int cnt; 
int city; 

bool dfs(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= n)
        return false; 

    if (board[x][y] == 1) {
        board[x][y] = 0; // 방문처리
        cnt++; 

        dfs(x, y - 1); 
        dfs(x, y + 1); 
        dfs(x - 1, y); 
        dfs(x + 1, y); 
        return true; 
    }

    return false; 
}

int main()
{    
    scanf_s("%d", &n); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%1d", &board[i][j]);             
        }
    }


    vector<int> count; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                cnt = 0;
                if (dfs(i, j)) {
                    city++;
                    count.push_back(cnt);
                }
            }            
        }
    }

    sort(count.begin(), count.end()); 

    printf("%d\n", city); 
    
    for (int i = 0; i < count.size(); i++) {
        printf("%d\n", count[i]); 
    }
}
