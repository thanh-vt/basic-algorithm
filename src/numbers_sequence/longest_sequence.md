Một bài nâng cao của [bài tập cũ](https://codelearn.io/LearningTask/Index?Id=3477&TaskId=3823)

Cho một mảng các số nguyên\
Hãy tìm ra dãy con có độ dài lớn nhất và tạo thành cấp số cộng

Example

-   Với `a = [1, 7, 3, 5, 4, 2]`, thì kết quả `longestSequence(a) = 3`.\
    Dãy `[1, 3, 5]` là dãy con không liên tiếp (giữ nguyên thứ tự xuất hiện) có độ dài lớn nhất tạo thành 1 cấp số cộng

Input/Output

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.integer a\
    Mảng chứa số nguyên\
    *Điều kiện:\
    *`1 ≤ a.length ≤ 20\
    ``-250 ≤ a[i] ≤ 250`.

-   [output] integer

    -   Độ dài lớn nhất của dãy con tạo thành cấp số cộng

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ Java:

```
int longestSequence(int[] a)
{
    int n = a.length;
    if (n <= 2)
        return n;
    int maxLength = 0;
    int currentLength = 0;
    List<Integer> list;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            list = new ArrayList<>();
            int cDiff = a[j] - a[i];
            if (cDiff == 0) {
                continue;
            }
            list.add(a[i]);
            list.add(a[j]);
            for (int k = j; k < n; k++) {
                if (a[k] - list.get(list.size() - 1) != cDiff) {
                    continue;
                }
                list.add(a[k]);
                currentLength = list.size();
                maxLength = Math.max(maxLength, currentLength);
            }
        }
    }
    return maxLength;
}
```