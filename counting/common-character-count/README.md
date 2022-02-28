###Thuật toán kiểm tra mảng có tần xuất bằng nhau

Cho hai xâu kí tự, tìm số lượng kí tự chung giữa chúng.

Ví dụ:

-   Với `s1 = "aabcc"` và `s2 = "adcaa"`, thì kết quả `commonCharacterCount(s1, s2) = 3`.\
    2 xâu s1 và s2 có `3` kí tự chung: `2` kí tự `'``a'` và `1` kí tự `'``c'`.

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] string s1, s2

    Xâu kí tự chỉ chứa các kí tự chữ cái in thường, in hoa

    *Điều kiện:*\
    `1 ≤ s1.length, s2.length < 15`.

-   [output] integer

### Lý thuyết

Mảng tần suất - frequency array 

Định nghĩa: Mảng tần suất - frequency array là mảng dùng để kiếm soát số lần xuất hiện của một giá trị trong một mảng cho trước 

Cách xây dựng: Cho trước một dãy số `A`. Tìm mảng `B` là mảng tần suất ứng với dãy `A`

-   Lần lượt xét các chỉ số `i` mà `0 <= i < A.size()` rồi tăng giá trị của `B[A[i]]` lên một đơn vị. 

    ```
    vector<int> frequencyArray(vector<int> A) {
        for (int i = 0; i < (int) A.size(); ++i) B[A[i]]++;
        return B;
    }

    ```

Ví dụ minh họa thuật toán: Với `A = [1,2,3,3,1,1]` thì

-   Xét `i=0` thì `B[A[0]]` tăng lên `1` đơn vị nên `B[1]=1` 
-   Xét `i=1` thì `B[A[1]]` tăng lên `1` đơn vị nên `B[2]=1` 
-   Xét `i=2` thì `B[A[2]]` tăng lên `1` đơn vị nên `B[3]=1` 
-   Xét `i=3` thì `B[A[3]]` tăng lên `1` đơn vị nên `B[3]=2` 
-   Xét `i=4` thì `B[A[4]]` tăng lên `1` đơn vị nên `B[1]=2` 
-   Xét `i=5` thì `B[A[5]]` tăng lên `1` đơn vị nên `B[1]=3` 

Độ phức tạp: `*O(n)*`

Một số ứng dụng cơ bản: 

-   Kiểm tra một số có xuất hiện trong dãy không ?
-   Tìm số lần xuất hiện của một số trong dãy
-   Áp dụng cho một số thuật toán sắp xếp *(Counting sort)*

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
int commonCharacterCount(std::string s1, std::string s2)
{
    vector <int> a(256);
    vector <int> b(256);
    for (int i = 0 ; i < s1.length(); i++)
        a[s1[i]]++;
    for (int i = 0 ; i < s2.length(); i++)
        b[s2[i]]++;
    int d = 0;
    for (int i = 97; i <= 122; i++)
        d += min(a[i], b[i]);
    return d;
}
```