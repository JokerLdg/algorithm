#include <iostream>
#include <algorithm>

using namespace std;
#define endl '\n'

const int MAX = 100000;

int main() {
    // cin, cout 최적화®
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        pair<int, int> score[MAX];

        for (int i=0; i < N; i++) {
            cin >> score[i].first >> score[i].second;
        }

        sort(score, score+N);
        int answer = 1;
        int temp = score[0].second;
        for (int i=1; i < N; i++) {
            if (score[i].second < temp) {
                answer++;
                temp = score[i].second;

                if (temp == 1) {
                    break;
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}
