# 🎓 StudentCare & English Learning App

Chào mừng đến với **StudentCare Manager**! Đây là bộ công cụ "All-in-one" giúp học sinh/sinh viên quản lý việc học, ôn luyện từ vựng Tiếng Anh và rèn luyện sự tập trung, được viết hoàn toàn bằng C++.

## ✨ Tính năng chính

Dự án bao gồm 4 module cốt lõi:

### 1. 📊 GPA Calculator (Tính điểm & Mục tiêu)
* Tính điểm trung bình môn học (GPA).
* **Goal Setting:** Tính toán số điểm cần đạt được trong bài thi cuối kỳ để đạt mục tiêu GPA mong muốn.

### 2. 🔤 FlashCard (Học từ vựng)
* Tạo và quản lý bộ thẻ từ vựng (Flashcards).
* Giúp ôn tập từ mới hiệu quả qua cơ chế lặp lại.

### 3. ❓ Quiz System (Trắc nghiệm)
* Hệ thống bài kiểm tra trắc nghiệm tiếng Anh.
* Tự động chấm điểm và hiển thị kết quả ngay lập tức.

### 4. 🍅 Pomodoro Timer (Đồng hồ tập trung)
* Đồng hồ đếm ngược theo phương pháp Pomodoro (25 phút học / 5 phút nghỉ).
* Giúp duy trì sự tập trung cao độ và tránh mệt mỏi.

---

## 🛠️ Công nghệ sử dụng

* **Ngôn ngữ:** C++ (Standard C++11 trở lên).
* **IDE:** Visual Studio Code / Code::Blocks.
* **Kỹ thuật:** Lập trình hướng đối tượng (OOP), Quản lý file, Đa luồng (Multi-threading cho đồng hồ).

---

## 🚀 Hướng dẫn Cài đặt & Chạy (Build & Run)

Vì dự án chia thành nhiều file (`.cpp` và `.h`), bạn cần biên dịch tất cả cùng lúc.

### Bước 1: Tải code về máy
    git clone https://github.com/Luchuongtam/English-app.git
    cd English-app

### Bước 2: Biên dịch (Compile)
Mở Terminal tại thư mục dự án và chạy lệnh sau để nối tất cả các file:
```text
    g++ *.cpp -o app
```

### Bước 3: Chạy chương trình
Trên Windows:

```text
    .\app.exe
```
Trên MacOS / Linux:

```text
    ./app
```

## 📂 Cấu trúc Dự án (Project Structure)

Dự án được tổ chức thành các module đơn giản:

```text
English-app/
│
├── 📄 main.cpp             # [CHÍNH] File chạy chương trình
│
├── 📦 FlashCard (Học từ vựng)
│   ├── FlashCard.h         # Định nghĩa cấu trúc thẻ từ
│   └── FlashCard.cpp       # Xử lý logic học từ
│
├── 📦 Pomodoro (Đồng hồ tập trung)
│   ├── Pomodoro.h          # Định nghĩa đồng hồ
│   └── Pomodoro.cpp        # Xử lý đếm ngược thời gian
│
├── 📦 GPA Calculator (Tính điểm)
│   ├── GPACalculator.h     # Định nghĩa công thức điểm
│   └── GPACalculator.cpp   # Xử lý tính toán GPA
│
├── 📦 Quiz (Trắc nghiệm)
│   ├── Quiz.h              # Định nghĩa câu hỏi
│   └── Quiz.cpp            # Xử lý bài kiểm tra
│
└── 📦 Utils (Tiện ích)
    ├── Utils.h             # Các hàm hỗ trợ chung
    └── Utils.cpp           # Xử lý giao diện, màu sắc
```

👤 Tác giả
Luchuongtam - N24DCCN139

Dự án phục vụ mục đích học tập và chia sẻ kiến thức lập trình C++.