#include <iostream>
#include <queue>

using namespace std;
#define endl '\n'

int main() {
    // 카드 정렬하기
    // cin, cout 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    priority_queue<int, vector<int>, greater<int>> queue;
    int minimum = 0;
    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
    } else {
        int n;
        for (int i=0; i<N; i++) {
            cin >> n;
            queue.push(n);
        }

        while (queue.size() > 1) {
            int A = queue.top();
            queue.pop();
            int B = queue.top();
            queue.pop();

            minimum += A + B;
            queue.push(A+B);
        }

        cout << minimum << endl;
    }

    return 0;
}
