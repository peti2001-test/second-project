#include<stdlib.h>
void swap(int *p, int *q)
{
    *p = *p + *q;
    *q = *p - *q;
    *p = *p - *q;
}

void bubbleSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n-i-1; j++)
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

void insertionSort(int arr[], int n)
{
    int key, j;
    for(int i = 1; i<n; i++)
    {
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid-low+1;
    int n2 = high - mid;

    int *l,*r;

    l = (int*)malloc(n1*sizeof(int));
    r = (int*)malloc(n2*sizeof(int));

    for (int i = 0; i < n1; i++)
        l[i] = arr[low + i];
    for(int i = 0; i< n2; i++)
        r[i] = arr[mid + 1 + i];

    int i=0, j=0, k=low;

    while (i<n1 && j<n2)
    {
        if (l[i]<=r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
    
}

void mergeSort(int arr[], int low, int high)
{
    if(low<high)
    {    
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high], i = low-1;

    for(int j = low; j<=high-1; j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    i++;
    swap(&arr[i], &arr[high]);
    
    return i;
}

void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int q = partition(arr, low, high);
        quickSort(arr, low, q-1);
        quickSort(arr, q+1, high);
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (int i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j]<arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
    
}
