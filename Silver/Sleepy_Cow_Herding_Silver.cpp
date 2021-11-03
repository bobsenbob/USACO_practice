/*
ID: david.w4
TASK: herding
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int main()
{
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
	int N, rvMax, rvMin, l = 0, r = 0, maxCont = 0;
	cin >> N;
	vector<int> cows(N);
	for (int i = 0; i < N; i++)
		cin >> cows[i];
	sort(cows.begin(), cows.end());

	rvMax = cows[cows.size() - 1] - cows[0] - cows.size() + 2 - min(cows[1] - cows[0], cows[cows.size() - 1] - cows[cows.size() - 2]);
	for (; r < cows.size() && l < cows.size();) {
		if ((cows[r] - cows[l] < cows.size())) {
			//cout << "r: " << r << " l: " << l << "\n";
			if ((cows[r] - cows[l] + 1 != cows.size() - 1))
				maxCont = max(maxCont, r - l + 1);
			r++;
		}
		else
			l++;
	}
	//cout << maxCont << "\n";
	rvMin = cows.size() - maxCont;
	cout << rvMin << "\n";
	cout << rvMax;
}

