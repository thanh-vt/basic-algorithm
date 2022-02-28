###Thuật toán tính tổng các số nguyên tố nhỏ hơn 1 số cho trước

Một bài nâng cao từ bài [kiểm tra số nguyên tố](https://codelearn.io/LearningTask/Index?Id=3477&TaskId=3831):

Cho số nguyên `n,` hãy tính tổng các số nguyên tố nhỏ hơn hoặc bằng `n

`Bởi vì tổng các số nguyên tố nhỏ hơn hoặc bằng `n` có thể rất lớn, nên hãy trả ra kết quả của tổng trên dưới dạng là số dư trong phép chia của tổng trên cho `22082018`.

Example

-   Với `n = 2` thì `primeSum(n) = 2`
-   Với `n = 3` thì `primeSum(n) = 5`

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 giây
-   [Đầu vào] integer n\
    `-10^7 < n < 10^7 `
-   [Đầu ra] integer

Gợi ý:

-   Kiểm tra và tính tổng các số nguyên tố từ `1` tới `n` có thể tốn nhiều thời gian
-   Để tăng tốc tìm các số nguyên tố, có thể sử dụng [sàng Eratosthenes](https://vi.wikipedia.org/wiki/S%C3%A0ng_Eratosthenes)

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
bool a[10000001];
void snt(int n){
    for (int i = 2; i <= n; i++)
        a[i]=1;
    a[0] = a[1] = 0;
    for (int i = 2; i <= sqrt(n); i++)
    if (a[i])
        for (int j = 2 * i; j <= n; j += i)
            a[j] = 0;
}
int primeSum(int n)
{
    int mod = 22082018;
    snt(n);
    int d = 0;
    for (int i = 2; i <= n; i++)
        if (a[i]) d = (d + i % mod) % mod;
    return d;
}
```
