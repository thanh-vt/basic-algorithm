###Thuật toán tìm số khác nhau trong bảng tích

Cho một bảng có `n` hàng và `m` cột

Mỗi một ô trong bảng ở hàng `i` và cột `j` chứa 1 số  có giá trị bằng `i * j `(chỉ số hàng và cột đều được đếm bắt đầu từ `1`)

Cho trước `n` và `m`, hãy tìm số lượng các số nguyên khác nhau nằm trong bảng

Ví dụ:

-   Với `n = 3` và `m = 2`, thì kết quả `differentValuesInMultiplicationTable2(n, m) = 5`.\
    Có `5` giá trị khác nhau nằm trong bảng là: `1, 2, 3, 4, 6`

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] integer n,m

    *Điều kiện:*\
    `1 ≤ n ≤ 20`

-   [Đầu ra] integer

### Lý thuyết

Cách đếm số lượng giá trị khác nhau trong một dãy số

Mô tả thuật toán: Xét từng giá trị trong dãy số. Kiểm tra xem giá trị này đã được xét đến trước đó hay chưa ? Nếu chưa thì tăng giá trị của kết quả lên một đơn vị. 

Ví dụ mô tả thuật toán: Với `A = [1,3,2,2,4,1]` thì: 

-   Xét giá trị `A[0]=1` của dãy số: Giá trị `1` chưa được xét đến nên kết quả tăng lên một đơn vị là `1` 
-   Xét giá trị `A[1]=3` của dãy số: Giá trị `3` chưa được xét đến nên kết quả tăng lên một đơn vị là `2`
-   Xét giá trị `A[2]=2` của dãy số: Giá trị `2` chưa được xét đến nên kết quả tăng lên một đơn vị là `3` 
-   Xét giá trị `A[3]=2` của dãy số: Giá trị `2` đã được xét đến trước đó (`A[2]=2`) nên kết quả giữ nguyên là `3` 
-   Xét giá trị `A[4]=4` của dãy số: Giá trị `4` chưa được xét đến nên kết quả tăng lên một đơn vị là `4` 
-   Xét giá trị `A[5]=1` của dãy số: Giá trị `1` đã được xét đến trước đó (`A[1]=1`) nên kết quả giữ nguyên là `4`  

Code minh họa thuật toán trên:

```
int numberDifferentValue(vector<int> A) {
    int res = 0;
    for (int i = 0; i < (int) A.size(); ++i) {
        /// biến ok kiểm soát xem giá trị A[i] đã xuất hiện trước đó hay chưa ?
        bool ok = true;
        for (int j = 0; j < i; ++j)
            if (A[i] == A[j]) {
                /// Nếu giá trị A[i] đã xuất hiện trước đó rồi thì gán lại ok là false
                ok = false;
                break;
            }
        /// Nếu giá trị A[i] chưa được xét trước đó thì tăng kết quả lên một
        if (ok) res++;
    }
    return res;
}
```

Code mẫu:

```
int differentValuesInMultiplicationTable2(int n, int m)
{
    vector<bool> a (401, false);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i * j] = 1;
    int d = 0;
    for (int i = 1; i <= m * n; i++)
        d += a[i];
    return d;
}
```