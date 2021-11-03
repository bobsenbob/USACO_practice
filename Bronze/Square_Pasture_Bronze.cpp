/*
ID: dwang5766
TASK: square
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct rectangle{
	int right;
	int top;
	int left;
	int bottom;
	rectangle() {}
	rectangle(int r, int t, int l, int b) : right(r), top(t), left(l), bottom(b) {}
};
int main()
{
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	int r, t, l, b;
	cin >> l >> b >> r >> t;
	rectangle r1 = rectangle(r, t, l, b);
	cin >> l >> b >> r >> t;
	rectangle r2 = rectangle(r, t, l, b);
	cout << max((max(r1.right, r2.right) - min(r1.left, r2.left)), (max(r1.top, r2.top) - min(r1.bottom, r2.bottom))) * max((max(r1.right, r2.right) - min(r1.left, r2.left)), (max(r1.top, r2.top) - min(r1.bottom, r2.bottom)));
	system("pause");
	return 0;

}

