#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int graph[100][100];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++) {

				if (graph[a][k] == 1 && graph[k][b] == 1)
					graph[a][b] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
}
