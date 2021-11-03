/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<string> plain;
vector<string> spotted;
bool test(int a){
	set<string> subs;
	for (int i = 0; i < M - a; i++){
		subs.clear();
		bool ok = true;
		for (int j = 0; j < spotted.size(); j++)
			subs.insert(spotted[j].substr(i, a));
		for (int j = 0; j < plain.size(); j++)
			if (subs.find(plain[j].substr(i, a)) != subs.end())
				ok = false;
		if (ok)
			return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cownomics.in", "r", stdin); freopen("cownomics.out", "w", stdout);
	cin >> N >> M;
	int l = 1, r = M - 1, mid;
	plain = vector<string>(N);
	spotted = vector<string>(N);
	for (int i = 0; i < N; i++)
		cin >> spotted[i];
	for (int i = 0; i < N; i++)
		cin >> plain[i];
	for (;l < r;){
		mid = (l + r) / 2;
		if (test(mid)){
			r = mid;
		}
		else
			l = mid + 1;
	}
	cout << r;
	return 0;
}

