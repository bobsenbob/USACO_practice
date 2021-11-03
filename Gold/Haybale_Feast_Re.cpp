/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct bale{
	int flavor;
	int spice;
	bale() {}
	bale(int f, int s) : flavor(f), spice(s) {}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("hayfeast.in", "r", stdin); freopen("hayfeast.out", "w", stdout);
	long long N, M, totalTaste = 0;
	int a, b, l = 0, r = 0, rv = INT_MAX, maxSpicy = 0, maxIndex = 0;
	cin >> N >> M;
	multiset<int> spices;
	vector<bale> bales(N);
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		bales[i] = bale(a, b);
	}
	for (;r < N && l < N;){
		//satisfies taste requirement
		for (;totalTaste < M && r < N; r++){
			totalTaste += bales[r].flavor;
			spices.insert(bales[r].spice);
		}
		if (totalTaste >= M)
			rv = min(rv, *(spices.rbegin()));
		//eliminate the spiciest bale
		for (;l < N && bales[l].spice != *(spices.rbegin()); l++){
			totalTaste -= bales[l].flavor;
			spices.erase(spices.lower_bound(bales[l].spice));
		}
		spices.erase(spices.lower_bound(bales[l].spice));
		totalTaste -= bales[l].flavor;
		l++;
	}
	cout << rv;
	return 0;
}

