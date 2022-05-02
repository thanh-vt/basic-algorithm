Cho một mảng các số nguyên, bạn hãy viết hàm kiểm tra xem các phần tử của mảng có tạo thành một dãy số tăng dần hoặc giảm dần hay không, nếu có `return true`, ngược lại `return false`.

Ví du

-   Với `sequence = [1, 4, 5, 7, 9]`, thì kết quả là `isMonotonous(sequence) = true`
-   Với `sequence = [0]`, thì kết quả là `isMonotonous(sequence) = true`;
-   Với `sequence = [3, 3]`, thì kết quả là `isMonotonous(sequence) = false`.\
    Giải thích: 2 phần tử bằng nhau không tạo thành dãy tăng hay dãy giảm.

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.integer sequence\
    *Điều kiện:*\
    `1 ≤ sequence.length ≤ 10`,\
    `-250 ≤ sequence[i] ≤ 250`.

-   [Đầu ra] boolean

    -   `true` nếu `sequence` là dãy tăng hoặc dãy giảm, `false` trong trường hợp ngược lại.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
bool isMonotonous(std::vector<int> sequence)
{
    if (sequence.size() == 1)
        return true;
    if (sequence.size() == 2)
        return (sequence[0] != sequence[1]);
    for (int i = 2; i < sequence.size(); i++)
        if ((sequence[i-1] - sequence[i-2])*(sequence[i]-sequence[i-1]) <= 0)
            return false;
    return true;
}
```