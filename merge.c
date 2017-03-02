#include "merge.h"

int main(int argc, char * argv[])
{
  if (argc < 2) {
    printf("Usage: merge <integer> <integer> ...");
    exit(1);
  }

  int numsCount = argc-1;
  int * nums = malloc(numsCount*sizeof(int));

  for (int i = 0; i < numsCount; i++)
    nums[i] = atoi(argv[i+1]);

  mergeSort(nums, numsCount);
  printIntArray(nums, numsCount);

  free(nums);
  return 0;
}

void merge(int * arr, int * left, int * right, int leftCount, int rightCount)
{
  int a=0, l=0, r=0;

  while (l < leftCount && r < rightCount)
  {
    if (left[l] < right[r])
      arr[a++] = left[l++];
    else
      arr[a++] = right[r++];
  }

  while (l < leftCount)
    arr[a++] = left[l++];
  while (r < rightCount)
    arr[a++] = right[r++];
}

void mergeSort(int * arr, int len) {
  if (len < 2)
    return;

  int i, mid, leftCount, rightCount, * left, * right;

  mid = len/2;
  leftCount = mid;
  rightCount = len-mid;

  left = malloc(leftCount*sizeof(int));
  right = malloc(rightCount*sizeof(int));
  
  for (int i = 0; i < mid; i++)
    left[i] = arr[i];
  
  for (int i = mid; i < len; i++)
    right[i-mid] = arr[i];

  mergeSort(left, leftCount);
  mergeSort(right, rightCount);

  merge(arr, left, right, leftCount, rightCount);

  free(left);
  free(right);
}

void printIntArray(int * arr, int len)
{
  int i;
  printf("\n[");
  for (i = 0; i < len-1; ++i)
    printf("%d, ", arr[i]);
  printf("%d]\n\n", arr[i]);
}