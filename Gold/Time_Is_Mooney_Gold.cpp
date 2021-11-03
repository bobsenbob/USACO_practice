/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct go{
	int target;
	int day;
	go() {}
	go(int t, int d) : target(t), day(d) {}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("time.in", "r", stdin); freopen("time.out", "w", stdout);
	int N, M, C, a, b, rv = 0;
	cin >> N >> M >> C;
	int lim = 999 / C + 2;
	vector<vector<int>> adj(N, vector<int>(0));
	vector<int> earn(N);
	vector<vector<int>> money(N, vector<int>(lim));
	vector<vector<bool>> visited(N, vector<bool>(lim));
	queue<go> next;
	for (int i = 0; i < N; i++)
		cin >> earn[i];
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
	}
	next.push(go(0, 0));
	for (;next.size() > 0;){
		go curr = next.front();
		next.pop();
		if (curr.day == lim - 1)
			continue;
		for (int i = 0; i < adj[curr.target].size(); i++){
			money[adj[curr.target][i]][curr.day + 1] = max(money[adj[curr.target][i]][curr.day + 1], money[curr.target][curr.day] + earn[adj[curr.target][i]]);
			if (!visited[adj[curr.target][i]][curr.day + 1]){
				next.push(go(adj[curr.target][i], curr.day + 1));
				visited[adj[curr.target][i]][curr.day + 1] = true;
			}
		}
	}
	for (int i = 0; i < money[0].size(); i++)
		rv = max(rv, money[0][i] - C * (i * i));
	cout << rv;
	return 0;
}

