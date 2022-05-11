Cho một ma trận `a` có kích thước `n*n` mà các phần tử trên cùng một hàng hoặc cùng một cột được sắp xếp không giảm

Viết chương trình tìm phần tử nhỏ thứ `k` (đếm từ `1`) của ma trận này (không tính các phần tử có giá trị bằng nhau). Nếu không có phần tử phù hợp trả về `-1`.

Ví dụ

-   Với `a = [[1, 3, 8], [2, 4, 10], [2, 5, 12]], k = 4` thì đầu ra của chương trình `searchElement02(a, k) = 4\
    `Danh sách các phần tử khác nhau của ma trận theo thứ tự tăng dần là: `[1,2,3,4,5,8,10,12]`
-   Với `a = [[1, 3, 8], [2, 4, 10], [2, 5, 12]], k = 10` thì đầu ra của chương trình `searchElement02(a, k) = -1`

Đầu vào/ Đầu ra

-   [Thời gian chạy] 1 giây

-   [đầu vào] Array.integer a\
    Ma trận `a` gồm các số nguyên\
    `0 <= a.length <= 1000`
-   [Đầu vào] integer k`\
    0 <= k <=1000`

-   [Đầu ra] integer

### Lý thuyết

Cách đưa một mảng cho trước về mảng "độc nhất"

-   Độ phức tạp: O(nlogn)
-   Miêu tả thuật toán:
    -   Sử dụng thuật toán sắp xếp (quick sort, merge sort) để sắp xếp lại mảng `A` cho trước.
    -   Nhận thấy sau khi sắp xếp thì các phần tử có giá trị bằng nhau sẽ nằm liên tiếp nhau trên dãy. Vậy khi xây dựng mảng *"**độc nhất"* ta chỉ cần lấy phần tử nằm đầu tiên trong đoạn liên tiếp các phần tử bằng nhau.
-   Ví dụ minh họa thuật toán:
    -   Với `A=[1,2,7,3,7,2,7]` thì sau khi sắp xếp lại dãy `A=[1,2,2,3,7,7,7]`. Lần lượt xét các giá trị:
        -   giá trị `1`: (nằm từ vị trí `0` -> đến vị trí `0`) Lấy phần tử đầu tiên của đoạn là `A[0]=1` bỏ vào mảng kết quả.
        -   giá trị `2`: (nằm từ vị trí `1` -> đến vị trí `2`) Lấy phần tử đầu tiên của đoạn là `A[1]=2` bỏ vào mảng kết quả
        -   giá trị `3`: (nằm từ vị trí `3` -> đến vị trí `3`) Lấy phần tử đầu tiên của đoạn là `A[3]=3` bỏ vào mảng kết quả
        -   giá trị `7`: (nằm từ vị trí `4` -> đến vị trí `6`) Lấy phần tử đầu tiên của đoạn là `A[4]=7` bỏ vào mảng kết quả
    -   Vậy mảng *"độc nhất"* của mảng `A` là `[1,2,3,7]`

        ```
        /// Hàm chuyển từ mảng a thành mảng độc nhất của nó
        vector<int> uniqueArray(vector<int> a)
        {
            vector<int> b;

            /// sắp xếp mảng a theo thứ tự tăng dần
            sort(a.begin(), a.end());

            for (int L = 0; L < (int) a.size(); ++L) {
                /// Xác định đoạn [L,R] sao cho các phần tử thuộc đoạn [L,R] có giá trị bằng nhau
                int R = L;
                while (R < (int) a.size() && a[R] == a[L]) ++R;
                --R;

                /// Đưa phần tử đầu tiên của đoạn [L,R] vào mảng kết quả
                b.push_back(a[L]);

                L = R;
            }
            return b;
        }
        ```

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
int searchElement02(std::vector<std::vector<int>> a, int k)
{
    std::vector<int> b;
    int m = a.size();
    int n = a[0].size();
    for (int i = 0; i<m; i++)
    for (int j = 0; j<n; j++)
    b.push_back(a[i][j]);
    sort(b.begin(), b.end());
    int h = 1;
    if (k == 1)
        return b[0];
    for (int i = 1; i < b.size(); i++)
    if (b[i] != b[i-1]){
        h++;
        if (h == k)
            return b[i];
    }
    return -1;
}
```