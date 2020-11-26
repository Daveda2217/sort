void Merge(int arr[], int left, int mid, int right)
{
    int sorted[MAX_SIZE]; // merge_sort는 additional memory가 필요하다.
    int first = left;     // mid를 기준으로 2개의 sub arr에 대해 첫번째 index 값들을 설정하자.
    int second = mid + 1;
    int i = left; // sorted array의 시작 index 값이다.

    while (first <= mid && second <= right)
    {
        if (arr[first] <= arr[second])
        {                               // 더 작은 값을 sorted array에 넣어주자.
            sorted[i++] = arr[first++]; // 넣어주면서 한칸 앞으로 전진
        }
        else
        {
            sorted[i++] = arr[second++];
        }
    }

    if (first > mid)
    { // first ~ mid range는 다 채웠다면 second ~ right까지 그대로 이어서 붙여준다.
        for (int j = second; j <= right; j++)
        {
            sorted[i++] = arr[j];
        }
    }
    else
    {
        for (int j = first; j <= mid; j++)
        {
            sorted[i++] = arr[j];
        }
    }

    // 정렬된 배열을 복사해서 넣어준다..
    for (int j = left; j <= right; j++)
    {
        arr[j] = sorted[j];
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

// ************************************************
// Bottom-up method (no need for additional space)

void iter_merge_sort(int arr[], int n)
{
    for (int size = 1; size < n; size = size * 2)
    { // 1, 2, 4, 8, ... (size of subarray)
        for (int left_start = 0; left_start < n - 1; left_start += 2 * size)
        { // 2*size씩 jump하면서 2개의 sub array를 merge해준다.
            int mid = left_start + size - 1;
            int right_end = min(n - 1, left_start + size * 2 - 1);
            // n-1은 배열의 맨 마지막 값이고
            // bottom-up 방식은 2의 거듭제곱의 형태로 size가 증가하기 때문에
            // n-1과 left_start_size*2-1의 값 중 작은 값을 right_end로 두어야
            // segment fault가 일어나지 않는다.

            Merge(arr, left_start, mid, right_end);
        }
    }
}

/*
always O(nlogn)

stable
*/