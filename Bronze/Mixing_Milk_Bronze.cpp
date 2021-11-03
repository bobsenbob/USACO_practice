/*
ID: david.w4
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

struct bucket{
	int capacity;
	int amount;
	bucket() {}
	bucket(int c, int a) : capacity(c), amount(a) {}
};
vector<bucket> milks;
void pour(int index){
int target = (index + 1) % 3;
int poured = min(milks[target].capacity - milks[target].amount, milks[index].amount);
milks[target].amount += poured;
milks[index].amount -= poured;
}
int main()
{
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
	milks = vector<bucket>(3);
	int c, a;
	for (int i = 0; i < 3; i++){
	cin >> c >> a;
	milks[i] = bucket(c, a);
}
	for (int i = 0; i < 100; i++){
		pour(i % 3);
	}
	for (int i = 0; i < 3; i++){
		cout << milks[i].amount << "\n";
	}
	system("pause");

	return 0;
}

