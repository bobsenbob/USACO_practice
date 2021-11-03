/*
ID: david.w4
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> cows;
vector<int> reciever;
vector<int> passing;
int pass(int index) {
	if (index == 0)
		return 1;
	if (index == cows.size() - 1)
		return cows.size() - 2;
	int right = cows[index + 1] - cows[index];
	int left = cows[index] - cows[index - 1];
	if (left <= right)
		return index - 1;
	return index + 1;
}

int main()
{
	freopen("hoofball.in", "r", stdin);
	freopen("hoofball.out", "w", stdout);
	int N, rv = 0;
	cin >> N;
	cows = vector<int>(N);
	reciever = vector<int>(N, 0);
	passing = vector<int>(N);
	for (int i = 0; i < N; i++)
		cin >> cows[i];
	sort(cows.begin(), cows.end());
	for (int i = 0; i < N; i++) {
		reciever[pass(i)]++;
		passing[i] = pass(i);
	}
	for (int i = 0; i < cows.size(); i++){
		if (reciever[i] == 0)
			rv++;
		if (passing[i] == i + 1 && passing[i + 1] == i && reciever[i] == 1 && reciever[i + 1] == 1)
			rv++;
	}
	cout << rv;

}

