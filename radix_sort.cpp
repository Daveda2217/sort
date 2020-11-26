// radix_sort 이론을 잘 이해했다면
// 코드 분석에 큰 어려움이 없을 것이다.
void counting(int arr[], int n, int exp)
{
    int cnt[10] = {
        0,
    };
    int output[MAX_SIZE];

    for (int i = 0; i < n; i++)
    {
        cnt[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        cnt[i] += cnt[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[cnt[(arr[i] / exp) % 10] - 1] = arr[i];
        cnt[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radix_sort(int arr[], int n)
{
    int max_element = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (max_element < arr[i])
            max_element = arr[i];
    }

    for (int exp = 1; max_element / exp > 0; exp *= 10)
    {
        counting(arr, n, exp);
    }
}