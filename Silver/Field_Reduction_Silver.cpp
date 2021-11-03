/*
ID: david.w4
TASK: reduce
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
};
bool sortX(const cow& a, const cow& b) {
	return a.x < b.x;
}
bool sortY(const cow& a, const cow& b) {
	return a.y < b.y;
}
int solveArea(vector<cow> cows) {
	int maxX, minX, maxY, minY;
	if (cows.size() < 2)
		return 0;
	maxX = cows[0].x, minX = cows[0].x, maxY = cows[0].y, minY = cows[0].y;
	for (int i = 1; i < cows.size(); i++) {
		if (maxX < cows[i].x) maxX = cows[i].x;
		if (minX > cows[i].x) minX = cows[i].x;
		if (maxY < cows[i].y) maxY = cows[i].y;
		if (minY > cows[i].y) minY = cows[i].y;
	}
	return (maxX - minX) * (maxY - minY);
}
void printVector(vector<cow> cows) {
	for (int i = 0; i < cows.size(); i++) {
		cout << "(" << cows[i].x << ", " << cows[i].y << ") ";
	}
	cout << "\n";
}
int explore(vector<cow> cows, int level) {
	cow removed;
	int area = solveArea(cows);
	if (level > 3) {
		//printVector(cows);
		//cout << area;
		//cout << "\n";
		return area;
	}
	int maxX, minX, maxY, minY, maxXin = 0, minXin = 0, maxYin = 0, minYin = 0;
	maxX = cows[0].x, minX = cows[0].x, maxY = cows[0].y, minY = cows[0].y;
	for (int i = 1; i < cows.size(); i++) 
		if (maxX < cows[i].x) maxXin = i, maxX = cows[i].x;
	removed = cows[maxXin];
	cows.erase(cows.begin() + maxXin);
	area = min(area, explore(cows, level + 1));
	cows.push_back(removed);
	for (int i = 1; i < cows.size(); i++) 
		if (minX > cows[i].x) minXin = i, minX = cows[i].x;
	removed = cows[minXin];
	cows.erase(cows.begin() + minXin);
	area = min(area, explore(cows, level + 1));
	cows.push_back(removed);
	for (int i = 1; i < cows.size(); i++) 
		if (maxY < cows[i].y) maxYin = i, maxY = cows[i].y;
	removed = cows[maxYin];
	cows.erase(cows.begin() + maxYin);
	area = min(area, explore(cows, level + 1));
	cows.push_back(removed);
	for (int i = 1; i < cows.size(); i++) 
		if (minY > cows[i].y) minYin = i, minY = cows[i].y;
	removed = cows[minYin];
	cows.erase(cows.begin() + minYin);
	area = min(area, explore(cows, level + 1));
	cows.push_back(removed);
	return area;
}
int main()
{
	freopen("reduce.in", "r", stdin);
	freopen("reduce.out", "w", stdout);
	int N;
	cin >> N;
	vector<cow> cows(N), sortedY(8), sortedX(8), subset(0);
	for (int i = 0; i < N; i++) {
		cin >> cows[i].x >> cows[i].y;
	}
	if (N < 5)
		cout << 0;
	cout << explore(cows, 1);

	system("pause");
	return 0;
}

