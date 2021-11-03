/*
ID: david.w4
TASK: pairup
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int M = 0;
struct group{
	int cows;
	int amount;
	group() {}
	group(int c, int a) : cows(c), amount(a) {}
};
vector<group> cows;
int pairUp(){
	int rv = 0, currCow = 0, last = cows.size() - 1, considering = 0;
	for (int i = 0; i < cows.size() && currCow < M/2; i++){
		considering = cows[i].cows;
		if (currCow + considering > M/2)
			considering = M/2 - currCow;
		currCow += considering;
		//cout << "last: " << last << " i: " << i << " cons: " << considering << " curr: " << currCow << "\n";
		rv = max(rv, cows[i].amount + cows[last].amount);
		for (;considering > 0;){
			int taken = min(considering, cows[last].cows);
			considering -= taken;
			cows[last].cows -= taken;
			if (cows[last].cows == 0){
			last--;	
		}
		}
	}
	return rv;
}
bool compareByAmount(const group &a, const group &b){
	return a.amount < b.amount;
}
int main()
{
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	int N, x, y, lim, parsed = 0, ans = 0;
	cin >> N;
	cows = vector<group> (N);
	for (int i = 0; i < N; i++){
		cin >> x >> y;
		cows[i] = group(x, y);
		M += x;
	}
	sort(cows.begin(), cows.end(), compareByAmount);
	cout << pairUp();
	system("pause");
	return 0;
}

