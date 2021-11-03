/*
ID: david.w4
TASK: pails
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int X, Y, K, M;
vector<vector<bool>> visited;
struct state{
	int first;
	int second;
	int moves;
	state() {}
	state(int bucket1, int bucket2, int m) : first(bucket1), second(bucket2), moves(m) {}
};
state fill(state a, int index){
	if (index == 1)
		return state(X, a.second, a.moves + 1);
	else
		return state(a.first, Y, a.moves + 1);
}
state empty(state a, int index){
	if (index == 1)
		return state(0, a.second, a.moves + 1);
	else
		return state(a.first, 0, a.moves + 1);
}
state transfer(state a, int from){
	if (from == 1)
		return state(a.first - min(a.first, Y - a.second), a.second + min(a.first, Y - a.second), a.moves + 1);
	else
		return state(a.first + min(a.second, X - a.first), a.second - min(a.second, X - a.first), a.moves + 1);
}
/*int DFS(state a, int moves){
	visited[a.first][a.second] = true;
	state temp;
	int minimum = abs(M - (a.first + a.second));
	cout << "DFrv: " << minimum << " move: " << moves << "\n";
	if (moves >= K)
		return minimum;
	for (int i = 1; i < 3; i++){
	temp = fill(a, i);
		if (!visited[temp.first][temp.second]){
			minimum = min(minimum, DFS(temp, moves + 1));
		}
	temp = empty(a, i);
		if (!visited[temp.first][temp.second]){
			minimum = min(minimum, DFS(temp, moves + 1));
		}
	temp = transfer(a, i);
		if (!visited[temp.first][temp.second]){
			minimum = min(minimum, DFS(temp, moves + 1));
		}
}
return minimum;
}*/
int main()
{
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	int rv = 200, moves = 0;
	cin >> X >> Y >> K >> M;
	state curr, temp;
	visited = vector<vector<bool>> (X + 1, vector<bool> (Y + 1, false));
	queue<state> next;
	next.push(state(0, 0, 0));
	visited[0][0] = true;
	for (;next.size() > 0;) {
		curr = next.front();
		next.pop();
		if (curr.moves > K)
			break;
		for (int i = 1; i < 3; i++){
			temp = fill(curr, i);
			if (!visited[temp.first][temp.second]){
				next.push(temp);
				visited[temp.first][temp.second] = true;
			}
			temp = empty(curr, i);
			if (!visited[temp.first][temp.second]){
				next.push(temp);
				visited[temp.first][temp.second] = true;
			}
			temp = transfer(curr, i);
			if (!visited[temp.first][temp.second]){
				next.push(temp);
				visited[temp.first][temp.second] = true;
			}
		}
		rv = min(rv, abs(M - (curr.first + curr.second)));
		//cout << "BFrv: " << rv << " move: " << curr.moves << "\n";
		moves = curr.moves;
	}
	//visited = vector<vector<bool>> (X + 1, vector<bool> (Y + 1, false));
	//cout << rv << "  " <<  DFS(state(0, 0, 0), 0);
	cout << rv;
	//system("pause");
	return 0;
}

