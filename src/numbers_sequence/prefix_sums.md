Cho mảng `a` chứa các số nguyên

Xây dựng mảng `b` là [prefix sums](keyword://prefix-sums) (từ này không dịch ra tiếng Việt do hơi chuối) của mảng `a `cụ thể theo công thức:

```
  b[0]   = a[0]
  b[1]   = a[0] + a[1]
  b[2]   = a[0] + a[1] + a[2]
  ...
  b[n - 1] = a[0] + a[1] + ... + a[n - 1]

```

với `n` là độ dài của mảng `a`.

Ví dụ

-   Với `a = [1, 2, 3]`, thì kết quả `prefixSums(a) = [1, 3, 6]`.\
    Mảng `b` được tạo ra: `[1, 1 + 2, 1 + 2 + 3] = [1, 3, 6]`

Đầu vào/đầu ra:

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.integer a\
    *Điều kiện tiền đề:*\
    `3 ≤ a.length ≤ 104`,\
    `-1000 ≤ a[i] ≤ 1000`.

-   [Đầu ra] array.integer.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
std::vector<int> prefixSums(std::vector<int> a)
{
    std::vector <int> b;
    b.push_back(a[0]);
    for (int i = 1; i<a.size(); i++)
    b.push_back(b[i-1] + a[i]);
    return b;
}
```