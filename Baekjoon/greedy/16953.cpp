#include <iostream>

using namespace std;
#define endl '\n'

int main() {
    // A -> B 문제
    // cin, cout 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     * 1. A 가 B 보다 크면 값을 구할 수 없음
     * 2. B를 10으로 나눴을 때 나머지가 1 이어야 한다.
     * 3. B를 2로 나눴을 때 나머지가 0 이어야 한다.
     * 4. 반복문을 돌린다.
     * 5. B를 10으로 나눴을 때 나머지가 1이면 B를 10으로 나눈다.
     * 6. 5번이 안되면 B를 2로 나눈다.
     */

    int count = 1;
    int A, B;

    cin >> A >> B;

    while (true) {
        if (A == B) {
            break;
        } else if (((B % 10 != 1) && (B % 2 != 0)) || (A > B)) {
            count = -1;
            break;
        } else {
            if (B % 10 == 1) {
                B /= 10;
            } else {
                B /= 2;
            }
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
