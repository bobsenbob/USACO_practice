/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> spotted;
vector<string> plain;
vector<vector<int>> S;
vector<vector<int>> P;
bool test(int a, int b, int c){
	set<string> included;
	for (int i = 0; i < spotted.size(); i++)
		included.insert(spotted[i].substr(a, 1) + spotted[i].substr(b, 1) + spotted[i].substr(c, 1));
	for (int i = 0; i < plain.size(); i++)
		if (included.count(plain[i].substr(a, 1) + plain[i].substr(b, 1) + plain[i].substr(c, 1)) != 0)
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("cownomics.in", "r", stdin); freopen("cownomics.out", "w", stdout);
	int N, M, rv = 0;
	cin >> N >> M;
	spotted = vector<string>(N);
	plain = vector<string>(N);
	for (int i = 0; i < N; i++){
		cin >> spotted[i];
		for (int j = 0; j < M; j++){
			if (spotted[i][j]=='A') S[i][j] = 0;
      		if (spotted[i][j]=='C') S[i][j] = 1;
      		if (spotted[i][j]=='G') S[i][j] = 2;
      		if (spotted[i][j]=='T') S[i][j] = 3;
    	}
	}
	for (int i = 0; i < N; i++){
		cin >> plain[i];
		for (int j = 0; j < M; j++){
			if (plain[i][j]=='A') P[i][j] = 0;
      		if (plain[i][j]=='C') P[i][j] = 1;
      		if (plain[i][j]=='G') P[i][j] = 2;
      		if (plain[i][j]=='T') P[i][j] = 3;
    	}
	}
	for (int i = 0; i < M; i++)
		for (int j = i + 1; j < M; j++)
			for (int k = j + 1; k < M; k++)
				if (test(i, j, k))
					rv++;
	cout << rv;
	return 0;
}

