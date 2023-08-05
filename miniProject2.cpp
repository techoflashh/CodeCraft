// ================  DO NOT TOUCH THIS FILE =====================

#include <bits/stdc++.h>
#include <iostream>

template <typename T>
class Fraction
{
public:
  Fraction(T, T);
  Fraction reduce();
  T get_numerator();
  T get_denominator();
  Fraction operator+(Fraction &);
  Fraction operator-(Fraction &);
  Fraction operator*(Fraction &);
  Fraction operator/(Fraction &);
  bool operator==(Fraction &);
  bool operator!=(Fraction &);
  bool operator<=(Fraction &);
  bool operator<(Fraction &);
  bool operator>=(Fraction &);
  bool operator>(Fraction &);
  void print();

private:
  T numerator;
  T denominator;
  const char div_char = '/';
};

template <typename T>
T gcd(T, T);

template <typename T>
T gcd(T a, T b)
{
  return b ? gcd<T>(b, a % b) : a;
}

//===================== DO NOT TOUCH THE STUFF ABOVE ==========

// print() implementation:
// it should print the fraction in the following order in its lowest form
// 1/2
// terminated by a newline, no spaces or anything else

//=========== YOUR CODE HERE ==============
template <typename T>
Fraction<T>::Fraction(T n, T d)
{
  if (n<0 && d<0){
    n = -n;
    d = -d;
  }
  else if (d<0){
    n = -n;
    d = -d;
  }
  numerator = n;
  denominator = d;
  return reduce();
}

template <typename T>
Fraction<T> Fraction<T>::reduce()
{
  T gcd_val = gcd<T>(abs(numerator), abs(denominator));
  numerator /= gcd_val;
  denominator /= gcd_val;
  return *this;
}

template <typename T>
T Fraction<T>::get_numerator()
{
  return numerator;
}

template <typename T>
T Fraction<T>::get_denominator()
{
  return denominator;
}

template <typename T>
Fraction<T> Fraction<T>::operator+(Fraction<T> &f)
{
  T n = numerator * f.get_denominator() + f.get_numerator() * denominator;
  T d = denominator * f.get_denominator();
  Fraction<T> f1(n, d);
  return f1.reduce();
}

template <typename T>
Fraction<T> Fraction<T>::operator-(Fraction<T> &f)
{
  T n = numerator * f.get_denominator() - f.get_numerator() * denominator;
  T d = denominator * f.get_denominator();
  Fraction<T> f1(n, d);
  return f1.reduce();
}

template <typename T>
Fraction<T> Fraction<T>::operator*(Fraction<T> &f)
{
  T n = numerator * f.get_numerator();
  T d = denominator * f.get_denominator();
  Fraction<T> f1(n, d);
  return f1.reduce();
}

template <typename T>
Fraction<T> Fraction<T>::operator/(Fraction<T> &f)
{
  T n = numerator * f.get_denominator();
  T d = denominator * f.get_numerator();
  Fraction<T> f1(n, d);
  return f1.reduce();
}

template <typename T>
bool Fraction<T>::operator==(Fraction<T> &f)
{
  return (numerator == f.get_numerator() && denominator == f.get_denominator());
}

template <typename T>
bool Fraction<T>::operator!=(Fraction<T> &f)
{
  return (numerator != f.get_numerator() || denominator != f.get_denominator());
}

template <typename T>
bool Fraction<T>::operator<=(Fraction<T> &f)
{
  return (numerator * f.get_denominator() <= f.get_numerator() * denominator);
}

template <typename T>
bool Fraction<T>::operator<(Fraction<T> &f)
{
  return (numerator * f.get_denominator() < f.get_numerator() * denominator);
}

template <typename T>
bool Fraction<T>::operator>=(Fraction<T> &f)
{
  return (numerator * f.get_denominator() >= f.get_numerator() * denominator);
}

template <typename T>
bool Fraction<T>::operator>(Fraction<T> &f)
{
  return (numerator * f.get_denominator() > f.get_numerator() * denominator);
}

template <typename T> 
void Fraction<T>::print()
{
  std::cout << numerator << div_char << denominator << std::endl;
}


enum OpIdTy
{
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  EQUAL,
  UNEQUAL,
  LEQ,
  LESS,
  GEQ,
  GREAT,
  PRINT
};

int main()
{
  Fraction<int> f1(6,16);
  Fraction<int> f2(3,8);
  Fraction<int> f3 = f2 - f1;
  Fraction<int> f4 = f1*f2;
  Fraction<int> f5 = f1/f2;
  Fraction<int> f6 = f1+f2;
  f6.print();
  f3.print();
  f4.print();
  f5.print();
  std::cout << (f1 == f2) << std::endl;
  std::cout << (f1 != f2) << std::endl;
  std::cout << (f1 <= f2) << std::endl;
  std::cout << (f1 < f2) << std::endl;
  std::cout << (f1 >= f2) << std::endl;
  std::cout << (f1 > f2) << std::endl;
}
