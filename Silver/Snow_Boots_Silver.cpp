/*
ID: david.w4
TASK: snowboots
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct boot {
	int depth;
	int distance;
	boot() : depth(0), distance(0) {}
	boot(int deep, int dist) : depth(deep), distance(dist) {}
};
int N, B, minBoot = 999;
vector<vector<bool>> visited(250, vector<bool>(250));
vector<int> path(250);
vector<boot> boots(250);
void visit(int step, int boot){
	//dont recheck already visited nodes
	if (visited[step][boot])
		return;
	visited[step][boot] = true;
	//if the snow is too deep, step is invalid
	if (boots[boot].depth < path[step])
		return;
	if (step == N - 1)
		minBoot = min(minBoot, boot);
	//try stepping forward
	for (int i = 1; i <= boots[boot].distance && step + i < N; i++)
		visit(step + i, boot);
	//try changing boot
	for (int b = boot + 1; b < B; b++)
		visit(step, b);
	//if at end, record minimum
	
}
int main()
{
	//ifstream fin("3.in");
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	int currBoot = 0, minimumBoot = 0;
	long long position = 0;
	cin >> N >> B;

	for (int i = 0; i < N; i++)
		cin >> path[i];
	for (int i = 0; i < B; i++) {
		int depth, distance;
		cin >> depth >> distance;
		boots[i] = boot(depth, distance);
	}
	visit(0, 0);

	
	cout << minBoot;
}

