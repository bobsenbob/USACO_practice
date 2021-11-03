/*
ID: david.w4
TASK: mountains
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct peak {
	int x;
	int y;
	peak() {
	}
	peak(int xpos, int ypos) : x(xpos), y(ypos){}
};
bool compareByHeight(const peak& a, const peak& b) {
	return a.y < b.y;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	int N, tempx, tempy;
	cin >> N;
	vector<peak> mountains(N);
	vector<bool> covered(N);
	for (int i = 0; i < N; i++) {
		cin >> tempx >> tempy;
		mountains[i] = peak(tempx, tempy);
	}
	sort(mountains.begin(), mountains.end(), compareByHeight);
	for (int i = mountains.size() - 1; i >= 0; i--) {
		if (!covered[i])
		for (int j = i - 1; j >= 0; j--)
			if (abs(mountains[i].x - mountains[j].x) <= mountains[i].y - mountains[j].y)
				covered[j] = true;
	}
	int rv = mountains.size();
	for (int i = 0; i < covered.size(); i++)
		if (covered[i])
			rv--;
	cout << rv;;
}

