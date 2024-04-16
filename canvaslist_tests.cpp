#include <gtest/gtest.h>

#include "canvaslist.h"
#include "shape.h"

// Tests for the Shape class
TEST(Shape, Constructors) {
  Shape expected = Shape(0, 0);
  Shape test = Shape();

  string testFeedbackX = "Shape's default and parameterized constructors are incorrect, did not intialize x to 0";
  string testFeedbackY = "Shape's default and parameterized constructors are incorrect, did not intialize y to 0";

  // testing default and parameterized constructors
  EXPECT_EQ(expected.getX(), test.getX()) << testFeedbackX;
  EXPECT_EQ(expected.getY(), test.getY()) << testFeedbackY;
}

TEST(Shape, Copy) {
  Shape expected = Shape(2, 3);
  Shape* test = expected.copy();

  string testFeedbackX = "Shape's copy function is incorrect, did not intialize x to 2";
  string testFeedbackY = "Shape's copy function is incorrect, did not intialize y to 3";

  // testing the copy() function
  EXPECT_EQ(expected.getX(), test->getX()) << testFeedbackX;
  EXPECT_EQ(expected.getY(), test->getY()) << testFeedbackY;

  delete test;
}

TEST(Shape, SettersGetters) {
  Shape expected = Shape(2, 3);
  Shape test = Shape(1, 1);

  test.setX(2);
  test.setY(3);

  string testFeedbackX = "Shape's set function is incorrect, did not intialize x to 2";
  string testFeedbackY = "Shape's set function is incorrect, did not intialize y to 3";

  // testing setters and getters
  EXPECT_EQ(expected.getX(), test.getX()) << testFeedbackX;
  EXPECT_EQ(expected.getY(), test.getY()) << testFeedbackY;
}

TEST(Shape, String) {
  Shape test = Shape(4, 6);
  string expected = "It's a Shape at x: 4, y: 6";

  string result = test.as_string();

  string testFeedback = "Shape's as_string function is incorrect, printed out: " + result;

  // testing that as_string returns corrent format
  EXPECT_EQ(expected, result) << testFeedback;
}

// tests for Circle class
TEST(Circle, Constructors) {
  Circle expected = Circle(0, 0, 0);
  Circle expected2 = Circle(0);
  Circle test = Circle();

  string testFeedbackX = "Circle's default and parameterized constructors are incorrect, did not intialize x to 0";
  string testFeedbackY = "Circle's default and parameterized constructors are incorrect, did not intialize y to 0";
  string testFeedbackR = "Circle's default and parameterized constructors are incorrect, did not intialize radius to 0";

  // testing default and parameterized constructors
  EXPECT_EQ(expected.getX(), test.getX()) << testFeedbackX;
  EXPECT_EQ(expected.getY(), test.getY()) << testFeedbackY;
  EXPECT_EQ(expected.getRadius(), test.getRadius()) << testFeedbackR;

  // testing default and parameterized constructors with only one parameter
  EXPECT_EQ(expected2.getX(), test.getX()) << testFeedbackX;
  EXPECT_EQ(expected2.getY(), test.getY()) << testFeedbackY;
  EXPECT_EQ(expected2.getRadius(), test.getRadius()) << testFeedbackR;
}

TEST(Circle, Copy) {
  Circle expected = Circle(2, 3, 1);
  Circle* test = expected.copy();

  string testFeedbackX = "Circle's copy function is incorrect, did not intialize x to 2";
  string testFeedbackY = "Circle's copy function is incorrect, did not intialize y to 3";
  string testFeedbackR = "Circle's default and parameterized constructors are incorrect, did not intialize radius to 1";

  // testing copy function
  EXPECT_EQ(expected.getX(), test->getX()) << testFeedbackX;
  EXPECT_EQ(expected.getY(), test->getY()) << testFeedbackY;
  EXPECT_EQ(expected.getRadius(), test->getRadius()) << testFeedbackR;

  delete test;
}

TEST(Circle, SettersGetters) {
  Circle expected = Circle(2, 3, 1);
  Circle test = Circle(1, 1, 3);

  test.setX(2);
  test.setY(3);
  test.setRadius(1);

  string testFeedbackX = "Circle's set function is incorrect, did not intialize x to 2";
  string testFeedbackY = "Circle's set function is incorrect, did not intialize y to 3";
  string testFeedbackR = "Circle's default and parameterized constructors are incorrect, did not intialize radius to 1";

  // testing setters and getters for x, y, and radius
  EXPECT_EQ(expected.getX(), test.getX()) << testFeedbackX;
  EXPECT_EQ(expected.getY(), test.getY()) << testFeedbackY;
  EXPECT_EQ(expected.getRadius(), test.getRadius()) << testFeedbackR;
}

TEST(Circle, String) {
  Circle test = Circle(2, 4, 3);
  string expected = "It's a Circle at x: 2, y: 4, radius: 3";

  string result = test.as_string();

  string testFeedback = "Circle's as_string function is incorrect, printed out: " + result;
  
  // testing that as_string returns corrent format
  EXPECT_EQ(expected, result) << testFeedback;
}

// tests for Rect class
TEST(Rect, Constructors) {
  Rect expected = Rect(0, 0, 0, 0);
  Rect test = Rect();

  string testFeedbackX = "Rect's default and parameterized constructors are incorrect, did not intialize x to 0";
  string testFeedbackY = "Rect's default and parameterized constructors are incorrect, did not intialize y to 0";
  string testFeedbackW = "Rect's default and parameterized constructors are incorrect, did not intialize width to 0";
  string testFeedbackH = "Rect's default and parameterized constructors are incorrect, did not intialize height to 0";

  // testing default and parameterized constructors
  EXPECT_EQ(expected.getX(), test.getX()) << testFeedbackX;
  EXPECT_EQ(expected.getY(), test.getY()) << testFeedbackY;
  EXPECT_EQ(expected.getWidth(), test.getWidth()) << testFeedbackW;
  EXPECT_EQ(expected.getHeight(), test.getHeight()) << testFeedbackH;
}

TEST(Rect, Copy) {
  Rect expected = Rect(2, 3, 1, 2);
  Rect* test = expected.copy();

  string testFeedbackX = "Rect's default and parameterized constructors are incorrect, did not intialize x to 2";
  string testFeedbackY = "Rect's default and parameterized constructors are incorrect, did not intialize y to 3";
  string testFeedbackW = "Rect's default and parameterized constructors are incorrect, did not intialize width to 1";
  string testFeedbackH = "Rect's default and parameterized constructors are incorrect, did not intialize height to 2";

  // testing copy() function 
  EXPECT_EQ(expected.getX(), test->getX()) << testFeedbackX;
  EXPECT_EQ(expected.getY(), test->getY()) << testFeedbackY;
  EXPECT_EQ(expected.getWidth(), test->getWidth()) << testFeedbackW;
  EXPECT_EQ(expected.getHeight(), test->getHeight()) << testFeedbackH;

  delete test;
}

TEST(Rect, SettersGetters) {
  Rect expected = Rect(2, 3, 1, 2);
  Rect test = Rect(1, 1, 3, 1);

  test.setX(2);
  test.setY(3);
  test.setWidth(1);
  test.setHeight(2);

  string testFeedbackX = "Rect's default and parameterized constructors are incorrect, did not intialize x to 2";
  string testFeedbackY = "Rect's default and parameterized constructors are incorrect, did not intialize y to 3";
  string testFeedbackW = "Rect's default and parameterized constructors are incorrect, did not intialize width to 1";
  string testFeedbackH = "Rect's default and parameterized constructors are incorrect, did not intialize height to 2";

  // testing setters and getters for x, y, width, and height
  EXPECT_EQ(expected.getX(), test.getX()) << testFeedbackX;
  EXPECT_EQ(expected.getY(), test.getY()) << testFeedbackY;
  EXPECT_EQ(expected.getWidth(), test.getWidth()) << testFeedbackW;
  EXPECT_EQ(expected.getHeight(), test.getHeight()) << testFeedbackH;
}

TEST(Rect, String) {
  Rect test = Rect(0, 0, 0, 10);
  string expected = "It's a Rectangle at x: 0, y: 0 with width: 0 and height: 10";

  string result = test.as_string();

  string testFeedback = "Rect's as_string function is incorrect, printed out: " + result;

  // testing that as_string returns corrent format
  EXPECT_EQ(expected, result) << testFeedback;
}

// tests for RightTriangle class
TEST(RightTriangle, Constructors) {
  RightTriangle expected = RightTriangle(0, 0, 0, 0);
  RightTriangle test = RightTriangle();

  string testFeedbackX = "RightTriangle's default and parameterized constructors are incorrect, did not intialize x to 0";
  string testFeedbackY = "RightTriangle's default and parameterized constructors are incorrect, did not intialize y to 0";
  string testFeedbackB = "RightTriangle's default and parameterized constructors are incorrect, did not intialize base to 0";
  string testFeedbackH = "RightTriangle's default and parameterized constructors are incorrect, did not intialize height to 0";
  
  // testing that contructors assign values correctly to the classes variables
  EXPECT_EQ(expected.getX(), test.getX()) << testFeedbackX;
  EXPECT_EQ(expected.getY(), test.getY()) << testFeedbackY;
  EXPECT_EQ(expected.getBase(), test.getBase()) << testFeedbackB;
  EXPECT_EQ(expected.getHeight(), test.getHeight()) << testFeedbackH;
}

TEST(RightTriangle, Copy) {
  RightTriangle expected = RightTriangle(2, 3, 1, 2);
  RightTriangle* test = expected.copy();

  string testFeedbackX = "RightTriangle's default and parameterized constructors are incorrect, did not intialize x to 2";
  string testFeedbackY = "RightTriangle's default and parameterized constructors are incorrect, did not intialize y to 3";
  string testFeedbackB = "RightTriangle's default and parameterized constructors are incorrect, did not intialize base to 1";
  string testFeedbackH = "RightTriangle's default and parameterized constructors are incorrect, did not intialize height to 2";

  // testing that copy() function correctly coppies x, y, base, and height
  EXPECT_EQ(expected.getX(), test->getX()) << testFeedbackX;
  EXPECT_EQ(expected.getY(), test->getY()) << testFeedbackY;
  EXPECT_EQ(expected.getBase(), test->getBase()) << testFeedbackB;
  EXPECT_EQ(expected.getHeight(), test->getHeight()) << testFeedbackH;

  delete test;
}

TEST(RightTriangle, SettersGetters) {
  RightTriangle expected = RightTriangle(2, 3, 1, 2);
  RightTriangle test = RightTriangle(1, 1, 3, 1);

  test.setX(2);
  test.setY(3);
  test.setBase(1);
  test.setHeight(2);

  string testFeedbackX = "RightTriangle's default and parameterized constructors are incorrect, did not intialize x to 2";
  string testFeedbackY = "RightTriangle's default and parameterized constructors are incorrect, did not intialize y to 3";
  string testFeedbackB = "RightTriangle's default and parameterized constructors are incorrect, did not intialize base to 1";
  string testFeedbackH = "RightTriangle's default and parameterized constructors are incorrect, did not intialize height to 2";

  // testing setters and getters for x, y, base, and height
  EXPECT_EQ(expected.getX(), test.getX()) << testFeedbackX;
  EXPECT_EQ(expected.getY(), test.getY()) << testFeedbackY;
  EXPECT_EQ(expected.getBase(), test.getBase()) << testFeedbackB;
  EXPECT_EQ(expected.getHeight(), test.getHeight()) << testFeedbackH;
}

TEST(RightTriangle, String) {
  RightTriangle test = RightTriangle(1, 2, 3, 4);
  string expected = "It's a Right Triangle at x: 1, y: 2 with base: 3 and height: 4";

  string result = test.as_string();

  string testFeedback = "RightTriangle's as_string function is incorrect, printed out: " + result;

  // testing that as_string returns corrent format
  EXPECT_EQ(expected, result) << testFeedback;
}

// tests for CanvasList
TEST(CanvasList, Constructor) {
  CanvasList test = CanvasList();

  int expectedSize = 0;
  ShapeNode* expectedShapeNode = nullptr;

  string testFeedbackSize = "CanvasList's default constructor is incorrect, did not intialize list_size to 0";
  string testFeedbackShape = "CanvasList's default constructors is incorrect, did not intialize list_front to nullptr";

  // testing that default constructor creates an empty canvas list
  EXPECT_EQ(expectedSize, test.size()) << testFeedbackSize;
  EXPECT_EQ(expectedShapeNode, test.front()) << testFeedbackShape;
}

TEST(CanvasList, Push_Back_Empty) {
  CanvasList test = CanvasList();

  int expectedSize = 1;
  Shape* expectedShape = new Shape(0, 1);
  ShapeNode* expectedShapeNode = new ShapeNode();
  expectedShapeNode->value = expectedShape;
  expectedShapeNode->next = nullptr;

  string testFeedbackSize = "CanvasList's push_back on an empty list is incorrect, list_size is not 1";
  string testFeedbackShapeValue = "CanvasList's push_back on an empty list is incorrect, list_front is not the ShapeNode with a Shape at (0,1)";
  string testFeedbackShapeNext = "CanvasList's push_back on an empty list is incorrect, list_front's next does not point to nullptr";

  test.push_back(expectedShape);

  // tests the push_back function for an empty list
  EXPECT_EQ(expectedSize, test.size()) << testFeedbackSize;
  EXPECT_EQ(expectedShapeNode->value, test.front()->value) << testFeedbackShapeValue;
  EXPECT_EQ(expectedShapeNode->next, test.front()->next) << testFeedbackShapeNext;

  delete expectedShapeNode;
}

TEST(CanvasList, Push_Front_Empty) {
  CanvasList test = CanvasList();

  int expectedSize = 1;
  Shape* expectedShape = new Shape(0, 1);
  ShapeNode* expectedShapeNode = new ShapeNode();
  expectedShapeNode->value = expectedShape;
  expectedShapeNode->next = nullptr;

  string testFeedbackSize = "CanvasList's push_front on an empty list is incorrect, list_size is not 1";
  string testFeedbackShapeValue = "CanvasList's push_front on an empty list is incorrect, list_front is not the ShapeNode with a Shape at (0,1)";
  string testFeedbackShapeNext = "CanvasList's push_front on an empty list is incorrect, list_front's next does not point to nullptr";

  test.push_front(expectedShape);

  // tests the push_front function for an empty list
  EXPECT_EQ(expectedSize, test.size()) << testFeedbackSize;
  EXPECT_EQ(expectedShapeNode->value, test.front()->value) << testFeedbackShapeValue;
  EXPECT_EQ(expectedShapeNode->next, test.front()->next) << testFeedbackShapeNext;

  delete expectedShapeNode;
}

TEST(CanvasList, Push_Back) {
  CanvasList test = CanvasList();

  int expectedSize = 2;
  Shape* firstShape = new Shape(0, 0);
  Shape* secondShape = new Shape(1, 1);

  ShapeNode* secondShapeNode = new ShapeNode();
  secondShapeNode->value = secondShape;
  secondShapeNode->next = nullptr;

  ShapeNode* firstShapeNode = new ShapeNode();
  firstShapeNode->value = firstShape;
  firstShapeNode->next = secondShapeNode;

  string testFeedbackSize = "CanvasList's push_back on a list is incorrect, list_size is not 2";
  string testFeedbackFirstShape = "CanvasList's push_back on a list is incorrect, front node is not the ShapeNode with a Shape at (0,0) pointing to a second node";
  string testFeedbackSecondShape = "CanvasList's push_back on a list is incorrect, second node is not the ShapeNode with a Shape at (1,1) pointing to nullptr";

  test.push_back(firstShape);
  test.push_back(secondShape);

  // tests the push_back function for a non-empty list
  EXPECT_EQ(expectedSize, test.size()) << testFeedbackSize;
  EXPECT_EQ(firstShapeNode->value, test.front()->value) << testFeedbackFirstShape;
  EXPECT_EQ(firstShapeNode->next->value, test.front()->next->value);
  EXPECT_EQ(secondShapeNode->value, test.front()->next->value) << testFeedbackSecondShape;
  EXPECT_EQ(secondShapeNode->next, test.front()->next->next);


  delete firstShapeNode;
  delete secondShapeNode;
}

TEST(CanvasList, Push_Front) {
   CanvasList test = CanvasList();

  int expectedSize = 2;
  Shape* firstShape = new Shape(0, 0);
  Shape* secondShape = new Shape(1, 1);

  ShapeNode* firstShapeNode = new ShapeNode();
  firstShapeNode->value = firstShape;
  firstShapeNode->next = nullptr;

  ShapeNode* secondShapeNode = new ShapeNode();
  secondShapeNode->value = secondShape;
  secondShapeNode->next = firstShapeNode;

  string testFeedbackSize = "CanvasList's push_front on a list is incorrect, list_size is not 2";
  string testFeedbackFirstShape = "CanvasList's push_front on a list is incorrect, front node is not the ShapeNode with a Shape at (1,1) pointing to a second node";
  string testFeedbackSecondShape = "CanvasList's push_front on a list is incorrect, second node is not the ShapeNode with a Shape at (0,0) pointing to nullptr";

  test.push_back(firstShape);
  test.push_front(secondShape);

  // tests the push_front function for a non-empty list
  EXPECT_EQ(expectedSize, test.size()) << testFeedbackSize;
  EXPECT_EQ(secondShapeNode->value, test.front()->value) << testFeedbackFirstShape;
  EXPECT_EQ(secondShapeNode->next->value, test.front()->next->value);
  EXPECT_EQ(firstShapeNode->value, test.front()->next->value) << testFeedbackSecondShape;
  EXPECT_EQ(firstShapeNode->next, test.front()->next->next);

  delete firstShapeNode;
  delete secondShapeNode;
}

TEST(CanvasList, CopyConstructor) {
  CanvasList test = CanvasList();

  test.push_back(new Shape(0, 0));
  test.push_back(new Shape(1, 1));
  test.push_back(new Shape(2, 2));

  CanvasList result = test;

  string testFeedbackSize = "CanvasList's copy constructor is incorrect, did not intialize list_size to 3";
  string testFeedbackShape = "CanvasList's copy constructors is incorrect, did not intialize list_front to firstShape's value";

  // tests that the copy constructor creates a copy of list
  EXPECT_EQ(test.size(), result.size()) << testFeedbackSize;
  EXPECT_EQ(test.front()->value->getX(), result.front()->value->getX()) << testFeedbackShape;
  EXPECT_EQ(test.front()->value->getY(), result.front()->value->getY()) << testFeedbackShape;
}

TEST(CanvasList, AssignmentOperator) {
  CanvasList test = CanvasList();
  CanvasList result = CanvasList();

  result.push_back(new Shape(1, 3));
  result.push_back(new Shape(2, 3));
  result.push_back(new Shape(3, 3));

  test.push_back(new Circle(4, 4, 4));
  test.push_back(new Rect(1, 1, 1, 1));
  test.push_back(new RightTriangle(2, 2, 2, 2));

  result = test;

  string testFeedbackSize = "CanvasList's assignment operator is incorrect, did not have a list_size to 3";
  string testFeedbackShape = "CanvasList's assignment operator is incorrect, did not have list_front's value equal to firstShape's value";

  // tests that the assignment operator overload function creates a deep copy of a list
  for (int i = 0; i < 3; i++) {
    EXPECT_EQ(test.shape_at(i)->as_string(), result.shape_at(i)->as_string()) << i + " was not the same shape";
  }

  EXPECT_EQ(test.size(), result.size()) << testFeedbackSize;
  EXPECT_EQ(test.front()->value->getX(), result.front()->value->getX()) << testFeedbackShape;
}

TEST(CanvasList, CopyOperatorSame) {
  CanvasList test = CanvasList();
  CanvasList result = CanvasList();

  result.push_back(new Shape(0, 0));
  result.push_back(new Shape(1, 1));
  result.push_back(new Shape(2, 2));

  test.push_back(new Shape(0, 0));
  test.push_back(new Shape(1, 1));
  test.push_back(new Shape(2, 2));

  result = test;

  string testFeedbackSize = "CanvasList's copy operator is incorrect, did not have a list_size to 3";
  string testFeedbackShape = "CanvasList's copy operator is incorrect, did not have list_front's value equal to firstShape's value";

  // tests that two list that are the same are not coppied 
  EXPECT_EQ(test.size(), result.size()) << testFeedbackSize;
  EXPECT_EQ(test.front()->value->getX(), result.front()->value->getX()) << testFeedbackShape;
  EXPECT_EQ(test.front()->value->getY(), result.front()->value->getY()) << testFeedbackShape;
}

TEST(CanvasList, Find) {
  CanvasList test = CanvasList();

  test.push_back(new Shape(0, 0));
  test.push_back(new Shape(1, 1));
  test.push_back(new Shape(2, 2));

  int expected1 = 0;
  int expected2 = 2;

  string testFeedback1 = "CanvasList's find function is incorrect, did not find shape at (0,0) at index 0";
  string testFeedback2 = "CanvasList's find function is incorrect, did not find shape at (2,2) at index 2";

  // tests that the find function finds a shape at a certain x and y value
  EXPECT_EQ(test.find(0, 0), expected1) << testFeedback1;
  EXPECT_EQ(test.find(2, 2), expected2) << testFeedback2;
}

TEST(CanvasList, ShapeAt) {
  CanvasList test = CanvasList();

  Shape* expected = new Shape(1, 1);

  test.push_back(new Shape(0, 0));
  test.push_back(expected);
  test.push_back(new Shape(2, 2));

  string testFeedback = "CanvasList's shape_at function is incorrect, did not find the shape at index 1 as being at (1,1)";

  // tests that the shape_at returns the shape at a given index
  EXPECT_EQ(test.shape_at(1), expected) << testFeedback;
}

TEST(CanvasList, InsertAfter) {
  CanvasList test = CanvasList();

  int expectedSize = 3;

  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);

  test.insert_after(0, shape2);

  test.push_back(shape1);
  test.push_back(shape3);

  test.insert_after(0, shape2);
  test.insert_after(3, shape2);
  test.insert_after(6, shape2);

  string testFeedbackSize = "CanvasList's copy operator is incorrect, did not have a list_size to 3";

  // tests that an element is correctly inserted into the list after the given index
  EXPECT_EQ(test.size(), expectedSize) << testFeedbackSize;
  EXPECT_EQ(test.shape_at(0), shape1) << "CanvasList's insert_after function is incorrect, did add shape at (0,0) at index 0";
  EXPECT_EQ(test.shape_at(1), shape2) << "CanvasList's insert_after function is incorrect, did add shape at (1,1) at index 1";
  EXPECT_EQ(test.shape_at(2), shape3) << "CanvasList's insert_after function is incorrect, did add shape at (2,2) at index 2";
}

TEST(CanvasList, PopFront) {
  CanvasList test = CanvasList();

  int expectedSize = 2;

  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);

  test.push_back(shape1);
  test.push_back(shape2);
  test.push_back(shape3);

  string testFeedbackSize = "CanvasList's pop_front is incorrect, did not have a list_size to 2";
  string testFeedbackPop = "CanvasList's pop_front is incorrect, did not return list_front";
  string testFeedbackFront = "CanvasList's pop_front is incorrect, list_front is not shape2";

  // tests that a shape at the front is removed from the list, returned, and list is adjusted
  EXPECT_EQ(test.pop_front(), shape1) << testFeedbackPop;
  EXPECT_EQ(test.front()->value, shape2) << testFeedbackFront;
  EXPECT_EQ(test.size(), expectedSize) << testFeedbackSize;

  test.pop_front();

  // tests that the last remaining shape is removed from the list, returned, and the list is now empty
  EXPECT_EQ(test.pop_front(), shape3) << "CanvasList's pop_front is incorrect, list_front was not shape3";
  EXPECT_EQ(test.size(), 0) << "CanvasList's pop_front is incorrect, did not have a list_size to 0";
  EXPECT_EQ(test.front(), nullptr) << "list is not empty after popping all shapes";

  // tests that nothing happens when the list is empty and pop_front is called
  test.pop_front();

  delete shape3;
  delete shape2;
  delete shape1;
}

TEST(CanvasList, PopBack) {
  CanvasList test = CanvasList();

  int expectedSize = 2;

  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);

  test.push_back(shape1);
  test.push_back(shape2);
  test.push_back(shape3);

  string testFeedbackSize = "CanvasList's pop_back is incorrect, did not have a list_size to 2";
  string testFeedbackPop = "CanvasList's pop_back is incorrect, did not return the list's back";

  // tests that a shape at the back is removed from the list, returned, and list is adjusted
  EXPECT_EQ(test.pop_back(), shape3) << testFeedbackPop;
  EXPECT_EQ(test.size(), expectedSize) << testFeedbackSize;

  test.pop_back();

  // tests that the last remaining shape is removed from the list, returned, and the list is now empty
  EXPECT_EQ(test.pop_back(), shape1) << "CanvasList's pop_back is incorrect, did not return the list's back";
  EXPECT_EQ(test.size(), 0) << "CanvasList's pop_back is incorrect, did not have a list_size to 0";
  EXPECT_EQ(test.front(), nullptr) << "list is not empty after popping all shapes";

  // tests that nothing happens when the list is empty and pop_front is called
  test.pop_back();

  delete shape3;
  delete shape2;
  delete shape1;
}

TEST(CanvasList, Clear) {
  CanvasList test = CanvasList();

  int expectedSize = 0;

  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);

  test.push_back(shape1);
  test.push_back(shape2);
  test.push_back(shape3);

  test.clear();

  string testFeedbackSize = "CanvasList's clear is incorrect, did not have a list_size to 0";
  string testFeedbackFront = "CanvasList's clear is incorrect, list_front is not nullptr";

  // tests that a list is now empty when the clear() function is called
  EXPECT_EQ(test.front(), nullptr) << testFeedbackFront;
  EXPECT_EQ(test.size(), expectedSize) << testFeedbackSize;
}

TEST(CanvasList, RemoveAt) {
  CanvasList test = CanvasList();

  int expectedSize = 2;

  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);

  test.push_back(shape1);
  test.push_back(shape2);
  test.push_back(shape3);

  test.remove_at(1);
  test.remove_at(2);

  string testFeedbackSize = "CanvasList's remove_at is incorrect, did not have a list_size of 2 after removal";
  string testFeedbackShape = "CanvasList's remove_at is incorrect, third shape is not at the end";

  // tests the remove_at() function so that an element is removed at a given index and the list is adjusted
  EXPECT_EQ(test.shape_at(1), shape3) << testFeedbackShape;
  EXPECT_EQ(test.size(), expectedSize) << testFeedbackSize;


  expectedSize = 1;

  test.remove_at(1);

  testFeedbackSize = "CanvasList's remove_at is incorrect, did not have a list_size of 1 after removal";
  testFeedbackShape = "CanvasList's remove_at is incorrect, first shape is not at the front";

  // tests that an element is removed at a given index and the list is adjusted
  EXPECT_EQ(test.shape_at(1), nullptr) << testFeedbackShape;
  EXPECT_EQ(test.front()->next, nullptr) << "list_front does not point to nullptr";
  EXPECT_EQ(test.size(), expectedSize) << testFeedbackSize;


  expectedSize = 0;

  test.remove_at(0);

  // tests that the last remaining element is removed at a given index and the list is adjusted
  testFeedbackSize = "CanvasList's remove_at is incorrect, did not have a list_size of 0 after removal";
  testFeedbackShape = "CanvasList's remove_at is incorrect, first shape is not at the front";

  EXPECT_EQ(test.shape_at(0), nullptr) << testFeedbackShape;
  EXPECT_EQ(test.size(), expectedSize) << testFeedbackSize;

  // tests that nothing happens if the list is empty
  test.remove_at(0);
  EXPECT_EQ(test.size(), expectedSize) << testFeedbackSize + " x 2";
}

TEST(CanvasList, RemoveEveryOther) {
  CanvasList test = CanvasList();

  int expectedSize = 2;

  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);
  Shape* shape4 = new Shape(3, 3);

  test.push_back(shape1);
  test.push_back(shape2);
  test.push_back(shape3);
  test.push_back(shape4);

  test.remove_every_other();

  string testFeedbackSize = "CanvasList's remove_every_other is incorrect, did not have a list_size of 2 after removal";
  string testFeedbackShape = "CanvasList's remove_every_other is incorrect, shape1 and shape3 are not the only remaining nodes";

  // tests that the remove_every_other() function is removing every other element, starting with index 1, and the list is adjusted
  EXPECT_EQ(test.shape_at(0), shape1) << testFeedbackShape;
  EXPECT_EQ(test.shape_at(1), shape3) << testFeedbackShape;
  EXPECT_EQ(test.size(), expectedSize) << testFeedbackSize;

  expectedSize = 1;
  test.remove_every_other();
  
  testFeedbackSize = "CanvasList's remove_every_other is incorrect, did not have a list_size of 1 after removal";
  testFeedbackShape = "CanvasList's remove_every_other is incorrect, shape1 is not the only remaining node";
  
  // tests that every other element is removed and the list is adjusted to have only one remaining element
  EXPECT_EQ(test.shape_at(0), shape1) << testFeedbackShape;
  EXPECT_EQ(test.size(), expectedSize) << testFeedbackSize;

  // tests that nothing happens if the list is of size 1
  test.remove_every_other();
  EXPECT_EQ(test.size(), expectedSize) << testFeedbackSize + " x 2";
}