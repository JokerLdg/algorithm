#include <iostream>

using namespace std;
#define endl '\n'

int main() {
    // 기타줄 문제
    // cin, cout 최적화
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     * N : 끊어진 기타줄의 개수
     * M : 기타 줄 브랜드 개수
     */

    int N, M;
    int x, y;
    int set_price = 1000, ea_price = 1000;
    int min_price = 0;
    cin >> N >> M;

    /*
     * 문제 풀이
     * 1. 세트, 낱개의 최솟값을 구하여 set와 ea변수에 대입한다.
     * 2. 공식
     *  1) ((사야할 개수 / 6)+1) * 세트 가격 : 사야할 기타줄을 전부 세트로만 살경우
     *  2) ((사야할 개수 / 6) * 세트 가격) + ((사야할 개수 % 6) * 낱개 가격): 세트 + 낱개로 사는경우
     *  3) 사야할 개수 * ea : 낱개로만 사는경우
     *  -> 위의 3개의 공식을 대입하면 밑과 같이 나온다.
     *  -> min(( (N/6)+1)*set_price, min( (N/6)*set_price + (N%6)*ea_price, N*ea_price))
     */

    while (M--) {
        cin >> x >> y;
        set_price = min(set_price, x);
        ea_price = min(ea_price, y);
    }

    min_price = min(( (N/6)+1)*set_price, min( (N/6)*set_price + (N%6)*ea_price, N*ea_price));
    cout << min_price << endl;

    return 0;
}
