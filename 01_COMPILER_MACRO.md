# Tìm hiểu về Compiler Process và Macro trong C
Compiler là gì? Quá trình compile gồm những bước nào? <br>
Macro là gì? Ý nghĩa của Macro ứng với quá trình compile và code.
## 1. Compiler
### A. Định nghĩa
Compiler có thể hiểu đơn giản là trình biên dịch, là một chương trình dịch (compile) một mã nguồn từ ngôn ngữ lập trình cấp cao (C++, C, Java,..) sang ngôn ngữ máy (Machine Language) để CPU, máy tính có thể hiểu được. 
### B. Quá trình compile (Compiler Process)
- Quá trình compile sẽ bao gồm các bước sau:
    - **Preprocessing** (Tiền xử lý): Quá trình sẽ chuyển các file (.c;.cpp;.h) sang file .i với cú pháp trong terminal:. <br>
```cpp
gcc -E file.c -o file.i
---
Quá trình này bao gồm các công việc:
    -     Include Header: Tìm kiếm và chèn mã nguồn
    -     Delete Comment: Xóa đi các dòng comment
    -     Expand Macro: Thay thế các macro 

# Macros
