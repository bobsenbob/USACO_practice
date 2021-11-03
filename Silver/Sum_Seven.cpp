/*
ID: david.w4
TASK: div7
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
	//ifstream fin("10.in");
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	long long N, res,currMax = 0;
	cin >> N;
	vector<long long> ids(N);
	vector<long long> sums(N);
	//long long ids[50000];
	//long long sums[50000];
	vector<int> preSums(N);
	for (long long i = 0; i < N; i++) 
		cin >> ids[i];
	sums[0] = ids[0];
	for (int i = 1; i < N; i++)
		sums[i] = sums[i - 1] + ids[i];
	for (int i = 0; i < N; i++)
		preSums[i] = sums[i] % 7;
	for (int i = N - 1; i >= 0; i--)
		for (int j = 0; j < i; j++) {
			if (i - j <= currMax)
				break;
			if ((preSums[i] - preSums[j]) == 0){
					currMax = i - j;
					break;
				}
		}
	cout << currMax;

}

