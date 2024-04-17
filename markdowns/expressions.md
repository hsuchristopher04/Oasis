### Expression.hpp:
The Expression.hpp file defines the core structure and interface for expressions in the Oasis namespace, particularly for a mathematical expressions framework. It lays the foundation for creating, manipulating, and evaluating different types of mathematical expressions within this system.
**ExpressionType Enum:** This enumeration defines the different specific types of expressions that the system can handle, such as real numbers, imaginary numbers, variables, and different kinds of binary operations (add, subtract, multiply, divide, exponent, log).
**ExpressionCategory Enum:** This defines categories for expressions to help identify their mathematical properties, such as whether they are associative or commutative.
**Key Methods:**
-   Copy(): Creates a deep copy of the expression. There's a version that operates synchronously and another that operates within a tf::Subflow, which is part of the Taskflow library for parallel computation.
-   Equals(): Compares this expression to another for equality, w/o simplifying them.
-   FindZeros(): Intended to find rational and possibly some irrational or complex zeros of a polynomial expression. This method appears to be incomplete as its implementation details are not provided in the header.
-   GetCategory() and GetType(): Return the category and type of the expression, respectively.
-   Generalize(): Converts a more specific expression type to a more general one. Like Copy(), it has both synchronous and tf::Subflow versions.
-   Specialize(): Attempts to convert a general expression into a more specific type. This static method also has both synchronous and tf::Subflow versions.
-   Is(): Checks if the expression is of a certain type. There are two versions to accommodate different kinds of template parameters
-   Simplify(): Reduces the expression to its simplest form. This method has synchronous, tf::Subflow, and asynchronous variants.
-   StructurallyEquivalent(): Determines if two expressions have the same structure, regardless of the values of their components. It also has synchronous, tf::Subflow, and asynchronous variants.
-   ToString(): Returns a string representation of the expression.

**Usage of Macros:**
-   EXPRESSION_TYPE: A macro to define the GetType() and GetStaticType() methods consistently across derived expression classes.
-   EXPRESSION_CATEGORY: Similar to EXPRESSION_TYPE, this macro defines the GetCategory() and GetStaticCategory() methods for derived classes. 

**Utility Functions:**
-   getAllFactors(long long n): Finds all positive factors of a given integer n.
-   gcf(long long a, long long b): Calculates the greatest common factor (or greatest common divisor) of two integers a and b.
    
**FindZeros Function:**
-   This function aims to find all rational zeros of a polynomial, assuming the polynomial is in one variable and its coefficients are integers.
-   It uses the Rational Root Theorem to find possible zeros by analyzing the polynomial's terms and their coefficients.
-   The implementation involves decomposing the polynomial into its components, handling different cases like variables, exponents, and products, and determining the polynomial's coefficients.
-   The actual zero-finding logic checks all combinations of factors from the constant term and the leading coefficient to test for valid roots.
-   The results are simplified and returned as expressions representing the possible roots.    

**Expression Class Method Implementations:**
-   Default implementations for the Expression base class methods like GetCategory, GetType, Generalize, Specialize, and Simplify provide basic functionality or, in most cases, placeholders that return the expression itself or zero.
-   Asynchronous methods SimplifyAsync and StructurallyEquivalentAsync are implemented using Taskflow (tf::Taskflow), allowing for concurrent execution. They respectively simplify the expression and check for structural equivalence asynchronously.

**Operator Overloading:**
-   The global operators +, -, *, and / are overloaded for std::unique_ptr<Expression> pointers, creating new Add, Subtract, Multiply, and Divide expression objects, respectively. These operations automatically simplify the resulting expressions.
### BinaryExpression.hpp:
This file serves as a base class for all binary expressions within a mathematical expressions framework. Examples might include addition, subtraction, multiplication, or division. This class inherits from Expression, implying it is part of a larger hierarchy of expression types. It sets a foundation for building and operating on binary expressions, handling different operand types, and enabling parallel computation.
**Template Parameters:**
-   DerivedT: The derived class that inherits from BinaryExpression, utilizing CRTP.
-   MostSigOpT and LeastSigOpT: The types of the most significant and least significant operands, respectively. They default to Expression, making the class flexible for different types of operands.

**Key Functionalities:**
-   Constructors and Copy Mechanisms: The class provides default and copy constructors, plus specialized copying methods (Copy) that handle deep copying and task-based parallel copying
-   Equality Checks: It offers methods to determine if two expressions are equal (Equals) or structurally equivalent (StructurallyEquivalent), considering the possibility of commutative operations (where operand order doesn't matter).
-   Generalization and Simplification: Generalize methods convert a specialized expression back into a more generalized form. Simplify methods attempt to reduce the expression to a simpler form, potentially utilizing parallel computation for efficiency.
-   Operands Handling: It provides methods to set and get operands, handle their presence checks (HasMostSigOp, HasLeastSigOp), and manipulate them (SetMostSigOp, SetLeastSigOp, SwapOperands).
-   Flatten: This method transforms the expression into a linear form, turning nested binary expressions into a flat list of operands. This is useful for operations like simplification or comparison, where hierarchical structure might complicate processing.
-   Taskflow Integration: The class integrates with the Taskflow library, evident in methods accepting tf::Subflow parameters. This integration allows expressions to be simplified or generalized in parallel, leveraging concurrent execution to speed up computation-heavy tasks.
### LeafExpression.hpp:
The LeafExpression.hpp file within the Oasis namespace defines the LeafExpression template class, which represents the concept of a leaf in the context of expression trees used within a symbolic mathematics framework.
**Template Class Definition:**
- LeafExpression is a template class designed to serve as a base for expressions that do not have child expressions (hence, "leaf" expressions). It inherits from the Expression base class.

**Template Parameter:**
-   DerivedT: Represents the type of the derived class. This design utilizes the Curiously Recurring Template Pattern (CRTP), where a class A derives from a template version of itself, e.g., B< A >. This pattern allows LeafExpression to provide implementations that automatically return the correct derived type.

**Member Functions:**
-   Copy(): Overridden from the Expression base class, this method returns a deep copy of the instance. It uses the CRTP to know the derived type (DerivedT) and create an instance of that specific type, ensuring that the copy is of the correct subclass without needing to know the exact type.
-   Copy(tf::Subflow&): Similar to Copy(), but intended for parallel computation contexts using tf::Subflow. It does not utilize the subflow argument since leaf expressions, having no children, do not require parallel copying logic.    
-   StructurallyEquivalent(const Expression&): Determines if the current instance is structurally equivalent to another expression. For leaf expressions, structural equivalence typically means being of the same type since they have no substructure.    
-   StructurallyEquivalent(const Expression&, tf::Subflow&): The parallel computation version of StructurallyEquivalent, which also doesn't use the subflow since there's no additional structure to parallelize over for leaf expressions.