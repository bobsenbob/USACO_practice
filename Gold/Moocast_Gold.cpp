/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct cow{
	int x;
	int y;
	cow() {}
	cow(int xp, int yp) : x(xp), y(yp) {}
};
struct path{
	int origin;
	int target;
	int length;
	path() {}
	path(int o, int t, int l) : origin(o), target(t), length(l) {}
};
int sqr(int a){
	return a * a;
};
struct compareD{
	bool operator() (const path &a, const path &b){
		return a.length > b.length;
	}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("moocast.in", "r", stdin); freopen("moocast.out", "w", stdout);
	int N, x, y, connected = 0, rv = 0;
	cin >> N;
	path curr;
	vector<cow> cows(N);
	set<int> visited;
	vector<vector<path>> adj(N, vector<path>(0));
	vector<vector<path>> mst(N, vector<path>(0));
	priority_queue<path, vector<path>, compareD> next;
	for (int i = 0; i < N; i++){
		cin >> x >> y;
		cows[i] = cow(x, y);
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			adj[i].push_back(path(i, j, sqr(cows[j].x - cows[i].x) + sqr(cows[j].y - cows[i].y)));
		}
	}
	//prims rooted at 0
	next.push(path(0, 0, 0));
	for (;visited.size() < cows.size();){
		curr = next.top();
		next.pop();
		if (visited.find(curr.target) != visited.end())
			continue;
		for (int i = 0; i < adj[curr.target].size(); i++){
			if (visited.find(adj[curr.target][i].target) == visited.end())
				next.push(path(curr.target, adj[curr.target][i].target, adj[curr.target][i].length));
		}
		mst[curr.origin].push_back(path(curr.origin, curr.target, curr.length));
		visited.insert(curr.target);
	}
	for (int i = 0; i < mst.size(); i++)
		for (int j = 0; j < mst[i].size(); j++)
			rv = max(rv, mst[i][j].length);
	cout << rv;
	return 0;
}

