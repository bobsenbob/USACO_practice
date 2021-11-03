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
	//freopen(".in", "r", stdin); freopen(".out", "w", stdout);
	string genome;
	cin >> genome;
	int N = genome.size();
	map<char, int> conv
	vector<vector<int>> dp (N, vector<int>(4));
	//dp[i][j] is # of original sequences for first i letters that ends in j (0 = A, 1 = C, 2 = G, 3 = T);
	for (int i = 0; i < 4; i++)
		dp[0][i] = 1;
	for (int i = 2; i < N; i++){

	}
	return 0;
}

