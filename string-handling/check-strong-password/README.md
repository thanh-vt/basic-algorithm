###Thuật toán kiểm tra mật khẩu mạnh

Một trang web định nghĩa 1 mật khẩu được gọi là mạnh (strong) nếu đảm bảo các yếu tố sau:

1.  Có độ dài tối thiểu là `6`
2.  Chứa ít nhất 1 chữ số (`1234567890`)
3.  Chứa ít nhất kí tự chữ cái in thường (`abc...z`)
4.  Chứa ít nhất 1 kí tự chữ cái in hoa (`ABC...Z`)
5.  Chứa ít nhất 1 kí tự đặc biệt: `!@#$%^&*()-+`

Cho một xâu kí tự thể hiện password, hãy kiểm tra xem đó có phải là password mạnh hay không?

Ví dụ:

-   Với `password = "abc"`, kết quả `checkStrongPassword(password ) = false`;
-   Với `password = "Aa1!"`, kết quả `checkStrongPassword(password ) = false`;
-   Với `password = "Aabc1!"`, kết quả `checkStrongPassword(password ) = true`;

Đầu vào/đầu ra:

-   [Thời gian chạy] 0.5s với C++, 3s với Java và C#, 4s với Python, JS, Go

-   [Đầu vào] string password

    *Điều kiện:*\
    `3 ≤ password.length ≤ 100`.

-   [Đầu ra] boolean

    true nếu password là strong, false ngược lại

### Lý thuyết 

Kiểu dữ liệu kí tự - character:

-   Là kiểu dữ liệu dùng để thể hiện các kí tự, chữ cái, chữ số (Ví dụ: `'a','b','C','D','6','9','@','$',...`)
-   Máy tính và các thiết bị truyền thông biểu thị kiểu dữ liệu kí tự (character) bằng cách "mã hóa kí tự" đó thành một số. Một kiểu mã hóa kí tự thường thấy đó là bảng mã ASCII
-   Bảng mã ASCII:\
    ![ASCII code Table](https://zentut.com//wp-content/uploads/2007/12/ascii-code-chart.gif)
-   Ví dụ: 
    -   số nguyên `65` thể hiện cho kí tự `'A'` 
    -   số nguyên `98` thể hiện cho kí tự `'b'` 
    -   số nguyên `51` thể hiện cho kí tự `'0'`
    -   số nguyên `64` thể hiện cho kí tự `'@'` 
-   Nhận xét: Nhờ bảng mã hóa ASCII nên ta hoàn toàn có thể coi kiểu dữ liệu kí tự (character) là một số nguyên để giải quyết các vấn đề.  

Kiểu dữ liệu xâu - string:

-   Là kiểu dữ liệu thường dùng để biểu diễn một đoạn văn bản.
-   Bản chất xâu (string) là một mảng kí tự (character). 
-   Ví dụ về xâu: `"A","123413","Codelearn is fun","baroibeo@gmail.com",...`
-   Nhận xét: Do các kí tự có thể mã hóa thành một số nguyên, nên ta hoàn toàn có thể coi xâu như là một mảng số nguyên. 
    -   Ví dụ: Với `S="aAbCCd"` thì ta có thể quy `S` thành mảng `[97,65,98,67,67,100]` thông qua bảng mã ASCII. 

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
bool checkStrongPassword(std::string password)
{
    if (password.length() < 6)
        return false;
    string p = "!@#$%^&*()-+";
    string s = password;
    bool kt1 = false;
    bool kt2 = false;
    bool kt3 = false;
    bool kt4 = false;
    for (int i=0; i<password.length(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
            kt1 = true;
        if (s[i] >= 97 && s[i] <= 122)
            kt2 = true;
        if (s[i] >= 48 && s[i] <= 57)
            kt4 = true;
        if (p.find(s[i])!= -1)
            kt3 = true;
    }
    return kt1 && kt2 && kt3 && kt4;
}
```
