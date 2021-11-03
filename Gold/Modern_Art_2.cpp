/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct color{
	int fa;
	int la;
	color() {}
	color(int f, int l) : fa(f), la(l){}
	bool operator<(const color &other) const{
		return fa < other.fa;
	}
};
void printV(vector<int> a){
	for (int i = 0; i < a.size(); i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("art2.in", "r", stdin); freopen("art2.out", "w", stdout);
	int N, rv = 0, covered = 0;
	cin >> N;
	vector<int> colors(N);
	vector<int> height(N);
	stack<int> active;
	vector<color> appear(N + 1, color(N + 1, -1));
	for (int i = 0; i < N; i++){
		cin >> colors[i];
	}
	for (int i = 0; i < colors.size(); i++){
		appear[colors[i]].fa = min(appear[colors[i]].fa, i);
		appear[colors[i]].la = max(appear[colors[i]].la, i);
	}
	for (int i = 0; i < colors.size(); i++){
		if (appear[colors[i]].la == -1|| colors[i] == 0)
			continue;
		if (i == appear[colors[i]].fa){
			active.push(colors[i]);
		}
		//cout << colors[i] << " " << i << " " << active.size() << "\n";
		rv = max(rv, (int)active.size());
		if (active.top() != colors[i]){
				rv = -1;
				break;
			}
		if (i == appear[colors[i]].la ){
				active.pop();
		}
	}
	for (int i = 1; i < colors.size(); i++)
		if (appear[i].la == -1)
			covered++;

	cout << rv;
	return 0;
}

