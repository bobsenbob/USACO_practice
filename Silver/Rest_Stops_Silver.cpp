/*
ID: david.w4
TASK: reststops
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct stop {
	int tasty;
	int position;
	stop() {}
	stop (int t, int p) : tasty(t), position(p) {}
};
bool compareByTasty(const stop &a, const stop &b){
	return a.tasty > b.tasty;
}
int main()
{
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	long long N, L, rf, rb, p, t, relative, currPos = 0, rv = 0;
	cin >> L >> N >> rf >> rb;
	relative = rf - rb;
	vector<stop> rests(N);
	for (int i = 0; i < N; i++){
		cin >> p >> t;
		rests[i] = stop(t, p);
	}
	//sort descending
	sort(rests.begin(), rests.end(), compareByTasty);
	for (int i = 0; i < rests.size(); i++){
		if (rests[i].position >= currPos){
			rv += (rests[i].position - currPos) * relative * rests[i].tasty;
			currPos = rests[i].position;
		}
	}
	cout << rv;
	system("pause");
	return 0;
}

