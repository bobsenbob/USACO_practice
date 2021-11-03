/*
ID: david.w4
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct animal{
vector<string> characteristics;
animal() {}
animal(int l) : characteristics(vector<string>(l)) {};
};
void printVector(vector<string> a){
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << "\n";
}
bool bsAnimal(vector<string> a, string element){
	int l, r, mid;
	l = 0, r = a.size() - 1;
	for (;l < r;){
		mid = (l + r + 1)/2;
		//cout << mid << " " << a[mid] << "\n";
		if (a[mid] == element)
			return true;
		if (a[mid] < element)
			l = mid + 1;
		else
			r = mid - 1;

	}
	if (a[r] == element)
			return true;
	//cout << "\n";
	return false;
}
int compareAnimals(animal a, animal b){
	int rv = 0;
	vector<string> d = a.characteristics;
	sort (d.begin(), d.end());
	//printVector(d);
	for (int i = 0; i < b.characteristics.size(); i++)
		if (bsAnimal(d, b.characteristics[i]))
			rv++;
	return rv;
}
int main()
{
	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);
	int N, z, rv = 0;
	string a;
	cin >> N;
	vector<animal> animals(N);
	for (int i = 0; i < N; i++){
		cin >> a >> z;
		animals[i] = animal(z);
		for (int j = 0; j < z; j++)
			cin >> animals[i].characteristics[j];
	}
	for (int i = 0; i < animals.size() - 1; i++)
		for (int j = i + 1; j < animals.size(); j++)
			rv = max(rv, compareAnimals(animals[i], animals[j]));
	cout << rv + 1;
	system("pause");
	return 0;
}

