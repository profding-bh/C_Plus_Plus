/*

a file  is the traditional unit of storage(in a file system)
and the traditional unit of compilation.


#include "to_be_included"

The #include-directive repalces the line in which  the #include appears
with  the contents of the  file to_be_included.

The One-Definition Rule

a given class, enumeration,and template ,etc,must be defined  exactly once  in a program


hackery


an extern "C" directive specifies the linkage convention (only)
and does not  affect the semantics of calls to the function.in
particluar , a function  declared extern "C" still obeys the C++ type-checking
and arguments conversion rules and not the weaker C rules.

this construct ,commonly called a a linkage block,can be  used to  enclose
a complete C header to make  a header suitable for C++ use.

This technique is commonly  used to  produce  a c++ header from a c header.



herculean:

derogatory:




there are  a variety of ill-behaved and implementation-dependent ways of making a 
program  crash(e.g.:dividing a double by zero)

basically, atexit()is a C workaround for the lack of  destructors.



*/
