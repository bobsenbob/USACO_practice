/*
ID: dwang5766
TASK: whereami
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
set<string> passed;
bool done(string b){
	return (passed.find(b) != passed.end());
}
bool check(string mail, int test){
	passed.clear();
	for (int i = 0; i <= mail.length() - test; i++){
			if (done(mail.substr(i, test))){
				return false;
			}
			else
				passed.insert(mail.substr(i, test));
			//printvector(a);
		}
	return true;
}
void printvector(vector<string> a){
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << "\n";
}
int main()
{
	//freopen("whereami.in", "r", stdin);
	//freopen("whereami.out", "w", stdout);
	int N, rv = 1;
	bool repeat = true;
	cin >> N;
	string mail;
	cin >> mail;
	int l = 1, r = mail.length();
	for (;l < r;){
		cout << "d" << "l" << l << "r" << r << "\n";
		int mid =( l + r) / 2;
		if (check(mail, mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << r;
	system("pause");
	return 0;
}

