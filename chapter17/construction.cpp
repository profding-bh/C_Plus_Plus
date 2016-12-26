/*

beget
the diff between move and copy is that after a copy  two 
objects must have  the same value,whereas after a move the
souce of the move is not required to have its original value.moves
can be used when the source object will not be used again.

one meaning of  ~is "complement"

The reason we need a virtual destructor  is that an object  usually 
 manipulated through the interface provided by a base class is often also 
deleted through that interface.


a constructor that can be  invoked  without  an argument is called a default constructor


such a constructor is called a delegating constructor(and occasionally a forwarding
constructor)


shallow copy
deep copy

this observation leads to  the notion of copy-on-write.

the idea is  that a copy  doesn't actually need independence until 
a shared state is written to,so we can delay  the copying of the shared
state until just before the first write to it.

panacea,

unwary.


slicing


the && indicates an rvalue reference.
far-fetched


tic_tac_toe://剪刀,石头,布?



*/
