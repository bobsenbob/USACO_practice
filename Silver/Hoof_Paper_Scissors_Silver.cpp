/*
ID: david.w4
TASK: hps
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int N, rv = 0;
	char a;
	cin >> N;
	vector<int> moves(N);
	//0 is before, 1 is after
	vector<vector<int>> count(2, vector<int>(3, 0));
	//0 = H, 1 = P, 2 = S
	for (int i = 0; i < N; i++){
		cin >> a;
		if (a == 'H'){
			moves[i] = 0;
			count[0][0]++;
		}
		else if (a == 'P'){
			moves[i] = 1;
			count[0][1]++;
		}
		else{
			moves[i] = 2;
			count[0][2]++;
		}
	}
	for (int i = 0; i < moves.size(); i++){
		count[1][moves[i]]++;
		count[0][moves[i]]--;
		rv = max(rv, max(max(count[0][0], count[0][1]), count[0][2]) + max(max(count[1][0], count[1][1]), count[1][2]));
	}
	cout << rv;
	return 0;
}

