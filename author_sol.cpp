#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long s1 = 0;
		long long s2 = 0;
		// sort the vector in non-decreasing order
		sort(a.begin(), a.end());
		// add the elements at the end of the array alternately to the two variables and
		// everytime an element is added in a certain set, we need to remove that element,
		// execute this process 'k' times
		while (k--) {
			s1 += a.back();
			a.pop_back();
			s2 += a.back();
			a.pop_back();
		}
		// add the last value of the vector to 's2' because the 2nd player, gets another turn
		s2 += a.back();
		// find the maximum between the two sets
		cout << max(s1, s2) << '\n';
	}
	return 0;
}
