#include "bubble.h"

int main(int argc, char * argv[])
{
  if (argc < 2) {
    printf("Usage: bubble <integer> <integer> ...");
    exit(1);
  }

  int numsCount = argc-1;
  int * nums = malloc(numsCount*sizeof(int));

  for (int i = 0; i < numsCount; i++)
    nums[i] = atoi(argv[i+1]);

  bubbleSort(nums, numsCount);
  printIntArray(nums, numsCount);

  free(nums);
  return 0;
}

void bubbleSort(int * arr, int len) {
  int swaps = 1;
  int iterations = 1;
  while (swaps > 0)
  {
    swaps = 0;
    for (int i = 0; i < len-iterations; i++)
    {
      if (arr[i] > arr[i+1])
      {
        int tmp = arr[i+1];
        arr[i+1] = arr[i];
        arr[i] = tmp;
        swaps++;
        // printIntArray(arr, len-iterations+1);
      }
    }
    iterations++;
    // if (swaps > 0)
    //   printf("Sorted after %d with %d swaps\n\n", len-iterations, swaps);
  }
}

void printIntArray(int * arr, int len)
{
  int i;
  printf("\n[");
  for (i = 0; i < len-1; ++i)
    printf("%d, ", arr[i]);
  printf("%d]\n\n", arr[i]);
}