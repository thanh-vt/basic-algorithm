Anh Việt Ducky năm nay mới được bổ nhiệm chức vụ giám đốc của một tập đoàn lớn, vì vừa lên chức nên anh ý muốn xem xét lại trình độ của các nhân viên bên dưới mình bằng một cuộc thi. Sau khi cuộc thi kết thúc thì anh ấy đã có danh sách điểm của các nhân viên của mình. Bạn là thư kí của anh ấy và bây giờ hãy giúp anh ý viết một chương trình tìm ra người có điểm cao thứ N trong danh sách điểm của các nhân viên của anh ý nhé.

Cho một mảng chứ các giá trị số và một số nguyên dương n. Tìm ra số lớn thứ n trong mảng đó. Nếu không có giá trị thoả mãn, trả về -1.

Note : Không tính các số trùng lặp trong mảng.

Ví dụ

-   Với `a = [6, 5, 4, 3, 2, 1], n = 1` thì đầu ra của chương trình `searchElement(a, n) = 6`
-   Với `a = [100, 100, 99, 98, 102, 103], n = 4` thì đầu ra của chương trình `searchElement(a, n) = 99`
-   Với `a = [1, 2, 3, 4, 5] , n = 10` thì đầu ra của chương trình `searchElement(a, n) = -1`

Đầu vào/ Đầu ra

-   [giới hạn thời gian chạy] 1 giây

-   [đầu vào] Array , integer

    Mảng số nguyên đầu vào : `0 <= a.length <= 1000`\
    Số tự nhiên n : `0 <= n <= 1000`

-   [đầu ra] Array\
    Số tự nhiên thoả mãn

### Lý thuyết

Cách đưa một mảng cho trước về mảng "độc nhất"

-   Định nghĩa: `B` được gọi là mảng *"độc nhất"* của mảng `A` nếu:
    -   Với mọi chỉ số `i (0 ≤ i < A.size())` thì ta luôn tìm được một chỉ số `j (0 ≤ j < B.size())` sao cho `B[j] = A[i]`
    -   Với mọi `i,j (0 ≤ i,j < B.size())` thì `B[i] ≠ B[j]`
-   Ví dụ minh họa:
    -   Với `A = [1,2,3,2,4,1,10]` thì `B = [1,10,4,2,3]` là mảng *"độc nhất" *của mảng `A`
    -   Với `A = [2,1,3,4]` thì `B = [2,1,3,4]` là mảng "độc nhất" của mảng `A`
-   Miêu tả thuật toán:
    -   Lần lượt đưa thử từng giá trị thuộc mảng `A` vào trong mảng `B`. Nếu như giá trị mình đang xét mà chưa được đưa vào mảng `B` thì đưa giá trị đó vào mảng, ngược lại thì bỏ qua.
    -   ```
        /// Hàm chuyển từ mảng a thành mảng độc nhất của nó
        vector<int> uniqueArray(vector<int> a)
        {
            vector<int> b;
            for (int x : a) {
                /// Biến Push dùng để kiểm soát xem có thể bỏ giá trị x vào mảng b hay không ?
                bool Push = true;

                for (int y : b) if (x == y) {
                    /// Nếu trong mảng b đã tồn tại một giá trị y = x rồi thì bỏ qua giá trị x
                    Push = false;
                    break;
                }
                if (Push) b.push_back(x);
            }
            return b;
        }​
        ```
Tuyến phố thông minh của nhà anh Việt có nhiều tòa nhà, tòa nhà thứ `i` có khoảng cách `x[i]` mét so với đầu của tuyến phố. Vì anh Việt là người giàu có và khá thoải mái chuyện tiền bạc nên anh đã quyết định sẽ đặt các trạm phát sóng wifi miễn phí tại các tòa nhà dọc theo tuyến phố thông minh của nhà anh. Mỗi thiết bị phát wifi có thể phủ sóng trong phạm vi `k` mét, tức là các tòa nhà có khoảng cách đến thiết bị không vượt quá `k` mét thì sẽ sử dụng được wifi từ thiết bị này.

Bạn hãy viết chương trình giúp anh Việt Ducky tìm cách đặt các trạm wifi để số lượng trạm wifi là ít nhất và tất cả các tòa nhà đều có thể sử dụng wifi.

Ví dụ:

-   Với `a = [1, 2, 3, 4, 5] , k = 1` thì đầu ra của chương trình `countPlace(a, k) = 2`\
    Việt sẽ đặt wifi ở tòa nhà có khoảng cách là `2` (tòa nhà có khoảng cách là `1` và `3` cũng sẽ bắt được sóng) và tòa nhà có khoảng cách là `4 (`tòa nhà có khoảng cách là `5` sẽ bắt được sóng`)`

-   Với `a = [1, 3, 4, 7, 8, 10], k = 2` thì đầu ra của chương trình `countPlace(a, k) = 2`\
    Việt sẽ đặt wifi ở tòa nhà có khoảng cách là `3` (tòa nhà có khoảng cách là `1` và `4` cũng sẽ bắt được sóng) và tòa nhà có khoảng cách là `8` (tòa nhà có khoảng cách là `7` và `10` sẽ bắt được sóng`)`

Đầu vào/Đầu ra:

-   [Thời gian chạy] 1 giây

-   [Đầu vào] Array.integer a\
    Mảng số nguyên dương `a` tăng dần\
    `0 < a.length <= 1000\
    `
-   [Đầu vào] Integer k\
    `0 < k <=1000`

-   [Đầu ra] Integer

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ Java:

```
static int countPlace(int[] a, int k)
{
	int count =0;
	int i = 0;
	while(i < a.length){
		int ht = i;
		if(ht == a.length -1) {
			count++;
			break;
		}
		int vt = i+1;
		while( vt < a.length&&a[vt]- a[ht] <= k){
			vt++;
		}
		if(vt < a.length) {
			i = vt - 1;
			int j = i + 1;
			while(j < a.length&&a[j] - a[i] <= k ){
				j++;
			}
			i = j;
			count++;
		}else {
			count++;
			break;
		}
	}
	return count;
}
```
-   Độ phức tạp: *O(n2)*

Cách tìm giá trị lớn thứ k trong một mảng cho trước

-   Để tìm giá trị lớn thứ `k` trong dãy thì ta chỉ việc sắp xếp dãy đó theo thứ tự giảm dần rồi lấy giá trị tại vị trí thứ `k` của dãy vừa sắp xếp.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
int searchElement(std::vector<int> a, int n)
{
    sort(a.begin(), a.end());
    int h = 1;
    if (n == 1 )
        return a[a.size() - 1];
    for (int i =a.size() - 1; i >= 0; i--)
    if (a[i] !=a [i+1]){
        h++;
        if (h == n+1)
            return a[i];
    }
    return -1;
}
```