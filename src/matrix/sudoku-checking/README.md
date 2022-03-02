Sudokulà trò chơi điền số vào ô trống. Mục tiêu là lấp đầy bảng 9x9 bằng các số sao cho mỗi cột, mỗi hàng và mỗi bảng con 3x3 đều chứa tất cả các số từ 1 đến 9 duy nhất một lần.

Hãy tạo ra 1 thuật toán để kiểm tra xem bảng Sudoku cho sẵn có hợp lệ theo các quy tắc được mô tả ở trên không. Lưu ý rằng bảng Sudoku không nhất thiết có thể giải được.

Ví dụ

-   Với `grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],`\
    `['.', '.', '6', '.', '.', '.', '.', '.', '.'],`\
    `['.', '.', '.', '.', '.', '.', '.', '.', '.'],`\
    `['.', '.', '1', '.', '.', '.', '.', '.', '.'],`\
    `['.', '6', '7', '.', '.', '.', '.', '.', '9'],`\
    `['.', '.', '.', '.', '.', '.', '8', '1', '.'],`\
    `['.', '3', '.', '.', '.', '.', '.', '.', '6'],`\
    `['.', '.', '.', '.', '.', '7', '.', '.', '.'],`\
    `['.', '.', '.', '5', '.', '.', '.', '7', '.']]`\
    thì output sẽ là `sudoku2(grid) = true`;
-   Với `grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],`\
    `['.', '.', '.', '.', '6', '.', '.', '.', '.'],`\
    `['7', '1', '.', '.', '7', '5', '.', '.', '.'],`\
    `['.', '7', '.', '.', '.', '.', '.', '.', '.'],`\
    `['.', '.', '.', '.', '8', '3', '.', '.', '.'],`\
    `['.', '.', '8', '.', '.', '7', '.', '6', '.'],`\
    `['.', '.', '.', '.', '.', '2', '.', '.', '.'],`\
    `['.', '1', '.', '2', '.', '.', '.', '.', '.'],`\
    `['.', '2', '.', '.', '3', '.', '.', '.', '.']]`\
    thì output sẽ là `sudoku2(grid) = false`.

Bảng Sudoku trên là không đúng bởi vì có 2 số 1 ở cột thứ 2. Mỗi cột, mỗi hàng và mỗi bảng con 3x3 chỉ có thể chứa số từ 1 đến 9 duy nhất 1 lần.

Input/Output

-   [Giới hạn thời gian] 0.5s(cpp)
-   [input] array.array.char grid

Một array 9x9 gồm các ký tự, trong đó mỗi kí tự có thể là chữ số từ '1' đến '9'hoặc dấu chấm '.'.

-   [output] boolean\
    Trảvề true nếu bảng Sudoku hợp lệ, nếu không thì False.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ Java:

```
boolean sudokuChecking(char[][] grid)
{
    if (grid == null || grid.length != 9 || grid[0].length != 9)
		return false;
	// check each column
	for (int i = 0; i < 9; i++) {
		boolean[] m = new boolean[9];
		for (int j = 0; j < 9; j++) {
			if (grid[i][j] != '.') {
				if (m[(int) (grid[i][j] - '1')]) {
					return false;
				}
				m[(int) (grid[i][j] - '1')] = true;
			}
		}
	}

	//check each row
	for (int j = 0; j < 9; j++) {
		boolean[] m = new boolean[9];
		for (int i = 0; i < 9; i++) {
			if (grid[i][j] != '.') {
				if (m[(int) (grid[i][j] - '1')]) {
					return false;
				}
				m[(int) (grid[i][j] - '1')] = true;
			}
		}
	}

	//check each 3*3 matrix
	for (int block = 0; block < 9; block++) {
		boolean[] m = new boolean[9];
		for (int i = block / 3 * 3; i < block / 3 * 3 + 3; i++) {
			for (int j = block % 3 * 3; j < block % 3 * 3 + 3; j++) {
				if (grid[i][j] != '.') {
					if (m[(int) (grid[i][j] - '1')]) {
						return false;
					}
					m[(int) (grid[i][j] - '1')] = true;
				}
			}
		}
	}
	return true;
}

```

`\
`

[](https://codelearn.io/learning/thuat-toan-can-ban/1126#)