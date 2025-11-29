#include <bits/stdc++.h>

using namespace std;

int N, M;
int r1, c1, r2, c2;
int a[1025][1025];
int s[1025][1025];

void init() {}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        cout << s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1] << '\n';
    }

    return 0;
}
