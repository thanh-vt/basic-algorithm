Cho ma trận `n x m` chứa tất cả các số nguyên từ `1` tới `n*m`, mỗi số chỉ xuất hiện một lần

Bạn xuất phát từ ô chứa số `1.` Mỗi nước đi, bạn được quyền đi tới `4` ô xung quanh chung cạnh. Mỗi ô bạn chỉ có thể đi qua một lần

Hãy kiểm tra xem có tồn tại phương án đi qua tất cả các ô với thứ tự tăng dần của các ô trong ma trận? (xuất phát từ ô số `1`, tới ô số `2`, rồi tới ô số `3`, ... cuối cùng kết thúc ở ô `n*m`)

Ví dụ:

-   Với `matrix = [[1, 4, 5], [2, 3, 6]]` thì kết quả `findPath(matrix) = true\
    `Bạn có thể đi lần lượt từ `1` tới `6`

-   Với `matrix = [[1, 3, 6], [2, 4, 5]] `thì kết quả `findPath(matrix) = false`.\
    Bạn có thể đi từ ô `1` sang ô `2`, nhưng không thể đi từ `2` sang `3` do hai ô này không chung cạnh

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [input] matrix.integer matrix\
    Mảng 2 chiều không rỗng chứa các số nguyên thể hiện ma trận hình chữ nhật.\
    *Điều kiện:*\
    `1 ≤ matrix.length ≤ 5`,\
    `1 ≤ matrix[0].length ≤ 10`,\
    `1 ≤ matrix[i][j] ≤ 25`.

-   [output] boolean

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ Java:

```
boolean findPath(int[][] matrix) {
	int column = matrix[0].length;
	int row = matrix.length;
	int columnOne = -1;
	int rowOne = -1;
	int count = 2;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (matrix[i][j] == 1) {
				columnOne = j;
				rowOne = i;
			}
		}
	}
	if (columnOne == -1 && rowOne == -1) {
		return false;
	}
	while (count <= column * row) {
		if (rowOne + 1 >= 0 && rowOne + 1 < row && matrix[rowOne + 1][columnOne] == count) {
			count++;
			rowOne++;
		} else if (rowOne - 1 >= 0 && rowOne - 1 < row && matrix[rowOne - 1][columnOne] == count) {
			count++;
			rowOne--;
		} else if (columnOne - 1 >= 0 && columnOne - 1 < column && matrix[rowOne][columnOne - 1] == count) {
			count++;
			columnOne--;
		} else if (columnOne + 1 >= 0 && columnOne + 1 < column && matrix[rowOne][columnOne + 1] == count) {
			count++;
			columnOne++;
		} else {
			return false;
		}
	}
	return true;
}
```