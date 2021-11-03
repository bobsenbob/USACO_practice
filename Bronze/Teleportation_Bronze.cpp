/*
ID: david.w4
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("teleport.in", "r", stdin);
	freopen("teleport.out", "w", stdout);
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	int direct = abs(b - a);
	int goX = abs(x - a) + abs(y - b);
	int goY = abs(y - a) + abs(x - b);
	cout << min(direct, min(goX, goY));
}

