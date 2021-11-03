/*
ID: david.w4
TASK: rental
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;
struct milker {
	int gallons;
	int price;
	milker (int g, int p) : gallons(g), price(p){}
	milker(){}
};

bool priceSort(const milker& a, const milker& b) {
	return a.price > b.price;
}

int main()
{
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	//ifstream cin("5.in");
	int N, M, R, farmerIt = 0, renterIt = 0, left = 0, cowIt = 0, sold = 0;
	bool recalc = true;
	long long profit = 0;
	cin >> N;
	cin >> M;
	cin >> R; 
	vector<int> cows(N);
	vector<milker> farmers(M);
	vector<int> renters(R);
	for (int i = 0; i < N; i++)
		cin >> cows[i];
	for (int i = 0; i < M; i++) {
		cin >> farmers[i].gallons;
		cin >> farmers[i].price;
	}
	for (int i = 0; i < R; i++)
		cin >> renters[i];
	sort(cows.rbegin(), cows.rend());
	sort(farmers.begin(), farmers.end(), priceSort);
	sort(renters.rbegin(), renters.rend());
	cowIt = cows.size() - 1;
	left = cows.size();
	int price = 0, vendors = R + M;
	if (R == 0)
		renters.push_back(0);
	if (M == 0)
		recalc = false;
	for (int i = 0; i < cows.size() && left > 0 && vendors > 0; ) {
		//if (farmerIt > 49500)
		//cout << farmerIt << "|" << renterIt << "|" << left << "|" << vendors << "|" << profit << "\n";
		if (recalc) {
			//price = priceCalc(farmers, cows[i], farmerIt);
			int rv = 0, sold = 0, selling = cows[i], farmIt = farmerIt;
			//cout << "sur";
			for (; selling > 0 && farmIt < farmers.size();) {
				sold = min(selling, farmers[farmIt].gallons);
				selling -= sold;
				rv += farmers[farmIt].price * sold;
				if (selling > 0)
					farmIt++;
			}
			price = rv;
			//cout << "san";
			recalc = false;
		}
		//cout << "sig";
		if (renterIt >= renters.size() || price > renters[renterIt]) {
			recalc = true;
			profit += price;
			left--;
			//cout << "cow " << cows[i] << " milked for " << price << "\n";
			for (; cows[i] > 0 && farmerIt < farmers.size();) {
				sold = min(cows[i], farmers[farmerIt].gallons);
				cows[i] -= sold;
				farmers[farmerIt].gallons -= sold;
				if (cows[i] > 0) {
					farmerIt++;
					vendors--;
				}
			}
			//cout << "sag";
			i++;
			
		}
		else {
			left--;
			int price = renters[renterIt];
			profit += price;
			renterIt++;
			//cout << "cow " << cows[cowIt] << " rented for " << price << "\n";
			cowIt--;
			vendors--;
		}

			

	}
	cout << profit;
}

