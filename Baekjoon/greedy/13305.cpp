#include <iostream>
#include <algorithm>

using namespace std;
#define endl '\n'

long long N;
long long roads[100001];
long long costs[100001];

int main() {
    // 주유소
    // cin, cout 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i=0; i<N-1; i++) {
        cin >> roads[i];
    }

    for (int i=0; i<N; i++) {
        cin >> costs[i];
    }

    long long answer = roads[0] * costs[0];
    long long min_cost = costs[0];

    for (int i=1; i<=N-1; i++) {
        if (min_cost > costs[i]) {
            min_cost = costs[i];
        }
        answer += min_cost * roads[i];
    }

    cout << answer << endl;

    return 0;
}
