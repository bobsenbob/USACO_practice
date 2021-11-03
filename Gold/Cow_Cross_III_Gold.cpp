/*
ID: dwang5766
TASK: 
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
public:
	SegmentTree(int count) {
		n = count;
		data = std::vector<int>(2 * n, 0);
	}

	SegmentTree(std::vector<int> const& values) {
		n = values.size();
		data = std::vector<int>(2 * n);
		std::copy(values.begin(), values.end(), &data[0] + n);
		for (int idx = n - 1; idx > 0; idx--)
			data[idx] = (data[idx * 2] + data[idx * 2 + 1]);
	}

	void update(int idx, int value) {
		idx += n;
		data[idx] = value;

		while (idx > 1) {
			idx /= 2;
			data[idx] = (data[2 * idx] + data[2 * idx + 1]);
		}
	}

	int sum(int left, int right) { // interval [left, right)
		int ret = 0;
		left += n;
		right += n;

		while (left < right) {
			//cout << "left: " << left << "right: " << right << "\n";
			if (left & 1) ret += (data[left++]);
			if (right & 1) ret += (data[--right]);
			left >>= 1;
			right >>= 1;

		}
		return ret;
	}
	void printBinaryTree(int level) {
		int z = n;
		for (int i = 0; i < level; i++)
			z /= 2;

		for (int i = z; i < 2 * z; i++)
			cout << data[i] << " ";
		cout << "\n";
		if (z > 1)
			printBinaryTree(level + 1);
	}
private:
	int n;
	vector<int> data;
};
map<int, int> sizeW;
bool in(int a){
	return sizeW.count(a) == 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("circlecross.in", "r", stdin); freopen("circlecross.out", "w", stdout);
	int N, rv = 0;
	cin >> N;
	vector<int> order(2 * N);
	for (int i = 0; i < 2 * N; i++)
		cin >> order[i];
	vector<int>sub(2 * N, 0);
	SegmentTree q(sub);
	for (int i = 0; i < order.size(); i++){
		//entry
		if (!in(order[i])){
			sizeW.insert({order[i], i});
			q.update(i, 1);
		}
		//exit
		else{
			q.update(sizeW[order[i]], 0);
			rv += abs(q.sum(sizeW[order[i]], i));
		}
		//q.printBinaryTree(0);
		//cout << "\n";
	}
	cout << rv;
	return 0;
}

