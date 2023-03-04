#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

int n, m, target_s, target_x, target_y;
int graph[200][200]; 

int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = { 0, 0, -1, 1 }; 

class Virus {
public:
    int index; 
    int second; 
    int x; 
    int y; 
    Virus(int index, int second, int x, int y) {
        this->index = index; 
        this->second = second; 
        this->x = x; 
        this->y = y; 
    }

    bool operator<(Virus& other) {
        return this->index < other.index; 
    }

};
vector<Virus> viruses; 

int main()
{    
    cin >> n >> m; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {            
            cin >> graph[i][j];
            
            if (graph[i][j] != 0) {
                viruses.push_back(Virus(graph[i][j], 0, i, j));
            }
        }
    }
    cin >> target_s >> target_x >> target_y;

    sort(viruses.begin(), viruses.end());
    queue<Virus> q; 
    for (int i = 0; i < viruses.size(); i++) {
        q.push(viruses[i]);
    }

    while (!q.empty()) {

        Virus virus = q.front(); 
        q.pop(); 

        if (virus.second == target_s)
            break; 

        for (int i = 0; i < 4; i++) {
            int nx = virus.x + dx[i]; 
            int ny = virus.y + dy[i]; 

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (graph[nx][ny] == 0) {
                    graph[nx][ny] = virus.index;   // 전파
                    q.push(Virus(virus.index, virus.second + 1, nx, ny)); 
                }
            }
        }
    }

    cout << graph[target_x - 1][target_y - 1] << endl; 
}
