#pragma once

#include <iostream>
#include <cstring>
#include <algorithm>


struct String {
private:
    char* data_;
    int size_;
    int capacity_;
    void expand(int new_capacity);
    void expand();

public:
    String();
    String(const char* c_str);
    String(int n, const char c);
    ~String();

    
    String(const String& other);
    String& operator = (const String& other); 
    String& operator = (const char* c_str);

    // auto operator <=> (const String& other) const;
     

    char& operator [] (int index);
    const char& operator [] (int index) const;

    int Length() const;
    int Size() const;
    int Capacity() const;

    void PushBack(char c);
    void PopBack();

    char& Front();
    const char& Front() const;
    char& Back();
    const char& Back() const;

    String& operator += (const char c);
    String& operator += (const char* c_str);
    String& operator += (const String& other);



    char* Data();
    const char* Data() const;

    bool Empty() const;

    void Clear();
    void ShrinkToFit();

    int Find(const String& substr) const;
    int Rfind(const String& substr) const;

    int Find(const char* substr) const;
    int Rfind(const char* substr) const;

    String Substr(int start, int count) const;

};

std::ostream& operator << (std::ostream& os, const String& str);
std::istream& operator >> (std::istream& is, String& str);

String operator + (const String& lhs, const String& rhs);
String operator + (const String& lhs, const char rhs);
String operator + (const char lhs, const String& rhs);

bool operator == (const String& lhs, const String& rhs); 
bool operator < (const String& lhs, const String& rhs); 
bool operator > (const String& lhs, const String& rhs); 
bool operator <= (const String& lhs, const String& rhs); 
bool operator >= (const String& lhs, const String& rhs);
bool operator != (const String& lhs, const String& rhs); 