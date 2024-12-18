#include <iostream>

// Abstrakcyjna implementacja rysowania
class Drawing {
public:
    virtual void drawLine() = 0;
    virtual void drawCircle() = 0;
    virtual ~Drawing() {}
};

// Implementacje DP1
class DP1 : public Drawing {
public:
    void drawLine() override {
        std::cout << "DP1 - Drawing a line" << std::endl;
    }

    void drawCircle() override {
        std::cout << "DP1 - Drawing a circle" << std::endl;
    }
};

// Implementacje DP2
class DP2 : public Drawing {
public:
    void drawLine() override {
        std::cout << "DP2 - Drawing a line" << std::endl;
    }

    void drawCircle() override {
        std::cout << "DP2 - Drawing a circle" << std::endl;
    }
};

// Implementacja V1Drawing
class V1Drawing : public Drawing {
private:
    DP1& dp1;

public:
    V1Drawing(DP1& dp1) : dp1(dp1) {}

    void drawLine() override {
        dp1.drawLine();
    }

    void drawCircle() override {
        dp1.drawCircle();
    }
};

// Implementacja V2Drawing
class V2Drawing : public Drawing {
private:
    DP2& dp2;

public:
    V2Drawing(DP2& dp2) : dp2(dp2) {}

    void drawLine() override {
        dp2.drawLine();
    }

    void drawCircle() override {
        dp2.drawCircle();
    }
};

// Klasa bazowa dla kształtów
class Shape {
protected:
    Drawing* drawing;

public:
    Shape(Drawing* drawing) : drawing(drawing) {}

    virtual void draw() = 0;
    virtual void setLib(Drawing* drawing) {
        this->drawing = drawing;
    }

    virtual ~Shape() {}
};

// Konkretne implementacje kształtu - Rectangle
class Rectangle : public Shape {
public:
    Rectangle(Drawing* drawing) : Shape(drawing) {}

    void draw() override {
        drawing->drawLine();
    }
};

// Konkretne implementacje kształtu - Circle
class Circle : public Shape {
public:
    Circle(Drawing* drawing) : Shape(drawing) {}

    void draw() override {
        drawing->drawCircle();
    }
};

int main() {
    DP1 library1; // pierwsza biblioteka
    DP2 library2; // druga biblioteka
  
    Drawing* d1 = new V1Drawing(library1);
    Drawing* d2 = new V2Drawing(library2);

    Shape* p1 = new Rectangle(d1);
    Shape* p2 = new Circle(d2);

    p1->draw(); // rectangle linia V1
    p2->draw(); // circle okrag V2
    p1->setLib(d2);
    p2->setLib(d1);
    p1->draw(); // rectangle linia V2
    p2->draw(); // circle okrag V1

    delete p1;
    delete p2;
    delete d1;
    delete d2;
}
