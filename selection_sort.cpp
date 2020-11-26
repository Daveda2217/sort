/*
selection sort

0~i-1 -> already sorted
i~n-1 -> to be sorted

1) 0~n-1 가장 작은 값 찾아서 index 0과 swap
2) 1~n-1 가장 작은 값 찾아서 index 1과 swap
...
반복
*/

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallest = i;
        for (int j = i + 1; j < n; j++)
        {
            // find smallest index
            if (arr[smallest] > arr[j])
                smallest = j; // update smallest index
        }
        // swap
        swap(arr[i], arr[smallest]);
    }
}

/*
The # of comparisons =  (n-1) + (n-2) + ... + 2 + 1
=> O(n^2) (Best, Worst)

Unstable
=> 4(1) 2 4(2) 1 5
=> 1 2 4(2) 4(1) 5

I think whether unstable or stable will be determined by whether the order is changed or not.
*/