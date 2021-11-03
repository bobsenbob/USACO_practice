/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct cow{
	int talent;
	int weight;
	cow() {}
	cow(int t, int w) : talent(t), weight(w) {}
	bool operator< (const cow &other)const{
		return weight < other.weight;
	}
};
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
	//freopen("talent.in", "r", stdin); freopen("talent.out", "w", stdout);
	int N, W, talent, weight, tt = 0, tw = 0;
	cin >> N >> W;
	vector<cow> cows(N);
	vector<vector<int>> dp(N + 1, vector<int>(W));
	for (int i = 0; i < N; i++){
		cin >> weight >> talent;
		cows[i] = cow(talent, weight);
		tt += talent;
		tw += weight;
	}
	cow currmax = cow(tt, tw);
	sort(cows.begin(), cows.end());
	for (int w = 0; w < W; w++)
		dp[0][w] = 0;
	for (int i = 1; i <= N; i++){
		for (int w = 0; w < W; w++){
			if (i == 0 || w == 0)
				dp[i][w] = 0;
			else if (w >= cows[i - 1].weight)
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - cows[i - 1].weight] + cows[i - 1].talent);
			else
				dp[i][w] = dp[i - 1][w];
		}
		for (int w = 0; w < W; w++){
			if (w + cows[i - 1].weight >= W && dp[i - 1][w] != 0){
				cow d = cow(dp[i - 1][w] + cows[i - 1].talent, w + cows[i - 1].weight);
				if (d.talent * currmax.weight >= currmax.talent * d.weight)
					currmax = d;
			}
		}

	}
	cout << (int)(((double)currmax.talent)/((double)currmax.weight) * 1000);
	return 0;
}

