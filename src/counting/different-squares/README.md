###Thuật toán tìm số hình vuông khác nhau trong ma trận

Cho một ma trận chữ nhật chứa các chữ số (`0-9)

`Hãy tính số lượng các hình vuông `2 × 2` khác nhau tồn tại trong ma trận

Ví dụ

-   Với `matrix = [[1, 2, 1],`\
    `[2, 2, 2],`\
    `[2, 2, 2],`\
    `[1, 2, 3],`\
    `[2, 2, 1]]` thì kết quả `differentSquares(matrix) = 6.

    `Dưới đây là `6` hình vuông `2 × 2` khác nhau:
    -   `1 2`\
        `2 2`
    -   `2 1`\
        `2 2`
    -   `2 2`\
        `2 2`
    -   `2 2`\
        `1 2`
    -   `2 2`\
        `2 3`
    -   `2 3`\
        `2 1`

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 giây
-   [Đầu vào] array.array.integer matrix\
    *Điều kiện:*\
    `1 ≤ matrix.length ≤ 100`\
    `1 ≤ matrix[i].length ≤ 100`\
    `0 ≤ matrix[i][j] ≤ 9`
-   [output] integer\
    Số các hình vuông `2 × 2` khác nhau tồn tại trong ma trận.

Hướng dẫn bài tập.
------------------

Có thể lưu các phần tử trong ma trận dưới dạng chuỗi.

Code mẫu:

Ngôn ngữ C++:

```
int differentSquares(std::vector<std::vector<int>> matrix)
{
    string s = "@";
    string p = "";
    int d = 0;
    for (int i = 0; i < matrix.size() - 1; i++)
        for (int j = 0; j < matrix[0].size() - 1; j++)
        {
            p = "";
            p = p + "@" + char(matrix[i][j] + 48) + " " + char(matrix[i][j + 1] + 48) + " " + char(matrix[i + 1][j]+48) + " " + char(matrix[i+1][j + 1] + 48) + "@ ";
            if (s.find(p) < 0 || s.find(p) > s.length() - 1){
                d++;
                s = s + p;
            }
        }
    return d;
}
```

Hoặc bạn có thể dùng set (Nếu chưa có kiến thức mục này bạn có thể học khóa Thư viện chuẩn C++):

```
int differentSquares(std::vector<std::vector<int>> matrix)
{
    set < vector <int> > a;
    for (int i = 0; i < matrix.size() - 1; i++)
        for (int j = 0; j < matrix[0].size() - 1; j++)
        {
            vector <int> b = {matrix[i][j], matrix[i][j + 1], matrix[i + 1][j], matrix[i+1][j + 1]};
            a.insert(b);
        }
    return a.size();
}
```