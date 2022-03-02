###Thuật toán tìm Factor Sum

Chúng ta có một số nguyên dương `n.` Mỗi một lần ta thay thế `n` bằng tổng các thừa số nguyên tố của nó (ví dụ `12=2*2*3` thì `12` sẽ được thay thế bằng số `2+2+3=7`)

Chúng ta áp dụng phép toán này vào số hiện tại cho đến khi kết quả thu được giống vs số hiện tại

Cho một số tự nhiên, hãy tìm kết quả cuối cùng của phép toán trên.

Ví dụ:

-   Với `n = 24`, kết quả `factorSum(n) = 5`.\
    `24 -> (2 + 2 + 2 + 3) = 9 -> (3 + 3) = 6 -> (2 + 3) = 5 -> 5`.\
    Vì vậy kết quả trong trường hợp `n = 24` là `5`.

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] integer n

    *Điều kiện:*\
    `2 ≤ n ≤ 200`.

-   [Đầu ra] integer

### Lý thuyết

Cách kiểm tra một số nguyên dương n có phải một số nguyên tố hay không ? 

-   Nhận thấy rằng một số nguyên `n > 1` không phải là một số nguyên tố khi và chỉ khi `n` có thể biểu diễn dưới dạng : `n = x * y`, với `x,y` là hai số nguyên dương lớn hơn `1`.
    -   Giả sử răng `x ≤ y ⇒ x * x ≤ x * y = n ⇒ x ≤ √n` 
    -   Từ nhận xét trên ta thấy rằng để kiểm tra xem `n` có chia hết cho một số nào nhỏ hơn nó hay không ta chỉ việc xét các số từ `2` đến `√n` thay vì xét các số từ `2` đến `n-1` như *Cách 1 *

        ```
        bool isPrime(int n)
        {
            if (n <= 1) return false;
            for (int i = 2; i <= sqrt(n); ++i)
                if (n % i == 0) return false;
            return true;
        }

        ```

-   *Độ phức tạp : `O(√n)`*

Hướng dẫn bài tập.
------------------

Với bài tập này ta không cần nhất thiết phải kiểm tra số nguyên tố.

Code mẫu:

Ngôn ngữ C++:

```
int solve(int n){
    int k = 2, sum = 0;
    while (n > 1){
        while (n % k == 0){
            sum += k;
            n /= k;
        }
        k++;
    }
    return sum;
}
int factorSum(int n)
{
    while (n != solve(n))
        n = solve(n);
    return n;
}
```