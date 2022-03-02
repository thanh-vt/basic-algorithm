Cho địa chỉ hai ô trên bàn cờ vua tiêu chuẩn, hãy kiểm tra chúng cùng màu hay khác màu

Ví dụ:

-   Với `cell1 = "A1"` và `cell2 = "C3"`, kết quả là `chessBoardCellColor(cell1, cell2) = true`.

    ![](https://codesignal.s3.amazonaws.com/tasks/chessBoardCellColor/img/example1.png?_tm=1551474248126)

-   Với `cell1 = "A1"` and `cell2 = "H3"`, kết quả `chessBoardCellColor(cell1, cell2) = false`.

    ![](https://codesignal.s3.amazonaws.com/tasks/chessBoardCellColor/img/example2.png?_tm=1551474248394)

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] string cell1, cell2\
    *Điều kiện:*\
    `cell1.length = cell2.length = 2`\
    `'A' ≤ cell1[0], cell2[0] ≤ 'H'`\
    `1 ≤ cell1[1], cell2[1] ≤ 8`.

-   [Đầu ra] boolean

    -   `true` nếu 2 ô chung màu `false` nếu ngược lại.

### Lý thuyết : 

-   Bàn cờ vua có kích cỡ `8 * 8`, gồm các ô trắng đen đan xen nhau
-   Các bạn coi `A` đến `H` là các chỉ số từ `1` đến `8`. Vậy thì các ô có chỉ số hàng cùng tính chẵn lẻ với chỉ số cột sẽ là ô đen, ngược lại là ô trắng
-   Vậy nên, để kiểm tra 1 ô là đen hay trắng, các bạn cần đưa tọa độ ô từ dạng `(A .. H, 1 .. 8)` về dạng `(1 .. 8, 1 .. 8)`, rồi kiểm tra
-   Ví dụ : 

```
int checkColor(string cell) {
	int x = cell[0] - 'A' + 1, y = cell[1] - '0';
	// viet lai form cua toa do (1 .. 8, 1 .. 8)
	return x % 2 == y % 2 ? 1 : 0;
	// 1 la black, 0 la white
}
```

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
bool chessBoardCellColor(std::string cell1, std::string cell2)
{
    if((cell1[0] + cell1[1] + cell2[0] + cell2[1]) % 2 == 0)
        return true;
    return false;
}
```