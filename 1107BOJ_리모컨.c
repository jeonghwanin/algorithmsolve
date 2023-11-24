// 숫자를 먼저 누르고 이동해야함
// 숫자 조각으로 쪼갬

#include <stdio.h>

int N, M;
int C[10];
int ans = 21e8;

void sv(int level, int value) {
  if (level > 7) return;
  int dif;
  if (level == 0) {
    dif = 100 - N;
  } else {
    dif = value - N;
  }
  if (dif < 0) dif *= -1;

  if (ans > dif + level) ans = dif + level;

  for (int i = 0; i < 10; ++i) {
    if (C[i]) continue;
    sv(level + 1, value * 10 + i);
  }

  return;
}

int main(void) {
  scanf("%d", &N);
  scanf("%d", &M);
  int j;
  for (int i = 0; i < M; ++i) {
    scanf("%d", &j);
    C[j] = 1;
  }
  sv(0, 0);
  printf("%d\n", ans);
}