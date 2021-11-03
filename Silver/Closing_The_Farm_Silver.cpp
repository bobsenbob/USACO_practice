/*
ID: david.w4
TASK:closing
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
vector<bool> closed(3000);
vector<vector<int>> barns;
int DFS(int start) {
	closed[start] = true;
	int rv = 1;
	//cout << start << "\n";
	for (int i = 0; i < barns[start].size(); i++) {
		if (!closed[barns[start][i]]) {
			rv += DFS(barns[start][i]);
		}

	}
	return rv;
}
int main()
{
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	//ifstream cin("2.in");
	int N, M, place, connection, left, closing, start = 0;
	cin >> N >> M;
	vector<bool> closeded(N);
	barns = vector<vector<int>> (N, vector<int>(0));
	left = N;
	for (int i = 0; i < M; i++) {
		cin >> place >> connection;
		barns[place - 1].push_back(connection - 1);
		barns[connection - 1].push_back(place - 1);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (!closeded[j]) {
				start = j;
				break;
			}
		closed = closeded;
		//cout << DFS(barns,start) << "v" << left << "\n";
		if (DFS(start) < left)
			cout << "NO\n";
		else
			cout << "YES\n";
		cin >> closing;
		closeded[closing - 1] = true;
		left--;
		
	}
}

