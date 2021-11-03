/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct pipe{
	int target;
	int flow;
	int cost;
	pipe() {}
	pipe(int t, int f, int c) : target(t), flow(f), cost(c) {}
};
vector<int> distances;
vector<vector<pipe>> adj;
vector<bool> visited;
int minF = INT_MAX;
struct compareC{
	bool operator() (const int &a, const int &b){
		return distances[a] > distances[b];
	}
};
int dijkstras(int s, int t){
	int curr;
	priority_queue<int, vector<int>, compareC> next;
	distances = vector<int> (1000, INT_MAX);
	visited = vector<bool> (1000, false);
	distances[s] = 0;
	next.push(s);
	for (;next.size() > 0;){
		curr = next.top();
		next.pop();
		if (visited[curr])
			continue;
		if (curr == t)
			return distances[t];
		for (int i = 0; i < adj[curr].size(); i++)
			if (!visited[adj[curr][i].target] && distances[curr] + adj[curr][i].cost < distances[adj[curr][i].target]){
				distances[adj[curr][i].target] = distances[curr] + adj[curr][i].cost;
				next.push(adj[curr][i].target);
		}
		visited[curr] = true;
	}
	return -1;
}
set<int> flows;
void removeFlow(int f){
	for (int i = 0; i < adj.size(); i++)
		for (int j = 0; j < adj[i].size(); j++)
			if (adj[i][j].flow == f)
				adj[i].erase(adj[i].begin() + j);
	flows.erase(flows.begin());
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("pump.in", "r", stdin); freopen("pump.out", "w", stdout);
	int N, M, a, b, c, f;
	double rv = 0;
	cin >> N >> M;
	adj = vector<vector<pipe>> (N, vector<pipe> (0));
	for (int i = 0; i < M; i++){
		cin >> a >> b >> c >> f;
		adj[a - 1].push_back(pipe(b - 1, f, c));
		adj[b - 1].push_back(pipe(a - 1, f, c));
		flows.insert(f);
	}
	for (;true;){
		int c = dijkstras(0, N - 1);
		//cout << c << "\n";
		if (c == -1)
			break;
		rv = max(rv, 1000000 * (double)*flows.begin() / (double) c);
		removeFlow(*flows.begin());
	}
	cout << (int)rv;
	return 0;
}

