/*

fiddling

postfix is suffix?

the result of an integral condition is always  compared to zero anyway.


is is often useful to create an object that exists independently of the scope in
which  it was created.
 


the main problems with free store are:

1) leaked objects:People use new  and then forget to delete the allocated object.
2)premature deletion: people delete an object that they have some other pointer 
to and later user that other pointer.
3) double deletion: an object  is deleted twice.invoking its destructor (if any)twice.

sloppy


The vector keeps its elements on the free store.but it handles all allocations and 
deallocations itself.

The "plain" operator delete is used to delete individual objects;
delete[] is used to delete arrays.

<new>header:

new[]
delete[]

The allocation and deallocation functions deal in untyped and uninitialized 

memory(ofen called "raw memory")

operator new() is known as the placement syntax

The nothrow is the name of an object of the  standard-library type 
nothrow_t that is used for disabiguation.nothrow and nothrow_t are declared in <new>


insurmountable

a lambda expression,sometimes also referred to as a lambda function or(strictly speaking
incorrectly,but colloquially)as a lambda,is a simplified notation for defining and using 
an anonymous function object.

This is particularly useful when  we want to pass an operation as an argument to an 
algorithm.such operations are often  referred to as callbacks.

an object of a class generated from a lambda is called a closure object(or simply a closure)

stylistic

a lambda might outlive its caller.

long-gone

if a lambda might outlive its caller,we must make sure that all logical  information(if any) is copied into the closure  object and that values are returned through the return 
mechanism.
we can declare the lambda mutable.


suffix == postfix



 


*/
