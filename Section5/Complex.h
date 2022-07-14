#pragma once

#include <ostream>
#include <iostream>

class Complex
{
public:
    Complex();
    Complex(const double &m_real, const double &m_imaginary);
    Complex(const Complex &com);

    friend std::ostream &operator<<(std::ostream &out, const Complex &com);
    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator+(const Complex &c1, const double &num);
    friend bool operator==(const Complex &c1, const Complex &c2);

    bool operator==(const Complex &c1) const;
    const Complex operator*() const;
    const Complex &operator=(const Complex &com);
    ~Complex() = default;
private:
    double real;
    double imaginary;
};

