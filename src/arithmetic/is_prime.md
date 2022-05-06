###Thuật toán kiểm tra số nguyên tố

Một số nguyên tố là một số tự nhiên lớn hơn `1` và không thể tạo thành từ tích của hai số tự nhiên nhỏ hơn.

Ví dụ số `2, 3, 5` được gọi là số nguyên tố

Viết một hàm xác định xem một số nguyên dương đã cho có phải là số nguyên tố hay không.

Ví dụ

-   Với `n = 47`, đầu ra là `isPrime(n) = true`

-   Với `n = 4`, đầu ra là `isPrime(n) = false`

Đầu vào/Đầu ra

-   [Giới hạn thời gian chạy] 0.5 seconds

-   [Đầu vào] integer n

    *Điều kiện tiền đề:*\
    `0 ≤ n ≤ 1000`.

-   [Đầu ra] boolean

    `true` nếu `n` là số nguyên tố, `false` nếu không phải.

Gợi ý:

-   Kiểm tra xem `n` có chia hết cho số nào trong khoảng từ `2` tới căn bậc `2` của `n` hay không? Nếu không thì `n` là số nguyên tố, ngược lại tức là `n` không phải là số nguyên tố.\
    Vì nếu `n` không chia hết cho các số từ `2` đến phần nguyên căn bậc hai của `n` thì cũng sẽ không chia hết cho các số từ phần tử từ phần nguyên căn bậc hai của `n` đến `n - 1`.

### Lý thuyết

Cách kiểm tra một số có phải một số nguyên dương n có phải số nguyên tố hay không ? 

-   Ta lần lượt xét các số từ `2` đến `n-1` và kiểm tra xem số đó có phải là ước của n hay không ? Nếu nó là ước của n thì ta trả về giá trị `*false*`

    ```
    bool isPrime(int n)
    {
        if (n <= 1) return false;
        for (int i = 2; i <= n-1; ++i)
            if (n % i == 0) return false;
        return true;
    }
    ​
    ```

-   *Độ phức tạp : `O(n)`*

Bạn có thể đọc phần gợi ý để biến nó về độ phức tạp chỉ O(√n).

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
```