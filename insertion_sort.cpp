/*
1. 0번째 index는 sort 되었다고 가정하자.
2. 그 다음 index부터는 알맞은 자리에 insert 해준다.
3. 즉, 자기 자신보다 작은 index와 compare해서 본인보다 작은 값이 
올때 까지 순회한다.
*/

void insert_sort(int arr[], int n)
{
    int j, key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i]; // 여기서 자기 자신의 값이 key 값이다.
        for (j = i - 1; j >= 0; j--)
        {
            if (key < arr[j])        // 만약 key값보다 더 큰 값이 온다면
                arr[j + 1] = arr[j]; // 그 큰 값을 오른쪽으로 이동 시켜준다.
            else
                break; // key값보다 더 작은 값이 온다면 그 index+1자리가 key의 자리이다.
        }
        arr[j + 1] = key;
    }
}

/*
Best : O(n)
Worst : O(n^2)

Stable
*/
