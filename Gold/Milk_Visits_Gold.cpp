/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int N, M, ceiling, step;
vector<vector<int>> adj;
vector<vector<int>> anc;
vector<vector<int>> marks;
vector<int> milks;
vector<int> onpath;
vector<int> itime;
vector<int> otime;
vector<bool> visited;
map<pair<int, int>, int> onway;
void blDFS(int target, int parent){
	itime[target] = step++;
	anc[target][0] = parent;
	for (int i = 1; i <= ceiling; i++)
		anc[target][i] = anc[anc[target][i - 1]][i - 1];
	for (int i = 0; i < adj[target].size(); i++){
		if (adj[target][i] != parent)
			blDFS(adj[target][i], target);
	}
	otime[target] = step++;
}
bool ancestor(int a, int b){
	return itime[a] <= itime[b] && otime[a] >= otime[b];
}
int lca(int a, int b){
	int l = 0, r = N; 
	if (ancestor(a, b))
		return a;
	if (ancestor(b, a))
		return b;
	for (int i = ceiling; i >= 0; i--) {
        if (!ancestor(anc[a][i], b))
            a = anc[a][i];
    }
    return anc[a][0];
}
void pre(){
	itime = vector<int>(N);
	otime = vector<int>(N);
	ceiling = ceil(log2(N));
	step = 0;
	adj = vector<vector<int>> (N, vector<int>(0));
	anc = vector<vector<int>> (N, vector<int>(ceiling + 1));
}
struct query{
	int a;
	int b;
	int t;
	query() {}
	query(int ap, int bp, int tp) : a(ap), b(bp), t(tp) {}
};
void milkDFS(int start){
	onpath[milks[start]]++;
	visited[start] = true;
	for (int i = 0; i < marks[start].size(); i++){
		onway.insert({make_pair(start, marks[start][i]), onpath[marks[start][i]]});
	}
	for (int i = 0; i < adj[start].size(); i++)
		if (!visited[adj[start][i]])
			milkDFS(adj[start][i]);
	onpath[milks[start]]--;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("milkvisits.in", "r", stdin); freopen("milkvisits.out", "w", stdout);
	int a, b, c;
	cin >> N >> M;
	pre();
	vector<query> queries(M);
	onpath = vector<int>(N);
	visited = vector<bool>(N);
	marks = vector<vector<int>>(N, vector<int>(0));
	milks = vector<int> (N);
	for (int i = 0; i < N; i++){
		cin >> milks[i];
		milks[i]--;
	}
	for (int i = 0; i < N - 1; i++){
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	blDFS(0, 0);
	for (int i = 0; i < M; i++){
		cin >> a >> b >> c;
		marks[a - 1].push_back(c - 1);
		marks[b - 1].push_back(c - 1);
		marks[lca(a - 1, b - 1)].push_back(c - 1);
		queries[i] = query(a - 1, b - 1, c - 1);
	}	milkDFS(0);
	for (int i = 0; i < queries.size(); i++){
		int a1 = onway[make_pair(queries[i].a, queries[i].t)];
		int a2 = onway[make_pair(queries[i].b, queries[i].t)];
		int a3 = onway[make_pair(lca(queries[i].a, queries[i].b), queries[i].t)];
		cout << (a1 + a2 - (2 * a3) + (milks[lca(queries[i].a, queries[i].b)] == queries[i].t) > 0);
	}
	return 0;
}

