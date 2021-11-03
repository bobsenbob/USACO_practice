/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct path
{
	long long target;
	long long length;
	path() {}
	path(long long t, long long l) : target(t), length(l) {} 
};
vector<long long> cows;
vector<long long> distances;
vector<long long> parent;
vector<long long> passing;
vector<bool> visited;
vector<vector<path>> adj;
vector<vector<long long>> dijkstras;
struct compareD{
	bool operator() (const long long &a, const long long &b){
		return distances[a] > distances[b];
	}
};
long long back_DFS(long long start){
	passing[start] = cows[start];
	for (long long i = 0; i < dijkstras[start].size(); i++){
		if (dijkstras[start][i] != parent[start])
			passing[start] += back_DFS(dijkstras[start][i]);
	}
	return passing[start];
}
void printV(vector<long long> a){
	for (int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("shortcut.in", "r", stdin); freopen("shortcut.out", "w", stdout);
	long long N, M, T, a, b, c, curr;
	long long rv = 0;
	cin >> N >> M >> T;
	cows = vector<long long>(N);
	distances = vector<long long>(N, INT_MAX);
	parent = vector<long long>(N, -1);
	passing = vector<long long>(N);
	visited = vector<bool>(N, false);
	adj = vector<vector<path>>(N, vector<path>(0));
	dijkstras = vector<vector<long long>>(N, vector<long long>(0));
	priority_queue<long long, vector<long long>, compareD> next;
	for (long long i = 0; i < N; i++)
		cin >> cows[i];
	for (long long i = 0; i < M; i++){
		cin >> a >> b >> c;
		adj[a - 1].push_back(path(b - 1, c));
		adj[b - 1].push_back(path(a - 1, c));
	}
	distances[0] = 0;
	next.push(0);
	for (;next.size() > 0;){
		curr = next.top();
		next.pop();
		if (visited[curr])
			continue;
		visited[curr] = true;
		for (long long i = 0; i < adj[curr].size(); i++){
			if (!visited[adj[curr][i].target]){
				if (distances[curr] + adj[curr][i].length < distances[adj[curr][i].target]){
					distances[adj[curr][i].target] = distances[curr] + adj[curr][i].length;
					parent[adj[curr][i].target] = curr;
					next.push(adj[curr][i].target);
				}
				else if (distances[curr] + adj[curr][i].length == distances[adj[curr][i].target]){
					if (curr < parent[adj[curr][i].target]){
						parent[adj[curr][i].target] = curr;
						next.push(adj[curr][i].target);
					}
				}
			}
		}

		if (curr != 0)
			dijkstras[parent[curr]].push_back(curr);
	}
	printV(distances);
	back_DFS(0);
	for (long long i = 0; i < passing.size(); i++)
		rv = max(rv, (distances[i] - T) * passing[i]);
	cout << rv;
	return 0;
}

