#include <bits/stdc++.h>
using namespace std;
vector<long long> rem {1, 2, 4, 7, 8, 11, 13, 14};
int main()
{
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);
	long long N, left, spoken;
	cin >> N;
	long long num = (N - 1)/ 8;
	spoken = 15 * (num);
	left = ((N - 1) % 8);
	cout << spoken + rem[left] << "\n";
	return 0;
}

