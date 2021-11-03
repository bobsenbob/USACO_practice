/*
ID: david.w4
TASK: planting
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
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
	int N, a, maximum = 0;
	cin >> N;
	vector<int> patches(N);
	for (int i = 0; i < N - 1; i++) {
		cin >> a;
		patches[a - 1]++;
		cin >> a;
		patches[a - 1]++;
	}
	for (int i = 0; i < N; i++)
		maximum = max(maximum, patches[i]);
	cout << maximum + 1;
}

