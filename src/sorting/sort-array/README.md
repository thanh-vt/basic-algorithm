Cho một dãy gồm các nguyên dương, bạn hãy viết chương trình sắp xếp các số trên theo thứ tự tăng dần. 

Ví dụ:

-   Với `arr = [6,5,4,3,2,1]` thì đầu ra của chương trình `sortArray(a) = [1,2,3,4,5,6]`
-   Với `arr = [100, 100, 99, 98, 102, 103]` thì đầu ra của chương trình `sortArray(a) = [98, 99, 100, 100, 102, 103]`

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.integer a\
    mảng số nguyên\
    `0 <= arr.length <= 1000`
-   [Đầu ra] array.integer\
    mảng số nguyên đã được sắp xếp

### Lý thuyết

Cách 1: Thuật toán Bubble sort

-   Mô tả thuật toán:
    -   Lần lượt xét hai phần tử `i` và `i+1` nếu như `A[i] > A[i+1]` thì đổi chỗ của `A[i]` và `A[i+1]` cho nhau. 
    -   Lặp lại bước trên cho đến khi dãy `A` là dãy tăng dần
-   Ví dụ minh họa thuật toán: 
    -   Xét dãy `A = [5,1,4,2]` độ dài `4` 
    -   Vòng lặp thứ nhất: 
        -   `A = [5,1,4,2] -> [1,5,4,2]` (So sánh phần tử thứ 0 và phần tử thứ 1)
        -   `A = [1,5,4,2] -> [1,4,5,2]` (So sánh phần tử thứ 1 và phần tử thứ 2)
        -   `A = [1,4,5,2] -> [1,4,2,5]` (So sánh phần tử thứ 2 và phần tử thứ 3)
    -   Vòng lặp thứ hai: 
        -   `A = [1,4,5,2] -> [1,4,5,2]` (So sánh phần tử thứ 0 và phần tử thứ 1)
        -   `A = [1,4,5,2] -> [1,4,5,2]` (So sánh phần tử thứ 1 và phần tử thứ 2)
        -   `A = [1,4,5,2] -> [1,4,2,5]` (So sánh phần tử thứ 2 và phần tử thứ 3)
    -   Vòng lặp thứ ba: 
        -   `A = [1,4,2,5] -> [1,4,2,5]` (So sánh phần tử thứ 0 và phần tử thứ 1)
        -   `A = [1,4,2,5] -> [1,2,4,5]` (So sánh phần tử thứ 1 và phần tử thứ 2)
        -   `A = [1,2,4,5] -> [1,2,4,5]` (So sánh phần tử thứ 2 và phần tử thứ 3)
    -   Dãy `A = [5,1,4,2]` được sắp xếp thành `A = [1,2,4,5]`
-   Độ phức tạp thuật toán: *O(n2)*
    -   Số có giá trị x sẽ đổi chỗ với các số có gíá trị bé hơn nó tối đa x - 1 lần
    -   Vậy thì số bé nhất sẽ đổi chỗ tối đa là 0 lần, số bé nhì là 1 lần, ... số lớn nhất là `n-1` lần ⇒ tổng số lần đổi chỗ tối đa là của cả dãy sẽ là `n*(n-1)/2` lần 

-   ```
    std::vector<int> sortArray(std::vector<int> arr)
    {
        int n = (int) arr.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n-1; ++j)
                if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
        return arr;
    }

    ```

Cách 2: Thuật toán Merge sort:

-   Tư tưởng thuật toán: 
    -   Dựa trên kĩ thuật *chia để trị (divide and conquer)*
-   Mô tả thuật toán:
    -   Ta chia đôi mảng `A[1..n]` thành hai mảng con `A[1..k]` và `A[k+1..n]` (với `k = n/2`). Giả sử hai mảng `A[1..k]` và `A[k+1..n]` đều đã được sắp xếp tăng dần thì ta thực hiện thao tác trộn hai mảng lại với nhau thì ta cũng thu được mảng `A[1..n]` sắp xếp tăng dần. Để sắp xếp hai mảng con `A[1..k]` và `A[k+1..n]` thì ta tiếp tục chia đôi chúng.
-   ```
    vector<int> Merge_Sort(vector<int> A) {
        int n = (int) A.size(), k = (n-1) / 2;

        vector<int> B, C;
        for (int i = 0; i <= k; ++i) B.push_back(A[i]);
        for (int i = k+1; i < (int) A.size(); ++i) C.push_back(A[i]);

        if ((int) B.size() > 1) B = Merge_Sort(B);
        if ((int) C.size() > 1) C = Merge_Sort(C);

        A.clear();
        A.resize(B.size() + C.size());
        merge(B.begin(), B.end(), C.begin(), C.end(), A.begin());

        return A;
    }

    ```

-   Độ phức tạp: *O(nlogn)*