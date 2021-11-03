/*
ID: david.w4
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct board{
	int left;
	int down;
	int right;
	int top;
	board() {}
	board(int l, int d, int r, int t) : left(l), down(d), right(r), top(t) {}
};
int cornersCovered(board a, board b){
	int rv = 0;
	//top right
	if (a.top >= b.top && a.right >= b.right)
		rv++;
	if (a.top >= b.top && a.left <= b.left)
		rv++;
	if (a.down <= b.down && a.right >= b.right)
		rv++;
	if (a.down <= b.down && a.left <= b.left)
		rv++;
	return rv;

}
int main()
{
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	int l, d, r, u;
	cin >> l >> d >> r >> u;
	board lawn = board(l, d, r, u);
	cin >> l >> d >> r >> u;
	board feed = board(l, d, r, u);
	//Check if all corners are obscured
	int areaLawn = (lawn.right - lawn.left) * (lawn.top - lawn.down);
	if (cornersCovered(feed, lawn) <= 1)
		cout << areaLawn;
	else if (cornersCovered(feed, lawn) == 4)
		cout << 0;
	else if (cornersCovered(feed, lawn) == 2)
		cout << areaLawn - (min(feed.right, lawn.right) - max(feed.left, lawn.left)) * (min(feed.top, lawn.top) - max(feed.down, lawn.down));
	system("pause");
	return 0;



}

