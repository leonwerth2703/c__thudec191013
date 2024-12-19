#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<pair<long long, long long> > intervals;

    for (int i = 0; i < N; i++) {
        long long s, t;
        cin >> s >> t;
        if (s > t) {
            intervals.push_back({t, s});
        }
    }

    sort(intervals.begin(), intervals.end());

    vector<pair<long long, long long> > merged;
    if (!intervals.empty()) {
        long long start = intervals[0].first, end = intervals[0].second;
        for (int i = 1; i < (int) intervals.size(); i++) {
            long long s = intervals[i].first, e = intervals[i].second;
            if (s <= end) {
                if (e > end) end = e;
            } else {
                merged.push_back({start, end});
                start = s;
                end = e;
            }
        }
        merged.push_back({start, end});
    }

    long long total_length = 0;
    for (auto &iv: merged) {
        total_length += (iv.second - iv.first);
    }

    long long ans = M + 2LL * total_length;
    cout << ans;

    return 0;
}
