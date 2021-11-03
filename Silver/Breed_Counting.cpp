/*
ID: david.w4
TASK: bcount
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	int N, Q, hi = 0, lo = 0;
	cin >> N >> Q;
	vector<int> breeds(N);
	vector<int> pair(2);
	vector<int> tri(3);
	vector<vector<int> > queries(N, pair); 
	vector<vector<int> > cows(N + 1, { 0, 0, 0 });
	vector<vector<int> >results(Q, { 0, 0, 0 });
	//stores all breed numbers in vector
	for (int i = 0; i < breeds.size(); i++)
		cin >> breeds[i];
	for (int i = 0; i < Q; i++) {
		cin >> queries[i][0] >> queries[i][1];
	}
	//cows[1][breeds[0] - 1]++;
	for (int i = 0; i < breeds.size(); i++)
	{
		cows[i + 1] = cows[i];
		cows[i + 1][breeds[i] - 1]++;
	}
	for (int i = 0; i < Q; i++)
	{
		lo = queries[i][0];
		hi = queries[i][1];
		results[i][0] = cows[hi][0] - cows[lo - 1][0];
		results[i][1] = cows[hi][1] - cows[lo - 1][1];
		results[i][2] = cows[hi][2] - cows[lo - 1][2];
	}
	for (int i = 0; i < Q; i++)
		//cout << breeds[i][0] << " " << queries[i][1] << "\n";
		//cout << cows[i][0] << " " << cows[i][1] << " " << cows[i][2] << "\n";
		cout << results[i][0] << " " << results[i][1] << " " << results[i][2] << "\n";

}

