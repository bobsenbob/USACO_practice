/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> nums;
void swap(int a, int b){
	int s = nums[a];
	nums[a] = nums[b];
	nums[b] = s;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("sort.in", "r", stdin); freopen("sort.out", "w", stdout);
	int N, rv = 0;
	cin >> N;
	nums = vector<int>(N);
	for(int i = 0; i < N; i++)
		cin >> nums[i];
	bool sorted = false;
	while (!sorted){
		sorted = true;
		rv++;
		for (int i = 0; i < N - 1; i++)
			if (nums[i + 1] < nums[i])
				swap(i, i + 1);
		for (int i = N - 2; i >= 0; i--)
			if (nums[i + 1] < nums[i])
				swap(i, i + 1);
		for (int i = 0; i < N - 1; i++)
			if (nums[i + 1] < nums[i]){
				sorted = false;
			}
	}
	cout << rv;
	return 0;
}

