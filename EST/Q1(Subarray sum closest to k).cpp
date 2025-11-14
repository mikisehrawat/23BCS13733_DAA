#include <bits/stdc++.h>
using namespace std;

int closestSubarraySumToK(int a[], int n, int k) {
    set<int> pref;
    int prefix = 0;
    int bestDiff = INT_MAX;
    int bestSum = 0;

    for (int i = 0; i < n; i++) {
        prefix += a[i];
        pref.insert(prefix);

        if (pref.find(k) != pref.end())
            return k;

        auto it = pref.lower_bound(prefix - k);

        if (it != pref.end()) {
            int candidate = prefix - *it;
            if (abs(candidate - k) < bestDiff) {
                bestDiff = abs(candidate - k);
                bestSum = candidate;
            }
        }

        if (it != pref.begin()) {
            --it;
            int candidate = prefix - *it;
            if (abs(candidate - k) < bestDiff) {
                bestDiff = abs(candidate - k);
                bestSum = candidate;
            }
        }

        if (abs(prefix - k) < bestDiff) {
            bestDiff = abs(prefix - k);
            bestSum = prefix;
        }
    }

    return bestSum;
}

int main() {
    int a[] = { -5, 12, -3, 4, -15, 6, 1 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2;

    cout << closestSubarraySumToK(a, n, k);
    return 0;
}
