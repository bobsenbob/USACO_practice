/*
ID: david.w4
TASK: perimeter
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct coord {
	int x;
	int y;
	coord() {
	}
	coord(int xpos, int ypos) : x(xpos), y(ypos){}
};
bool inBounds(int N, int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < N);
}
int main()
{
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	int N, rvArea = 0, rvPerimeter = 0, area, perimeter;
	vector<int> xmoves = { 1, -1, 0, 0 };
	vector<int> ymoves = { 0, 0, 1, -1 };
	cin >> N;
	vector<vector<char>> grid(N, vector<char>(N));
	vector<vector<bool>> visited(N, vector<bool>(N));
	queue<coord> next;
	coord a;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> grid[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == '#' && !visited[i][j]) {
				next.push(coord(i, j));
				visited[i][j] = true;
				area = 1;
				perimeter = 0;
				for (; next.size() > 0;) {
					a = next.front();
					next.pop();
					int singlePerimeter = 4;
					for (int k = 0; k < 4; k++) {
						if (inBounds(N, a.x + xmoves[k], a.y + ymoves[k]) && grid[a.x + xmoves[k]][a.y + ymoves[k]] == '#' && !visited[a.x + xmoves[k]][a.y + ymoves[k]]) {
							next.push(coord(a.x + xmoves[k], a.y + ymoves[k]));
							visited[a.x + xmoves[k]][a.y + ymoves[k]] = true;
							area++;
						}
						if (inBounds(N, a.x + xmoves[k], a.y + ymoves[k]) && grid[a.x + xmoves[k]][a.y + ymoves[k]] == '#')
							singlePerimeter--;
					}
					perimeter += singlePerimeter;
				}
				if (area > rvArea) {
					rvArea = area;
					rvPerimeter = perimeter;
				}
				if (area == rvArea)
					rvPerimeter = min(rvPerimeter, perimeter);
				
			}
		}
	}
	cout << rvArea << " " << rvPerimeter << "\n";
	return 0;
}

