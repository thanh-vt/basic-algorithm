Cho một đồ thị liên thông vô hướng (từ một đỉnh luôn tồn tại đường đi tới các đỉnh khác)

Hãy tính khoảng cách giữa một đỉnh `startVertex` tới tất cả các đỉnh khác trong đồ thị

Khoảng cách giữa hai đỉnh trong đồ thị được tính bằng số cạnh nối trong đường đi ngắn nhất từ đỉnh này tới đỉnh kia

Ví dụ:

-   Với `matrix = [[false, false, true],`\
    `          [false, false, true],`\
    `          [true, true, false]]` và `startVertex = 0`, thì kết quả `bfsDistancesUnweightedGraph(matrix, startVertex) = [0, 2, 1]`.

    Đồ thị trên và khoảng cách từ đỉnh `0` tới các đỉnh khác được miêu tả như hình dưới đây:\
    ![](https://codesignal.s3.amazonaws.com/tasks/bfsDistancesUnweightedGraph/img/example.png?_tm=1551432773367)

Đầu vào/Đầu ra

-   [Thời gian chạy] 3 seconds

-   [Đầu vào] array.array.boolean matrix\
    Ma trận kề của đồ thị vô hướng\
    *Điều kiện:*\
    `3 ≤ matrix.length ≤ 10`,\
    `matrix[i].length = matrix.length`.

-   [Đầu vào] integer startVertex\
    *Điều kiện:*\
    `0 ≤ startVertex ≤ matrix.length - 1`.

-   [Đầu ra] array.integer

    -   Một mảng chứa khoảng cách từ đỉnh bắt đầu `startVertex `đến từng đỉnh trong đồ thị

### Hướng dẫn bài tập.

Ngôn ngữ C#:

```
int[] BfsDistancesUnweightedGraph(bool[][] matrix, int startVertex)
{
    int[] distance = new int[matrix.Length];
    for(int i=0;i<distance.Length;i++)
    {
        distance[i] = -1;
    }
    distance[startVertex] = 0;
    Stack<int> queue = new Stack<int>();
    queue.Push(startVertex);
    while(queue.Count>0)
    {
        int top = queue.Pop();
        bool[] edges = matrix[top];
        for (int j = 0; j < edges.Length; j++)
        {
            if (edges[j])
                if (distance[j] == -1 || distance[j] > distance[top] + 1)
                {
                    distance[j] = distance[top] + 1;
                    queue.Push(j);
                }
        }
    }
    return distance;
}
```