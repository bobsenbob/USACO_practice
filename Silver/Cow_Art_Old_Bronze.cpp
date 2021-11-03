/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> painting;
vector<vector<bool>> visited;
vector<int> xmoves{1, -1, 0, 0};
vector<int> ymoves{0, 0, 1, -1};
bool inBounds(int x, int y){
	return x >= 0 && x < painting.size() && y >= 0 && y < painting.size();
}
void DFS(int x, int y){
	visited[x][y] = true;
	for (int i = 0; i < 4; i++){
		if (inBounds(x + xmoves[i], y + ymoves[i]) && !visited[x + xmoves[i]][y + ymoves[i]] && painting[x + xmoves[i]][y + ymoves[i]] == painting[x][y])
			DFS(x + xmoves[i], y + ymoves[i]);
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowart.in", "r", stdin); freopen("cowart.out", "w", stdout);
	int N, human = 0, cow = 0;
	string line;
	cin >> N;
	painting = vector<vector<char>> (N, vector<char>(N));
	visited = vector<vector<bool>> (N, vector<bool>(N));
	for (int i = 0; i < N; i++){
		cin >> line;
		for (int j = 0; j < N; j++){
			painting[i][j] = line[j];
		}
	}
	//human dfs
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j]){
				DFS(i, j);
				human++;
			}
	visited = vector<vector<bool>> (N, vector<bool>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (painting[i][j] == 'G')
				painting[i][j] = 'R';
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j]){
				DFS(i, j);
				cow++;
			}
	cout << human << " " << cow << "\n";
	return 0;
}

