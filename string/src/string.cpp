#include "../string.hpp"

String::String() : size_(0), capacity_(0) {
    data_ = new char[1];
    data_[0] = '\0';
};
String::String(const char* c_str) : size_(std::strlen(c_str)), capacity_(size_*2) {
    data_ = new char[capacity_ + 1];
    std::copy(c_str, c_str + size_, data_);
    data_[size_] = '\0';
};
String::String(int n, const char c) : size_(n), capacity_(size_*2) {
    data_ = new char[capacity_ + 1];
    std::fill(data_, data_ + size_, c);
    data_[size_] = '\0';
};
String::~String() {
    delete[] data_;
}

String::String(const String& other) : size_(other.size_), capacity_(other.capacity_) {
    data_ = new char[capacity_ + 1];
    std::copy(other.data_, other.data_ + other.size_, data_);
    data_[size_] = '\0';
};
String& String::operator = (const String& other) {
    if (this == &other) {
        return *this;
    }
    if (other.size_ > capacity_) {
        delete[] data_;
        capacity_ = other.capacity_;
        data_ = new char[capacity_ + 1];
    }
    size_ = other.size_;
    
    std::copy(other.data_, other.data_ + other.size_, data_);
    data_[size_] = '\0';
    return (*this);
}; 

String& String::operator = (const char* c_str) {
    (*this) = String(c_str);
    return (*this);
}

// auto String::operator <=> (const String& other) const {
//     return std::strcmp(Data(), other.Data());
// }



bool operator == (const String& lhs, const String& rhs) {
    if (lhs.Size() != rhs.Size()) {
        return false;
    }
    return (std::strcmp(lhs.Data(), rhs.Data()) == 0);
}
bool operator < (const String& lhs, const String& rhs) {
    if (lhs.Size() < rhs.Size()) {
        return true;
    }
    return (std::strcmp(lhs.Data(), rhs.Data()) < 0);
}
bool operator > (const String& lhs, const String& rhs) {
    return (rhs < lhs);
}
bool operator <= (const String& lhs, const String& rhs) {
    return !(lhs > rhs);
}
bool operator >= (const String& lhs, const String& rhs) {
    return !(lhs < rhs);
}
bool operator != (const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

char& String::operator [] (int index) {
    return data_[index];
}
const char& String::operator [] (int index) const {
    return data_[index];
}

int String::Length() const {
    return size_;
}
int String::Size() const {
    return size_;
}
int String::Capacity() const {
    return size_;
}

void String::expand(int new_capacity) {
    if (capacity_ == 0) {
        if (new_capacity < 1) {
            new_capacity = 1;
        }
    } //костыль чтобы когда у пустого объекта вызывался экспенд он мог увеличить капасити даже если передает расширение по мультипликатору 
    if (capacity_ >= new_capacity) {
        return;
    }
    char* new_data = new char[new_capacity + 1];
    std::copy(data_, data_ + size_, new_data);
    new_data[size_] = '\0';
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}
void String::expand() {
    (*this).expand(capacity_ * 2);
}
void String::PushBack(char c) {
    if (capacity_ < size_ + 1) {
        expand();
    }
    ++size_;
    data_[size_ - 1] = c;
    data_[size_] = '\0';
    return;
}
void String::PopBack() {
    --size_;
    data_[size_] = '\0';
}

char& String::Front() {
    return *data_;
}
const char& String::Front() const {
    return *data_;
}
char& String::Back() {
    return *(data_ + size_ - 1);
}
const char& String::Back() const {
    return *(data_ + size_ - 1);
}

String& String::operator += (const char c) {
    (*this).PushBack(c);
    return (*this);
}
String& String::operator += (const char* c_str) {
    int c_str_len = std::strlen(c_str);
    if (size_ + c_str_len > capacity_) {
        expand((capacity_ + c_str_len) * 2);
    }
    std::copy(c_str, c_str + c_str_len, data_ + size_);
    size_ += c_str_len;
    data_[size_] = '\0';
    return (*this);
}
String& String::operator += (const String& other) {
    if (size_ + other.size_ > capacity_) {
        expand((capacity_ + other.capacity_) * 2);
    }
    std::copy(other.data_, other.data_ + other.size_, data_ + size_);
    size_ += other.size_;
    data_[size_] = '\0';
    return (*this);
}

char* String::Data() {
    return data_;
}
const char* String::Data() const {
    return data_;
}

std::ostream& operator << (std::ostream& os, const String& str) {
    for (int i = 0; i < str.Size(); i++) {
        os << str[i];
    }
    return os;
    // return os << (str).Data(); потомушта в тесте кто-то вставил бэкслэщ ноль
}
std::istream& operator >> (std::istream& is, String& str) {
    char c;
    String temp;
    while(is.get(c)) {
        if (c == '\n') {
            break;
        }
        temp.PushBack(c);
    }
    str = temp;
    return is;
}

bool String::Empty() const {
    return (size_ == 0);
}

void String::Clear() {
    size_ = 0;
    data_[size_] = '\0';
}

void String::ShrinkToFit() {
    char* new_data = new char[size_ + 1];
    std::copy(data_, data_ + size_, new_data);
    capacity_ = size_;
    delete[] data_;
    data_ = new_data;
    data_[size_] = '\0';
}

String operator + (const String& lhs, const String& rhs) {
    String result = lhs;
    result += rhs;
    return result;
}
String operator + (const String& lhs, const char rhs) {
    String result = lhs;
    result += rhs;
    return result;
}
String operator + (const String& lhs, const char* rhs) {
    String result = lhs;
    result += rhs;
    return result;
}
String operator + (const char lhs, const String& rhs){
    String result(1, lhs);
    result += rhs;
    return result;
}
String operator + (const char* lhs, const String& rhs){
    String result(lhs);
    result += rhs;
    return result;
}


int String::Find(const String& substr) const {
    if (substr.Length() == 0) {
        return Length();
    }

    //пришлось здесь НАГОВНИТЬ потому что в гугл тестах видимо нельзя в методе find НИЧЕГО создавать на куче
    int prefix[substr.Length()];
    for (int i = 0; i < substr.Length(); i++) {
        prefix[i] = 0;
    }

    for (int i = 1; i < substr.Length(); i++) {
        int k = prefix[i - 1];
        while(k > 0 && (substr[k] != substr[i])) {
            k = prefix[k - 1];
        }
        if (substr[k] == substr[i]) {
            k += 1;
        }
        prefix[i] = k;
    }

    int j = 0;
    for (int i = 0; i < Length(); i++) {
        while (substr[j] != (*this)[i] && j > 0) {
            j = prefix[j - 1];
        }
        if (substr[j] == (*this)[i]) {
            j++;
            

        }
        if (j == substr.Length()) {
            
            return (i - substr.Length() + 1);
        }
        
    }
    
    return Length();
}



int String::Rfind(const String& substr) const {
    if (substr.Length() == 0) {
        return Length();
    }

    int prefix[substr.Length()];
    for (int i = 0; i < substr.Length(); i++) {
        prefix[i] = 0;
    }

    for (int i = 1; i < substr.Length(); i++) {
        int k = prefix[i - 1];
        while(k > 0 && (substr[k] != substr[i])) {
            k = prefix[k - 1];
        }
        if (substr[k] == substr[i]) {
            k += 1;
        }
        prefix[i] = k;
    }

    int j = 0;
    int result = Length();
    for (int i = 0; i < Length(); i++) {
        while (substr[j] != (*this)[i] && j > 0) {
            j = prefix[j - 1];
        }
        if (substr[j] == (*this)[i]) {
            j++;
            

        }
        if (j == substr.Length()) {
            result = (i - substr.Length() + 1);
            j = prefix[j - 1];
        }
        
    }
    return result;
}

int String::Find(const char* substr) const {
    return Find(String(substr));
}
int String::Rfind(const char* substr) const {
    return Rfind(String(substr));
}

String String::Substr(int start, int count) const {
    // if (start > size_) {
    //     return String();
    // }
    if (count > size_ - start) {
        count = size_ - start;
    }
    char tmp[count + 1];
    for (int i = 0; i < count; i++) {
        tmp[i] = (*this)[start + i];
    } 
    tmp[count] = '\0';
    return String(tmp);
}

// String::String(String&& other) : size_(other.size_), capacity_(other.capacity_), data_(other.data_) {
//     other.data_ = nullptr;
//     other.size_ = 0;
//     other.capacity_ = 0;
// }
