/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct state{
	vector<int> wins;
	state() : wins(vector<int>(4)) {}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("hps.in", "r", stdin); freopen("hps.out", "w", stdout);
	int N, K;
	cin >> N >> K;
	char a;
	vector<vector<state>>dp (K + 1, vector<state>(N + 1, state()));
	vector<int> john (N + 1);
	vector<vector<int>> ps(N + 1, vector<int>(3));
	//max wins with i swaps for the first j rounds;
	for (int i = 1; i <= N; i++){
		cin >> a;
		//H = 0, P = 1, S = 2
		if (a == 'H')
			john[i] = 0;
		if (a == 'P')
			john[i] = 1;
		if (a == 'S')
			john[i] = 2;
	}
	for (int i = 1; i <= N; i++){
		ps[i] = ps[i - 1];
		ps[i][john[i]]++;
	}
	for (int i = 1; i <= N; i++){
		dp[0][i].wins[0] = ps[i][0];
		dp[0][i].wins[1] = ps[i][1];
		dp[0][i].wins[2] = ps[i][2];
		dp[0][i].wins[3] = max(ps[i][0], max(ps[i][1], ps[i][2]));
	}
	for (int i = 1; i <= K; i++){
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < 3; k++){
				dp[i][j].wins[k] = max(dp[i - 1][j - 1].wins[3], dp[i][j - 1].wins[k]);
				if (john[j] == k)
					dp[i][j].wins[k]++;
			}
			dp[i][j].wins[3] = max(dp[i][j].wins[0], max(dp[i][j].wins[1], dp[i][j].wins[2]));
		}
	}
	cout << dp[K][N].wins[3];
	return 0;
}

