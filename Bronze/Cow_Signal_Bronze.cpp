/*
ID: dwang5766
TASK: cowsignal
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("cowsignal.in", "r", stdin);
	freopen("cowsignal.out", "w", stdout);
	int X, Y, K;
	cin >> Y >> X >> K;
	vector<string> signal (Y);
	string doubled;
	char a;
	for (int i = 0; i < Y; i++)
		cin >> signal[i];
	for (int i = 0; i < Y; i++){
		doubled = "";
		for (int j = 0; j < signal[i].length(); j++){
			a = signal[i].at(j);
			for (int z = 0; z < K; z++)
				doubled += a;
		}
		signal[i] = doubled;
	}
	for (int i = 0; i < K * Y; i++)
		cout << signal[i / K] << "\n";
	system("pause");
	return 0;
}

