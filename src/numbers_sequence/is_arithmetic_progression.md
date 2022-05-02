Trong [toán học](https://vi.wikipedia.org/wiki/To%C3%A1n_h%E1%BB%8Dc "Toán học"), một cấp số cộng (tiếng Anh: *arithmetic progression* hoặc *arithmetic sequence*) là một [dãy số](https://vi.wikipedia.org/wiki/D%C3%A3y_s%E1%BB%91_th%E1%BB%B1c "Dãy số thực") thoả mãn điều kiện: hai phần tử liên tiếp nhau sai khác nhau một hằng số. Chẳng hạn, dãy số `3, 5, 7, 9, 11,...` là một cấp số cộng với các phân tử liên tiếp sai khác nhau hằng số `2`.

Cho một mảng số nguyên. Hãy kiểm tra xem nó có tạo thành một cấp số cộng hay không?

Ví dụ

-   Với `sequence = [1, 4, 7]`, thì kết quả `isArithmeticProgression(sequence) = true`;
-   Với `sequence = [2, 4, 7]`, thì kết quả `isArithmeticProgression(sequence) = false`.

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.integer sequence\
    Mảng các số nguyên\
    *Điều kiện:*\
    `3 ≤ sequence.length ≤ 10`,\
    `-10 ≤ sequence[i] ≤ 10`.

-   [Đầu ra] boolean

    `true` nếu `sequence` là một cấp số cộng, `false` nếu ngược lại.

### Lý thuyết 

Dãy cấp số cộng - *arithmetic sequence*

Định nghĩa: một cấp số cộng là một [dãy số](https://vi.wikipedia.org/wiki/D%C3%A3y_s%E1%BB%91_th%E1%BB%B1c "Dãy số thực") thoả mãn điều kiện: hai phần tử liên tiếp nhau sai khác nhau một hằng số. Chẳng hạn, dãy số `3, 5, 7, 9, 11,...` là một cấp số cộng với các phân tử liên tiếp sai khác nhau hằng số `2`.

Tính chất:

-   Số hạng thứ n của một dãy số cấp số cộng là: `an = a1 + (n-1) * d` , với `d = a2 - a1`
-   Tổng của n phần tử đầu tiên là: `Sn = n*(2*a1 + (n-1)*d) / 2`

Kiểm tra một dãy số A có phải một cấp số cộng hay không ?

-   Xét từng chỉ số `i (1 <= i < A.size())` và kiểm tra xem đẳng thức `A[i]-A[i-1] = A[2]-A[1]` đúng hay không ?

Bài toán mở rộng: Cho trước một dãy cấp số cộng dài vô hạn và có `2` phần tử đầu tiên là `A` và `B`. Hỏi xem số `C` có thuộc dãy cấp số cộng đó hay không ?

-   Để giải được bài toán này ta sẽ áp dụng tính chất số hạng thứ `n` của dãy cấp số cộng.
-   Gỉa sử `C` là phần tử thứ `n` của dãy cấp số cộng. Ta có `C = A + (n-1) * (B-A)` ⇒ `n-1 = (C-A) / (B-A)` ⇒ phần tử `C` thuộc dãy cấp số cộng khi và chỉ khi `(C-A) % (B-A) = 0`

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
bool isArithmeticProgression(std::vector<int> sequence)
{
    if (sequence.size() == 1)
        return true;
    int k = sequence[1] - sequence[0];
    for (int i = 1; i < sequence.size(); i++)
        if (sequence[i]-sequence[i-1]!=k)
            return false;
    return true;
}
```