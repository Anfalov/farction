//#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>

using namespace std;

class fraction
{
    int numerator, denominator;

public:
    fraction()
    {
        this->numerator = 0;
        this->denominator = 1;
    }

    fraction(int numerator, int denominator)
    {
        if (denominator == 0)
            throw invalid_argument("Denominator can't be 0");
        this->numerator = numerator;
        this->denominator = denominator;
    }

    fraction operator+(fraction second)
    {
        fraction result;
        result.numerator = (numerator * second.denominator + second.numerator * denominator);
        result.denominator = denominator * second.denominator;
        return result;
    }

    fraction& operator+=(fraction second)
    {
        numerator = (numerator * second.denominator + second.numerator * denominator);
        denominator = denominator * second.denominator;
        return *this;
    }

    fraction operator*(fraction second)
    {
        return { numerator * second.numerator, denominator * second.denominator };
    }

    fraction& operator*=(fraction second)
    {
        numerator = numerator * second.numerator;
        denominator = denominator * second.denominator;
        return *this;
    }

    fraction operator/(fraction second)
    {
        if (second.denominator == 0)
            throw invalid_argument("Denominator can't be 0");
        fraction result;
        result.numerator = numerator * second.denominator;
        result.denominator = denominator * second.numerator;
        return result;
    }

    fraction& operator/=(fraction second)
    {
        if (second.denominator == 0)
            throw invalid_argument("Denominator can't be 0");
        numerator = numerator * second.denominator;
        denominator = denominator * second.numerator;
        return *this;
    }

    fraction operator-(fraction second)
    {
        fraction result;
        result.numerator = (numerator * second.denominator - second.numerator * denominator);
        result.denominator = denominator * second.denominator;
        return result;
    }

    fraction& operator-=(fraction second)
    {
        numerator = (numerator * second.denominator - second.numerator * denominator);
        denominator = denominator * second.denominator;
        return *this;
    }

    int get_numerator()
    {
        return numerator;
    }

    void set_numerator(int numerator)
    {
        this->numerator = numerator;
    }

    int get_denominator()
    {
        return denominator;
    }

    void set_denominator(int denominator)
    {
        if (denominator == 0)
            throw invalid_argument("Denominator can't be 0");
        this->denominator = denominator;
    }

    fraction& reduce()
    {
        int n = nod(numerator, denominator);
        numerator = numerator / n;
        denominator = denominator / n;
        return *this;
    }

    friend ostream& operator<<(ostream& out, fraction fract);

    friend istream& operator>>(istream& in, fraction& fract);

private:
    int nod(int a, int b)
    {
        int d;
        while (b != 0)
        {
            d = a % b;
            a = b;
            b = d;
        }
        return a;
    }
};

ostream& operator<<(ostream& out, fraction fract)
{
    return out << fract.numerator << " / " << fract.denominator;
}

istream& operator>>(istream& in, fraction& fract)
{
    return in >> fract.numerator >> fract.denominator;
}

int main()
{
    fraction c, d, q;
    cin >> c >> d;
    q = c + d;
    q.reduce();
    cout << q << endl;
    cout << (c - d).reduce();
    //q.set_denominator(0);
}
