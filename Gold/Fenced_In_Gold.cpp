#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> distances;
struct path{
	int target;
	int length;
	path() {}
	path(int t, int l) : target(t), length(l){}
};
struct compareD{
	bool operator()(const path &a, const path &b) {
		return a.length > b.length;
	}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fencedin.in", "r", stdin); freopen("fencedin.out", "w", stdout);
	int A, B, n, m, length, visits = 0, rv = 0;
	cin >> A >> B >> n >> m;
	priority_queue<path, vector<path>, compareD> next;
	path curr;
	int field = (n + 1) * (m + 1);
	vector<int> vertical(n + 2);
	vector<int> horizontal(m + 2);
	vector<vector<path>> adj(field, vector<path>(0));
	vector<bool> visited(field);
	distances = vector<int>(field, INT_MAX);
	vertical[0] = 0;
	vertical[n + 1] = A;
	horizontal[0] = 0;
	horizontal[m + 1] = B;
	for (int i = 1; i <= n; i++)
		cin >> vertical[i];
	for (int i = 1; i <= m; i++)
		cin >> horizontal[i];
	sort (vertical.begin(), vertical.end());
	sort (horizontal.begin(), horizontal.end());
	//divide horizontally
	for (int i = 1; i < vertical.size(); i++){
		length = vertical[i] - vertical[i - 1];
		for (int j = 0; j < m; j++){
			adj[j * (n + 1) + i - 1].push_back(path((j + 1) * (n + 1) + i - 1, length));
			adj[(j + 1) * (n + 1) + i - 1].push_back(path(j * (n + 1) + i - 1, length));
		}
	}
	//divide vertically
	for (int i = 1; i < horizontal.size(); i++){
		length = horizontal[i] - horizontal[i - 1];
		for (int j = 0; j < n; j++){
			adj[(i - 1) * (n + 1) + j].push_back(path((i - 1) * (n + 1) + j + 1, length));
			adj[(i - 1) * (n + 1) + j + 1].push_back(path((i - 1) * (n + 1) + j, length));
		}
	}
	distances[0] = 0;
	next.push(path(0, 0));
	cout << "\n";
	for (;visits < field;){
		curr = next.top();
		next.pop();
		cout << curr.target << "\n";
		if (visited[curr.target])
			continue;
		for(int i = 0; i < adj[curr.target].size(); i++)
			if (!visited[adj[curr.target][i].target] && adj[curr.target][i].length < distances[adj[curr.target][i].target]){
				distances[adj[curr.target][i].target] = adj[curr.target][i].length;
				next.push(adj[curr.target][i]);
			}
		visited[curr.target] = true;
		rv += distances[curr.target];
		visits++;
	}
	cout << rv;
	return 0;
}

