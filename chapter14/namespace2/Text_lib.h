// Text_lib:--defined in a header  Text_lib.h

class Glyph { /* ...*/ };
class Line { /* ...*/ }; 

namespace Text_lib {
class Glyph { /* ...*/ };
class Word { /* ...*/ }; // sequence of Glyphs
class Line { /* ...*/ }; 	// sequence of Words
class Text { /* ...*/ }; // sequence of Lines


File* open(const char* ); // open text file

Word operator+(const Line&, const Line&);// concatenate
//Here: Word, Line  refer to  Text_lib::Word & Text_lib::Line
// That local name lookup is not affected by the global Line.

}

Glyph glyph(Line& In,int i);//In[i]
// here: Glyph,Line refer to the global ::Glyph &  ::Line
// That(nonlocal) lookup isnot affected by Text_lib's Glyph & Line


// To refer to members of a namespace,we can use its fully qualified name.

Text_lib::Glyph glyph(Text_lib::Line& In,int i);//In[i]


//namespace-name::member-name notation.




