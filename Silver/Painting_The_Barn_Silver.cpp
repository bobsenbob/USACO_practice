/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
void printV(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++){
		for (int j = 0; j < a[i].size(); j++){
			if (a[i][j] >= 0)
				cout << " ";
			cout << a[i][j] << " ";
		}
		cout << "\n";
}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("paintbarn.in", "r", stdin); freopen("paintbarn.out", "w", stdout);
	int N, K, l, b, r, t, c = 0, rv = 0, d = 1001;
	cin >> N >> K;
	vector<vector<int>> base(d, vector<int>(d));
	vector<vector<int>> wall(d, vector<int>(d));
	//setting up prefixes
	for (int i = 0; i < N; i++){
		cin >> l >> b >> r >> t;
		for (int j = l; j < r; j++){
			base[b][j]++;
			base[t][j]--;;
		}
	}
	//printV(base);
	//cout << "\n";
	for (int i = 0; i < d; i++){
		for (int j = 0; j < d; j++){
			c += base[j][i];
			wall[j][i] = c;
		}
	}
	//printV(wall);
	for (int i = 0; i < wall.size(); i++)
		for (int j = 0; j < wall[i].size(); j++)
			if (wall[i][j] == K)
				rv++;
	cout << rv << "\n";
	return 0;
}

