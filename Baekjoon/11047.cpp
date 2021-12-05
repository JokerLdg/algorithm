#include <bits/stdc++.h>

using namespace std;

// 동전 0 문제
/*
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.
 */
bool desc(int n1, int n2) {
    return n1 > n2;
}

int main() {

    int N, K;
    int count = 0;
    cin >> N >> K;

    int coins[N];

    for (int i=0; i < N; i++) {
        cin >> coins[i];
    }
    
    // 문제에는 오름차순으로 입력받는다고 하였으나, 내림차순 정렬을 해줘야함.
    sort(coins, coins+N, desc);
    
    // 내림차순 정렬 순서대로 값 구하기
    for (int i=0; i<N; i++) {
        count += K / coins[i];
        K %= coins[i];
    }

    cout << count << "\n";

    return 0;
}
