#include "Complex.h"

Complex::Complex()
{
    this->imaginary = 0.0;
    this->real = 0.0;
}

Complex::Complex(const Complex &com)
{
    this->real = com.real;
    this->imaginary = com.imaginary;
}

Complex::Complex(const double &m_real, const double &m_imaginary)
{
    this->real = m_real;
    this->imaginary = m_imaginary;
}

const Complex& Complex::operator=(const Complex &com)
{
    this->real = com.real;
    this->imaginary = com.imaginary;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Complex &com)
{
    return out << "Real: " << com.real << " Imaginary: " << com.imaginary << std::endl;
}

Complex operator+(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real + c2.real, c2.imaginary + c1.imaginary);
}

Complex operator+(const Complex &c1, const double &num)
{
    return Complex(c1.real + num, c1.imaginary + num);
}

bool operator==(const Complex &c1, const Complex &c2)
{
    return (c1.real == c2.real && c1.imaginary == c2.imaginary);
}

bool Complex::operator==(const Complex &c1) const
{
    return (real == c1.real && imaginary == c1.imaginary);
}

const Complex Complex::operator*() const
{
    return Complex(-real, -imaginary);
}