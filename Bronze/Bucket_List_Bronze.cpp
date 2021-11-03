/*
ID: david.w4
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct point{
	int time;
	int value;
	point() {}
	point (int t, int v) : time(t), value(v) {}
};
bool sortByTime(const point &a, const point &b){
	return a.time < b.time;
}
int main()
{
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);
	int N, t1, t2, v, rv = 0, curr = 0;
	cin >> N;
	vector<point> times(2 * N);
	for (int i = 0; i < N; i++){
		cin >> t1 >> t2 >> v;
		times[i * 2] = point(t1, v);
		times[i * 2 + 1] = point(t2, -v);
	}
	sort(times.begin(), times.end(), sortByTime);
	for (int i = 0; i < times.size(); i++){
		curr += times[i].value;
		rv = max(rv, curr);
	}
	cout << rv;
	system("pause");
	return 0;

	
}

