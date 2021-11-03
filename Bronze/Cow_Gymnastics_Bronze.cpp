/*
ID: dwang5766
TASK: gymnastics
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> rankings;
vector<vector<int>> placing;
bool consistent(int a, int b){
	for (int i = 0; i < placing.size(); i++){
		if (placing[i][a] > placing[i][b])
			return false;
	}
	return true;
}
int main()
{
	//freopen("gymnastics.in", "r", stdin);
	//freopen("gymnastics.out", "w", stdout);
	int K, N, rv = 0;
	cin >> K >> N;
	rankings = vector<vector<int>> (K, vector<int>(N));
	placing = vector<vector<int>> (K, vector<int>(N));
	for (int i = 0; i < K; i++)
		for (int j = 0; j < N; j++){
			cin >> rankings[i][j];
			placing[i][rankings[i][j]] = j;
		}
	for (int i = 0; i < rankings[0].size(); i++){
		for (int j = i + 1; j < rankings[0].size(); j++)
			if (consistent(rankings[0][i], rankings[0][j]))
				rv++;
	}
	//cout << consistent(4, 2);
	cout << rv;
	system("pause");
	return 0;
}

