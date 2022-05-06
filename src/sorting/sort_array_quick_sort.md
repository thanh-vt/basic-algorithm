Một nhóm người đứng thành hàng trong công viên. Giữa họ có một số cây không thể di chuyển

Nhiệm vụ của bạn là thay đổi vị trí của họ, sao cho chiều cao của họ tạo thành một dãy tăng dần (không tính cây). Chú ý rằng cây không thể di chuyển

Ví dụ

-   Với `a = [-1, 150, 190, 170, -1, -1, 160, 180]`, thì kết quả `sortByHeight(a) = [-1, 150, 160, 170, -1, -1, 180, 190]`.

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.integer a

    Nếu `a[i] = -1` có nghĩa là ở vị trí `i` có cây. Ngược lại `a[i]` là độ cao của người ở vị trí thứ `i`.\
    *Điều kiện:*\
    `1 ≤ a.length ≤ 1000`\
    `-1 ≤ a[i] ≤ 1000`.

-   [Đầu ra] array.integer\
    Mảng đầu ra thể hiện độ cao của nhóm người sau khi đã đổi chỗ

### Lý thuyết

Thuật toán Quick sort

-   Ý tưởng thuật toán:
    -   Dựa trên kĩ thuật *chia để trị (divide and conquer)*
    -   Để sắp xếp một đoạn từ `L→R` trong dãy `A`. Nếu `L=R` thì đoạn đó đã được sắp xếp, ngược lại ta chọn một phần tử `x` trong đoạn đó làm *chốt* *(pivot)*, mọi phần tử có giá trị nhỏ hơn *chốt *sẽ được sắp xếp vào vị trí nằm trước vị trí của chốt, mọi phần tử có giá trị lớn hơn *chốt *sẽ được sắp xếp vào vị trí nằm sau chốt. Sau phép chuyển trên thì đoạn `L→R` sẽ được chia ra làm hai phần, phần đầu là các số có giá trị nhỏ hơn hoặc bằng giá trị của *chốt*, phần sau là các số có giá trị lớn hơn giá trị của *chốt*. Tiếp tục làm như vậy với hai đoạn con ta sẽ thu được đoạn từ `L→R` sắp xếp tăng dần.
-   Mô tả cách làm:
    -   Cần sắp xếp đoạn từ `L→R`.
    -   Chọn `x` là *chốt* của đoạn ( giả sử có thể lấy `x=A[(L+R)/2]` ).
    -   Chạy con trỏ từ `i` từ `L` sang phải, con trỏ `j` từ `R` sang trái. Nếu gặp một cặp `(i,j)` mà `i ≤ j` và `A[i] ≥ x ≥ A[j]`. Thì thực hiện phép đổi vị trí `A[i]` và `A[j]`.
    -   Tiếp tục lặp lại quá trình cho đến khi `i > j` thì dừng vòng lặp.
    -   Tiếp tục sắp xếp hai đoạn con `L→j` và `i→R`
-   ```
    void quickSort(int L, int R) {
        if (L >= R) return;
        int i = L, j = R, x = a[(L+R)/2];
        while (i <= j) {
            while (i <= R && a[i] < x) ++i;
            while (j >= L && a[j] > x) --j;
            if (i <= j) {
                swap(a[i], a[j]);
                ++i; --j;
            }
        }
        quickSort(L, j);
        quickSort(i, R);
    }
    ```

-   Độ phức tạp thuật toán: *O(nlogn)*

    -   Sau mỗi lần sắp xếp mình lại chia đôi đoạn nên trong trường hợp trung bình thì độ phức tạp thuật toán sẽ là *O(nlogn)*
    -   Trong trường hợp xấu nhất thì độ phức tạp của thuật toán sẽ là *O(n2)*. Vì khi chia đoạn mình có thể chia đoạn thành 2 phần có độ dài là `n-1` và `1`. Nhưng trường hợp này rất khó để xảy ra.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
std::vector<int> sortByHeight(std::vector<int> a)
{
    std::vector <int> b = a;
    sort(a.begin(), a.end());
    int h =0 ;
    for (int i = 0; i < a.size(); i++)
    if (a[i] != -1){
        h = i;
        break;
    }
    for (int i = 0; i<a.size(); i++)
    if (b[i] != -1){
        b[i] = a[h];
        h++;
    }
    return b;
}
```