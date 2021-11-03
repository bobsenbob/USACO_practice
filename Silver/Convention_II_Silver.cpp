/*
ID: david.w4
TASK: convention2
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct cow {
	int arrival;
	int eating;
	int seniority;
	cow() {}
	cow(int a, int e, int s) : arrival(a), eating(e), seniority(s) {}
};
bool sortArrival(const cow& a, const cow& b) {
	return a.arrival < b.arrival;
}
struct compareSeniority {
	bool operator()(const cow& a, const cow& b) {
		return a.seniority < b.seniority;
	}
};
int main()
{
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	int N, a, t, rv = 0, lastend = 0;
	cin >> N;
	cow grazing;
	vector<cow> attend(N);
	for (int i = 0; i < N; i++) {
		cin >> a >> t;
		attend[i] = cow(a, t, N - i);
	}
	sort(attend.begin(), attend.end(), sortArrival);
	priority_queue<cow, vector<cow>, compareSeniority> line;
	line.push(attend[0]);
	for (int i = 1; line.size() > 0 || i < attend.size();) {
		if (line.size() < 1) {
			line.push(attend[i]);
				i++;
		}
		grazing = line.top();
		line.pop();
		rv = max(rv, lastend - grazing.arrival);
		lastend = max(lastend, grazing.arrival) + grazing.eating;
		for (; i < attend.size() && attend[i].arrival <= lastend;) {
				line.push(attend[i]);
				i++;
		}
	}
	cout << rv;
	system("pause");
	return 0;

}

