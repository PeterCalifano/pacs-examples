# Notes from lecture 2: floating point arithmetic
### Basic definition
- Floating point numbers are represented as a sign bit, an exponent and a mantissa (or significand).
- The exponent is stored in a biased form, meaning that a fixed value (bias) is added to the actual exponent to obtain the stored exponent. This allows for both positive and negative exponents to be represented.
- Often, the mantissa is normalized, meaning that the leading digit is always 1 (for binary numbers). This allows for a more efficient representation of the number.
![alt text](floating_point_numbers.png)
- The reason why the basis of the floating point arithmetic is 2, is the fact that storage and error checking is simpler when working with only two values (0 and 1, binary code).

### Machine precision
- The machine precision is the smallest number that can be added to 1.0 while still being able to distinguish the sum from 1.0. This is also known as the machine epsilon.
- The roundoff unit $u$ is defined as $u = 0.5 * \epsilon_{M}.$
This is such that: $$1.0 + u = 1.0.$$
### IEEE 754 standard
![alt text](image.png)

- The standard also prescribes the representation of special values:
  - NaN (Not a Number): used to represent undefined or unrepresentable values, such as the result of 0/0. Essentially, it is used to indicate invalid operations. Any operation with NaN will result in NaN.
  - Infinity: used to represent overflow or division by zero.

- Note that underflow/overflow conditions do **not** stop the computations, but rather produce special values (0, NaN, Inf). This is for performance reasons (i.e., to avoid checking each single arithmetic operation). However, a floating point exception may be recorded in some architectures.

### Forward and backward error analysis
- Forward error analysis: measures the error in the output of a function due to errors in the input. It is defined as the difference between the exact output and the computed output.
- Backward error analysis: measures the error in the input of a function due to errors in the output. 
- The **condition number** is defined as the ratio of the relative change in the output to the relative change in the input. That is, it measures how sensitive the output of a function is to changes in the input. It is defined as:
$$
\kappa(f) = \frac{\partial f}{\partial x} \cdot \frac{x}{f(x)}
$$
- **IMPORTANT**: the subtraction of almost equal floating point numbers can lead to cancellation phenomena (big round-off errors). Avoid it when possible.

#### Interesting note: 
The reason why lower precision floating point numbers are useful in machine learning is that input and output are often pre-normalized such that a network only requires a tiny small interval of values (between 0 and 1) for the computation. 

##### Stopped at minute 30