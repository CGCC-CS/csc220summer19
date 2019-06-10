
**pointers.c ** has an example of a pointer and some pointer arithmetic.

**stringpointers.c ** demonstrates how strings can be stored in an array or referenced with a pointer.

**arrayvsptr.c** has examples of arrays and pointers and shows where they are similar (syntax) and where they are different (memory allocation).

**raggedstringarray.c** demonstrates the difference between a 2D array of characters vs a 1D array of pointers for storing strings.  

**structures.c** has an example of declaring a struct, accessing it using a variable or pointer, and structs as a parameter to a function. 

**structsize.c** demonstrates the effects of field ordering on the size of a struct.  Also an example of a bitfield.

**union.c** has an example of a union.  

**usertypes.c** demonstrates how to define your own types using typedef.  Examples with enum, struct, and union.  Also an example of passing a pointer to a structure to a function.  

The **conditional** directory has an example of using a compile-time directive to change what code is included in the build.  In this example, the makefile will build two programs - hello & goodmorning - from the same source file.  The MORNING symbolic constant determins which string is printed out.
