int partition(int arr[], int left, int right)
{
    int pivot = arr[left]; // 가장 왼쪽의 값을 pivot으로 선택하자.
    int low = left + 1;    // pivot 바로 앞에 있는 값을 low로 선택하자.
    int high = right;      // high는 right값으로 선택하자.

    while (1)
    {
        while (low < right && arr[low] < pivot)
            // right를 넘어가지 않고 pivot보다 작은 값들은 pass
            low++;
        while (high > left && arr[high] > pivot)
            // left를 넘어가지 않고 pivot보다 큰 값들은 pass
            high--;
        if (low < high)
            // 서로 엇갈리지 않았다면 swap해준다.
            swap(arr[low], arr[high]);
        else
            break;
    }
    swap(arr[left], arr[high]); // pivot값을 high값과 swap한다.
    return high;
}

void quick_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = partition(arr, left, right);
        // partition함수를 통해 pivot을 기준으로 왼쪽은 pivot보다 작은 값
        // 오른쪽은 pivot보다 큰 값으로 나뉜다.

        // pivot을 중심으로 왼쪽, 오른쪽 sub array들을 재귀호출한다.
        quick_sort(arr, left, mid - 1);
        quick_sort(arr, m + 1, right);
    }
}

/*
Average : T(n) = 2T(n/2) + cn 
이와 같이 계속 반반으로 나뉜다면
=> O(nlogn)

Worst : T(n) = T(n-1) + cn = T(n-2) + 2cn = ...
이와 같이 split이 하나의 element와 나머지로 계속 나뉜다면
(예를 들어, 내림차순으로 정렬된 arr라면)
=> O(n^2)
*/

/*
quick_sort의 time complexity는 pivot selection에 의존한다.

따라서 pivot의 선택에는 다양한 방법이 존재한다.
1. random
2.(1st, middle, last)의 중간 값
*/