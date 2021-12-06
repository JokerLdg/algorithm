#include <bits/stdc++.h>

using namespace std;

// 보물 문제
/*
옛날 옛적에 수학이 항상 큰 골칫거리였던 나라가 있었다. 이 나라의 국왕 김지민은 다음과 같은 문제를 내고 큰 상금을 걸었다.
길이가 N인 정수 배열 A와 B가 있다. 다음과 같이 함수 S를 정의하자.

S = A[0] × B[0] + ... + A[N-1] × B[N-1]

S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안 된다.
S의 최솟값을 출력하는 프로그램을 작성하시오.
 */

#define endl "\n"

bool desc(int n1, int n2) {
    return n1 > n2;
}

int main() {

    int N;
    int input;
    int min = 0;

    cin >> N;

    int A[N];
    int B[N];

    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    for (int i=0; i<N; i++) {
        cin >> B[i];
    }

    sort(A, A+N);
    sort(B, B+N, desc);

    for (int i=0; i<N; i++) {
        min += A[i] * B[i];
    }

    cout << min << endl;

    return 0;
}
