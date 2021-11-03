/*
ID: david.w4
TASK: angry
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool check(vector<int> bales, int P, int K)
{
	P = 2 * P;
	int prev;
	for (int i = 0; K > 0;) {
		prev = bales[i];
		//cout << "prev: " << prev << "\n";
		for (; bales[i] - prev <= P; i++) {
			if (i == bales.size() - 1)
				return true;
		}
		K--;
	}
	return false;
}

int main()
{
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	int N, K, l = 0, r = 1000000000, mid;
	cin >> N >> K;
	vector<int> bales(N);
	for (int i = 0; i < N; i++)
		cin >> bales[i];
	sort(bales.begin(), bales.end());
	for (; l < r;) {
		mid = (l + r) / 2;
		if (check(bales, mid, K))
			r = mid;
		else
			l = mid + 1;
	}
	cout << r;
}



