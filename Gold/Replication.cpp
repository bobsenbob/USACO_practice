/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct query{
	int x;
	int y;
	int step;
	query() {}
	query(int xin, int yin, int s) : x(xin), y(yin), step(s) {}
};
vector<int> xmoves = {1, -1, 0, 0};
vector<int> ymoves = {0, 0, 1, -1};
bool ok(int value, int up){
	return value >= 0 && value < up;
}
void printV2(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++){
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}
void printV2(vector<vector<bool>> a){
	for (int i = 0; i < a.size(); i++){
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(".in", "r", stdin); freopen(".out", "w", stdout);
	char a;
	int N, D;
	int rv = 0;
	cin >> N >> D;
	vector<vector<int>> grid(N, vector<int>(N));
	vector<vector<bool>> visited (N, vector<bool>(N));
	vector<vector<bool>> done (N, vector<bool>(N));
	vector<vector<int>> steps(N, vector<int>(N));
	vector<vector<query>> centers(N * N, vector<query>(0));
	vector<query> line;
	queue<query> come;
	queue<query> next;
	//0 is free, 1 is starting, 2 is rock
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> a;
			if (a == '.')
				grid[i][j] = 0;
			else if (a == 'S'){
				grid[i][j] = 1;
				next.push(query(i, j, 0));
				done[i][j] = true;
			}
			else{
				grid[i][j] = 2;
				come.push(query(i, j, 0));
				visited[i][j] = true;
			}
		}
	}
	while(come.size() > 0){
		query curr = come.front();
		come.pop();
		for (int i = 0; i < 4; i++){
			int movex = curr.x + xmoves[i];
			int movey = curr.y + ymoves[i];
			if(ok(movex, N) && ok(movey, N) && !visited[movex][movey] && grid[movex][movey] != 2){
				visited[movex][movey] = true;
				steps[movex][movey] = curr.step + 1;
				come.push(query(movex, movey, curr.step + 1));
			}
		}
	}
	visited = vector<vector<bool>>(N, vector<bool>(N));
	//multisource BFS to whether each point can hold a center robot or not
	while(next.size() > 0){
		query curr = next.front();
		next.pop();
		if (curr.step / D >= steps[curr.x][curr.y])
			continue;
		//blob of size n can only go on nodes of size n + 1 or larger
		for (int i = 0; i < 4; i++){
			int movex = curr.x + xmoves[i];
			int movey = curr.y + ymoves[i];
			if(ok(movex, N) && ok(movey, N) && !done[movex][movey] && curr.step / D < steps[movex][movey]){
				done[movex][movey] = true;
				next.push(query(movex, movey, curr.step + 1));
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			if (done[i][j]){
				centers[steps[i][j]].push_back(query(i, j, 0));
				visited[i][j] = true;
			}
		}
	for (int i = N * N - 1; i > 1; i--){
		for (int j = 0; j < centers[i].size(); j++){
			line.push_back(centers[i][j]);
		}
		for (int j = 0; j < line.size(); j++){
			query curr = line[j];
			for (int k = 0; k < 4; k++){
				int movex = curr.x + xmoves[k];
				int movey = curr.y + ymoves[k];
				if(ok(movex, N) && ok(movey, N) && !visited[movex][movey] && grid[movex][movey] != 2){
					visited[movex][movey] = true;
					centers[i - 1].push_back(query(movex, movey, 0));
				}
			}
		}
		line.clear();
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (visited[i][j])
				rv++;
	//printV2(steps);
	//cout << "\n";
	//printV2(done);
	//cout <<"\n";
	//printV2(visited);
	cout << rv;
	return 0;
}

