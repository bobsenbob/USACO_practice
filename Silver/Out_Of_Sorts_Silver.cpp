/*
ID: david.w4
TASK: sort
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct point{
	int value;
	int index;
};
bool sortValue(const point &a, const point &b){
	return a.value < b.value || (a.value == b.value && a.index < b.index);
}
int main()
{
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	int N, ans = 0;
	cin >> N;
	vector<point> a(N);
	for (int i = 0; i < N; i++){
		a[i].index = i;
		cin >> a[i].value;
	}
	sort (a.begin(), a.end(), sortValue);
	for (int i = 0; i < N; i++){
		ans = max(ans, a[i].index - i);
	}
	cout << ans + 1;
}

