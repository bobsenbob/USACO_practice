/*
ID: david.w4
TASK: gates
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct point {
	int x;
	int y;
	point() {}
	point (int xpos, int ypos) : x(xpos), y(ypos){}
};
int main()
{
	
	//freopen("gates.in", "r", stdin);
	//freopen("gates.out", "w", stdout);
	string directions;
	point curr;
	vector<int> xmoves = { 1, -1, 0, 0 };
	vector<int> ymoves = { 0, 0, 1, -1 };
	//
	int N;

	cin >> N;
	cin >> directions;
	//
	int jonx = N + 2, jony = N + 2, rv = 0, dir = 0;
	vector<vector<bool>> farm(2 * N + 4, vector<bool>(2 * N + 4));
	//
	queue<point> next;
	for (int i = 0; i < N; i++) {
		if (directions[i] == 'N')
			dir = 2;
		if (directions[i] == 'S')
			dir = 3;
		if (directions[i] == 'E')
			dir = 0;
		if (directions[i] == 'W')
			dir = 1;
		for (int j = 0; j < 2; j++) {
			jonx += xmoves[dir];
			jony += ymoves[dir];
			farm[jonx][jony] = true;
		}
	}
	for (int i = 0; i < farm.size(); i++) {
		for (int j = 0; j < farm[i].size(); j++) {
			if (farm[i][j]) {
				continue;
			}
				next.push(point(i, j));
				farm[i][j] = true;
				for (; next.size() > 0;)
				{
					curr = next.front();
					next.pop();
					for (int k = 0; k < 4; k++) {
						int newx = curr.x + xmoves[k];
						int newy = curr.y + ymoves[k];
						if (newx >= 0 && newx < farm.size() && newy >= 0 && newy < farm.size() && !farm[newx][newy]) {
							next.push(point(newx, newy));
							farm[newx][newy] = true;
						}
					}

				}
				rv++;
			

		}
	}
	
	cout << rv - 1;
}

