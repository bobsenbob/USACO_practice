/*
ID: david.w4
TASK: revegetate
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> plant;
int original = 0;
bool impossible = false;
struct edge{
	int target;
	char type;
	//1 is same, 2 is different
	edge(){}
	edge(int to, char form) : target(to), type(form) {}
};
/*struct planter{
	int field;
	int seed;
	planter(){}
	planter(int f, int s) : field(f), seed(s) {}
};*/
vector<vector<edge>> cows;
void visit(int cow, int seed){
	visited[cow] = true;
	//cout << cow << "\n";
	if (plant[cow] != 3 - seed)
		plant[cow] = seed;
	else {
		impossible = true;
	}
	for (int i = 0; i < cows[cow].size(); i++){
		if (!visited[cows[cow][i].target]){
			if (cows[cow][i].type == 'S'){
				visit(cows[cow][i].target, seed);
			}
			else{
				visit(cows[cow][i].target, 3 - seed);
			}
		}
		if (cows[cow][i].type == 'S'){
			if (plant[cows[cow][i].target] == 3 - seed)
				impossible = true;
			}
		else{
			if (plant[cows[cow][i].target] == seed)
				impossible = true;
		}
	}
}
int main()
{	
	//freopen("revegetate.in", "r", stdin);
	//freopen("revegetate.out", "w", stdout);
	int N, M, first, second, rv = 0;
	cin >> N >> M;
	char a;
	visited = vector<bool>(N);
	plant = vector<int>(N);
	cows = vector<vector<edge>> (N, vector<edge>(0));
	for (int i = 0; i < M; i++){
		cin >> a >> first >> second;
		cows[first - 1].push_back(edge(second - 1, a));
		cows[second - 1].push_back(edge(first - 1, a));
	}
	for (int i = 0; i < N; i++){
		if (!visited[i]){
			visit(i, 1);
			rv++;
		}
	}
	if (impossible)
		cout << 0;
	else {
		cout << 1;
		for (int i = 0; i < rv; i++)
			cout << 0;
	}
	system("pause");
	return 0;

}