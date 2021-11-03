/*
ID: david.w4
TASK: lifeguards
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct period {
	int start;
	int end;

};
bool compareByStart(const period& a, const period& b)
{
	return a.start < b.start;
}
void printTimes(vector<period> a) {
	for (int i = 0; i < a.size(); i++)
		cout << a[i].start << " " << a[i].end << "\n";
};
period createPeriod(int start, int end) {
	period a;
	a.start = start;
	a.end = end;
	return a;
}

int main()
{
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	//ifstream cin("2.in");
	int N = 0, start = 0, end = 0, ttime = 0, absMin = 0, maxEnd = 0;
	cin >> N;
	vector<period>times(N);
	vector<int> overlaps(0);
	for (int i = 0; i < N; i++) {
		cin >> times[i].start;
		cin >> times[i].end;
	}
	sort(times.begin(), times.end(), compareByStart);
	start = times[0].start;
	end = times[0].end;
	for (int i = 0; i < times.size(); i++) {
		if ((times[i].start > end)) {
			ttime += end - start;
			start = times[i].start;
			end = times[i].end;
		}
		else if (times[i].end > end)
			end = times[i].end;
		if (i == times.size() - 1)
			ttime += end - start;

	}
	for (int i = 0; i < times.size(); i++) {
		int currOverlap = 0;
		if (maxEnd > times[i].start) 
			currOverlap += min(maxEnd - times[i].start, times[i].end - times[i].start);
		if (i < times.size() - 1)
			if (times[i + 1].start < times[i].end)
				currOverlap += times[i].end - max(times[i + 1].start, maxEnd);
		if (times[i].end > maxEnd)
			maxEnd = times[i].end;
		overlaps.push_back(times[i].end - times[i].start - currOverlap);
	}
	/*for (int i = 0; i < overlaps.size(); i++)
		cout << overlaps[i];*/
	absMin = overlaps[0];
	for (int i = 0; i < overlaps.size(); i++) {
		//cout << overlaps[i];
		if (absMin > overlaps[i])
			absMin = overlaps[i];
	}
	//cout << absMin;
	ttime -= absMin;
	cout << ttime << "\n";
	return 0;

}

