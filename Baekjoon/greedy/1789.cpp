#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {
    // cin, cout 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long S;
    long long sum = 0, num = 1;
    int count = 0;

    cin >> S;

    // 1부터 차례대로 더하다가 값이 초과되면 현재까지 더한 숫자의 개수 -1이 답.
    while (S >= sum) {
        sum += num;
        count++;
        num++;
    }

    cout << count-1 << endl;

    return 0;
}
