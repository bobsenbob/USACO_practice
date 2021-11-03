/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sp;
vector<vector<int>> timeper;
vector<vector<int>> dp;
vector<vector<int>> ps;
void floydMarshall(){
	for (int k = 0; k < sp.size(); k++)
		for (int i = 0; i < sp.size(); i++)
			for (int j = 0; j < sp[i].size(); j++)
				sp[i][j] = min(sp[i][j], sp[i][k] + sp[k][j]);
}
void printV(vector<int> a){
	for (int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}
void printV2(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++){
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cowmbat.in", "r", stdin); freopen("cowmbat.out", "w", stdout);
	int N, M, K;
	string s;
	cin >> N >> M >> K >> s;
	sp = vector<vector<int>> (M, vector<int>(M));
	dp = vector<vector<int>> (N + 1, vector<int>(M, INT_MAX));
	vector<int> dpm (N + 1, INT_MAX);
	ps = vector<vector<int>> (N + 1, vector<int>(M));
	timeper = vector<vector<int>> (s.length(), vector<int>(M));
	for (int i = 0; i < sp.size(); i++)
		for (int j = 0; j < sp[i].size(); j++)
			cin >> sp[i][j];
	floydMarshall();
	for (int i = 0; i < s.length(); i++)
		for(int j = 0; j < M; j++)
			timeper[i][j] = sp[s[i] - 'a'][j];
	for (int i = 0; i < M; i++){
		dp[0][i] = 0;
		ps[1][i] = timeper[0][i];
	}

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++)
			ps[i][j] = ps[i - 1][j] + timeper[i - 1][j];

	dpm[0] = 0;

	for (int i = 1; i <= N; i++){
		//cout << i << "\n";
		for (int j = 0; j < M; j++){
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + timeper[i - 1][j]);
			if (i - K >= K){
				dp[i][j] = min(dp[i][j], dpm[i - K] + ps[i][j] - ps[i - K][j]);
			}
			//cout << j << "\n";
			dpm[i] = min(dpm[i], dp[i][j]);
		}
		//cout << i << "\n";
		//printV2(dp);
		//cout << "\n";
		//printV(dpm);
		//cout << "\n";
		//printV2(ps);
	}
	cout << dpm[N];
	return 0;
}

