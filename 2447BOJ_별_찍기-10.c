#include <stdio.h>

int N;
char map[2187][2187];

void print(int sy, int sx, int ey, int ex) {
  int dif = ey - sy;

  // base case
  if (dif == 2) {
    for (int y = sy; y <= ey; ++y) {
      for (int x = sx; x <= ex; ++x) {
        // conquer
        if (y == (sy + ey) / 2 && x == (sx + ex) / 2) continue;
        map[y][x] = 1;
      }
    }
    return;
  }

  // merge
  dif = (dif + 1) / 3 - 1;
  for (int y = sy; y <= ey; y += (1 + dif)) {
    print(y, sx, y + dif, sx + dif);
    print(y, ex - dif, y + dif, ex);
  }
  for (int x = sx + 1 + dif; x <= ex - dif; x += (1 + dif)) {
    print(sy, x, sy + dif, x + dif);
    print(ey - dif, x, ey, x + dif);
  }
}

int main(void) {
  scanf("%d", &N);
  print(0, 0, N - 1, N - 1);
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      if (map[y][x])
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }
}