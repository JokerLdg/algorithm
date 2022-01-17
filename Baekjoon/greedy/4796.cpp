#include <iostream>

using namespace std;
#define endl '\n'

int main() {
    // 캠핑
    // cin, cout 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L, P, V;
    int index = 1;
    int answer;
    while (true) {
        cin >> L >> P >> V;
        if (L + P + V == 0) {
            break;
        }

        answer = ((V/P) * L) + min(V%P, L);
        cout << "Case " << index << ": " << answer << endl;
        index += 1;
    }

    return 0;
}
