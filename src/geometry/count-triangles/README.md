Cho một tập hợp các điểm trên mặt phẳng 2 chiều

Hãy viết chương trình đếm số lượng tam giác có diện tích lớn hơn 0 được tạo ra bởi cách nối 3 điểm trong số các điểm cho trước.

Ví dụ

-   Với `x = [0, 0, 1, 1]` và `y = [0, 1, 1, 0]`, kết quả là `countTriangles(x, y) = 4`.

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.integer x, y\
    2 mảng có cùng độ dài, thể hiện tọa độ của các điểm trong mặt phẳng 2 chiều\
    *Guaranteed constraints:*

    `3 ≤ x.length , y.length ≤ 10`,\
    `-10 ≤ x[i], y[i] ≤ 10`.

-   [Đầu ra] integer\
    Số tam giác được tạo ra bởi các điểm đã cho

### Lý thuyết :

-   Cho hệ `Oxy`, và 3 điểm `A(xA, yA)`, `B(xB, yB)`, `C(xC, yC)`
-   Gọi `u` là vector tạo bởi `A` và `B`, `v` là vector tạo bởi `B` và `C`. Theo lý thuyết ở các bài trước, ta xác định được `u(xB - xA, yB - yA)`, `v(xC - xB, yC - yB)`
-   3 điểm `A`, `B`, `C` thẳng hàng, khi và chỉ khi `u`, `v` tỉ lệ với nhau, hay `u = k * v` (`k` là số thực bất kì). Ngược lại thì không
-   Tức là `A`, `B`, `C` thẳng hàng, khi và chỉ khi `(xB - xA) * (yC - yB) = (yB - yA) * (xC - xB)`
-   Code minh họa

```
int isCollinear(vector <int> A, vector <int> B, vector <int> C) {
    return (B[0] - A[0]) * (C[1] - B[1]) - (B[1] - A[1]) * (C[0] - B[0]) == 0;
}
```

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ Java:

```
int countTriangles(int[] x, int[] y)
{
    int count = 0;
    for(int i = 0;i < x.length;i++)
    {
        for(int j = i + 1;j < x.length;j++)
        {
            for(int k = j + 1;k < x.length;k++)
            {
                if((x[j] - x[i]) * (y[k] - y[j]) != (y[j] - y[i]) * (x[k] - x[j]))
                    count++;
            }
        }
    }
    return count;
}
```