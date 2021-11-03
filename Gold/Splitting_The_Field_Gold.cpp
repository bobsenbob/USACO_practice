/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct cow{
	int x;
	int y;
	cow() {}
	cow(int xp, int yp) : x(xp), y(yp) {}
};
bool compareY(const cow &a, const cow &b){
	return a.y < b.y;
}
bool compareX(const cow &a, const cow &b){
	return a.x < b.x;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("split.in", "r", stdin); freopen("split.out", "w", stdout);
	long long N, maxx, minx, maxy, miny, a, b, curr;
	long long sarea, marea = LLONG_MAX, tarea;
	cin >> N;
	vector<cow> sx(N);
	vector<cow> sy(N);
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		sx[i] = cow(a, b);
		sy[i] = cow(a, b);
	}
	sort(sx.begin(), sx.end(), compareX);
	sort(sy.begin(), sy.end(), compareY);
	maxx = sx[N - 1].x;
	minx = sx[0].x;
	maxy = sy[N - 1].y;
	miny = sy[0].y;
 	sarea = (maxx - minx) * (maxy - miny);
	//sweep left to right
	multiset<int> left;
	multiset<int> right;
	//cout << sarea << "\n";
	for (int i = 0; i < sx.size(); i++)
		right.insert(sx[i].y);
	for (int i = 0; i < N;){
		curr = sx[i].x;
		for (;i < N && sx[i].x == curr; i++){
			left.insert(sx[i].y);
			right.erase(right.lower_bound(sx[i].y));
		}
		tarea = (curr - minx) * (*left.rbegin() - *left.begin());
		if (i < N)
			tarea += (maxx - sx[i].x) * (*right.rbegin() - *right.begin());
		marea = min(marea, tarea);
		/*cout << "split at " << curr << " area: " <<  (curr - minx) * (*left.rbegin() - *left.begin());
		if (i < N)
			cout << " " << (maxx - sx[i].x) * (*right.rbegin() - *right.begin());
		cout << "\n";*/
	}
	//sweep down to up;
	multiset<int> down;
	multiset<int> up;
	for (int i = 0; i < sy.size(); i++)
		up.insert(sy[i].x);
	for (int i = 0; i < N;){
		curr = sy[i].y;
		for (;i < N && sy[i].y == curr; i++){
			down.insert(sy[i].x);
			up.erase(up.lower_bound(sy[i].x));
		}
		tarea = (curr - miny) * (*down.rbegin() - *down.begin());
		if (i < N)
			tarea += (maxy - sy[i].y) * (*up.rbegin() - *up. begin());
		marea = min(marea, tarea);
		/*cout << "split at " << curr << " area: " << (curr - miny) * (*down.rbegin() - *down.begin());
		if (i < N)
			cout << " " << (maxy - sy[i].y) * (*up.rbegin() - *up. begin());
		cout << "\n";*/
	}
	cout << sarea - marea << "\n";
	return 0;
}

