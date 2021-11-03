/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct query{
	int k;
	int v;
	int o;
	query() {}
	query(int kp, int vp, int op) : k(kp), v(vp), o(op) {}
	bool operator<(query other)const
	{
		return k > other.k;
	}
};
struct connect{
	int a;
	int b;
	int r;
	connect() {}
	connect(int ap, int bp, int rp) : a(ap), b(bp), r(rp) {}
	bool operator<(connect other)const
	{
		return r > other.r;
	}
};
struct node{
	int size;
	node() {}
	node(int s) : size(s) {}
};
void printV(vector<int> a){
	for (int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}
vector<node> nodes;
vector<connect> connections;
vector<query> queries;
vector<int> finder;
int find(int a){
//cout << a << "f\n";
if (finder[a] == a)
	return a;
else
	return find(finder[a]);
finder[a] = finder[finder[a]];
};
void merge(int a, int b){
	//cout << a << "\n";
	//printV(finder);
	int sb = nodes[find(b)].size;
	//cout << "n";
	nodes[find(a)].size += sb;
	finder[find(b)] = finder[find(a)];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("mootube.in", "r", stdin); freopen("mootube.out", "w", stdout);
	int N, Q, a, b, r, cit = 0;
	cin >> N >> Q;
	nodes = vector<node> (N, node(1));
	connections = vector<connect> (N - 1);
	queries = vector<query> (Q);
	vector<int> ans(Q);
	finder = vector<int> (N);
	for (int i = 0; i < N; i++)
		finder[i] = i;
	for (int i = 0; i < N - 1; i++){
		cin >> a >> b >> r;
		connections[i] = connect(a - 1, b - 1, r);
	}
	sort(connections.begin(), connections.end());
	for (int i = 0; i < Q; i++){
		cin >> r >> a;
		queries[i] = query(r, a - 1, i);
	}
	sort(queries.begin(), queries.end());
	for (int i = 0; i < queries.size(); i++){
		//cout << i;
		for (;cit < connections.size() && connections[cit].r >= queries[i].k; cit++){
				merge(connections[cit].a, connections[cit].b);
		}
		ans[queries[i].o] = nodes[find(queries[i].v)].size - 1;
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
	return 0;
}

