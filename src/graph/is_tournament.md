Cho một đồ thị có hướng

Kiểm tra xem đồ thị trên có phải là [tournament](https://en.wikipedia.org/wiki/Tournament_(graph_theory)) (từ khóa này hơi khó dịch sang tiếng Việt) hay không[?](https://en.wikipedia.org/wiki/Tournament_(graph_theory))

Có thể hiểu tournament là một đồ thị mà giữa 2 đỉnh bất kì luôn tồn tại 1 và chỉ 1 cạnh nối

Ví dụ

-   Với `n = 5`, `fromV = [2, 1, 3, 4, 4, 4, 1, 2, 3, 4]`, và `toV = [3, 2, 1, 3, 2, 1, 5, 5, 5, 5]`, kết quả `isTournament(n, fromV, toV) = true`.

    Đồ thị có hướng trên là [tournament](https://en.wikipedia.org/wiki/Tournament_(graph_theory))\
    ![](https://codesignal.s3.amazonaws.com/tasks/isTournament/img/example.png?_tm=1551474877304)

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] integer n\
    Số nguyên dương n thể hiện số đỉnh của đồ thị\
    *Điều kiện:\
    *`1 ≤ n ≤ 10`.

-   [Đầu vào] integer fromV\
    Mảng chứa số nguyên có không quá `n` phần tử\
    *Điều kiện:\
    *`0 ≤ fromV.length ≤ 50`\
    `1 ≤ fromV[i] ≤ n`

-   [Đầu vào] array.integer toV\
    Với mỗi `i` nằm trong khoảng `[0, fromV.length)` sẽ có một cạnh từ đỉnh `fromV[i]` đến đỉnh `toV[i]` trong đồ thị có hướng đã cho.\
    *Điều kiện:*\
    `toV.length = fromV.length`,\
    `1 ≤ toV[i] ≤ n`.

-   [Đầu ra] boolean

    `true` nếu đồ thị đã cho là một tournament, `false` nếu ngược lại.

### Lý thuyết :

-   *Đồ thị `n` đỉnh `m` cạnh*, là 1 tập `n` điểm (thường được đánh số từ `0` đến `n` `- 1`, hoặc `1` đến `n`), và `m` đường nối giữa các điểm ấy
-   *Đồ thị vô hướng* là đồ thị mà các cạnh `(u, v)` có 2 chiều, `u` đến `v` được, `v` cũng đến `u` được. *Đồ thị có hướng* thì cạnh `(u, v)` chỉ đi được 1 chiều duy nhất từ `u` đến `v`. Y như đường bộ 2 chiều và 1 chiều thôi :v
-   *Đồ thị đầy đủ* là đồ thị mà bất cứ 2 đỉnh bất kì nào cũng có cạnh nối trực tiếp với nhau. Để kiểm tra 1 đồ thị có đầy đủ hay không, ta chỉ việc kiểm tra xem mỗi đỉnh có nối với toàn bộ n - 1 đỉnh còn lại hay không
-   *Thành phần liên thông* là 1 tập đỉnh trong đồ thị vô hướng, mà 2 đỉnh bất kì trong đó có thể đi đến được với nhau (qua cạnh nối trực tiếp, hoặc 1 số cạnh trung gian). Nếu điều kiện trên vẫn đúng trong đồ thị có hướng, thì ta gọi tập đỉnh này là *Thành phần liên thông mạnh*

### Hướng dẫn bài tập.

Ngôn ngữ Java:

```
boolean isTournament(int n, int[] fromV, int[] toV) {
	if (fromV.length != toV.length) {
		return false;
	}
	boolean status = true;
	List<Integer> lst = new ArrayList<Integer>();
	for (int i = 1; i <= n; i++) {
		lst.add(i);
	}
	for (int i = 1; i <= n; i++) {
		status = status && checkConnect(lst, i, fromV, toV);
	}
	return status;
}

boolean checkConnect(List<Integer> lst, int i, int[] fromV, int[] toV) {
	List<Integer> lst1 = new ArrayList<Integer>();
	lst1.add(i);
	for (int j = 0; j < toV.length; j++) {
		if (toV[j] == i) {
			lst1.add(fromV[j]);
		}
		if (fromV[j] == i) {
			lst1.add(toV[j]);
		}
	}

	Collections.sort(lst1);
	return lst.equals(lst1);
}
```