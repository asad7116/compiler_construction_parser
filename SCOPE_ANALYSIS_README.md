# Scope Analysis Module

## Overview

A comprehensive scope analysis module for the compiler implementing a **spaghetti stack** data structure to track variable and function scopes throughout the program's Abstract Syntax Tree (AST).

## Features

### Scope Error Detection

The module detects the following scope errors following C programming language rules:

```cpp
enum class ScopeError {
    UndeclaredVariableAccessed,      // Using a variable that was never declared
    UndefinedFunctionCalled,          // Calling a function that doesn't exist
    VariableRedefinition,             // Declaring the same variable twice in the same scope
    FunctionPrototypeRedefinition     // Defining the same function multiple times
};
```

### Spaghetti Stack Implementation

The scope analyzer uses a **spaghetti stack** - a tree-like structure where each scope node points to its parent:

```cpp
class ScopeNode {
    int level;                                           // Scope depth
    std::shared_ptr<ScopeNode> parent;                   // Parent scope
    std::unordered_map<std::string, VariableSymbol> variables;  // Local variables
    
    // Lookup in current scope only
    VariableSymbol* lookup(const std::string& name);
    
    // Lookup recursively up the scope chain
    VariableSymbol* lookupRecursive(const std::string& name);
};
```

### Symbol Tables

#### Variable Symbol
```cpp
struct VariableSymbol {
    std::string name;       // Variable name
    std::string type;       // Type (int, float, etc.)
    int scopeLevel;         // Scope depth where declared
    bool isParameter;       // Is this a function parameter?
};
```

#### Function Symbol
```cpp
struct FunctionSymbol {
    std::string name;                        // Function name
    std::string returnType;                  // Return type
    std::vector<std::string> parameterTypes; // Parameter types
    std::vector<std::string> parameterNames; // Parameter names
    bool isDefined;                          // Is function defined?
};
```

## C Language Scoping Rules Implemented

1. **Block Scope**: Local variables are visible from declaration to block end
2. **Shadowing**: Inner scope variables can shadow outer scope variables (legal)
3. **Parameter Scope**: Function parameters are local to the function
4. **Global Scope**: Global variables are file-scoped
5. **Function Forward References**: Functions can be called before definition (C-style)
6. **Scope Lifetime**: Variables cease to exist when their scope exits

## Architecture

### Two-Phase Analysis

**Phase 1: Symbol Registration**
- Register all global variables
- Register all function prototypes
- Detect function and global variable redefinitions

**Phase 2: Body Analysis**
- Analyze each function body
- Track scope entry/exit for blocks
- Validate all variable and function references

### Visitor Pattern

The analyzer traverses the AST using a visitor-like pattern:

```
analyzeProgram()
├─ analyzeFunction()
│  ├─ enterScope()
│  ├─ declare parameters
│  ├─ analyzeStatement() for each statement
│  └─ exitScope()
│
├─ analyzeStatement()
│  ├─ analyzeVariableDeclaration()
│  ├─ analyzeAssignment()
│  ├─ analyzeIfStatement()
│  ├─ analyzeWhileStatement()
│  ├─ analyzeForStatement()
│  └─ ...
│
└─ analyzeExpression()
   ├─ analyzeFunctionCall()
   ├─ analyzeIdentifier()
   ├─ analyzeBinaryOp()
   └─ ...
```

## Usage

### Integration into Compiler Pipeline

```cpp
#include "scope_analyzer.h"

// After successful parsing
if (parse_successful) {
    ScopeAnalyzer scopeAnalyzer;
    bool scopeSuccess = scopeAnalyzer.analyze(program_root);
    
    if (!scopeSuccess) {
        scopeAnalyzer.printErrors();
        return 1;  // Stop compilation
    }
    
    // Continue to type checking phase...
}
```

### API

```cpp
class ScopeAnalyzer {
public:
    // Main analysis entry point
    bool analyze(const std::shared_ptr<ProgramNode>& program);
    
    // Get detected errors
    const std::vector<std::pair<ScopeError, std::string>>& getErrors() const;
    
    // Check if errors exist
    bool hasErrors() const;
    
    // Print errors in human-readable format
    void printErrors() const;
    
    // Print symbol tables (debugging)
    void printSymbolTables() const;
};
```

## Test Suite

### Test Files Created

1. **test_undeclared_var.txt** - Tests UndeclaredVariableAccessed error
2. **test_undefined_func.txt** - Tests UndefinedFunctionCalled error
3. **test_var_redef.txt** - Tests VariableRedefinition error
4. **test_func_redef.txt** - Tests FunctionPrototypeRedefinition error
5. **test_shadowing.txt** - Tests valid variable shadowing
6. **test_block_scope.txt** - Tests block scope rules
7. **test_for_scope.txt** - Tests for-loop scope
8. **test_complex_valid.txt** - Complex valid program with multiple functions

### Test Results

✅ **UndeclaredVariableAccessed** - Correctly detected
```
✗ Scope analysis failed with 1 error(s):
  [UndeclaredVariableAccessed] Use of undeclared variable 'undeclaredVar'
```

✅ **UndefinedFunctionCalled** - Correctly detected
```
✗ Scope analysis failed with 1 error(s):
  [UndefinedFunctionCalled] Call to undefined function 'undefinedFunction'
```

✅ **VariableRedefinition** - Correctly detected
```
✗ Scope analysis failed with 1 error(s):
  [VariableRedefinition] Variable 'x' redefined in same scope
```

✅ **FunctionPrototypeRedefinition** - Correctly detected
```
✗ Scope analysis failed with 1 error(s):
  [FunctionPrototypeRedefinition] Function 'duplicate' redefined
```

## Example Output

### Valid Program
```
=== SCOPE ANALYSIS ===
✓ Scope analysis passed: No scope errors detected.

=== SYMBOL TABLES ===
Functions:
  int add(int a, int b)
  int factorial(int n)
  int main()
=====================
```

### Program with Errors
```
=== SCOPE ANALYSIS ===
✗ Scope analysis failed with 3 error(s):
  [UndeclaredVariableAccessed] Use of undeclared variable 'x'
  [UndefinedFunctionCalled] Call to undefined function 'foo'
  [VariableRedefinition] Variable 'temp' redefined in same scope
Scope analysis failed! Cannot proceed to type checking.
```

## Design Benefits for Type Checking

The spaghetti stack structure is ideal for the upcoming type-checking phase:

1. **Type Information Storage**: Each `VariableSymbol` already stores type information
2. **Quick Type Lookup**: `lookupRecursive()` efficiently finds variable types
3. **Function Signatures**: `FunctionSymbol` stores complete parameter type lists
4. **Scope-Aware**: Type checking can leverage the same scope structure
5. **Extensible**: Easy to add type inference and type compatibility checks

### Preparing for Type Checking

The current implementation can be extended with:

```cpp
struct VariableSymbol {
    std::string name;
    std::string type;
    int scopeLevel;
    bool isParameter;
    
    // For future type checking:
    // bool isConst;
    // bool isPointer;
    // int pointerLevel;
    // TypeInfo* detailedType;
};
```

## Files

- **scope_analyzer.h** - Header file with class and struct definitions
- **scope_analyzer.cpp** - Implementation of scope analysis logic
- **main.cpp** - Integrated scope analysis into compilation pipeline
- **test_*.txt** - Comprehensive test suite

## Compilation

```bash
C:\msys64\usr\bin\bison.exe -d parser.y
g++ -std=c++17 main.cpp lexer.cpp token.cpp parser.cpp lexer_wrapper.cpp parser.tab.c scope_analyzer.cpp -o output/program.exe
```

## Future Enhancements

1. **Type Checking**: Extend symbol tables with detailed type information
2. **Type Inference**: Infer types for expressions
3. **Type Compatibility**: Check assignment and function call type compatibility
4. **Advanced Scoping**: Support for namespaces, classes, or modules
5. **Warning System**: Warnings for shadowing, unused variables, etc.
6. **Scope Visualization**: Generate scope tree diagrams for debugging

## References

- C Programming Language Specification (ISO/IEC 9899)
- Compiler Design Principles (Aho, Lam, Sethi, Ullman)
- Spaghetti Stack Data Structure for Symbol Table Management
