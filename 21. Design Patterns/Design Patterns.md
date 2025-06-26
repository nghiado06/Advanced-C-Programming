# NỘI DUNG TÌM HIỂU
- Hôm nay chúng ta sẽ cùng tìm hiểu về một kiến thức hết sức quan trọng trong lập trình hướng đối tượng - Design Pattern.
- Bất kỳ một lập trình viên nào thực sự muốn thông thạo C/C++ thì phải nắm được kiến thức về Design Pattern này.
- Vậy thì hôm nay chúng ta sẽ cùng tìm hiểu:
  - Design Pattern
  - Các loại Design Pattern
  - Cụ thể của từng loại Design Pattern
  - Ví dụ và phân tích sâu.

# DESIGN PATTERN
# 1. KHÁI NIỆM
- **Design Patterns (mẫu thiết kế)** là một kĩ thuật trong lập trình hướng đối tượng và được sử dụng thường xuyên trong các ngôn ngữ OOP như Java,C#,Kotlin...
Nó cũng cấp cho ta các mẫu (Pattern) để giải quyết các vẫn đề thường gặp, tuy bạn có thể tự nghĩ ra nhưng nó có thể không phải là tối ưu. Design pattern sẽ giúp chúng ta giải quyết những vấn đề này được **tối ưu nhất**.
- Nó sẽ như một **công thức** đã được tìm ra giúp các lập trình viên áp dụng xử lý tình huống trong quá trình thiết kế của mình.
- Design Patterns không phụ thuộc vào ngôn ngữ nào cả bạn có thể áp dụng với phần lớn những ngôn ngữ lập trình hiện nay.

# 2. Lí do và Các vấn đề gặp phải
## 2.1 Các vấn đề gặp phải khi code
- Khó kiểm soát việc tạo đối tượng.
- Khó mở rộng hoặc thay đổi hành vi.
- Giao tiếp giữa các modules phức tạp.
- Lặp code hoặc logic tương tự nhau.
- Logic xử lý và giao diện người dùng (UI) bị trộn lẫn.


## 2.2 Lí do nên sử dụng
- Tái sử dụng lại code và dễ mở rộng
- Là những giải pháp đã được tối ưu hóa và chúng ta có thể sử dụng tùy theo trường hợp mà không cần suy nghĩ.
- Đồng thời tăng tốc độ phát triển và testing cho các nhà phát triển
- Đương nhiên code sẽ trở nên dễ đọc và dễ hiểu kèm theo đó là dễ bảo trì nâng cấp về sau.
- Tiết kiệm thời gian làm việc với code của các dev khác.

# 3. PHÂN LOẠI
- Design Pattern có thể được chia thành 23 mẫu và 3 nhóm khác nhau.
- 
## 3.1 Creational Patterns (Nhóm khởi tạo)
- Bao gồm 5 mẫu : Factory Method, Abstract Factory, Builder, Prototype, Singleton.
- Cung cấp giải pháp giúp tạo ra object và che giấu logic tạo ra nó thay vì tạo một cách trực tiếp => giúp chương trình mềm dẻo hơn khi muốn tạo object nào và theo tình huống nào.

## 3.2 Structural Patterns (Nhóm cấu trúc)
- Bao gồm 7 mẫu : Adapter, Bridge, Composite, Decorator, Facade, Flyweight và Proxy.
- Giúp ta thiết lập mối quan hệ giữa các đối tượng với nhau.

## 3.3 Behavioral Patterns (Nhóm tương tác)
- Bao gồm 11 mẫu: Interpreter, Template Method, Chain of Responsibility, Command, Iterator, Mediator, Memento, Observer, State, Strategy và Visitor
- Cung cấp giải pháp để thực hiện các hành vi của đối tượng cũng như giữa các object với nhau.

