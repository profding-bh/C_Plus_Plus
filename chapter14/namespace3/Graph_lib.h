
namespace Graph_lib {
class Shape {/* ... */ };

class Line:public Shape {/* ... */ };
class Poly_Line:public Shape {/* ... */ };// connected sequence of lines
class Text:public Shape {/* ... */ };// text label

Shape operator+(const Shape&, const Shape&);// compose


Graph_reader open(const char*);// open files of Shapes

}
