
#include <bits/stdc++.h>
using namespace std;
struct cow {
	int start;
	int end;
	cow() {}
	cow(int s, int e) : start(s), end(e) {}
	bool operator<(cow other)const {return end < other.end;} // sorts cows in descending order by default
};
bool sortStart(const cow& a, const cow& b) { // sorts cows in ascending order
	return a.start < b.start;
}
int main()
{
	//freopen("helpcross.in", "r", stdin); 
	//freopen("helpcross.out", "w", stdout);
	int C, N, start, end, j = 0, rv = 0, previous = 0;
	cin >> C >> N;
	vector<int> chickens(C);
	vector<cow> cows(N);
	multiset<cow> active;
	for (int i = 0; i < C; i++)
		cin >> chickens[i];
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		cows[i] = cow(start, end);
	}
	sort(cows.begin(), cows.end(), sortStart);
	sort(chickens.begin(), chickens.end());
	for (int i = 0; i < chickens.size(); i++) {
		for (;j < cows.size() && cows[j].start <= chickens[i]; j++)
			active.insert(cows[j]);
		active.erase(active.begin(), active.lower_bound(cow(0, chickens[i])));
		if (active.size() > 0) {
			rv++;
			active.erase(active.begin());
		}
	}
	cout << rv;
	return 0;
}