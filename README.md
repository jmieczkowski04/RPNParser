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
 
## Supported one argument operators
 - sqrt square root
 - abs absolute value
 - sin
 - cos

## Supported constants
 - `PI` PI number (3.14...)
 - `e` Euler's number (2.71...)
 Each constant has 100 digits after `.`. This is more than enought to fully fill `double` C++ type(64-bit precision).
 
## Support for polish notation
RPNParser also supports normal polish notation. To enable that pass `--pn` command line argument. Parsing speed will not be affected, but there is some setup before calling parser, so it will take a little bit longer to execute it. 