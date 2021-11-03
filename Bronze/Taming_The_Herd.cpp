/*
ID: david.w4
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
	int N, rv = 0, m = 0, M = 0;
	cin >> N;
	vector<int> logs(N);
	for (int i = 0; i < N; i++)
		cin >> logs[i];
	logs[0] = 0;
	for (int i = logs.size() - 1; i > 0; i--){
		if (logs[i] > 0 && (logs[i - 1] != -1 && logs[i - 1] != logs[i] - 1)){
			cout << -1;
			system("pause");
			return 0;
		}	
		else if (logs[i] > 0)
			logs[i - 1] = logs[i] - 1;
	}
	vector<int> minCopy = logs;
	for (int i = 1; i < minCopy.size(); i++)
		if (minCopy[i] == -1)
			minCopy[i] == minCopy[i - 1] + 1;
	for (int i = 0; i < minCopy.size(); i++)
		if (minCopy[i] == 0)
			m++;
	for (int i = 0; i < logs.size(); i++)
		if (logs[i] == -1)
			logs[i] = 0;
	for (int i = 0; i < logs.size(); i++)
		if (logs[i] == 0)
			M++;
	cout << m << " " << M << "\n";
	system("pause");
	return 0;
}

