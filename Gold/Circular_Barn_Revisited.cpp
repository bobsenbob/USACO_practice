/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct state{
	int last;
	int distance;
	state(){}
	state(int l, int d) : last(l), distance(d) {}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(".in", "r", stdin); freopen(".out", "w", stdout);
	int N, K;
	cin >> N >> K;
	vector<int> rooms(N);
	vector<vector<state>> dp (N, vector<state>(K));
	for (int i = 0; i < N; i++)
		cin >> rooms[i];
	
	return 0;
}

