#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        long long U, D;
        cin >> N >> U >> D;

        vector<long long> H(N);
        for (int i = 0; i < N; i++) {
            cin >> H[i];
        }

        bool parachuteUsed = false;
        int answer = 1;

        for (int i = 0; i < N - 1; i++) {
            long long curr = H[i];
            long long next = H[i + 1];

            if (next == curr) {
                answer++;
            }
            else if (next > curr) {
                if (next - curr <= U) {
                    answer++;
                } else {
                    break;
                }
            }
            else {
                if (curr - next <= D) {
                    answer++;
                }
                else if (!parachuteUsed) {
                    parachuteUsed = true;
                    answer++;
                }
                else {
                    break;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
