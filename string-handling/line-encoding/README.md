###Thuật toán mã hóa ký tự

Cho một xâu kí tự, viết hàm mã hóa xâu đó theo các luật sau:

-   Đầu tiên, cắt xâu ban đầu thành các xâu con mà mỗi xâu con chỉ chứa các kí tự giống nhau và xâu con tạo ra có độ dài là lớn nhất
    -   Ví dụ, xâu `"aabbbc"` được tách thành `["aa", "bbb", "c"]`
-   Tiếp theo, với mỗi xâu con có chiều dài lớn hơn `1,` hãy thay thế xâu đó bằng việc viết liền độ dài của xâu với kí tự lặp lại
    -   Ví dụ, xâu con `"bbb"` được thay thế bằng `"3b"`
-   Cuối cùng, viết liên tiếp các xâu con vừa được mã hóa theo thứ tự ban đầu để tạo ra xâu kết quả

Ví dụ:

-   Với `s = "aabbbc"`, thì kết quả `lineEncoding(s) = "2a3bc"`.

Đầu vào/Đầu ra:

-   [Thời gian chạy] 0.5 seconds 

-   [Đầu vào] string s\
    Xâu kí tự chứa các kí tự chữ cái in thường.\
    *Điều kiện:*\
    `4 ≤ s.length ≤ 100`.

-   [Đầu ra] string

    -   Xâu kí tự mã hóa.

### Hướng dẫn bài tập.

Ta dùng một biết `k` để lưu số lượng các ký tự giống nhau. Dùng một vòng for để duyệt từ đầu đến cuối chuổi, nếu ký s[i] giống `s[i - 1]` ta tăng `k` lên `1` đơn vị, ngược lại in ra k và `s[i - 1]`, nhớ khởi tạo lại biến `k` các bạn nhé.

Code mẫu:

Ngôn ngữ C++:

```
string toString(int n){
	string s = "";
	while (n > 0){
		s = char(n % 10 + '0') + s;
		n /= 10;
	}
	return s;
}
std::string lineEncoding(std::string s)
{
	string kq = "";
    int k = 1;
    s = s+" ";
	for (int i = 0;i < s.length() - 1; i++)
	if (s[i] == s[i + 1]) k++;
	else{
		if (k > 1)
			kq = kq + toString(k);
		kq = kq + s[i];
		k = 1;
	}
    return kq;
}
```