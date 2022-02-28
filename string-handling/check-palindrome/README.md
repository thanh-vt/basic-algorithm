###Thuật toán kiểm tra số Palindrome
Một xâu được gọi là palindrome nếu viết xuôi hay viết ngược xâu đó đều cho ra kết quả giống nhau

Cho một xâu kí tự, kiểm tra nó có phải xâu palindrome không.

Ví dụ

-   Với `inputString = "aabaa"`, kết quả `checkPalindrome(inputString) = true`;
-   Với `inputString = "abac"`, kết quả `checkPalindrome(inputString) = false`;
-   Với `inputString = "a"`, kết quả `checkPalindrome(inputString) = true`.

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] string inputString.\
    Xâu không rỗng chứa các kí tự chữ cái in thường\
    *Điều kiện:*\
    `1 ≤ inputString.length ≤ 105`.

-   [Đầu ra] boolean

    -   `true` nếu `inputString` là xâu palindrome, `false` nếu không.

### Lý thuyết :

-   Để kiểm tra 1 xâu `S` độ dài `n` có là *xâu palindrome* không, thì ta chỉ việc kiểm tra xâu S có đối xứng không là được, tức là `S[i] = S[n - i - 1]` với `i = [0 .. n/2)`. *ĐPT : O(N)*

```
bool isPalindrome(string S)
{
    int n = S.size();
    for (int i = 0; i < n/2; ++i)
        if (S[i] != S[n - i - 1]) return false;
    return true;
}
```

-   Mở rộng vấn đề : nếu như ta muốn kiểm tra 1 lượng lớn xâu con của` S` có phải là *xâu palindrome* không, vậy có cách nào để kiểm tra nhanh không ?
    -   Nhận xét : với xâu` S`, nếu xâu con `S[L, R`] là xâu palin
        -   TH1 : `L = R`. Điều này hiển nhiên phải không các bạn ?
        -   TH2 : `L < R`

            -   kí tự `S[L] = S[R]`
            -   hoặc `L = R - 1`, hoặc `S[L + 1, R - 1]` cũng phải là xâu palin
    -   Từ nhận xét trên, ta có thể dùng 1 mảng `CheckPalin[][]` để lưu lại kết quả khi kiểm tra với các xâu con của `S`. Ta sẽ kiểm tra `CheckPalin[i][j]` dựa vào `S[i]`, `S[j]` và `CheckPalin[i + 1][j - 1]`
    -   Khi cần kiểm tra 1 đoạn `[L, R]` có là xâu palin không, ta chỉ việc lấy ra `CheckPalin[L][R]` là được. 1 bước, quá nhanh gọn.
    -   Code minh họa

```
int CheckPalin[1003][1003];

void buildCheck(string S) {
    int n = S.size();
    for (int i = n - 1; i >= 0; --i) {
        CheckPalin[i][i] = 1; // day la TH1
        for (int j = i + 1; j < n; ++j)
            CheckPalin[i][j] = (S[i] == S[j]) && (i == j - 1 || CheckPalin[i + 1][j - 1]);
            // day la TH2
    }
}

bool checkSubS(int L, int R) {
    return CheckPalin[L][R];
}
```

Hướng dẫn bài tập.
------------------

Code mẫu C++:

Cách 1:

```
bool checkPalindrome(std::string inputString)
{
    for (int i = 0; i < inputString.length() / 2; i++)
    if (inputString[i] != inputString[inputString.length() - 1 - i])
        return false;
    return true;
}

```

Cách 2:

```
bool checkPalindrome(std::string inputString)
{
    string s = "";
    for (int i = inputString.length() - 1; i >= 0; i--)
        s = s + inputString[i];
    return s == inputString;
}
```