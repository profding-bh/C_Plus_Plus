// Text_lib:--defined in a header  Text_lib.h
namespace Text_lib {
class Glyph { /* ...*/ };
class Word { /* ...*/ }; // sequence of Glyphs
class Line { /* ...*/ }; 	// sequence of Words
class Text { /* ...*/ }; // sequence of Lines


File* open(const char* ); // open text file

Word operator+(const Line&, const Line&);// concatenate

}
