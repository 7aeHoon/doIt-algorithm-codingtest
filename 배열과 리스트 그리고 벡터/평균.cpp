#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, max;
    double sum = 0;
    vector<double> v;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        v.push_back(score);
    }

    max = *max_element(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        v[i] = v[i] / max * 100;
    }

    for (int i = 0; i < n; i++) {
        sum += v[i];
    }

    cout << sum / n << endl;

    return 0;
}
