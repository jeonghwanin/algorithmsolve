// 추론
// 1. 각 행에는 1개의 퀸이 존재해야한다.
// 2. 대칭을 활용하여 경우의 수를 모두 세지 않아도 된다.

// 쪼개기
// 행에 퀸을 놓는 것을 조각으로 쪼개기
// n행 퀸 경우의 수 = 첫행 퀸 놓기 + n-1행 퀸 경우의 수

#include <stdio.h>

int mask[15];
int qx[15];

int N;

int sv(int n) {
  // base case
  if (n >= N) return 1;

  int sum = 0;

  for (int i = 0; i < N; ++i) {
    // 열검사
    if (mask[i]) continue;
    // 대각선 검사
    int check = 1;
    for (int j = 0; j < n; ++j) {
      int dy = j - n;
      int dx = qx[j] - i;
      if (dy == dx || dy + dx == 0) {
        check = 0;
        break;
      }
    }
    if (!check) continue;
    mask[i] = 1;
    qx[n] = i;
    // inductive case
    sum += sv(n + 1);

    // restore mask
    mask[i] = 0;
  }

  return sum;
}

int main(void) {
  scanf("%d", &N);
  printf("%d\n", sv(0));
  return 0;
}