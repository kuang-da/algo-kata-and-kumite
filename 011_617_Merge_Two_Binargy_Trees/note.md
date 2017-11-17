# Tips
+ a NULL struct is 0

# Why TreeNode*

Why use pointers of treenode as the type return value and input arguments?

## Struct in cpp

Structure is a collection of variables of different data types under a single name. It is similar to a class in that, both holds a collecion of data of different data types.

### How to declare a structure in C++ 
```cpp
struct Person
{
    char name[50];
    int age;
    float salary;
};
```

### How to define a structure variable
Once you declare a structure person as above. You can define a structure variable as:
```cpp
Person bill;
```

### How to access members of a structure
The members of structure variable is accessed using a dot (.) operator.
```cpp
bill.age = 50;
```
## Why pass pinter or reference instead of value into function?


## Why pass pointer instead of reference into function?

A pointer can receive a NULL parameter, a reference parameter can not. If there's ever a chance that you could want to pass "no object", then use a pointer instead of a reference.

+  Passing by pointer

	+ Caller has to take the address -> not transparent

	+ A 0 value can be provided to mean nothing. This can be used to provide optional arguments.

+ Pass by reference

	+ Caller just passes the object -> transparent. Has to be used for operator overloading, since overloading for pointer types is not possible (pointers are builtin types). So you can't do 
	
	```cpp
	string s = &str1 + &str2; 
	```
	
	using pointers.
	+ No 0 values possible -> Called function doesn't have to check for them
	+ Reference to const also accepts temporaries: void f(const T& t); ... f(T(a, b, c));, pointers cannot be used like that since you cannot take the address of a temporary.
	+ Last but not least, references are easier to use -> less chance for bugs.

[More](http://www.cplusplus.com/articles/z6vU7k9E/)
