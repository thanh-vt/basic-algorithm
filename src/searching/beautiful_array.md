Một mảng được gọi là "đẹp" nếu mảng đó chứa một phần tử mà phần tử đó chia mảng làm 2 phần (không rỗng và không chứa phần tử đó) có tổng bằng nhau.

Hãy kiểm tra xem một mảng bất kì có phải là một mảng "đẹp" hay không?

Ví dụ:

-   Với `a = [1, 2, 3]` thì kết quả `beautifulArray(a) = false`
-   Với `a = [1, 2, 3, 3]` đầu ra của chương trình sẽ là `beautifulArray(a) = true\
    `Chọn phần tử ở vị trí thứ `3` (tính từ trái sang), thì mảng ban đầu được chia thành 2 phần `[1,2]` và `[3]` có tổng 2 phần bằng nhau

Đầu vào/Đầu ra

-   [Thời gian chạy] 1 giây

-   [Đầu vào] Array.integer a\
    `0 <= a.length <= 10000`

-   [Đầu ra] Boolean

### Lý thuyết

Mảng cộng dồn

-   Bài toán: Cho trước một dãy số `A`. Tính tổng: `A[L]+A[L+1]+...+A[R-1]+A[R]`
    -   Ở bài toán này thông thường ta sẽ mất một chi phí là *`O(R-L+1)` *để xét các số từ `L` đến `R` và cộng vào kết quả. Nhưng với *"mảng cộng dồn" *ta chỉ cần chuẩn bị trong `*O(A.size())*` và lấy kết quả trong độ phức tạp là *`O(1)`.*
-   Định nghĩa : `S` được gọi là *"mảng cộng dồn"* của dãy `A` nếu `S[i] = A[1]+A[2]+...+A[i] `với mọi `0 <= i < A.size())`
-   Áp dụng:

    -   `A[L]+A[L+1]+...+A[R]` = `(A[0]+A[1]+...+A[R]) - (A[1]+A[2]+...+A[L-1])` = `S[R]-S[L-1]`.
    -   Từ biểu thức trên, ta thấy rằng thay vì ta phải xét toàn bộ các phần tử từ `L→R` trong mảng `A`, ta chỉ cần quan tâm đến 2 phần từ `S[R]` và `S[L-1]` trong *"mảng cộng dồn".*
-   Miêu tả thuật toán:
    -   Với `i=0`: `S[i]` = `A[i]`
    -   Với `i≥0`: `S[i]` = `A[1]+A[2]+...+A[i]` = `(A[1]+A[2]+...+A[i-1])+A[i]` = `S[i-1]+A[i]`

        ```
        /// Xây dựng mảng cộng dồn S
        vector<int> Build(vector<int> A) {
            S.resize(A.size());
            for (int i = 0; i < (int) A.size(); ++i) {
                if (i == 0) S[i] = A[i];
                else S[i] = S[i-1] + A[i];
            }
            return S;
        }

        /// Tính tổng các số thuộc đoạn [L,R] của mảng A
        int getSum(vector<int> A, int L, int R) {
            vector<int> S = Build(A);
            if (L == 0) return S[R];
            return S[R] - S[L-1];
        }
        ```

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
bool beautifulArray(std::vector<int> arr)
{
    std::vector<int> s;
    s.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
        s.push_back(s[i-1] + arr[i]);
    for (int i = 1; i < arr.size() - 1; i++)
        if (s[i-1] == s.back() - s[i])
            return true;
    return false;
}
```