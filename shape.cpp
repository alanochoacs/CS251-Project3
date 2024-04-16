#include "shape.h"

#include <string>

using namespace std;


// Shape class
Shape::Shape() {
    this->x = 0;
    this->y = 0;
}

Shape::Shape(int x, int y) {
    this->x = x;
    this->y = y;
}

Shape::~Shape() {}

Shape* Shape::copy() {
    Shape* newShape = new Shape(this->x, this->y);
    return newShape;
}

int Shape::getX() const {
    return this->x;
}

int Shape::getY() const {
    return this->y;
}

void Shape::setX(int x) {
    this->x = x;
}

void Shape::setY(int y) {
    this->y = y;
}

string Shape::as_string() const {
    return "It's a Shape at x: " + to_string(this->x) + ", y: " + to_string(this->y);
}


// Circle class
Circle::Circle() {
    this->radius = 0;
}

Circle::Circle(int r) {
    this->radius = r;
}

Circle::Circle(int x, int y, int r) {
    this->x = x;
    this->y = y;
    this->radius = r;
}

Circle::~Circle() {}

Circle* Circle::copy() {
    Circle* newCricle = new Circle(this->x, this->y, this->radius);
    return newCricle;
}

int Circle::getRadius() const {
    return this->radius;
}

void Circle::setRadius(int r) {
    this->radius = r;
}

string Circle::as_string() const {
    return "It's a Circle at x: " + to_string(this->x) + ", y: " + to_string(this->y) + ", radius: " + to_string(this->radius);
}


// Rect class
Rect::Rect() {
    this->width = 0;
    this->height = 0;
}

Rect::Rect(int w, int h) {
    this->width = w;
    this->height = h;
}

Rect::Rect(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    this->width = w;
    this->height = h;
}

Rect::~Rect() {}

Rect* Rect::copy() {
    Rect* newRect = new Rect(this->x, this->y, this->width, this->height);
    return newRect;
}

int Rect::getWidth() const {
    return width;
}

int Rect::getHeight() const {
    return height;
}

void Rect::setWidth(int w) {
    this->width = w;
}

void Rect::setHeight(int h) {
    this->height = h;
}

string Rect::as_string() const {
    return "It's a Rectangle at x: " + to_string(this->x) + ", y: " + to_string(this->y) + " with width: " + to_string(this->width) + " and height: " + to_string(this->height);
}


// RightTriangle class
RightTriangle::RightTriangle() {
    this->base = 0;
    this->height = 0;
}

RightTriangle::RightTriangle(int b, int h) {
    this->base = b;
    this->height = h;
}

RightTriangle::RightTriangle(int x, int y, int b, int h) {
    this->x = x;
    this->y = y;
    this->base = b;
    this->height = h;
}

RightTriangle::~RightTriangle() {}

RightTriangle* RightTriangle::copy() {
    RightTriangle* newRightTriangle = new RightTriangle(this->x, this->y, this->base, this->height);
    return newRightTriangle;
}

int RightTriangle::getBase() const {
    return base;
}

int RightTriangle::getHeight() const {
    return height;
}

void RightTriangle::setBase(int b) {
    this->base = b;
}

void RightTriangle::setHeight(int h) {
    this->height = h;
}

string RightTriangle::as_string() const {
    return "It's a Right Triangle at x: " + to_string(this->x) + ", y: " + to_string(this->y) + " with base: " + to_string(this->base) + " and height: " + to_string(this->height);
}
