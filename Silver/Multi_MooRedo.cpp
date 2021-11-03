/*
ID: david.w4
TASK: multimoo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int N;
vector<vector<int>> grid;
vector<vector<int>> regionGrid;
vector<int> xmoves = { 1, -1, 0, 0 };
vector<int> ymoves = { 0, 0, 1, -1 };
vector<vector<bool>> visited;
vector<bool> visitedNodes;
map<int, bool> counted;
struct region {
	int cowID;
	int size;
	vector<int> adjacent;
	map<int, bool> matched;
	region() {}
	region(int i, int s, int n) : cowID(i), size(s), adjacent(vector<int>(n)) {}
};
vector<region> nodes;
bool inbounds(int x, int y, int N) {
	return x >= 0 && x < N && y >= 0 && y < N;
}
int singleDFSone(int x, int y) {
	int area = 1;
	visited[x][y] = true;
	regionGrid[x][y] = nodes.size();
	for (int i = 0; i < 4; i++) {
		if (inbounds(x + xmoves[i], y + ymoves[i], N) && !visited[x + xmoves[i]][y + ymoves[i]] && grid[x + xmoves[i]][y + ymoves[i]] == grid[x][y])
			area += singleDFSone(x + xmoves[i], y + ymoves[i]);
	}
	return area;
}
void adjacentDFS(int x, int y){
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (inbounds(x + xmoves[i], y + ymoves[i], N)){
		if (grid[x + xmoves[i]][y + ymoves[i]] != grid[x][y] && counted.find(regionGrid[x + xmoves[i]][y + ymoves[i]]) == counted.end()){
			counted.insert({regionGrid[x + xmoves[i]][y + ymoves[i]], 1});
			//cout << regionGrid[x][y] << " " << regionGrid[x + xmoves[i]][y + ymoves[i]] << "\n";
			nodes[regionGrid[x][y]].adjacent.push_back(regionGrid[x + xmoves[i]][y + ymoves[i]]);
		}
		if (!visited[x + xmoves[i]][y + ymoves[i]] && grid[x + xmoves[i]][y + ymoves[i]] == grid[x][y])
			adjacentDFS(x + xmoves[i], y + ymoves[i]);
	}
	}
}
int multiDFS(int starter, int partner){
	int size = nodes[starter].size;
	visitedNodes[starter] = true;
	//if any pairs of nodes are repeated, then stop searching
	for (int i = 0; i < nodes[starter].adjacent.size(); i++){
		int j = nodes[starter].adjacent[i];
		if (!visitedNodes[j] && nodes[j].cowID == partner){
			if (nodes[starter].matched.find(j) != nodes[starter].matched.end())
				return 0;
			nodes[starter].matched.insert({j, true});
			nodes[j].matched.insert({starter, true});
			int res = multiDFS(j, nodes[starter].cowID);
			if (res == 0)
				return 0;
			size += res;
		}
	}
	return size;
}
int main()
{
	freopen("multimoo.in", "r", stdin);
	freopen("multimoo.out", "w", stdout);
	int ID = 0, size = 0, maxSingle = 0, maxTeam = 0, currRegion, maximal = 0;
	cin >> N;
	regionGrid = vector<vector<int>>(N, vector<int>(N));
	grid = vector<vector<int>>(N, vector<int>(N));
	visited = vector<vector<bool>>(N, vector<bool>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> grid[i][j];
	}
	//dfs to find largest individual region
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				size = singleDFSone(i, j);
				maxSingle = max(maxSingle, size);
				nodes.push_back(region(grid[i][j], size, 0));
			}
		}
	}
	/*for (int i = 0; i < regionGrid.size(); i++) {
		for (int j = 0; j < regionGrid[i].size(); j++)
			cout << regionGrid[i][j] << " ";
		cout << "\n";
	}*/
	visited = vector<vector<bool>>(N, vector<bool>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				counted.clear();
				adjacentDFS(i, j);
			}
		}
	}
	/*for (int i = 0; i < nodes.size(); i++)
		nodes[i].adjacent.push_back(i);
	for (int i = 0; i < nodes.size(); i++){
		cout << i << ": ";
		for (int j = 0; j < nodes[i].adjacent.size(); j++)
			cout << nodes[i].adjacent[j] << " ";
		cout << "\n";
	}*/
	visitedNodes = vector<bool>(nodes.size(), false);
	map<int, bool> checked;
	for (int i = 0; i < nodes.size(); i++){
		checked.clear();
			for (int j = 0; j < nodes[i].adjacent.size(); j++){
				if (checked.find(nodes[nodes[i].adjacent[j]].cowID) == checked.end()){
				visitedNodes = vector<bool>(nodes.size(), false);
				checked.insert({nodes[nodes[i].adjacent[j]].cowID, 1});
				int res = multiDFS(i, nodes[nodes[i].adjacent[j]].cowID);
				//cout << i << ", " << nodes[i].adjacent[j] << " " << res << " " << nodes[nodes[i].adjacent[j]].cowID <<"\n";
				maxTeam = max(maxTeam, res);
			}
		}
	}
	cout << maxSingle << "\n" << maxTeam;
	system("pause");
	return 0;
}


