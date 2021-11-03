/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int T, A, B, rv = 0;
vector<vector<bool>> visited;
bool ok(int a, int used){
	return a >= 0 && a <= T && !visited[a][used];
}
void DFS(int start, int used){
	visited[start][used] = true;
	//cout << start;
	rv = max(rv, start);
	if (ok(start + A, used))
		DFS(start + A, used);
	if (ok(start + B, used))
		DFS(start + B, used);
	if (ok(start / 2, used) && !used)
		DFS(start / 2, 1); 
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("feast.in", "r", stdin); freopen("feast.out", "w", stdout);
	cin >> T >> A >> B;
	visited = vector<vector<bool>>(T + 1, vector<bool>(2));
	DFS(0, 0);
	cout << rv;
	return 0;
}

