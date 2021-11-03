/*
ID: david.w4
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
vector<bool> possible(2001);
void friday(int z,vector<int> a, vector<int> b){
	for (int i = 0; i < b.size(); i++){
		int x = b[i];
		possible[z + x] = true;
	}

}
void thursday(int z,vector<int> a, vector<int> b){
	for (int i = 0; i < a.size(); i++){
		int x = a[i];
		vector<int> newa = a;
		newa.erase(newa.begin() + i);
		vector<int> newb = b;
		newb.push_back(x);
		friday(z - x, newa, newb);
	}

}
void wednesday(int z,vector<int> a, vector<int> b){
	for (int i = 0; i < b.size(); i++){
		int x = b[i];
		vector<int> newb = b;
		newb.erase(newb.begin() + i);
		vector<int> newa = a;
		newa.push_back(x);
		thursday(z + x, newa, newb);
	}

}
void tuesday(int z,vector<int> a, vector<int> b){
	for (int i = 0; i < a.size(); i++){
		int x = a[i];
		vector<int> newa = a;
		newa.erase(newa.begin() + i);
		vector<int> newb = b;
		newb.push_back(x);
		wednesday(z - x, newa, newb);
	}

}
int main()
{
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);
	int rv = 0;
	vector<int> a(10);
	vector<int> b(10);
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	for (int i = 0; i < 10; i++)
		cin >> b[i];
	tuesday(1000, a, b);
	for (int i = 0; i < possible.size(); i++)
		if (possible[i]){
			rv++;
			//cout << i << "\n";
		}
	cout << rv;
	system("pause");
	return 0;
}

