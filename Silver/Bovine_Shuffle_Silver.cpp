/*
ID: david.w4
TASK: shuffle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int main()
{
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	int N, rv, place, check;
	cin >> N;
	rv = N;
	vector<int> to(N);
	vector<vector<int>> destinations(N,vector<int>(0));
	queue<int> next;
	for (int i = 0; i < N; i++) {
		cin >> to[i];
		to[i]--;
	}
	for (int i = 0; i < N; i++)
		destinations[to[i]].push_back(i);
	for (int i = 0; i < destinations.size(); i++)
		if (destinations[i].size() == 0) {
			next.push(i);
			rv--;
		}
	for (; next.size() > 0;) {
		place = next.front();
		next.pop();
		check = to[place];
		destinations[check].erase(remove(destinations[check].begin(), destinations[check].end(), place), destinations[check].end());
		if (destinations[check].size() == 0) {
			next.push(check);
			rv--;
		}
	}
	cout << rv;

}

