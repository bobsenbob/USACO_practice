/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("snakes.in", "r", stdin); freopen("snakes.out", "w", stdout);
	int N, K, currmax;
	cin >> N >> K;
	vector<vector<int>> dp(K + 1, vector<int>(N + 1, INT_MAX));
	//minimum amount of space wasted with i size changes and the first j groups captured
	vector<int> snakes(N + 1);
	vector<int> ps(N + 1);
	//prefix sums for total snakes
	for(int i = 1; i <= N; i++){
		cin >> snakes[i];
		ps[i] = ps[i - 1] + snakes[i];
	}
	dp[0][0] = 0;
	currmax = 0;
	for (int i = 1; i <= N; i++){
		currmax = max(currmax, snakes[i]);
		dp[0][i] = currmax * (i) - ps[i];
	}
	for (int i = 1; i <= K; i++){
		for (int j = 0; j <= N; j++){
			if (j == 0)
				dp[i][j] = 0;
			else{
				dp[i][j] = dp[i - 1][j];
				currmax = 0;
				for (int k = j - 1; k >= 0; k--){
					int range = ps[j] - ps[k];
					currmax = max(currmax, snakes[k + 1]);
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + currmax * (j - k) - range);
				}
			}
		}
	}
	cout << dp[K][N];
	return 0;
}

