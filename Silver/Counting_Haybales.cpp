/*
ID: david.w4
TASK: haybales
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
//:/
int LEQ(int* values, int target) {
	int l = 0, r = 100000, mid, value = 0;
	if (values[0] > target)
		return -1;
	//cout << "r: " << r;
	while (l != r) {
		mid = (l + r + 1) / 2;
		if (values[mid] <= target)
			l = mid;
		else
			r = mid - 1;

	}
	return r;
}
int main()
{
	//ifstream cin("4.in");
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	int N, Q;

	cin >> N;
	cin >> Q;
	//int cows[100000];
	vector<int> cows(N);
	for (int i = 0; i < N; i++)
		cin >> cows[i];
	//sort(cows, cows + N);
	sort(cows.begin(), cows.end());
	for (int i = 0; i < Q; i++) {
		int lo, hi;
		cin >> lo >> hi;
		int aind = lower_bound(cows.begin(), cows.end(), lo) - cows.begin();
		int bind = upper_bound(cows.begin(), cows.end(), hi) - cows.begin();
		cout << bind - aind << "\n";
		//cout << (LEQ(cows, hi) - LEQ(cows, lo - 1)) << "\n";
	}
	return 0;
}

