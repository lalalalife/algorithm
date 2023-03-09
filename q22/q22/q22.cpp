// q22.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

class Node {
public:
    int pos1X; 
    int pos1Y;
    int pos2X;
    int pos2Y;

    Node(int pos1X, int pos1Y, int pos2X, int pos2Y) {
        this->pos1X = pos1X; 
        this->pos1Y = pos1Y;
        this->pos2X = pos2X;
        this->pos2Y = pos2Y;
    }

    void toString()
    {
        cout << pos1X + ", " + pos1Y << endl;
        cout << pos2X + ", " + pos2Y << endl;
    }
};

vector<Node> getNextPos(Node pos, vector<vector<int>> board) {
    // 상하좌우, 회전으로 이동가능한 모든 위치좌표를 찾아서 반환

    vector<Node> nextPos; 
    int dx[] = { -1, 1, 0, 0 }; 
    int dy[] = { 0, 0, -1, 1 }; 
    for (int i = 0; i < 4; i++) {
        int pos1NextX = pos.pos1X + dx[i]; 
        int pos1NextY = pos.pos1Y + dy[i]; 
        int pos2NextX = pos.pos2X + dx[i];
        int pos2NextY = pos.pos2Y + dy[i];

        // 상하좌우 이동이 가능하다면 이동위치 저장 
        if (board[pos1NextX][pos1NextY] == 0 && board[pos2NextX][pos2NextY] == 0) {
            nextPos.push_back(Node(pos1NextX, pos1NextY, pos2NextX, pos2NextY));            
        }
    }

    int hor[] = { -1, 1 };
    if (pos.pos1X == pos.pos2X) {
        for (int i = 0; i < 2; i++) { // 위쪽으로 회전하거나, 아래쪽으로 회전
            // 위쪽 혹은 아래쪽 두 칸이 모두 비어 있다면
            if (board[pos.pos1X + hor[i]][pos.pos1Y] == 0 && board[pos.pos2X + hor[i]][pos.pos2Y] == 0) {
                nextPos.push_back(Node(pos.pos1X, pos.pos1Y, pos.pos1X + hor[i], pos.pos1Y));
                nextPos.push_back(Node(pos.pos2X, pos.pos2Y, pos.pos2X + hor[i], pos.pos2Y));
            }
        }
    }
    // 현재 로봇이 세로로 놓여 있는 경우
    int ver[] = { -1, 1 };
    if (pos.pos1Y == pos.pos2Y) {
        for (int i = 0; i < 2; i++) { // 왼쪽으로 회전하거나, 오른쪽으로 회전
            // 왼쪽 혹은 오른쪽 두 칸이 모두 비어 있다면
            if (board[pos.pos1X][pos.pos1Y + ver[i]] == 0 && board[pos.pos2X][pos.pos2Y + ver[i]] == 0) {
                nextPos.push_back(Node(pos.pos1X, pos.pos1Y, pos.pos1X, pos.pos1Y + ver[i]));
                nextPos.push_back(Node(pos.pos2X, pos.pos2Y, pos.pos2X, pos.pos2Y + ver[i]));
            }
        }
    }

    return nextPos; 
}

int solution(vector<vector<int>> board) {
    // 외곽에 벽(1)을 두는 형태로 
    int n = board.size(); 
    vector<vector<int>> newBoard(n + 2, vector<int>(n + 2, 1)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newBoard[i + 1][j + 1] = board[i][j]; 
        }
    }

    // 너비우선탐색
    queue<pair<Node, int>> q; 
    vector<Node> visited; 
    Node pos = Node(1, 1, 1, 2);    // 시작위치
    q.push({pos, 0});
    visited.push_back(pos);     // 방문처리 

    while (!q.empty()) {
        Node pos = q.front().first; 
        int cost = q.front().second; 
        q.pop(); 

        if ((pos.pos1X == n && pos.pos1Y == n) || (pos.pos2X == n && pos.pos2Y == n)) {

            return cost; 
        }

        // 현재 위치에서 상하좌우, 회전으로 이동가능한 위치 모두 확인
        vector<Node> nextPos = getNextPos(pos, newBoard); 

        for (int i = 0; i < nextPos.size(); i++) {
            bool check = true; 
            Node pos = nextPos[i]; 

            for (int j = 0; j < visited.size(); j++) {
                if (pos.pos1X == visited[j].pos1X && pos.pos1Y == visited[j].pos1Y &&
                    pos.pos2X == visited[j].pos2X && pos.pos2Y == visited[j].pos2Y) {
                    // 이동하려는 좌표에 방문한적이 있는지 체크
                    check = false; 
                    break; 
                }
            }

            if (check) {
                // 방문한적이 없는 곳이라면
                q.push({ pos, cost + 1 }); 

                cout << pos.pos1X << "," << pos.pos1Y << "/" << pos.pos2X << "," << pos.pos2Y << endl;
                cout << "cost : " << cost + 1 << endl ; 

                visited.push_back(pos); 
            }
        }
    }

    return 0; 
}

int main()
{
    vector<vector<int>> v = {
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0},
    }; 

    cout << solution(v); 
}

