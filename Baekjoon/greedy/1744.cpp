#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define endl '\n'

int main() {
    // 수 묶기 문제
    // cin, cout 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     *  0, 양수 = 덧셈
        0, 음수 = 곱셈

        1, 양수 = 덧셈
        1, 음수 = 덧셈
        즉, 1 = 덧셈

        양수, 양수 = 곱셈
        음수, 음수 = 곱셈
        양수, 음수 = 덧셈

        양수 리스트는 내림차순 정렬, 음수 리스트는 오름차순 정렬을 해준다.
        해당 리스트의 길이가 짝수이면 리스트의 숫자를 2개씩 곱해주면 최댓값이 나온다.
        홀수이면 마지막 숫자를 빼고 2개씩 곱해주고 마지막 수를 더해준다.
     */
    int N, n;
    int negative_size = 0;
    int positive_size = 0;
    cin >> N;
    int max = 0;
    vector<int> positive;
    vector<int> negative;

    for (int i=0; i<N; i++) {
        cin >> n;

        if (n == 1) {
            max += 1;
        } else if (n > 1) {
            positive.push_back(n);
        } else {
            negative.push_back(n);
        }
    }

    // 양수는 내림차순 정렬
    sort(positive.begin(), positive.end(), greater<>());

    // 음수는 오름차순 정렬
    sort(negative.begin(), negative.end());

    positive_size = positive.size();
    negative_size = negative.size();

    if (positive_size % 2 == 0) {
        for (int i=0; i<positive_size; i+=2) {
            max += positive[i] * positive[i+1];
        }
    } else {
        for (int i=0; i<positive_size-1; i+=2) {
            max += positive[i] * positive[i+1];
        }
        max += positive.back();
    }

    if (negative_size % 2 == 0) {
        for (int i=0; i<negative_size; i+=2) {
            max += negative[i] * negative[i+1];
        }
    } else {
        for (int i=0; i<negative_size-1; i+=2) {
            max += negative[i] * negative[i+1];
        }
        max += negative.back();
    }

    cout << max << endl;

    return 0;
}
