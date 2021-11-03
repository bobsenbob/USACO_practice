/*
ID: david.w4
TASK: moo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
using namespace std;

struct Connection {
	int connected;
	int distance;
	Connection() {}
	Connection(int other, int length) : connected(other), distance(length) {}
};
void printVector(vector<bool> row) {
	for (int i = 0; i < row.size(); i++)
		cout << row[i] << " ";
}
void printAdjList(vector<vector<Connection>> adjlist) {
	for (int i = 0; i < adjlist.size(); i++) {
		cout << "{";
		for (int j = 0; j < adjlist[i].size(); j++)
			cout << adjlist[i][j].connected << " " << adjlist[i][j].distance << ", ";
		cout << "}" << "\n";

	}
}
int main()
{
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	int N = 0, Q = 0, a = 0, b = 0, d = 0, position, distance;
	cin >> N;
	cin >> Q;
	vector<Connection>row(0);
	//vector<vector<Connection>>adjlist(N, row);
	vector<Connection>* adjlist = new vector<Connection>[N];
	queue<int> next;
	for (int i = 0; i < N - 1; i++) {
		cin >> a;
		cin >> b;
		cin >> d;
		adjlist[a - 1].push_back(Connection(b - 1, d));
		adjlist[b - 1].push_back(Connection(a - 1, d));
	}
	//printAdjList(adjlist);
	for (int i = 0; i < Q; i++) {
		int query, minK, rv = 0;
		vector<bool> visited(N, false);
		cin >> minK;
		cin >> query;
		query--;
		next.push(query);
		for (; next.size() > 0;) {
			int curr = next.front();
			next.pop();
			//cout << "curr: " << curr << "\n";
			visited[curr] = true;
			for (int j = 0; j < adjlist[curr].size(); j++) {
				if (adjlist[curr][j].distance >= minK && !visited[adjlist[curr][j].connected]) {
					next.push(adjlist[curr][j].connected);
					visited[adjlist[curr][j].connected] = true;
					rv++;
				}
			}

		}
		cout << rv << "\n";

	}
}


