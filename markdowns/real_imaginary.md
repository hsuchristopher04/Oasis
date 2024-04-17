### Real.hpp
Real is a derived class of LeafExpression, specifically designed to handle real numbers. It encapsulates a single double-precision floating-point value. The Real class serves as a fundamental component of the symbolic mathematics library, allowing the representation and manipulation of real numbers within expressions.
**Constructors and Assignment:**
- Default and copy constructors.
- An explicit constructor taking a double to initialize the real number.

**Key Methods:**
- Equals(): Checks if another expression is a Real object with the same value.
- GetValue(): Returns the stored double value.
- ToString(): Provides a string representation of the real number.
**Specialization:**
- Specialize(): Converts a general Expression to a Real if it is indeed a Real. This is useful for ensuring type safety within operations that require real numbers.
- Checks the type of the passed Expression and safely downcasting it if it matches the Real type.

**Expression Traits:**
- Type and Category: The class uses macros to set its type to Real and category to none, as real numbers do not conform to associative or commutative properties by themselves.

**Equality Check:** Implements the equality logic to check if another Expression is a Real and has the same value.
**Value Accessor:** Simple getter to return the internal double value.
**String Representation:** Converts the double value to a string using std::to_string, which is straightforward but does not handle formatting specifics like trailing zeros or scientific notation.
**Type Safety and Conversion:** Offers mechanisms to safely convert between general expressions and real numbers, crucial for maintaining integrity across various mathematical operations.

### Imaginary.hpp
Imaginary is a derived class of LeafExpression, specifically designed to handle imaginary numbers represented typically as 'i' in mathematics. This class represents an imaginary number within a symbolic mathematics library. Like the Real class, Imaginary also inherits from LeafExpression, indicating that it functions as a terminal node in the expression tree with no child expressions.

**Constructors and Assignment:**
Default and copy constructors are provided, enabling basic instantiation and copying of Imaginary objects.

**Core Methods:**
- Equals(): Checks if another expression is an Imaginary object. This would typically involve confirming that the other object is of the type Imaginary.
- ToString(): Returns a string representation of the imaginary unit, which is "i".

**Specialization:**
- Specialize(): Converts a general Expression to an Imaginary if it is indeed an Imaginary. This function is crucial for maintaining type safety and correctness in operations that involve imaginary numbers.

**Expression Traits:**
- Type and Category: Defines its type as Imaginary with no specific associative or commutative category settings since imaginary units by themselves don't imply these properties.

**Equality Check:**
- Implements the Equals method to check if another Expression is an Imaginary. The method checks the type of the expression to ensure it's Imaginary.

**String Representation:**
- The ToString method returns the string "i", representing the mathematical notation for the square root of -1.

**Specialization Implementation:**
- Implements the specialization function by checking if the passed Expression is of type Imaginary and then safely downcasting it if it is. This is essential for operations that specifically require an imaginary number.

**Simplicity and Specificity:**
- As a leaf node, Imaginary handles no child expressions and encapsulates the simplest form of an imaginary unit. This simplicity ensures that it can be efficiently used in various complex number operations.

**Type Safety and Conversion:**
- The class provides mechanisms to convert between general expressions and Imaginary objects safely, ensuring that mathematical operations involving imaginary numbers are performed correctly.

**Utility in Symbolic Computations:**
- Imaginary plays a vital role in computations involving complex numbers, particularly in functions that need to differentiate between real and imaginary parts of complex expressions.

### Undefined.hpp
This class represents an undefined expression, often used in mathematical computations where an operation results in an undefined value (such as division by zero). Undefined is a derived class of LeafExpression, specifically designed to represent undefined expressions in mathematical computations.
**Constructors and Assignment:**
Provides default and copy constructors, facilitating basic instantiation and copying of Undefined objects.
**Key Methods:**
- Equals(): Always returns false, indicating that an undefined expression is not equal to any other expression, including another undefined expression. This reflects the mathematical concept that undefined values cannot be compared.
- ToString(): Returns a string representation of the undefined state, specifically "Undefined".

**Specialization:**
- Specialize(): Converts a general Expression to an Undefined if it is indeed an Undefined. This function is crucial for ensuring type correctness in operations that might result in an undefined state.

**Expression Traits:**
- Type and Category: Defines its type as None with no specific associative or commutative category settings, appropriate for an expression that cannot partake in usual operations.

**String Representation:** 
- Implements the ToString method to return "Undefined," which is used to denote the state of the expression in outputs and logs.

**Specialization Implementation:**
- Implements the specialization function by checking if the passed Expression is of type Undefined and then creating a new Undefined instance if true. This is essential for maintaining correct behavior in expression trees that encounter undefined results.

**Consistency in Comparison:** 
- By always returning false in the Equals() method, Undefined maintains the mathematical principle that undefined values are not comparable.

**Utility in Error Handling:** 
- This class plays a critical role in error handling within the library, particularly in functions that can result in mathematically undefined states, such as division by zero or invalid operations in domain-specific contexts.

**Simplicity and Effectiveness:**
- As a leaf node with no children, Undefined is simple yet effective in marking errors or exceptional cases in an expression tree, ensuring that these can be easily detected and handled.
