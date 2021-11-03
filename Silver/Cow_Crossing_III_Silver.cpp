/*
ID: david.w4
TASK: countcross
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> visited;
vector<int> xmoves = {1, -1, 0, 0};
vector<int> ymoves = {0, 0, 1, -1};
struct position{
	int x;
	int y;
	position() {}
	position(int xpos, int ypos) : x(xpos), y(ypos) {}
};
struct spot{
	bool cow;
	vector<position> roads;
	spot() : cow(false), roads(vector<position>(0)){}
};
vector<vector<spot>> field;
bool valid(int x, int y){
	return (x >= 0 && x < field.size() && y >= 0 && y < field.size());
}
bool roaded(spot a, int x, int y){
	for (int i = 0; i < a.roads.size(); i++){
		if (x == a.roads[i].x && y == a.roads[i].y)
			return true;
	}
	return false;
}
int visit(int x, int y){
	int rv = 0;
	visited[x][y] = true;
	if (field[x][y].cow)
		rv++;
	for (int i = 0; i < 4; i++){
		if (valid(x + xmoves[i], y + ymoves[i]) && !visited[x + xmoves[i]][y + ymoves[i]] && !roaded(field[x][y], x + xmoves[i], y + ymoves[i]))
			rv += visit(x + xmoves[i], y + ymoves[i]);
	}
	return rv;
}
int main()
{
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);
	int N, K, R, x1, y1, x2, y2, rv = 0;
	cin >> N >> K >> R;
	field = vector<vector<spot>> (N, vector<spot>(N, spot()));
	visited = vector<vector<bool>> (N, vector<bool>(N));
	vector<int> sections(0);
	for (int i = 0; i < R; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		field[x1 - 1][y1 - 1].roads.push_back(position(x2 - 1, y2 - 1));
		field[x2 - 1][y2 - 1].roads.push_back(position(x1 - 1, y1 - 1));
	}
	for (int i = 0; i < K; i++){
		cin >> x1 >> y1;
		field[x1 - 1][y1 - 1].cow = true;
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (!visited[i][j])
				sections.push_back(visit(i, j));
		}
	}
	/*for (int i = 0; i < sections.size(); i++){
		cout << sections[i] << "\n";
	}*/
	for (int i = 0; i < sections.size(); i++){
		for (int j = i + 1; j < sections.size(); j++)
			rv += sections[i] * sections[j];
	}
	cout << rv;
	system("pause");
	return 0;
}

