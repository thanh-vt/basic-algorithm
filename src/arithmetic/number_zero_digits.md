###Thuật toán tính số chữ số 0 tận cùng của n!

Cho số tự nhiên `n`.\
Hãy tính số chữ số 0 tận cùng của `n!` (`n!` (hay còn gọi là `n` giai thừa) là tích các số tự nhiên liên tiếp từ `1` tới `n`)

Ví dụ:

-   Với `n = 5`, `n! = 1*2*3*4*5 = 120`, vì vậy `numberZeroDigits(n) = 1`

Đầu ra/Đầu vào:

-   Đầu vào: integer n\
    `1 <= n <= 10^12`
-   Output:\
    Số chữ số `0` tận cùng của `n!`
-   Thời gian chạy: 0.5 giây

Gợi ý:

-   Chú ý `n` rất lớn nếu các bạn dùng thuật toán duyệt từ `1` tới `n` chắc chắn ko chạy đc trong thời gian cho phép
-   Số chữ số `0` tận cùng có thể hiểu bằng số lần chia hết cho `10` của `n!`
-   Vì `10 = 2*5` (số lần chia hết cho `10` tính bằng số lần chia hết cho `2` và cho `5`). Hãy dùng công thức toán học + vòng lặp đơn giản để giải quyết việc này.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
long long numberZeroDigits(long long n)
{
    long long d = 0;
    long long k = 5;
    while (k <= n){
        d += n / k;
        k *= 5;
    }
    return d;
}
```
