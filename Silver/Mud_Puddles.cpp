#include <bits/stdc++.h>
using namespace std;
vector<int> xmoves{1, -1, 0, 0};
vector<int> ymoves{0, 0, 1, -1};
vector<vector<bool>> grid(1001, vector<bool>(1001));
vector<vector<bool>> visited(1001, vector<bool>(1001));
bool in(int x, int y){
	return x >= 0 && x < 1001 && y >= 0 && y < 1001 && !grid[x][y] && !visited[x][y];
}
struct turn{
int x;
int y;
int steps;
turn() {}
turn(int xp, int yp, int s) : x(xp), y(yp), steps(s) {}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int bx, by, N, a, b;
	turn curr;
	queue<turn> next;
	cin >> bx >> by >> N;
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		grid[a + 500][b + 500] = true;
	}
	//bfs
	next.push(turn(500, 500, 0));
	visited[500][500] = true;
	for (;next.size() > 0;){
		curr = next.front();
		next.pop();
		if (curr.x == bx + 500 && curr.y == by + 500){
			cout << curr.steps;
			break;
		}
		for (int i = 0; i < 4; i++){
			if (in(curr.x + xmoves[i], curr.y + ymoves[i])){
				next.push(turn(curr.x + xmoves[i], curr.y + ymoves[i], curr.steps + 1));
				visited[curr.x + xmoves[i]][curr.y + ymoves[i]] = true;
			}
		}
	}
	return 0;
}

