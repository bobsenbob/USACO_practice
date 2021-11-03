/*
ID: david.w4
TASK: convention
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
bool test(vector<int> cows, int time, int buses, int capacity) {
	int prev = 0, j = 0, curr = 0;
		for (int i = 0; i < buses; i++) {
			prev = cows[j];
			//cout << "prev: " << prev << "\n";
			curr = 0;
			for (;j < cows.size() && cows[j] - prev <= time && curr < capacity;j++) {
				curr++;
				//cout << "curr: " << curr << "\n";
				//cout << "current cow" << cows[j] << "\n";
				
			}

		}
		return (j >= cows.size());
}
int main()
{
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	int N, M, C, l, r, mid;
	cin >> N;
	cin >> M;
	cin >> C;
	vector<int> cows(N);
	for (int i = 0; i < N; i++)
		cin >> cows[i];
	l = 0;
	sort(cows.begin(), cows.end());
	r = cows[cows.size() - 1] - cows[0];
	mid = (l + r) / 2;
	while (l != r) {
		mid = (l + r) / 2;
		//cout << "m: " << mid << " l: " << l << " r: " << r << "\n";
		if (test(cows, mid, M, C))
		{
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << l;
}
