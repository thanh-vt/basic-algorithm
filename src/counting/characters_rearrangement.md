###Thuật toán kiểm tra 1 chuỗi là ký tự đảo của chuỗi khác

Cho hai xâu kí tự, hãy kiểm tra xem có tồn tại phương án đổi chỗ các kí tự ở trong xâu thứ nhất để trở thành xâu thứ hai được hay không? 

Ví dụ

-   Với `string1 = "abcd"` và `string2 = "cbad"` thì kết quả `charactersRearrangement(string1, string2) = true`;
-   Với `string1 = "a"` và `string2 = "b"` thì kết quả `charactersRearrangement(string1, string2) = false`.

Đầu vào/Đầu ra

-   [Thời gian chạy] 0.5 giây

-   [Đầu vào] string s1, s2\
    Xâu kí tự chứa các kí tự chữ cái in thường\
    *Điều kiện:*\
    `1 ≤ string1.length ≤ 105`.

-   [Đầu ra] boolean

    `true` nếu tồn tại phương án đổi chỗ, `false` nếu ngược lại.

### Lý thuyết 

Bài toán: Kiểm tra xâu `A` có thể sắp xếp thành xâu `B` bằng cách đổi chỗ các kí tự với nhau hay không ?

Nhận xét: Nhận thấy rằng khi đổi chỗ các kí tự thì số lượng kí tự mỗi loại thuộc xâu `A` sẽ không đổi. Nên xâu `A` sắp xếp được thành xâu `B` khi và chỉ khi số lượng của mỗi kí tự trong `A` và `B` bằng nhau.

Ví dụ minh họa: Với `A="abbad"`, `B="babda"` thì:

-   Kí tự `'a'`: xâu `A` và xâu `B` đều chứa `2` kí tự `'a'`   
-   Kí tự `'b'`: xâu `A` và xâu `B` đều chứa `2` kí tự `'b'`
-   Kí tự `'c'`: xâu `A` và xâu `B` đều không chứa kí tự `'c'`
-   Kí tự `'d'`: xâu `A` và xâu `B` đều chứa `1` kí tự `'d'`

⇒ Xâu `A` có thể biến đổi về thành xâu `B`

Hướng giải khác:

-   Giả sử xâu `A` có thể biến đổi thành xâu `B` bằng cách sắp xếp lại các kí tự. Điều đó đồng nghĩa với việc cả xâu `A` và xâu `B` đều có thể sắp xếp thành một xâu `C` nào đó. Chính vì vậy ta có thể tìm một xâu `C` phù hợp mà `A` có thể biến đổi thành. Từ đó kiểm tra xem xâu `B` có thể biến đổi thành xâu `C` được hay không ? 
-   Một cách chọn xâu `C` là xâu có thứ tự từ điển nhỏ nhất có thể biến đổi từ xâu `A`. Để kiểm tra xâu `B` có thể biến đổi thành xâu `C` hay không, ta chỉ việc xây thêm xâu `D` là xâu có thứ tự từ điển nhỏ nhất có thể biến đổi được từ xâu `B` và kiểm tra xem xâu `C` và xâu `D` có bằng nhau hay không ? 

Ví dụ minh họa: Với `A="cbac"` và `B="bcda"` thì

-   Xâu có thứ tự từ điển nhỏ nhất có thể biến đổi từ `A` là: `C="abcc"`
-   Xâu có thứ tự từ điển nhỏ nhất có thể biến đổi từ `B` là: `D="abcd"`

Do `C≠D` nên `A` không thể biến đổi về `B`.

Hướng dẫn bài tập.
------------------

Code mẫu:

Ngôn ngữ C++:

```
bool charactersRearrangement(std::string string1, std::string string2)
{
    vector <int> a(256, 0);
    for (int i = 0; i < string1.length(); i++)
        a[string1[i]]++;
    for (int i = 0; i  <string2.length(); i++)
        a[string2[i]]--;
    for (int i = 0; i <= 255; i++)
        if (a[i]!=0)
            return false;
    return true;
}
```