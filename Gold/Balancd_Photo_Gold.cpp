#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
public:
	SegmentTree(int count) {
		n = count;
		data = vector<int>(2 * n, 0);
	}
	SegmentTree(vector<int> const& values) {
		n = values.size();
		data = vector<int>(2 * n);
		copy(values.begin(), values.end(), data.begin() + n);
		for (int idx = n - 1; idx > 0; idx--){
			data[idx] = (data[idx * 2] + data[idx * 2 + 1]);
		}
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
			if (left & 1) ret += (data[left++]);
			if (right & 1) ret += (data[--right]);
			left >>= 1;
			right >>= 1;
		}
		return ret;
	}
private:
	int n;
	vector<int> data;
};
struct cow{
	int height;
	int index;
	cow() {}
	cow(int h, int i) : height(h), index(i) {}
	bool operator<(const cow &other) const{
		return height > other.height;
	}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("bphoto.in", "r", stdin); freopen("bphoto.out", "w", stdout);
	int N, a, rv = 0, l, r;
	cin >> N;
	vector<cow> cows(N);
	SegmentTree seg = SegmentTree(vector<int>(N, 0));
	for (int i = 0; i < N; i++){
		cin >> a;
		cows[i] = cow(a, i);
	}
	sort(cows.begin(), cows.end());
	for (int i = 0; i < cows.size(); i++){
		seg.update(cows[i].index, 1);
		l = seg.sum(0, cows[i].index);
		r = seg.sum(cows[i].index + 1, cows.size());
		if (max(l, r) > 2 * min(l, r))
			rv++;
	}
	cout << rv;
	return 0;
}

