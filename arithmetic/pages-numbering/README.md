###Thuật toán tìm số chữ số để đánh số trang sách

Cho biết số trang sách của 1 quyển sách

Hãy tìm số lượng các chữ số dùng để đánh số trang của quyển sách đó

Ví dụ:

-   Với `n = 11`, thì kết quả `pagesNumbering(n) = 13.\
    13` chữ số được sử dụng là: `1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1`

Đầu vào/đầu ra:

-   [Thời gian chạy] 0.5 giây
-   [Đầu vào] integer n\
    Điều kiện:\
    `1 ≤ n ≤ 10^8`.
-   [output] integer

Gợi ý:

-   Do `n` có thể rất lớn, nên ko thể dùng vòng lặp để tính số các chữ số
-   Hãy tính số các chữ số theo công thức toán học (ví dụ như có bao nhiêu số có `1` chữ số, `2` chữ số, `3` chữ số, ...)

### Lý thuyết :

-   Số có `i` chữ số sẽ bắt đầu từ `10i - 1` đến `10i - 1`
-   Vậy với các số có `1, 2, 3 ... n` chữ số, thì tổng số chữ số sẽ là bao nhiêu ? Nó sẽ là `∑(10i - 10i - 1)` (`i = 1 .. n`) (Cứ lấy số lượng số từng loại nhân với số chữ số tương ứng)
-   Vậy làm sao đếm được số chữ số từ `1` đến `n` ? 
    -   Ta cần xác định xem `n` có bao nhiêu chữ số. Giả sử `n` có `x` chữ số
    -   Vậy thì các số từ `1` đến `x - 1` chữ số sẽ xuất hiện đủ. Riêng các số có `x` chữ số sẽ chỉ xuất hiện từ `10``x - 1` đến `n`
    -   Cộng tổng số lượng số nhân số chữ số tương ứng, ta sẽ có kết quả cần tìm

Hướng dẫn bài tập.

Code mẫu:

Ngôn ngữ Java:

```
int pagesNumbering(int n)
{
    int k = 1;
    int v1 = 0;
    int v2 =0;
    int m = String.valueOf(n).length();

    if(n<10 && n>0){
        v1 = n;
        v2 =0;
    }else{
        for (int i = 1; i <= m - 1; i++){
            v1 = (n - (int) Math.pow(10, i) + 1) * m;
            v2 = v2 + (9 * i) * k;
            k = k * 10;
        }
    }
    return (v1 + v2);
}
```