void count_sort(int arr[], int n)
{
    int cnt[MAX_SIZE] = {
        0,
    };
    int output[MAX_SIZE];

    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
    }

    // index 계산?????
    // 잘 이해가 안되는 부분이다.
    // radix sort에도 나오는 부분이다.
    for (int i = 1; i < MAX_SIZE; i++)
    {
        cnt[i] += cnt[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        output[cnt[arr[i]] - 1] = arr[i];
        cnt[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}