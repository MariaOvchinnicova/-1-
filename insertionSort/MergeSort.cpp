void merge(int arr[], int left, int mid, int right)
{
    int i = 0, j = 0, k = 0;
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];
    for ( i = 0; i <= mid - left; i++) 
    {
        leftArr[i] = arr[left + i];
    }
    for ( i = 0; i < right - mid; i++) 
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    i = 0; j = 0; k = 0;
    while (i < leftSize && j < rightSize) 
    {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        }
        else {
            arr[k++] = rightArr[j++];
        }
    }
    while (i < leftSize) 
    {
        arr[k++] = leftArr[i++];
    }
    while (j < rightSize) 
    {
        arr[k++] = rightArr[j++];
    }

    delete[]leftArr;
    delete[]rightArr;
}


void MergeSort(int arr[], int left, int right) 
{
    if (left >= right) 
        return;
    
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    
    merge(arr, left, mid,right);
}

