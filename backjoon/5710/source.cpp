#include <stdio.h>

int tolls[] = {2, 3, 5, 7};
int watts[] = {100, 10000 - 100, 1000000 - 10000, 1000000000};

int calculateUsage (int toll, int i)
{
  if (toll <= tolls[i] * (long long int)watts[i]) {
#ifdef _DEBUG
    printf("toll: %d, i: %d => %d\n", toll, i, toll / tolls[i]);
#endif
    return toll / tolls[i];
  } else {
    return watts[i] + calculateUsage(toll - (watts[i] * tolls[i]), i + 1);
  }
}

int calculateToll (int usage, int i)
{
  if (usage <= watts[i]) {
    return usage * tolls[i];
  } else {
    return (tolls[i] * watts[i]) + calculateToll(usage - watts[i], i + 1);
  }
}

int solveCase (int A, int B)
{
  int totalUsage = calculateUsage(A, 0);
  int s = 0, e = totalUsage / 2;
  while (s <= e) {
    int mid = (s + e) / 2;

    int diff = calculateToll(totalUsage - mid, 0) - calculateToll(mid, 0);
    if (diff == B) {
      s = mid;
      break;
    } else if (diff < B) {
      e = mid - 1;
    } else { // diff > B
      s = mid + 1;
    }
  }

  return calculateToll(s, 0);
}

int main ()
{
#ifdef _DEBUG
  printf("%d\n", calculateUsage(100000000, 0));
#endif
  while (true) {
    int A, B;
    scanf("%d %d", &A, &B);
    if (!A && !B) {
      break;
    }
    printf("%d\n", solveCase(A, B));
  }
  return 0;
}
