You are given an array of integers. Sort it in such a way that if `a` comes before `b` then the sum of digits of `a` is less than or equal to the sum of digits of `b`. If two numbers have the same sum of digits, the smaller one (in the regular sense) should come first.

Cho mảng số nguyên. Hãy sắp xếp chúng theo nguyên tắc:

-   `a` đứng trước `b` nếu tổng các chữ số của `a` nhỏ hơn `b\
    `
-   Nếu hai số có tổng các chữ số bằng nhau, số nào nhỏ hơn sẽ đứng trước. Ví dụ `4` và `13` có tổng chữ số bằng nhau, nhưng `4 < 13` nên `4` sẽ đứng trước `13` trong mảng kết quả

Ví dụ

-   Ví dụ `a = [13, 20, 7, 4]`, kết quả `digitalSumSort(a) = [20, 4, 13, 7]`.

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.integer a\
    Mảng các số nguyên\
    *Điều kiện:*\
    `4 ≤ a.length ≤ 20`\
    `1 ≤ a[i] ≤ 1000`

-   [Đầu ra] array.integer\
    Mảng đã được sắp xếp theo yêu cầu đề bài

### Lý thuyết 

Thuật toán: Counting sort - Sắp xếp bằng đếm phân phối

-   Trong trường hợp mà các giá trị của dãy số có giá trị dương nhỏ (Ví dụ: `A[i] ≤ 106`) thì ta có thể sử dụng đếm phân phối để sắp xếp dãy số.
-   Mô tả thuật toán:
    -   Gọi giá trị nhỏ nhất của dãy là `minVal` và giá trị lớn nhất của dãy là `maxVal`.
    -   Với các giá trị `x` mà `minVal <= x <= maxVal`, đếm xem số lần xuất hiện của `x` trong dãy `A`.
    -   Chạy giá trị `x` từ `minVal` đến `maxVal`, gọi số lần xuất hiện của `x` trong dãy `A` là `cnt_x` thì bỏ vào mảng kết quả `cnt_x` lần giá trị `x`
-   ```
    int Count[1000005];
    std::vector<int> sortArray(std::vector<int> arr)
    {
        int maxVal = 0;
        for (int i = 0; i < (int) arr.size(); ++i) {
            int x = arr[i];

            /// tìm giá trị lớn nhất của dãy
            maxVal = max(maxVal, x);

            /// đếm xem số lần xuất hiện của giá trị x trong dãy
            Count[x]++;
        }

        vector<int> ans;
        for (int i = 1; i <= maxVal; ++i)
            for (int j = 1; j <= Count[i]; ++j) ans.push_back(i);
        return ans;
    }

    ```

-   Độ phức tạp: *O(maxVal) *

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
int sum(int n){
    int d = 0;
    while(n > 0){
        d += n % 10;
        n /= 10;
    }
    return d;
}
std::vector<int> digitalSumSort(std::vector<int> a)
{
    for (int i = 0; i < a.size()-1; i++)
    for (int j = i + 1; j < a.size(); j++)
    if (sum(a[i]) > sum(a[j]) || (sum(a[i]) == sum(a[j]) && a[i] > a[j])){
        swap(a[i] ,a[j]);
    }
    return a;
}
```