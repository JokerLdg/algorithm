#include <bits/stdc++.h>

using namespace std;

// 로프 문제
/*
N(1 ≤ N ≤ 100,000)개의 로프가 있다. 이 로프를 이용하여 이런 저런 물체를 들어올릴 수 있다. 각각의 로프는 그 굵기나 길이가 다르기 때문에 들 수 있는 물체의 중량이 서로 다를 수도 있다.
하지만 여러 개의 로프를 병렬로 연결하면 각각의 로프에 걸리는 중량을 나눌 수 있다. k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸리게 된다.
각 로프들에 대한 정보가 주어졌을 때, 이 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구해내는 프로그램을 작성하시오. 모든 로프를 사용해야 할 필요는 없으며, 임의로 몇 개의 로프를 골라서 사용해도 된다.
 */

#define endl "\n"

bool desc(int n1, int n2) {
    return n1 > n2;
}

int main() {

    int N;
    int input;
    cin >> N;

    vector<int> rope;

    for (int i=0; i<N; i++) {
        cin >> input;
        rope.push_back(input);
    }

    sort(rope.begin(), rope.end(), desc);

    // 문제풀이
    // 가장 작은 무게를 들 수 있는 로프가 들 수 있는 질량 * 병렬 연결 로프 갯수 = 최종 무게
    // 즉 rope[i] * (i+1)을 하고난 후, 가장 큰 값을 출력한다.
    for (int i=0; i<N; i++) {
        rope[i] = rope[i] * (i+1);
    }

    cout << *max_element(rope.begin(), rope.end()) << endl;

    return 0;
}
