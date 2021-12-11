#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool desc(int n1, int n2) {
    return n1 > n2;
}

int main() {
    string N;
    // cin, cout 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    // 내림차순 정렬
    sort(N.begin(), N.end(), desc);

    // 0이 아닌경우 30의 배수가 될 수 없기 때문에 -1 출력
    if(N[N.length()-1] != '0') {
        cout << -1 << endl;
    } else {
        long long sum = 0;
        for (auto o:N) {
            sum += o - '0';
        }

        if (sum % 3 == 0) {
            cout << N << endl;
        } else {
            cout << -1;
        }
    }

    return 0;
}
