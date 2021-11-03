/*
ID: david.w4
TASK: lightson
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct Room {
	int x;
	int y;
	Room() {}
	Room(int posx, int posy) : x(posx), y(posy) {}
};
bool inBounds(int x, int y, int N) {
	return (x >= 0 && y >= 0 && x < N && y < N);
}
int main()
{
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	int N, M, rv = 1;
	cin >> N >> M;
	vector<int> xmoves = { 1, -1, 0, 0 };
	vector<int> ymoves = { 0, 0, 1, -1 };
	vector<Room> swatch(0);
	vector<vector<Room>> row(N, swatch);
	vector<vector<vector<Room> >> switches(N, row);
	vector<bool> falseRow(N, false);
	vector<vector<bool>> visited(N, falseRow);
	vector<vector<bool>> lit(N, falseRow);
	queue<Room> next;
	//starting room is visited and lit
	visited[0][0] = true;
	lit[0][0] = true;
	next.push(Room(0, 0));
	//input all rooms and corresponding switches
	for (int i = 0; i < M; i++) {
		int inX, inY, switchX, switchY;
		cin >> inX >> inY >> switchX >> switchY;
		switches[inX - 1][inY - 1].push_back(Room(switchX - 1, switchY - 1));
	}
	for (; next.size() > 0;) {
		//pops next room
		Room curr = next.front();
		next.pop();
		//cout << "current position room: " << curr.x << ", " << curr.y << "\n";
		for (int i = 0; i < switches[curr.x][curr.y].size(); i++) {
			Room lighting = switches[curr.x][curr.y][i];
			//cout << "n" << "\n";
			if (!lit[lighting.x][lighting.y]) {
				lit[lighting.x][lighting.y] = true;
				for (int j = 0; j < 4; j++) {
					//cout << "n" << "\n";
					int checkx = lighting.x + xmoves[j];
					int checky = lighting.y + ymoves[j];
					//cout << "j" << j << "\n";
					
					if (inBounds(checkx, checky, N) && visited[checkx][checky]) {

						next.push(Room(lighting.x, lighting.y));
						visited[lighting.x][lighting.y] = true;
					}
				}
				rv++;
			}
			
		}
		for (int i = 0; i < 4; i++) {
			int checkx = curr.x + xmoves[i];
			int checky = curr.y + ymoves[i];
			if (inBounds(checkx, checky, N) && lit[checkx][checky] && !visited[checkx][checky]) {
				next.push(Room(checkx, checky));
				visited[checkx][checky] = true;
			}
		}

	}
	cout << rv;
}

