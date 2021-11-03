/*
ID: david.w4
TASK: lemonade
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
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
	int N, ans = 0;
	cin >> N;
	vector<int> waits(N);
	for (int i = 0; i < N; i++)
		cin >> waits[i];
	sort(waits.begin(), waits.end());
	for (int i = waits.size() - 1; i >= 0; i--){
		if (waits[i] < waits.size() - 1 - i)
			break;
		ans++;
	}
	cout << ans;
}

