Cho một mảng các xâu kí tự, hãy sắp xếp mảng tăng dần theo độ dài của xâu kí tự

Nếu hai xâu kí tự có cùng độ dài, thứ tự của chúng giữ nguyên như thứ tự trong mảng ban đầu

Ví dụ:

-   Với `inputArray = ["abc", "", "aaa", "a", "zz"]` thì kết quả `sortByLength(inputArray) = ["", "a", "zz", "abc", "aaa"]

    `Mảng được sắp xếp theo thứ tự tăng của độ dài xâu. Xâu `"abc"` có cùng độ dài với xâu `"aaa"`, nhưng do đứng trước `"aaa"` trong mảng ban đầu nên vẫn đứng trước `"aaa"` trong mảng kết quả

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] array.string inputArray\
    Mang không rỗng chứa các xâu kí tự\
    *Điều kiện:\
    *`3 ≤ inputArray.length ≤ 100\
    ``0 ≤ inputArray[i].length ≤ 100`

-   [Đầu ra] array.string

### Lý thuyết: 

Trong bài toán sắp xếp, không phải lúc nào đề bài cũng yêu cầu sắp xếp một dãy số nguyên tăng dần. Nhưng cách làm cũng tương tự với bài toán sắp xếp thông thường chỉ thay đổi điều kiện so sánh:

Ví dụ với bài toán trên. Nếu ta áp dụng thuật toán *bubble sort* thì khi so sánh 2 xâu `inputString[i`] và `inputString[i+1]` thì ta sẽ so sánh độ dài của của chúng.

```
std::vector<std::string> sortByLength(std::vector<std::string> inputArray)
{
    int n = (int) inputArray.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n-1; ++j)
            if (inputArray[j].length() > inputArray[j+1].length())
                swap(inputArray[j], inputArray[j+1]);
    return inputArray;
}

```

Hướng dẫn bài tập:
------------------

Code mẫu:

Ngôn ngữ Java:

```
String[] sortByLength(String[] inputArray)
{
    String temp;
    int len = inputArray.length;
    int count;
    do {
      count = 0;
      for (int i = 0; i < len - 1; i++) {
        if(inputArray[i].length() > inputArray[i+1].length()) {
          temp = inputArray[i];
          inputArray[i] = inputArray[i+1];
          inputArray[i+1] = temp;
          count++;
        }
      }
    } while (count>0);
    return inputArray;
}
```