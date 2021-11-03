/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct cow{
	int weight;
	int position;
	int velocity;
	cow() {}
	cow(int w, int p, int v) : weight(w), position(p), velocity(v) {}
	bool operator<(cow other) const{
		return position < other.position;
	}
};
vector<cow> cows;
struct entry{
	int time;
	int direction;
	entry() {}
	entry(int t, int d) : time(t), direction(d){}
	bool operator<(entry other) const{
		return time > other.time;
	}
};
int solve(int time){
	int rv = 0;
	queue<int> colliding;
	for (int i = 0; i < cows.size(); i++){
		if (cows[i].velocity == -1){
		for (;colliding.size() > 0 && colliding.front() + 2 * time < cows[i].position;){
			colliding.pop();
		}
		rv += colliding.size();
	}
		else 
			colliding.push(cows[i].position);

	}
	return rv;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("meetings.in", "r", stdin); freopen("meetings.out", "w", stdout);
	int N, L, w, p, v, currWeight = 0, totalWeight = 0, lit, rit, ttime = 0;
	entry nextEntry;
	cin >> N >> L;
	cows = vector<cow>(N);
	for (int i = 0; i < N; i++){
		cin >> w >> p >> v;
		cows[i] = cow(w, p, v);
	}
	priority_queue<entry> next;
	sort(cows.begin(), cows.end());
	for (int i = 0; i < cows.size(); i++){
		if (cows[i].velocity == 1)
			next.push(entry(L - cows[i].position, 1));
		else
			next.push(entry(cows[i].position, -1));
		totalWeight += cows[i].weight;
	}
	lit = 0, rit = N - 1;
	for (;2 * currWeight < totalWeight;){
		nextEntry = next.top();
		next.pop();
		if (nextEntry.direction == 1){
			currWeight += cows[rit].weight;
			rit--;
		}
		else{
			currWeight += cows[lit].weight;
			lit++;
		}
		ttime = nextEntry.time;
	}
	cout << solve(ttime);
	return 0;
}

