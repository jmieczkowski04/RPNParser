# Reverse polish notation calculator

## Requirements
This program requires installed xxhash library. To install it use vcpkg.

## How does it translate to normal math?

`2 5 +` - `2 + 5`

`4 3 - 5 *` - `(4-3)*5`

## Supported two argument operators
 - \+ addition
 - \- subtraction
 - \* multiplication
 - \\ division
 - ^ exponentiation
 
## Supported one argument functions
 - sqrt square root
 - abs absolute value
 - sin
 - cos

## Supported constants
 - `PI` PI number (3.14...)
 - `e` Euler's number (2.71...)
 Each constant has 100 digits after `.`. This is more than enought to fully fill `double` C++ type(64-bit precision).
 
## Functions 
You are able to define your own one argument functions. To do it, write command `def <name>`. After that you will enter formula with x variable and from now you can call it like other one argument functions. They are much slower than build-in functions, but they are faster than expressions with no functions.  
 
## Support for polish notation
RPNParser also supports normal polish notation. To enable that pass `--pn` command line argument or exectue switch command. Parsing speed will not be affected, but there is some setup before calling parser, so it will take a little bit longer to execute it. 