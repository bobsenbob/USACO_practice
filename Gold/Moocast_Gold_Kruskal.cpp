#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
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
bool compareD(const path &a, const path &b){
	return a.length < b.length;
}
int find(int a){
	if (parent[a] == a)
		return a;
	parent[a] = find(parent[a]);
	return parent[a];
}
void merge(int a, int b){
	if (find(a) != find(b))
		parent[find(b)] = find(a);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("moocast.in", "r", stdin); freopen("moocast.out", "w", stdout);
	int N, x, y, connected = 0, rv = 0;
	cin >> N;
	path curr;
	parent = vector<int>(N);
	for (int i = 0; i < N; i++)
		parent[i] = i;
	vector<cow> cows(N);
	vector<path> edges(N * N);
	for (int i = 0; i < N; i++){
		cin >> x >> y;
		cows[i] = cow(x, y);
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			edges[i * N + j] = path(i, j, sqr(cows[j].x - cows[i].x) + sqr(cows[j].y - cows[i].y));
		}
	}
	sort(edges.begin(), edges.end(), compareD);
	for (int i = 0; i < edges.size() && connected < N; i++){
		curr = edges[i];
		if (find(curr.origin) != find(curr.target)){
			merge(curr.origin, curr.target);
			connected++;
			rv = curr.length;
		}
	}
	cout << rv;
	return 0;
}

