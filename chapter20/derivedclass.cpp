/*
props 

derivation if often  represented  graphically by a pointer from the derived calss to 
its base  class,indicating that the derivated class refers to its base(rather than the
other way around.)

in general, if a class  Derived has  a public  base  calss Base,then a
Derived* can  be assigned to  a variable of type Base* without the use of  explicit type
conversion.
Base* b = Derived* d
The opposite conversion from Base* to Derived*,must be explicit.


unwary

typically, destructors in a hierarchy need to be virtual

in source text,definitions of base classes must occur before the definitions of 
their derived classes.

This implies that for small examples,the bases  appear above  the 
derived classes on a screen.

c++ can express a directed acyclic graph of classes.


severity,
intertwined


a virtual member functions is sometimes  called a method.

a type with virtual functions is called a polymorphic type or(more precisely)
a run-time polymorphic type.

to get runtime polymorphic behavior in c++ ,the member functions called must be
virtual and objects must be manipluated through pointers or references.


by default, a function that overrides a virtual  function itself becomes  virtual.
we can ,but do not have to,repeat  virtual in a derived class.
I don't recommend repeating  virtual .if you want to  be explicit,use override

the usual  implementation technique is for the compiler to convert  the name of 
a virtual function into  an index into a table of  pointers to functions,
that table is usually called  the virtual function table or simply,
the vtbl.

Each class with virtual functions has its own vtbl identifying  its virtual functions .


It is therefore typically a bad  idea to call a virtual function from a constructor 
or a destructor


the override specifier comes last in a declaration, after all other parts.


an verride specifier is not  part of the type  of a function adn cann't be repeated
in an out-of-class definition.

curiously, override is not  a keyword; it is what is called  a contextual keyword.

that is ,override has a special meaning in a few context but can be  used as an 
identifier elsewhere.

indulge.

the other  contextual keyword is final.


there is  a relaxation of the  rule that  the type of an overriding function must be
the same  as the type of the virtual function it overrides.

this is sometimes called the covariant return rule.



because functions such as new_expr() and clone() are virtual and they (indirectly)
construct objects.they are often  called virtual  constructors.

to make an object,a constructor needs the exact type of the object it is to create.
consequently, a constructor cannot be  virtual.

futhermore,a constructor is not  quite an ordinary  function.
in particular,it interacts with memory management routines in ways ordinary member functions don't. so you can not  take a pointer to a constructor and pass that to 
an object  creation function.

a virtual function is "made pure" by the "pseudo initializer"=0

a class with one  or more pure virtual functions  is an abstract class.
and no objects of that abstract class can  be created.



nonintrusive

surrounding
corrupt.



contravariance.



 
*/
