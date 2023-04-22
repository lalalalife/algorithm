#include<vector>
#include <iostream>

using namespace std; 



void rotate(vector<vector<int>>& key)
{
    // 90도 회전
    // x, y => a, b
    // a == m-1-y
    // b == x
    int m = key.size(); 

    vector<vector<int>> temp = key;
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < m; y++) {
            temp[x][y] = key[m - 1 - y][x];
        }
    }
    key = temp;
}

bool isUnLock(int n, vector<vector<int>> newLock)
{
    int len = newLock.size() / 3; 

    for (int x = len; x < len*2; x++) {
        for (int y = len; y < len*2; y++) {
            if (newLock[x][y] != 1)
                return false; 
        }
    }

    return true; 
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) 
{
    int m, n;
    n = lock.size(); 
    m = key.size(); 

    // 자물쇠 크기 키우기 기존사이즈보다 위아래, 양옆 하나씩 더 놓기 
    // 그럼 원래 사이즈의 3배 
    vector<vector<int>> newLock(n * 3, vector<int>(n*3));   // 행, 열
    
    // 커진 자물쇠에 기존 자물쇠 초기값
    for (int i = n; i < n * 2; i++) {
        for (int j = n; j < n * 2; j++) {
            newLock[i][j] = lock[i - n][j - n]; 
        }
    }

    // key배열의 value와 newLock배열의 value를 더해서, 
    // lock 배열의 전체 value가 1인지 확인하기 
    for (int r = 0; r < 4; r++) 
    {
        rotate(key);

        for (int x = 0; x < n*2; x++) {
            for (int y = 0; y < n*2; y++) {                
             
                // 자물쇠 + 열쇠
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        newLock[x + i][y + j] += key[i][j]; 
                    }
                }

                if (isUnLock(n, newLock))
                    return true;
                else {
                    // 원상복구
                    for (int i = 0; i < m; i++) {
                        for (int j = 0; j < m; j++) {
                            newLock[x + i][y + j] -= key[i][j];
                        }
                    }
                }
            }        
        }
    }

    
    return false;
}



int main()
{
    vector<vector<int>> key;
    key.push_back({0, 0, 0});
    key.push_back({ 1, 0, 0 }); 
    key.push_back({ 0, 1, 1 }); 
    
    vector<vector<int>> lock; 
    lock.push_back({ 1, 1, 1 }); 
    lock.push_back({ 1, 1, 0 });
    lock.push_back({ 1, 0, 1 });

    solution(key, lock) ? cout << "true" : cout << "false"; 

}

