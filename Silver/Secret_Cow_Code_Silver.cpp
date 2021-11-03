/*
ID: david.w4
TASK: cowcode
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
long long predecessor(long long place, long long length){
	place--;
	if (place < 1)
		place = length;
	return place;
}
int main()
{
	freopen("cowcode.in", "r", stdin);
	freopen("cowcode.out", "w", stdout);
	string a;
	long long N, cycle = 1, index;
	cin >> a >> N;
	cycle = a.length();
	for (;cycle < N; cycle *= 2){}
	cycle /= 2;
	index = N;
	for (;cycle >= a.length(); cycle /= 2){
		if (index <= cycle)
			continue;
		index = (index - 1)% cycle + 1;
		index = predecessor(index, cycle);
		//cout << "c: " << cycle << " i: " << index << "\n";
	}
	cout << a[index - 1] << "\n";
	system("pause");
	return 0;
	
}

