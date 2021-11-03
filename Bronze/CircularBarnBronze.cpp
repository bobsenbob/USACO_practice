/*
ID: david.w4
TASK: cbarn
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int countDistance(int starting, vector<int> a) {
	int rv =  0;
	for (int i = 1; i < a.size(); i++) {
		starting++;
		if (starting >= a.size())
			starting = 0;
		rv += i * a[starting];
	}
	return rv;
}
int main()
{
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	int N, rv = 0;
	cin >> N;
	vector<int> rooms(N);
	for (int i = 0; i < N; i++)
		cin >> rooms[i];
	rv = countDistance(0, rooms);
	for (int i = 1; i < N; i++)
		rv = min(rv, countDistance(i, rooms));
	cout << rv;

}

