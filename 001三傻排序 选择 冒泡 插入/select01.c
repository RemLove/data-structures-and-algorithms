#include <stdio.h>

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//1.选择排序
//在 i到n-1的位置选择最下的数 和i互换位置 然后继续i+1到n-1
void select_sort(int arr[],int length)
{
    for(int i=0;i<length;i++)
    {
        int minIndex = i;
        for(int j=i;j<length;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}
//2.冒泡排序
//0到i的位置 相邻的较大数一直滚下去 最大的数最终来到i位置 然后继续0到i-1
void bubble_sort(int arr[],int length)
{
    for(int i=length-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
//3.插入排序
//0到i的位置已经是有序的 新来的数和前面的数比较 找到合适的位置插入
void insert_sort(int arr[],int length)
{
    if(arr==NULL || length<2)
    {
        return;
    }
    for(int i=1;i<length;i++)
    {
        for(int j=i;j>0&&arr[j]<arr[j-1];j--)
        {
            swap(&arr[j], &arr[j-1]);
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for(int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    select_sort(arr, length);
    printf("Sorted array (Selection Sort): ");
    for(int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, length);
    printf("Sorted array (Bubble Sort): ");
    for(int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insert_sort(arr, length);
    printf("Sorted array (Insertion Sort): ");
    for(int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}