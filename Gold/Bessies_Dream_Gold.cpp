/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> rmoves{1, -1, 0, 0};
vector<int> cmoves{0, 0, 1, -1};
struct turn{
	int row;
	int column;
	int smell;
	//-1 is not sliding, rest correspond to their movement index
	int sliding;
	int steps;
	turn() {}
	turn(int r, int c, bool s, int sl, int st) : row(r), column(c), smell(s), sliding(sl), steps(st) {}
};
struct visitNode{
	vector<bool> smell;
	vector<bool> sliding;
	visitNode() : smell(vector<bool>(2, false)), sliding(vector<bool>(2, false)) {}
};
vector<vector<visitNode>> visited;
vector<vector<int>> grid;
bool ok(int row, int column, int smelling){
	//out of bounds or impassable
	if (!(row >= 0 && row < N && column >= 0 && column < M && grid[row][column] != 0))
		return false;
	//piranha tile without smell
	if (grid[row][column] == 3 && smelling != 1)
		return false;
	return true;
	
}
bool inSlide(int row, int column){
	return row >= 0 && row < N && column >= 0 && column < M && grid[row][column] != 0 && grid[row][column] != 3;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("dream.in", "r", stdin); freopen("dream.out", "w", stdout);
	cin >> N >> M;
	turn curr;
	bool found = false;
	grid = vector<vector<int>> (N, vector<int> (M));
	visited = vector<vector<visitNode>> (N, vector<visitNode>(M));
	queue<turn> next;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> grid[i][j];
	next.push(turn(0, 0, 0, - 1, 0));
	visited[0][0].smell[0] = true;
	for (;next.size() > 0;){
		curr = next.front();
		next.pop();
		//checks if bessie has reached destination
		if (curr.row == N - 1 && curr.column == M - 1){
			cout << curr.steps;
			found = true;
			break;
		}
		//if bessie is on an orange tile, apply smell
		if (grid[curr.row][curr.column] == 2)
			curr.smell = 1;
		//if bessie is on a purple tile, remove smell
		if (grid[curr.row][curr.column] == 4)
			curr.smell = 0;
		//sliding from a purple tile
		if (curr.sliding != -1 && grid[curr.row][curr.column] == 4 && inSlide(curr.row + rmoves[curr.sliding], curr.column + cmoves[curr.sliding]) && !visited[curr.row + rmoves[curr.sliding]][curr.column + cmoves[curr.sliding]].sliding[curr.sliding / 2]){
			next.push(turn(curr.row + rmoves[curr.sliding], curr.column + cmoves[curr.sliding], 0, curr.sliding, curr.steps + 1));
			visited[curr.row + rmoves[curr.sliding]][curr.column + cmoves[curr.sliding]].sliding[curr.sliding / 2] = true;
		}
		else {
			//explores surroundings
			for (int i = 0; i < 4; i++){
				//not impassable
				if (ok(curr.row + rmoves[i], curr.column + cmoves[i], curr.smell)){
					if (grid[curr.row + rmoves[i]][curr.column + cmoves[i]] == 4 && !visited[curr.row + rmoves[i]][curr.column + cmoves[i]].sliding[i / 2]){
						next.push(turn(curr.row + rmoves[i], curr.column + cmoves[i], 0, i, curr.steps + 1));
						visited[curr.row + rmoves[i]][curr.column + cmoves[i]].sliding[i / 2] = true;
					}
					else if (grid[curr.row + rmoves[i]][curr.column + cmoves[i]] != 4 && !visited[curr.row + rmoves[i]][curr.column + cmoves[i]].smell[curr.smell]){
						next.push(turn(curr.row + rmoves[i], curr.column + cmoves[i], curr.smell, -1, curr.steps + 1));
						visited[curr.row + rmoves[i]][curr.column + cmoves[i]].smell[curr.smell] = true;
					}
				}
			}
		}
	}
	if (!found)
		cout << -1;
	return 0;
}

