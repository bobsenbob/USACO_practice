/*
ID: david.w4
TASK: moocast
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct cow {
	int x;
	int y;
	int range;
	cow() {
	}
	cow(int xpos, int ypos, int r) : x(xpos), y(ypos), range(r){}
};
int maxReach(int cow, vector<vector<int>> adjList) {
	int rv = 0, currCow;
	vector<bool> visited(adjList.size(), false);
	queue<int> next;
	next.push(cow);
	visited[cow] = true;
	for (; next.size() > 0;) {
		currCow = next.front();
		next.pop();
		rv++;
		for (int i = 0; i < adjList[currCow].size(); i++)
			if (!visited[adjList[currCow][i]]) {
				next.push(adjList[currCow][i]);
				visited[adjList[currCow][i]] = true;
			}
	}
	return rv;
}
int squared(int a) {
	return a * a;
}
int main()
{
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	int N, maxCow = 0;
	cow currCheck;
	cin >> N;
	vector<vector<int>> adjList(N, vector<int>(0));
	vector<cow>cows(N);
	for (int i = 0; i < N; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		cows[i] = cow(x, y, r);
	}
	for (int i = 0; i < N; i++) {
		currCheck = cows[i];
		for (int j = 0; j < N; j++) {
			if (j == i)
				continue;
			//cout << currCheck.range << "v" << sqrt(squared(cows[j].x - currCheck.x) + squared(cows[j].y - currCheck.y)) << "\n";
			if (currCheck.range >= (sqrt(squared(cows[j].x - currCheck.x) + squared(cows[j].y - currCheck.y))))
				adjList[i].push_back(j);
;		}
	}
	for (int i = 0; i < cows.size(); i++)
		maxCow = max(maxCow, maxReach(i, adjList));
	/*for (int i = 0; i < adjList.size(); i++) {
		for (int j = 0; j < adjList[i].size(); j++)
			cout << adjList[i][j] << " ";
		cout << "\n";
	}*/
	cout << maxCow;
		

}

