#include <iostream>
#include <string>
#include <cmath>

struct BoundingBoxDimensions {
    double width = 0;
    double height = 0;
};

class Shape {
public:
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual std::string type() = 0;
};

class Rectangle: virtual public Shape {
    double width = 0;
    double height = 0;

    public:
        virtual double square() {
            return width * height;
        }

        virtual BoundingBoxDimensions dimensions() {
            BoundingBoxDimensions boundingBoxDimensions;
            boundingBoxDimensions.height = height;
            boundingBoxDimensions.width = width;
            return boundingBoxDimensions;
        }

        virtual std::string type() {
            std::string tempStr = "Type: rectangle\n";
            tempStr += "Square: " + std::to_string(square()) + "\n";
            BoundingBoxDimensions boundingBoxDimensions = dimensions();
            tempStr += "Height: " + std::to_string(boundingBoxDimensions.height) + "\n";
            tempStr += "Width: " + std::to_string(boundingBoxDimensions.width) + "\n";
            return tempStr;
        }

        Rectangle (double inWidth, double inHeight) {
            if (inWidth <= 0 || inHeight <= 0) {
                std::cout << "Invalid side" << std::endl;
            }
            else {
                width = inWidth;
                height = inHeight;
            }
        }
};

class Circle: virtual public Shape {
    double radius = 0;

    public:
        virtual double square() {
            return std::atan(1) * 4 * radius;
        }

        virtual BoundingBoxDimensions dimensions() {
            BoundingBoxDimensions boundingBoxDimensions;
            boundingBoxDimensions.height = (radius * 2);
            boundingBoxDimensions.width = (radius * 2);
            return boundingBoxDimensions;
        }

        virtual std::string type() {
            std::string tempStr = "Type: circle\n";
            tempStr += "Square: " + std::to_string(square()) + "\n";
            BoundingBoxDimensions boundingBoxDimensions = dimensions();
            tempStr += "Height: " + std::to_string(boundingBoxDimensions.height) + "\n";
            tempStr += "Width: " + std::to_string(boundingBoxDimensions.width) + "\n";
            return tempStr;
        }

        Circle (double inRadius) {
            if (inRadius <= 0) {
                std::cout << "Invalid side" << std::endl;
            }
            else {
                inRadius = radius;
            }
        }
};

class Triangle: virtual public Shape {
    double firstSide = 0;
    double secondSide = 0;
    double thirdSide = 0;

    public:
        virtual double square() {
            double semiperimeter = (firstSide + secondSide + thirdSide) / 2;
            return sqrt(semiperimeter * (semiperimeter - firstSide) * (semiperimeter - secondSide) * (semiperimeter - thirdSide));
        }

        virtual BoundingBoxDimensions dimensions() {
            BoundingBoxDimensions boundingBoxDimensions;
            boundingBoxDimensions.height = 2 * (firstSide * secondSide * thirdSide / (4 * square()));
            boundingBoxDimensions.width = 2 * (firstSide * secondSide * thirdSide / (4 * square()));
            return boundingBoxDimensions;
        }

        virtual std::string type() {
            std::string tempStr = "Type: triangle\n";
            tempStr += "Square: " + std::to_string(square()) + "\n";
            BoundingBoxDimensions boundingBoxDimensions = dimensions();
            tempStr += "Height: " + std::to_string(boundingBoxDimensions.height) + "\n";
            tempStr += "Width: " + std::to_string(boundingBoxDimensions.width) + "\n";
            return tempStr;
        }

        Triangle (double inFirstSide, double inSecondSide, double inThirdSecond) {
            if (inFirstSide <= 0 || inSecondSide <= 0 || inThirdSecond <= 0) {
                std::cout << "Invalid side" << std::endl;
            }
            else {
                firstSide = inFirstSide;
                secondSide = inSecondSide;
                thirdSide = inThirdSecond;
            }
        }
};

void printParams(Shape *shape) {
    std::cout << "Type: " << shape->type() << std::endl;
}

int main() {
    Triangle t(3, 4, 5);
    printParams(&t);
}

/*
У вас есть набор классов различных геометрических фигур: круг(Circle), 
прямоугольник(Rectangle) и треугольник(Triangle), которые наследуются 
от общего класса геометрическая фигура (Shape). Каждый из этих классов 
имеет методы подсчёта площади, описывающего прямоугольника и взятия 
типа. Также есть общая функция printParams которая по переданному ей 
указателю на объект типа геометрическая фигура выводит на экран тип фигуры.
*/