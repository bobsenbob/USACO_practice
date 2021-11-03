/*
ID: david.w4
TASK: maxcross
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	int N, K, B, off, count = 0, rv = INT_MAX;
	cin >> N >> K >> B;
	int start = 0, end = K - 1;
	vector<int> crosswalks(N, 0);
	for (int i = 0; i < B; i++){
		cin >> off;
		crosswalks[off - 1] = 1;
	}
	for (int i = 0; i < K; i++)
		count += crosswalks[i];
	for (;end < N;){
		count -= crosswalks[start];
		start++, end++;
		count += crosswalks[end];
		rv = min(rv, count);
	}
	cout << rv;
	system("pause");
	return 0;
}

