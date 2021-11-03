/*
ID: david.w4
TASK: gravity
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int N, M, sx, sy;
vector<vector<int>> grid;
struct point {
	int x;
	int y;
	int flips;
	bool down;
	point() {}
	point(int xpos, int ypos, int flip, bool dwn) : x(xpos), y(ypos), flips(flip), down(dwn) {}
};
bool valid(point a){
	if (a.down)
		return(a.x >= 0 && a.x < grid[0].size() && a.y > 0 && a.y < grid.size() && grid[a.y][a.x] != 0 || grid[a.y][a.x] == 3);
	else
		return(a.x >= 0 && a.x < grid[0].size() && a.y >= 0 && a.y < grid.size() - 1 && grid[a.y][a.x] != 0 || grid[a.y][a.x] == 3);
}
point fall(point a){
	if (a.down){
		for (;a.y > 0 && grid[a.y - 1][a.x] != 0;a.y--)
			if (grid[a.y][a.x] == 3)
				return a;
	} else {
		for (;a.y < N - 1 && grid[a.y + 1][a.x ]!= 0; a.y++)
			if (grid[a.y][a.x] == 3)
				return a;
	}
	return a;
}
bool doc(point a){
	return (grid[a.y][a.x] == 3);
}
int main()
{
	//freopen("gravity.in", "r", stdin);
	//freopen("gravity.out", "w", stdout);
	cin >> N >> M;
	point pos;
	vector<int> xmoves = {-1, 1};
	grid = vector<vector<int>>(N, vector<int>(M));
	vector<vector<bool>> visited(N, vector<bool>(M));
	deque<point> next;
	for (int i = N - 1; i >= 0; i--){
		string in;
		cin >> in;
		for (int j = 0; j < M; j++) {
			if (in[j] == '.')
				grid[i][j] = 1;
			else if (in[j] == '#')
				grid[i][j] = 0;
			else if (in[j] == 'C') {
				grid[i][j] = 2;
				sx = j, sy = i;
			}
			else if (in[j] == 'D')
				grid[i][j] = 3;
		}
	}
	next.push_back(fall(point(sx, sy, 0, true)));
	visited[sy][sx] = true;
	for (;next.size() > 0;){
		pos = next.front();
		next.pop_front();
		//cout << "x: " << pos.x << " y: " << pos.y << " flips: " << pos.flips << " down: " << pos.down << "\n";
		if (doc(pos)){
			cout << pos.flips;
			return 0;
		}
		for (int i = 0; i < 2; i++) {
			if (valid(point(pos.x + xmoves[i], pos.y, pos.flips, pos.down))) {
				point newp = fall((point(pos.x + xmoves[i], pos.y, pos.flips, pos.down)));
				if (valid(newp) && !visited[newp.y][newp.x]) {
					visited[newp.y][newp.x] = true;
					next.push_front(newp);
				}
			}
		}
		point newp = fall(point(pos.x, pos.y, pos.flips + 1, !pos.down));
		if (valid(newp) && !visited[newp.y][newp.x]) {
			visited[newp.y][newp.x] = true;
			next.push_back(newp);
		}
	}
	cout << -1;
	return 0;
}	


