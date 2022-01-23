#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define endl '\n'

int main() {
    // 보석 도둑 문제
    // cin, cout 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     * 우선순위 큐를 이용하여 담을 수 있는 보석의 무게를 전부 가방에 집어넣고 최댓값을 빼서 더한다.
     */

    int N, K;
    long long max = 0;
    cin >> N >> K;

    vector<pair<int, int>> jewelry(N);
    vector<int> weights(K);
    priority_queue<int> pq;

    for (int i=0; i<N; i++) {
        cin >> jewelry[i].first >> jewelry[i].second;
    }

    for (int i=0; i<K; i++) {
        cin >> weights[i];
    }

    sort(jewelry.begin(), jewelry.end()); // 보석의 무게를 기준으로 오름차순
    sort(weights.begin(), weights.end()); // 가방의 무게를 기준으로 오름차순

    int index = 0;

    for (int i=0; i<K; i++) {
        while (index < N && jewelry[index].first <= weights[i]) {
            pq.push(jewelry[index++].second);
        }

        if (!pq.empty()) {
            max += (long long) pq.top();
            pq.pop();
        }
    }

    cout << max << endl;

    return 0;
}
