/*
ID: dwang5766
TASK: lineup
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<bool> used(8, false);
map<string, int> finder;
struct cow{
	string name;
	int left;
	vector<string> constraints;
	cow() {}
	cow(string s) : name(s), constraints( vector<string>(0)), left(0) {}
};
	vector<cow> cows(8);
	vector<cow> order(8);
int firstcow(vector<cow> cows){
	for (int i = 0; i < cows.size(); i++)
		if (!used[i] && cows[i].constraints.size() < 2){
			used[i] = true;
			return i;
		}
}
int nextcow(cow a){
	for (int i = 0; i < a.constraints.size(); i++)
		if (!used[finder[a.constraints[i]]]){
			used[finder[a.constraints[i]]] = true;
			return finder[a.constraints[i]];
		}
}
int main()
{
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	int N;
	string a, b, throwaway;
	cows[0] = cow("Beatrice");
	cows[1] = cow("Belinda");
	cows[2] = cow("Bella");
	cows[3] = cow("Bessie");
	cows[4] = cow("Betsy");
	cows[5] = cow("Blue");
	cows[6] = cow("Buttercup");
	cows[7] = cow("Sue");
	cin >> N;
	for (int i = 0; i < cows.size(); i++)
		finder.insert({cows[i].name, i});
	for (int i = 0; i < N; i++){
		cin >> a;
		for (int j = 0; j < 4; j++)
			cin >> throwaway;
		cin >> b;
		cows[finder[a]].constraints.push_back(b);
		cows[finder[b]].constraints.push_back(a);
		cows[finder[a]].left++;
		cows[finder[b]].left++;

	}
	order[0] = cows[firstcow(cows)];
	for (int i = 1; i < order.size(); i++)
		if (order[i - 1].left == 0)
			order[i] = cows[firstcow(cows)];
		else{
			order[i] = cows[nextcow(order[i - 1])];
			order[i - 1].left--;
			order[i].left--;
		}
	for (int i = 0; i < order.size(); i++)
		cout << order[i].name << "\n";
	system("pause");
	return 0;
}

