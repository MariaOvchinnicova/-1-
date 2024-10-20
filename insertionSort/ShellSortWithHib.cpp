#include <corecrt_math.h>
void shellSortWithHib(int arr[], int n)
{
    for (int gap = pow(2, (int)(log(n) / log(2))) - 1; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap; j -= gap)
                if (arr[j - gap] > temp)
                    arr[j] = arr[j - gap];
                else
                    break;
            arr[j] = temp;
        }
    }

}
