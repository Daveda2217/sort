/*
단순히 생각하면 
매 순회마다 가장 큰 값이
맨 뒤로 간다.
*/

void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    { // 순회 해야할 arr size는 점점 줄어든다.
        for (int j = 0; j < i; j++)
        {
            // 0부터 i까지 가장 큰 값을 찾아서
            // 해당 sub arr 맨 뒤로 보내준다.
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1])
        }
    }
}

/*
O(n^2) (Best, Worst)

Stable => keep order
*/
