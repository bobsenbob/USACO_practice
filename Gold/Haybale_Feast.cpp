
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
long long tastySum(long long it1, long long it2, vector<long long> tasty) {
	long long sum = 0;
	for (long long i = it1; i <= it2; i++) {
		sum += tasty[i];
	}
	return sum;
}
long long maxSpicy(long long it1, long long it2, vector<long long> spicy) {
	long long max = 0;
	for (long long i = it1; i < it2; i++)
		if (spicy[i] > max)
			max = spicy[i];
	return max;
}
int main()
{
	//ifstream fin("6.in");
	freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);
	long long N, M, it1 = 0, it2 = 0, maximum = 0, tastyTotal = 0;
	long long min = 0;

	cin >> N >> M;
	vector<long long> tasty(N);
	vector<long long> spicy(N);
	vector<long long> spiceness(0);
	for (long long i = 0; i < N; i++) {
		cin >> tasty[i] >> spicy[i];
	}
	//cout << "check";
	while (it2 < N) {

		tastyTotal = tastySum(it1, it2, tasty);
		//finds next interval starting from it1 that satisfies the minimum taste
		while (tastyTotal < M) {
			it2++;
			if (!(it2 < N))
				break;
			tastyTotal += tasty[it2];
			//cout << "it1 " << it1 << " it2 " << it2 << " tasty " << tastyTotal << " M " << M << "\n";
			//its++;
		}
		//cout << "check";
		//cout << maximum;
		//cout << tastyTotal;
		maximum = maxSpicy(it1, it2, spicy);
		if (tastyTotal >= M)
			spiceness.push_back(maximum);
		while (tastyTotal >= M) {
			//cout << "check2";
			tastyTotal -= tasty[it1];
			it1++;
			//cout << "it1 " << it1 << " it2 " << it2 << " tasty " << tastyTotal << " M " << M << "\n";
			//its++;
		}
		for (it1;it1 < it2 && spicy[it1] != maximum; it1++);
		it1++;
	}
	for (long long i = 0; i < spiceness.size(); i++);
	//	cout << spiceness[i];
	min = spiceness[0];
	for (long long i = 1; i < spiceness.size(); i++)
		if (spiceness[i] < min)
			min = spiceness[i];
	//cout << "\n" << its << "\n";
	cout << min;
}