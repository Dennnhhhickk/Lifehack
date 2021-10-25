class C
{
public:
    C() {};
    C(int a) {};
    C(double a) {};
    C(const C& a) {};
    C(const C& a, const C& b) {};
    friend C operator++(const C &a);
    friend C operator+(int value, const C &a);
    friend int operator*(const C &a, const C b[]);
    friend C operator&(const C &a);
    friend int operator~(const C &a);
 
private:
    double ld_;
};

C operator++(const C &a)
{
    return 0;
}

C operator+(int value, const C &a)
{
    return 0;
}

int operator*(const C &a, const C b[])
{
    return 0;
}
C operator&(const C &a)
{
    return 0;
}

int operator~(const C &a)
{
    return 0;
}
