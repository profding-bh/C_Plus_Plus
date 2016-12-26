/*
fanatics

for many programmers that puts  a limit of  of about 40 lines on a function.
my ideal is a much smaller size still,maybe an average of 7 lines.



virtual, indicating that it can be overridden in a derived class
override,indicating that it must be overiding a virtual function from a base class.

*/

struct S{
		[[noreturn]] virtual inline auto f(const unsigned long int* const) -> void const noexcept;
};


/*
a const is ignored at the highest level of an argument type.

Traditionally, in C and C++ ,the return type comes first in a
function declaration (before the name of the function).
However, a function  declaration can also be written using a syntax 
that  places the return type after argument list.

string to_string(int a);
auto to_string(int a) -> string// suffix return type

a prefix auto indicates that the return type is placed after the argument list.
the suffix return type is preceded by ->.

ODR("one-definiton rule")

a construct [[...]] is called an attribute  and can  be placed just about anywhere in
the C++ syntax.

two standard attributes,[[noreturn]] & [[carries_dependency]]

 
a name defined in a function is commonly  referred to as a local name.

There are no local functions;if you feel you need one, use a function object or
lambda expression.

foolhardy


It is usually preferable to pass a reference to some container,
such as vector,array,or map.

note that the number of elements is part of a reference-to-array type.

initializer lists take priority.

stopgap.

precluded.

because C does not have function objects or lambda　expressions.


The first rule about  macros is:don't use them unless you have to.


yuk


#ifdef IDEN
does nothing if IDEN is defined,but if it is not,the directive causes all input 
to be ignored until a #endif directive is seen.

if possible ,#pragma are best avoided.




*/
