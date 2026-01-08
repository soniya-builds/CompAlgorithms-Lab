#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), [](auto x, auto y) {
        return x.second < y.second;
    });

    int cnt = 1;
    int lastEnd = a[0].second;

    cout << a[0].first << " " << a[0].second << "\n";

    for (int i = 1; i < n; i++) {
        if (a[i].first >= lastEnd) {
            cout << a[i].first << " " << a[i].second << "\n";
            lastEnd = a[i].second;
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
