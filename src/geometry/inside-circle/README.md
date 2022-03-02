Cho tọa độ tâm và bán kính của một đường tròn cùng tọa độ của một điểm trên mặt phẳng 2 chiều

Kiểm tra xem điểm có nằm trong (hoặc nằm trên viền) của đường tròn hay không?

Ví dụ

-   Với `point = [1, 1]`, `center = [2, 2]`, và `radius = 1`, kết quả `insideCircle(point, center, radius) = false`.

    ![](https://codesignal.s3.amazonaws.com/tasks/insideCircle/img/example1.png?_tm=1551474766568)

-   Với `point = [1, 1]`, `center = [0, 0]`, và `radius = 3`, kết quả `insideCircle(point, center, radius) = true`.

    ![](https://codesignal.s3.amazonaws.com/tasks/insideCircle/img/example2.png?_tm=1551474767010)

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.integer point\
    Mảng 2 phần tử thể hiện tọa độ của điểm cần kiểm tra.\
    *Điều kiện:*\
    `-100 ≤ point[i] ≤ 100`.

-   [Đầu vào] array.integer center\
    Mảng 2 phần tử thể hiện tọa độ tâm của đường tròn\
    *Điều kiện:*\
    `-10 ≤ center[i] ≤ 10`.

-   [Đầu vào] integer radius\
    Bán kính đường tròn.\
    *Điều kiện:*\
    `1 ≤ radius ≤ 5`.

-   [Đầu ra] boolean

    `true` nếu `point` nằm trong đường tròn, `false` nếu ngược lại.

### Lý thuyết :

-   Cho hệ `Oxy`, 1 điểm `A``(x, y)` và 1 hình tròn có tâm tại `C(xC, yC)`, bán kính `R`
-   Khi đó có 3 quan hệ :
    -   `dist(A, C) < R` : điểm `A` nằm trong hình tròn
    -   `dist(A, C) = R` : điểm `A` ở trên biên hình tròn
    -   `dist(A, C) > R` : điểm `A` nằm ngoài hình tròn với `dist(A, C)` là khoảng cách giữa điểm `A` và điểm `C`
-   Code minh họa

```
int sqr(int x) { // tra ve binh phuong cua 1 so
    return x * x;
}
int checkPointCircle(vector <int> A, vector <int> C, int R) {
    int sqr_dist = sqr(C[0] - A[0]) + sqr(C[1] - A[1]);
    // binh phuong dist(A, C)
    if (sqr_dist < R * R) return -1; // trong hinh tron
    if (sqr_dist == R * R) return 0; // tren bien hinh tron
    if (sqr_dist > R * R) return 1;  // ngoai hinh tron
}
```

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
bool insideCircle(std::vector<int> point, std::vector<int> center, int radius)
{
   return (pow((center[0]-point[0]),2)+pow((center[1]-point[1]),2) <= radius*radius)?true:false;
}

```

`\
`

[](https://codelearn.io/learning/thuat-toan-can-ban/3822#)