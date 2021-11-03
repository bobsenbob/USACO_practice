/*
ID: david.w4
TASK: balancing
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct Point
{
	int x;
	int y;
};
bool compareX(Point a, Point b)
{
	return a.x < b.x;
}
bool compareY(Point a, Point b)
{
	return a.y < b.y;
}
int max(vector<int> integers) {
	int max = integers[0];
	for (int i = 1; i < integers.size(); i++)
		if (integers[i] > max)
			max = integers[i];
	return max;
}
vector<int> underOver(vector<Point> cows, int y) {
	//0 is above, 1 is below
	vector<int> res(2);
	for (int i = 0; i < cows.size(); i++)
	{
		if (cows[i].y > y)
			res[0]++;
		else if (cows[i].y < y)
			res[1]++;
	}
	return res;

}
int main()
{
	//ifstream fin("3.in");
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	int N, midX = 0, midY = 0, storage, rv = 10000, prv = 10000, placex, placey, over = 0, under = 0, currValue = 0;
	cin >> N;
	vector<Point> cows(N);
	vector<int> placeholder(2);
	vector<int> quads(4, 0);
	vector<int> uniqueY;
	for (int i = 0; i < N; i++) {
		cin >> cows[i].x;
		cin >> cows[i].y;
	}
	sort(cows.begin(), cows.end(), compareY);
	uniqueY.push_back(cows[0].y);
	for (int i = 1; i < cows.size(); i++) {
		if (cows[i].y != cows[i - 1].y)
			uniqueY.push_back(cows[i].y);
	}
	/*for (int i = 0; i < uniqueY.size(); i++)
		cout << uniqueY[i] << "\n";*/
	sort(cows.begin(), cows.end(), compareX);
	for (int j = 0; j < uniqueY.size(); j++) {
		midY = uniqueY[j] + 1;
		placeholder = underOver(cows, midY);
		quads[0] = placeholder[0];
		quads[3] = placeholder[1];
		quads[1] = 0;
		quads[2] = 0;
		/*cout << "midy: " << midY << "\n";
		cout << "prequads\n";
		for (int k = 0; k < 4; k++)
			cout << quads[k];
		cout << "\n";*/
		for (int i = 0; i < N;) {
			currValue = cows[i].x;
			for (; i < N && cows[i].x == currValue; i++) {
				if (cows[i].y > midY) {
					quads[1]++;
					quads[0]--;
					//cout << "going to quad 2 : " << cows[i].x << "," << cows[i].y << " " << i << "\n";
				}
				else {
					quads[2]++;
					quads[3]--;
					//cout << "going to quad 3 : " << cows[i].x << "," << cows[i].y << "\n";
				}
				/*cout << "interquads\n";
				for (int k = 0; k < 4; k++)
					cout << quads[k];
				cout << "\n";*/
				if (max(quads) < rv) {
					rv = max(quads);
				}

			}
			
		}
		if (rv < prv) 
			prv = rv;
		/*cout << "interquads\n";
		for (int k = 0; k < 4; k++)
			cout << quads[k];
		cout << "\n";*/
	}
	//middle line for x
	rv = max(quads);

	/*for (int i = 0; i < N; i++)
		cout << cows[i].x << "," << cows[i].y << "\n";*/
	cout << prv;
}

