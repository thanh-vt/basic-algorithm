Cho số nguyên dương `n`. Hãy tạo ra ma trận vuông kích thước `n*n` chứa các số từ `1` tới `n*n` tăng dần theo hình xoắn ốc, xuất phát từ ô trên trái và đi theo theo theo chiều kim đồng hồ

Ví dụ

-   Với `n = 3`, kết quả

    `spiralNumbers(n) = [[1, 2, 3],\
                        ``[8, 9, 4],\
                        ``[7, 6, 5]]`

Đầu vào/đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] integer n\
    Độ dài của ma trận\
    *Điều kiện:*\
    `3 ≤ n ≤ 100`.

-   [Đầu ra] matrix.integer

Gợi ý:

-   Tạo ra ma trận kích thước `n*n`
-   Sử dụng `2` biến để lưu trữ hàng và cột hiện tại, bắt đầu xuất phát từ ô (`0,0`) (trên trái)
-   Sử dụng `1` biến để lưu trữ giá trị hiện tại của số nằm trong ma trận. Biến này sẽ tăng dần từ `1` cho tới `n*n`
-   Điền số vào ma trận theo nguyên tắc:
    -   Với cạnh đi từ trái qua phải: tăng dần cột, giữ nguyên hàng
    -   Với cạnh đi từ trên xuống dưới: tăng dần hàng, giữ nguyên cột
    -   Với cạnh đi từ phải qua trái: giảm dần cột, giữ nguyên hàng
    -   Với cạnh đi từ dưới lên trên: giảm dần hàng, giữ nguyên cột.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
std::vector<std::vector<int>> spiralNumbers(int n)
{
    std::vector<std::vector<int>> a;
    std::vector<int> b;
    for (int i=0; i<n; i++) b.push_back(1);
    for (int i=0; i<n; i++) a.push_back(b);
    int l=0;
    int r = n-1;
    int k=0;
    while (k<n*n){
        if (k<n*n){
            for (int j=l; j<=r; j++){
                k++;
                a[l][j] = k;
            }
        }
        if (k<n*n){
            for (int i=l+1; i<=r; i++){
                k++;
                a[i][r] = k;
            }
        }
        if (k<n*n){
            for (int j=r-1; j>=l; j--){
                k++;
                a[r][j] = k;
            }
        }
        if (k<n*n){
            for (int i=r-1; i>=l+1; i--){
                k++;
                a[i][l] = k;
            }
        }
        l++; r--;
    }
    return a;
}
```