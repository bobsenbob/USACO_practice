/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int l = 0, r = 0;
struct grass{
	int position;
	int amount;
	grass() {}
	grass(int p, int a) : position(p), amount(a) {}
	bool operator<(grass other) const{
		return position < other.position;
	}
};
vector<grass> patches;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("lazy.in", "r", stdin); freopen("lazy.out", "w", stdout);
	int N, K, p, a;
	long long rv = 0, priorSum = 0;
	cin >> N >> K;
	patches = vector<grass>(N);
	for (int i = 0; i < N; i++){
		cin >> a >> p;
		patches[i] = grass(p, a);
	}
	sort(patches.begin(), patches.end());
	for (;r < patches.size();){
		for (;patches[r].position - patches[l].position > 2 * K; l++)
			priorSum -= patches[l].amount;
		for (;r < patches.size() && patches[r].position - patches[l].position <= 2 * K; r++){
			priorSum += patches[r].amount;
		}
		rv = max(rv, priorSum);
	}
	cout << rv;
	return 0;
}

