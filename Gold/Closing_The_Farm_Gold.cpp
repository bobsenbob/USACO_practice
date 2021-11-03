
#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> size;
vector<int> order;
vector<bool> active;
vector<vector<int>> adj;
void make_set(int a){
	parent[a] = a;
	size[a] = 1;
}
int find(int a){
	if (parent[a] != a)
		parent[a] = find(parent[a]);
	return parent[a];
}
void merge(int a, int b){
	int fa = find(a), fb = find(b);
	if (fa != fb){
			parent[fa] = fb;
			size[fb] += size[fa];
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);
	int N, M, a, b;
	cin >> N >> M;
	vector<string> ret(N);
	parent = vector<int>(N);
	size = vector<int>(N);
	order = vector<int>(N);
	active = vector<bool>(N, false);
	adj = vector<vector<int>> (N, vector<int>(0));
	for (int i = 0; i < N; i++)
		make_set(i);
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	for (int i = N - 1; i >= 0; i--){
		cin >> order[i];
		order[i]--;
	}
	for (int i = 0; i < order.size(); i++){
		active[order[i]] = true;
		for (int j = 0; j < adj[order[i]].size(); j++)
			if (active[adj[order[i]][j]])
				merge(order[i], adj[order[i]][j]);
		if (size[find(order[i])] == i + 1)
			ret[N - 1 - i] = "YES";
		else
			ret[N - 1 - i] = "NO";
	}
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << "\n";
	return 0;
}

