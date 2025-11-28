#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sum = 0;
    cin >> n;

    string str;
    cin >> str;

    for (int i = 0; i < n; i++) {
        sum += str[i] - '0';
    }

    cout << sum << endl;

    return 0;
}
