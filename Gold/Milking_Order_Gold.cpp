/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int N, M, xj, rn;
vector<vector<int>> obs;
vector<vector<int>> graph;
vector<bool> visited;
vector<bool> rec;
void printV2(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++){
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}
bool cycle(int a){
	visited[a] = true;
	rec[a] = true;
	for (int i = 0; i < graph[a].size(); i++){
		if (rec[graph[a][i]])
			return true;
		else if (!visited[graph[a][i]] && cycle(graph[a][i]))
			return true;
	}
	rec[a] = false;
	return false;
}
bool test(int a){
	graph = vector<vector<int>>(N, vector<int>(0));
	visited = vector<bool>(N, false);
	rec = vector<bool>(N, false);
	for (int i = 0; i < a; i++){
		for (int j = 0; j < obs[i].size() - 1; j++){
			graph[obs[i][j]].push_back(obs[i][j + 1]);
		}
	}
	//printV2(graph);
	for (int i = 0; i < N; i++)
		if (!visited[i])
			if (cycle(i))
				return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("milkorder.in", "r", stdin); freopen("milkorder.out", "w", stdout);
	cin >> N >> M;
	obs = vector<vector<int>>(M);
	for (int i = 0; i < M; i++){
		cin >> xj;
		obs[i] = vector<int>(xj);
		for (int j = 0; j < xj; j++){
			cin >> obs[i][j];
			obs[i][j]--;
		}
	}
	int l = 0, r = M, mid;
	for (;l < r;){
		mid = (l + r + 1) / 2;
		if (test(mid))
			l = mid;
		else
			r = mid - 1;

	}
	priority_queue<int, vector<int>, greater<int>> next;
	vector<int> after(N);
	vector<int> res(0);
    graph = vector<vector<int>>(N, vector<int>(0));
    visited = vector<bool>(N, false);
    for (int i = 0; i < r; i++){
		for (int j = 0; j < obs[i].size() - 1; j++){
			graph[obs[i][j]].push_back(obs[i][j + 1]);
			after[obs[i][j + 1]]++;
		}
	}
	for (int i = 0; i < N; i++)
		if (after[i] == 0)
			next.push(i);
	for (;next.size() > 0;){
		rn = next.top();
		next.pop();
		if (visited[rn])
			continue;
		visited[rn] = true;
		res.push_back(rn);
		for (int b : graph[rn]){
			after[b]--;
			if (after[b] == 0)
				next.push(b);
		}
	
	}
	for (int i = 0; i < res.size(); i++){
		cout << res[i] + 1;
		if (i != res.size() - 1)
			cout << " ";
	}
	return 0;
	
}

