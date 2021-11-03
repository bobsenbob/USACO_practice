/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> original;
vector<int> final;
vector<int> target;
void printVector(vector<int> a) {
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << "\n";
}
int shift(int start, int targ, int origin){
	//printVector(original);
	//printVector(target);
	//cout << "start: " << start << " target: " << targ << " origin: " << origin << "\n";
	if (targ == origin){
		original[targ] = original[start];
		return 1;
	}
	int originalVal = original[start];
	int rv = shift(target[original[start] - 1], target[original[target[original[start] - 1]] - 1], origin) + 1;
	original[target[originalVal - 1]] = originalVal;
	return rv;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("reorder.in", "r", stdin); freopen("reorder.out", "w", stdout);
	int N, shifts = 0, longest = -1;
	cin >> N;
	original = vector<int>(N);
	final = vector<int>(N);
	target = vector<int>(N);
	for (int i = 0; i < N; i++)
		cin >> original[i];
	for (int i = 0; i < N; i++){
		cin >> final[i];
		target[final[i] - 1] = i;
	}
	for (int i = 0; i < N; i++){
		if (original[i] != final[i]){
			longest = max(longest, shift(i, target[original[i] - 1], i));
			shifts++;
			//printVector(original);
		}
	}
	cout << shifts << " " << longest << "\n";
	return 0;
}

