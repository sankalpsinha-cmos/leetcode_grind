# Bit Operations: The Magic

## Basic Bit Operations

### Bitwise AND (&):
Let n = 4 and m = 5. Then n&m = 100 & 101 = 100
### Bitwise OR (|):
Let n = 4 and m = 5. Then n|m = 100 | 101 = 101
### Bitwise Not(~):
Let n = 4. Then ~n = ~100 = 011 (3)
### Left Shif(<<):
Let n = 4. Then n<<1 = 100<<1 = 1000 (8).
(Left shift is multiplication by 2)
### Right Shift(>>):
Let n = 4. Then n>>1 = 100>>1 = 10 (2)
(Right shift is division by 2)
### Bitwise XOR (^):
Let n = 4 and m = 5. Then n^m = 100 ^ 101 = 001
(If bits are same then 0. If bits are different then 1)

Some properties of XOR that are amazing:
1. a^a = 0
2. a^0 = a
3. a^b^a = b
4. a^b = b^a (Commutative)
5. a^(b^c) = (a^b)^c (Associative)

These properties are used in many problems. A simple example could be:

**“Given a set of numbers where all elements occur even number of times except one number, find the odd occurring number”**

This problem can be efficiently solved by just doing XOR of all numbers.
```
A = { 12, 12, 14, 90, 14, 14, 14 } Find the number that occurs odd times.

Then xor all the numbers togerther to get answer:

12 ^ 12 ^ 14 ^ 90 ^ 14 ^ 14 ^ 14

Since 12 ^ 12 = 0 (property 1)

=> 0 ^ 14 ^ 90 ^ 14 ^ 14 ^ 14

Since 0 ^ 14 = 14 (property 2)

=> 14 ^ 90 ^ 14 ^ 14 ^ 14.

Since 14 ^ 90 ^ 14 = 90 (property 3)

=> 90 ^ 14 ^ 14.

Since (90 ^ 14) ^ 14 = 90 ^ (14 ^ 14) (property 5)

=> 90 ^ 0

Since 90 ^ 0 = 90 (property 2)

=> 90

```
---

### Some cool things we can do with bitwise operators

1. To multiply any number by 2 left shift the number one place:
2. To intergral divide any number by 2 right shift the number one place.
3. To find any power to 2, left shift 2 by the exponent.
4. Check if a number is a power of 2. If n is a power of 2 then n&(n-1) == 0 else 1.
5. Check if a number is even or odd. If n is even then n&1 == 0 else 1
6. Swap 2 numbers. To swap 'a' and 'b' do:
    1. a = a ^ b
    2. b = a ^ b
    3. a = a ^ b
7. Check if 2 numbers are equal. If a == b then a^b == 0.
8. Convert a decimal number to binary number.
    1. Find the no of binary digits needed to repersent the number by doing ceil(log2(n)).
    2. loop from 0 to ceil(log2(n)) and do:
        1. Calculate (n>>i)&1 and push it onto some vector.
    3. After the loop exits reverse the vector to get the binary repersentation of the number.
---

More questions that can be solved using bit operation can be found here:
[Click Here](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)