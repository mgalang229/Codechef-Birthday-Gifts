#include <bits/stdc++.h>

using namespace std;

long long GetMax(long long a, long long b) {
	return (a > b ? a : b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		// store 'k' to 'temp' because both twins have the same number of turns (2 * k)
		int temp = k;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long first_set = 0;
		long long second_set = 0;
		// sort the vector in non-increasing order
		sort(a.rbegin(), a.rend());
		// create a 'last_index' variable to store the last index used by the second twin
		int last_index = -1;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0 && k > 0) {
				// if the element is placed in an even position, then store it in the 'first_set'
				first_set += a[i];
				// decrement 'k' turns
				k--;
			} else if (temp > 0) {
				// otherwise, if the element is placed in an odd position, then store it in the 'second_set'
				second_set += a[i];
				// store the last index used
				last_index = i;
				// decrement 'temp' turns
				temp--;
			}
		}
		if (last_index + 1 < n) {
			// if 'last_index' plus one is still less than 'n', then add this value to the
			// 'second_set' because the second twin (last turn) gets an additional one element
			second_set += a[last_index + 1];
		}
		// find the maximum value between the two sets
		cout << GetMax(first_set, second_set) << '\n';
	}
	return 0;
}
