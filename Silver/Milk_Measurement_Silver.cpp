/*
ID: dwang5766
TASK: measurement
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct scan{
	int day;
	int cow;
	int change;
	scan() {}
	scan(int d, int co, int ch) : day(d), cow(co), change(ch) {}
};
bool sortByDay(const scan &a, const scan &b){
	return a.day < b.day;
}
int main()
{
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	int N, G, rv = 0, currNum = INT_MAX;
	bool wasMax;
	cin >> N >> G;
	multiset<int> measured;
	map<int, int> produce;
	measured.insert(0);
	int dayin, cowin, changein;
	vector<scan> scans(N);
	for (int i = 0; i < N; i++){
		cin >> dayin >> cowin >> changein;
		scans[i] = scan(dayin, cowin, changein);
	}
	sort(scans.begin(), scans.end(), sortByDay);
	for(int i = 0; i < scans.size(); i++){
		wasMax = false;
		if(produce.count(scans[i].cow) == 0){
			produce.insert({scans[i].cow, scans[i].change});
			measured.insert(scans[i].change);
		}
		else{
			if (produce[scans[i].cow] == *(prev(measured.end())))
				wasMax = true;
			measured.erase(measured.lower_bound(produce[scans[i].cow]));
			produce[scans[i].cow] += scans[i].change;
			measured.insert(produce[scans[i].cow]);
		}
		if(measured.count(*(prev(measured.end()))) != currNum){
			//cout << "1day: " << scans[i].day << " max: " << *(prev(measured.end())) << "\n";
			currNum = measured.count(*(prev(measured.end())));
			rv++;
		}
		else if (wasMax && produce[scans[i].cow] != *(prev(measured.end()))){
			//cout << "2day: " << scans[i].day << " max: " << *(prev(measured.end())) << "\n";
			rv++;
		}
		else if(!wasMax && produce[scans[i].cow] == *(prev(measured.end()))){
			//cout << "3day: " << scans[i].day << " max: " << *(prev(measured.end())) << "\n";
			rv++;
		}
	}
	cout << rv;
	system("pause");
	return 0;
}

