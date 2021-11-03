/*
ID: david.w4
TASK: friday
LANG: C++
*/
#include <bits/stdc++.h>;
int check(vector<int> cows, int K) {
	int leaving = 0;
	priority_queue <int, vector<int>, greater<int>> runTimes;
	for (int i = 0; i < K; i++)
		runTimes.push(cows[i]);
	for (int i = K; i < cows.size(); i++) {
		leaving = runTimes.top();
		runTimes.pop();
		leaving += cows[i];
		runTimes.push(leaving);
	}
	for (int i = 0; i < K - 1; i++) {
		runTimes.pop();
	}
	return runTimes.top();
}
int main()
{
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);

	int N, T, l = 0, r, stage = 0;
	cin >> N >> T;
	r = N;
	vector<int> cows(N);
	for (int i = 0; i < N; i++)
		cin >> cows[i];
	for (; l < r;) {
		stage = (l + r) / 2;
		if (check(cows, stage) <= T) {
			
			r = stage;
		}
		else
			l = stage + 1;
	}
	cout << r;
}

