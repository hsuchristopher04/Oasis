### Variable.hpp
Variable is defined as a class that inherits from LeafExpression<Variable>, indicating that it represents a leaf node in an expression tree, typical for elements that do not act as operators (i.e., they have no child expressions).

The Variable class serves as a fundamental component of the symbolic mathematics framework, allowing for the representation of unknown values or placeholders within mathematical expressions. There is no computational logic within Variable beyond equality checking and string conversion, as variables, unlike operators or functions, do not undergo mathematical transformations by themselves within the framework's scope. The Variable class, along with its methods, facilitates the symbolic manipulation and interpretation of algebraic expressions by providing a clear and concise representation of variables within those expressions.

**Constructor and Assignment:**
-   Includes a default constructor, a copy constructor, and an explicit constructor that takes a std::string name representing the variable's identifier (such as "x", "y", or "z"). The copy assignment operator is also provided by default.    

**Member Functions:**
-   Equals(): Determines whether the current variable instance is equal to another expression, specifically checking if the other expression is also a variable with the same name.    
-   GetName(): Returns the name of the variable.    
-   ToString(): Converts the variable into its string representation, which is essentially the name of the variable.    
-   Specialize(): Methods to specialize a general Expression into a Variable if applicable, provided in both synchronous and tf::Subflow (parallel computation) forms.    

**Expression Traits:**
-   Marked with EXPRESSION_TYPE(Variable) to identify the class type within the expression framework. EXPRESSION_CATEGORY is set to 0, as variables do not have mathematical properties like associativity or commutativity. 

**Equality Check Implementation:**
-   Implements the Equals() method by checking if the other expression is a Variable and comparing the names of the variables for equality.
    
**Name Access and String Conversion:**
-   Implements the GetName() method to return the variable's name and the ToString() method to provide the string representation of the variable.
    
**Specialization Logic:**
-   Provides the Specialize() methods to create a new Variable instance from another expression if it is also a variable. This involves dynamic casting to ensure that the other expression is indeed a Variable and copying the name if the conversion is valid.