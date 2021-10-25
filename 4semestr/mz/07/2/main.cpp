#include <string>
#include <sstream>
#include <cmath>    

class Square : public Figure
{
private:
    double _a{};
public:
    Square() {};
    Square(std::string s)
    {
        std::stringstream myString;
        myString << s << std::endl;
        myString >> _a;
    };
    static Square* make(std::string s)
    {   
        return new Square(s);
    }
    virtual double get_square() const { return _a * _a; };
    virtual ~Square() {};
};

class Circle : public Figure
{
private:
    double _r{};
public:
    Circle() {};
    Circle(std::string s)
    {
        std::stringstream myString;
        myString << s << std::endl;
        myString >> _r;
    };
    static Circle* make(std::string s)
    {   
        return new Circle(s);
    }
    virtual double get_square() const { return M_PI * _r * _r; };
    virtual ~Circle() {};
};

class Rectangle : public Figure
{
private:
    double _a{}, _b{};
public:
    Rectangle() {};
    Rectangle(std::string s)
    {
        std::stringstream myString;
        myString << s << std::endl;
        myString >> _a >> _b;
    };
    static Rectangle* make(std::string s)
    {   
        return new Rectangle(s);
    }
    virtual double get_square() const { return _a * _b; };
    virtual ~Rectangle() {};
};
