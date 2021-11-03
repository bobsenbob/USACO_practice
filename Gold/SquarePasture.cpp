/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct cow{
	int x;
	int y;
	cow() {}
	cow (int xx, int yy) : x(xx), y(yy) {}
};
bool sortX (cow a, cow b){
	return a.x < b.x;
}
bool sortY (cow a, cow b){
	return a.y < b.y;
}
void printCows(vector<cow> a){
	for (cow i : a){
		cout << "(" << i.x << ", " << i.y << ")" << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, a, b;
	int window = 1;
	int rv = 1, count = 0;
	cin >> N;
	vector<cow> cows(N);
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		cows[i] = cow(a, b);
	}
	sort(cows.begin(), cows.end(), sortX);
	printCows(cows);
	for (int window = 1; window <= N; window++){
		for (int start = 0; start <= N - window; start++){
			int size = cows[start + window - 1].x - cows[start].x;
			if (size < abs(cows[start + window - 1].y - cows[start].y)){
				continue;
			}
			vector<cow> temp(0);
			for (int i = start; i < start + window; i++){
				temp.push_back(cows[i]);
			}	
			sort(temp.begin(),temp.end(), sortY);
			int low = max(cows[start].y, cows[start + window - 1].y) - size;
			int high = min(cows[start].y, cows[start + window - 1].y);
			for (int i = 0; i < temp.size() && temp[i].y <= high; i++){
				cout << start << " " << start + window - 1 << " " << temp[i].y << "\n";
				if (temp[i].y < low){
					cout << "SKIPPED" << "\n";
					continue;
				}
				rv++;
			}
			//might change to binary search later
			//need to be able to query min and max x in range of temp in log(N)
			//i is the start of the vertical interval that we're checking

		}
	}
	sort(cows.begin(), cows.end(), sortY);
	printCows(cows);
	cout << rv;
	return 0;
}

