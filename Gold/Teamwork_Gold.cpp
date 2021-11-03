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
	freopen("teamwork.in", "r", stdin); freopen("teamwork.out", "w", stdout);
	int N, K;
	cin >> N >> K;
	vector<int> cows(N + 1);
	vector<int> dp(N + 1);
	//maximum skill with first i cows;
	for (int i = 1; i <= N; i++)
		cin >> cows[i];
	dp[0] = 0;
	for (int i = 1; i <= N; i++){
		int currmax = 0;
		for (int j = i - 1; j >= 0 && i - j <= K; j--){
			currmax = max(currmax, cows[j + 1]);
			dp[i] = max(dp[i], dp[j] + currmax * (i - j));
		}
	}
	cout << dp[N];
	return 0;
}

