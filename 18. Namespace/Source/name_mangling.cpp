// Cơ chế name_mangling
/*
    Trình biên dịch sẽ mã hóa tên của hàm tại giai đoạn biên
    dịch - cụ thể là giai đoạn compiler

    A::func() --> _ZN1A4funcEv
    B::func() --> _ZN1B4funcEv

    Phân tích:
        _Z - Bắt đầu name mangling
        N...E: Tên nằm trong namespace hoặc class
        1A : Namespace "A" (1 ký tự)
        4func: Tên hàm func (4 ký tự)
        v: không có tham số


*/
