/*
ID: david.w4
TASK: sleepy
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
vector<int> ftree;
void update(int pos, int val)
{
    for(; pos < ftree.size(); pos += pos&-pos)
       ftree[pos] += val;
}
int query(int a)
{
     int sum = 0;
     for(; a > 0; a -= a&-a)
        sum += ftree[a];
     return sum;
}
void construct(vector<int> a){
	ftree = vector<int>(a.size(), 0);
	for (int i = 1; i < a.size(); i++)
		update(i, a[i]);
}
int main()
{
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	//ifstream fin("3.in");
	int N, outIndex = 0, rv, min;
	cin >> N;
	vector<int> cows(N);
	for (int i = 0; i < N; i++) {
		cin >> cows[i];
	}
	for (int i = 0; i < cows.size() - 1; i++)
		if (cows[i] > cows[i + 1])
			outIndex = i;
	construct(vector<int> (N + 1, 0));
	for (int i = outIndex + 1; i < cows.size(); i++) {
		update(cows[i], 1);
	}
	rv = outIndex + 1;
	min = cows[rv];
	cout << rv << "\n";

	for (int i = 0; i < outIndex + 1; i++) {
		//orderedCows.printBinaryTree(0);
		cout << query(cows[i]) + outIndex - i;
		if (i != outIndex)
			cout << " ";
		if (cows[i] < min)
			min = cows[i];
		update(cows[i], 1);
	}
}

