#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> ranks;
int find(int a){
	if (parent[a] == a)
		return a;
	return find(parent[a]);
}
void merge(int a, int b){
	int fa = find(a), fb = find(b);
	if (fa != fb){
		if (ranks[fa] > ranks[fb])
			parent[fb] = fa;
		else if(ranks[fa] == ranks[fb]){
			parent[fb] = fa;
			ranks[fa]++;
		}
		else
			parent[fa] = fb;

	}
}
struct row{
	int thickness;
	int index;
	//0 is top, 1 is side
	int type;
	row() {}
	row(int t, int i, int ty) : thickness(t), index(i), type(ty) {}
	bool operator<(const row &other) const {
		return thickness < other.thickness;
	}
};
void printV(vector<row> a){
	for (int i = 0; i < a.size(); i++){
		cout << a[i].thickness << " ";
	}
	cout << "\n";
}
void printV(vector<int> a){
	for (int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("fencedin.in", "r", stdin); freopen("fencedin.out", "w", stdout);
	int A, B, n, m, ti = 0, si = 0;
	long long rv = 0;
	cin >> A >> B >> n >> m;
	int field = (n + 1) * (m + 1);
	vector<int> vertical(n + 2);
	vector<int> horizontal(m + 2);
	vector<row> rows(n + m + 2);
	parent = vector<int>(field);
	ranks = vector<int>(field);
	vertical[0] = 0;
	vertical[n + 1] = A;
	horizontal[0] = 0;
	horizontal[m + 1] = B;
	for (int i = 1; i <= n; i++)
		cin >> vertical[i];
	for (int i = 1; i <= m; i++)
		cin >> horizontal[i];
	sort(vertical.begin(), vertical.end());
	sort(horizontal.begin(), horizontal.end());
	//divide horizontally
	for (int i = 1; i < vertical.size(); i++){
		rows[i - 1] = row(vertical[i] - vertical[i - 1], i - 1, 0);
	}
	for (int i = 1; i < horizontal.size(); i++){
		rows[i - 2 + vertical.size()] = row(horizontal[i] - horizontal[i - 1], i - 1, 1);
	}
	for (int i = 0; i < parent.size(); i++)
		parent[i] = i;
	sort(rows.begin(), rows.end());
	for (int i = 0; i < rows.size(); i++){
		if (rows[i].type == 0){
			for (int j = rows[i].index; j < field - (n + 1); j += n + 1)
				if (find(j) != find(j + n + 1)){
					rv += rows[i].thickness;
					merge(j, j + n + 1);
					//cout << "merging: " << j << " " << j + n + 1 << " for " << rows[i].thickness << "\n";
				}
		}
		else {
			for (int j = rows[i].index * (n + 1); j < (rows[i].index + 1) * (n + 1) - 1; j++){
				if (find(j) != find(j + 1)){
					rv += rows[i].thickness;
					merge(j, j + 1);
					//cout << "merging: " << j << " " << j + 1 << " for " << rows[i].thickness << "\n";
				}
			}
		}

	}
	cout << rv;
	return 0;
	
}

