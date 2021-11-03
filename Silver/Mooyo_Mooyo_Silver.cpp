/*
ID: david.w4
TASK: mooyomooyo
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> board;
vector<vector<bool>> visited;
vector<vector<bool>> dvisited;
vector<int> xmoves = {1, -1, 0, 0};
vector<int> ymoves = {0, 0, 1, -1};
bool final = false;
void printBoard() {
	for (int i = board.size() - 1; i >= 0; i--) {
		for (int j = 0; j < 10; j++)
			cout << board[i][j];
		cout << "\n";
	}
}
void fall(int x, int y) {
	int color = board[y][x];
	board[y][x] = 0;
	for (; y > 0 && board[y - 1][x] == 0;) {
		y--;
	}
	board[y][x] = color;
}
void applyGravity() {
	for (int i = 1; i < board.size(); i++)
		for (int j = 0; j < 10; j++) {
			if (board[i][j] != 0 && board[i - 1][j] == 0)
				fall(j, i);
		}
}
bool valid(int x, int y){
	return (x >= 0 && x < 10 && y >= 0 && y < board.size());
}
int visit(int x, int y){
	int rv = 1;
	visited[y][x] = true;
	for (int i = 0; i < 4; i++){
		if (valid(x + xmoves[i], y + ymoves[i]) && !visited[y + ymoves[i]][x + xmoves[i]] && board[y + ymoves[i]][x + xmoves[i]] == board[y][x])
			rv += visit(x + xmoves[i], y + ymoves[i]);
	}
	return rv;
}
void destroy(int x, int y){
	dvisited[y][x] = true;
		for (int i = 0; i < 4; i++){
			if (valid(x + xmoves[i], y + ymoves[i]) && !dvisited[y + ymoves[i]][x + xmoves[i]] && board[y + ymoves[i]][x + xmoves[i]] == board[y][x])
				destroy(x + xmoves[i], y + ymoves[i]);
	}
	board[y][x] = 0;
}
int main()
{
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
	int N, K;
	string a;
	cin >> N >> K;
	board = vector<vector<int>>(N, vector<int>(10));
	for (int i = N - 1; i >= 0; i--) {
		cin >> a;
		for (int j = 0; j < 10; j++) {
			board[i][j] = a[j] - 48;
		}
	}
	//applyGravity();
	for (;!final;){
		final = true;
		//printBoard();
		visited = vector<vector<bool>>(N, vector<bool>(10));
		dvisited = vector<vector<bool>>(N, vector<bool>(10));
		for (int i = 0; i < board.size(); i++){
			for (int j = 0; j < 10; j++){
				if (!visited[i][j] && board[i][j] != 0){
					if (K <= visit(j, i)){
						destroy(j, i);
						final = false;
					}
				}
			}
		}
		applyGravity();
	}
	printBoard();
	system("pause");
	return 0;
}

