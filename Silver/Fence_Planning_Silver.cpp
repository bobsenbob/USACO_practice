/*
ID: david.w4
TASK: fenceplan
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct cow{
	int x;
	int y;
	vector<int> edge;
	cow() : edge (vector<int>(0)){}
	};
vector<cow> cows;
vector<bool> visited;
struct component{
int top;
int bottom;
int right;
int left;
component(){}
component(int t, int b, int r, int l) : top(t), bottom(b), right(r), left(l){}
};
vector<component> networks(0);
int perimeter(component a){
	return 2 * ((a.top - a.bottom) + (a.right - a.left));
}
void DFS(int start, int comp){
	visited[start] = true;
	networks[comp].top = max(networks[comp].top, cows[start].y);
	networks[comp].bottom = min(networks[comp].bottom, cows[start].y);
	networks[comp].right = max(networks[comp].right, cows[start].x);
	networks[comp].left = min(networks[comp].left, cows[start].x);
	for (int i = 0; i < cows[start].edge.size(); i++){
		if (!visited[cows[start].edge[i]])
			DFS(cows[start].edge[i], comp);
	}
}
int main()
{
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	int N, M, cx, cy, a, b, comp = 0, ans = INT_MAX;
	cin >> N >> M;
	cows = vector<cow> (N);
	visited = vector<bool>(N);
	for (int i = 0; i < N; i++){
		cin >> cx >> cy;
		cows[i].x = cx, cows[i].y = cy;
	}
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		cows[a - 1].edge.push_back(b - 1);
		cows[b - 1].edge.push_back(a - 1);
	}
	for (int i = 0; i < cows.size(); i++){
		if (!visited[i]){
			networks.push_back(component(cows[i].y, cows[i].y, cows[i].x, cows[i].x));
			DFS(i, comp);
			comp++;
		}
	}
	for (int i = 0; i < networks.size(); i++)
		ans = min(ans, perimeter(networks[i]));
	cout << ans;

	system("pause");
	return 0;
	
}

