//
// Created by kurchin_iu on 24.03.2026.
//
#include <iostream>
#include <cmath>

enum colors {
    none,
    red,
    blue,
    green
};

const double sizeFrame = 1.2;

using namespace std;

class HierarchyOfGeometricShapes {
protected:
    double x = 0.0,
           y = 0.0;
    colors color = none;

public:
    HierarchyOfGeometricShapes(double inX, double inY, colors inColor) {
        this->x = inX;
        this->y = inY;
        this->color = inColor;
    }

    string getOutColor () {
        if (color == none) {
            return "none";
        } else if (color == red) {
            return "red";
        } else if (color == blue) {
            return "blue";
        } else if (color == green) {
            return "green";
        }
    }
};

class Circle : public HierarchyOfGeometricShapes {
protected:
    double radius = 0.0;

public:
    Circle(double inX, double inY, colors inColor, double inRadius):
    HierarchyOfGeometricShapes(inX, inY, inColor), radius(inRadius) {}

    double getAreaCircl() {
        return atan(1) * 4 * radius * radius;
    }

    void outFrame () {
        double width = radius * sizeFrame,
               height  = radius * sizeFrame;

        cout << "\nFrame for Circle"
                "\nWidth: "<<  width <<
                "\nHeight: " << height <<
                "\nColor: "<< getOutColor() <<endl;
    }
};

class Square : public HierarchyOfGeometricShapes {
protected:
    double widthSq = 0.0;

    public:
    Square(double inX, double inY, colors inColor, double inWidthSq):
    HierarchyOfGeometricShapes(inX, inY, inColor), widthSq(inWidthSq) {}

    double getAreaSq() {
        return pow(widthSq, 2);
    }
    void outFrame () {
        double width =  widthSq * sizeFrame;
        cout << "\nFrame for Circle"
                "\nWidth: "<<  width <<
                "\nHeight: " << width <<
                "\nColor: "<< getOutColor() <<endl;

    }

};

class triangle : public HierarchyOfGeometricShapes {
protected:
    double lenghtTr = 0.0;

public:
    triangle(double inX, double inY, colors inColor, double inlenghtTr):
    HierarchyOfGeometricShapes(inX, inY, inColor), lenghtTr(inlenghtTr) {}

    double getAreaTr() {
        return pow(lenghtTr, 2) * sqrt(3) / 4;
    }
    void outFrame () {
        double side =  lenghtTr * sizeFrame;
        cout << "\nFrame for Circle"
                "\nWidth: "<<  side <<
                "\nHeight: " << side * sqrt(3) / 2 <<
                "\nColor: "<< getOutColor() <<endl;
    }
};

class rectangle : public HierarchyOfGeometricShapes {
protected:
    double widthRc = 0.0,
           heightRc = 0.0;
public:
    rectangle(double inX, double inY, colors inColor, double inWidthRc, double inHeightRc):
    HierarchyOfGeometricShapes(inX, inY, inColor), widthRc(inWidthRc), heightRc(inHeightRc) {}

    double getAreaTr() {
        return widthRc * heightRc;
    }

    void outFrame () {
        double width =  widthRc * sizeFrame,
               hight = heightRc * sizeFrame;
        cout << "\nFrame for Circle"
                "\nWidth: "<<  width <<
                "\nHeight: " << hight <<
                "\nColor: "<< getOutColor() <<endl;
    }
};

int main () {
    string command = " ";

  do {
      cout << "\nEnter shape:"
              "\n~circle"
              "\n~square"
              "\n~triangle"
              "\n~rectangle"
              "\n~exit - for exit"
              "\nEnter:"; cin >> command;

      if (command == "circle") {
          double radiusInit;
          int colorInit;

          cout << "\nEnter radius: "; cin >> radiusInit;
          cout << "\nEnter color"
                  "\n(0-none, 1-red, 2-blue, 3-green): "; cin >> colorInit;

          Circle circle(0, 0, (colors)colorInit, radiusInit);
          cout << "\nArea of Circle: " << circle.getAreaCircl();
          circle.outFrame();
      } else if (command == "square") {
          double width;
          int colorInit;

          cout << "\nEnter width square: "; cin >> width;
          cout << "\nEnter color"
                  "\n(0-none, 1-red, 2-blue, 3-green): "; cin >> colorInit;

          Square square(0, 0, (colors)colorInit, width);
          cout << "\nArea of Square: " << square.getAreaSq();
          square.outFrame();
      } else if (command == "triangle") {
          double lenght;
          int colorInit;

          cout << "\nEnter lenght side triangle: "; cin >> lenght;
          cout << "\nEnter color"
                  "\n(0-none, 1-red, 2-blue, 3-green): "; cin >> colorInit;

          triangle Triangle (0, 0, (colors)colorInit, lenght);
          cout << "\nArea of Triangle: " << Triangle.getAreaTr();
          Triangle.outFrame();
      } else if (command == "rectangle") {
          double width,
                 hight;
          int colorInit;

          cout << "\nEnter width : "; cin >> width;
          cout << "\nEnter hight : "; cin >> hight;
          cout << "\nEnter color"
                  "\n(0-none, 1-red, 2-blue, 3-green): "; cin >> colorInit;

          rectangle Rectangle (0, 0, (colors)colorInit, width, hight);
          cout << "\nArea of Rectangle: " << Rectangle.getAreaTr();
          Rectangle.outFrame();
      }
  } while (command != "exit");

    return 0;
}