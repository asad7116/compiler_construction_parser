@echo off
echo ========================================
echo SCOPE ANALYSIS TEST SUITE
echo ========================================
echo.

echo [Test 1: Undeclared Variable]
.\output\program.exe test_undeclared_var.txt 2^>^&1 | findstr /C:"SCOPE ANALYSIS" /C:"UndeclaredVariable" /C:"passed" /C:"failed"
echo.

echo [Test 2: Undefined Function]
.\output\program.exe test_undefined_func.txt 2^>^&1 | findstr /C:"SCOPE ANALYSIS" /C:"UndefinedFunction" /C:"passed" /C:"failed"
echo.

echo [Test 3: Variable Redefinition]
.\output\program.exe test_var_redef.txt 2^>^&1 | findstr /C:"SCOPE ANALYSIS" /C:"VariableRedefinition" /C:"passed" /C:"failed"
echo.

echo [Test 4: Function Redefinition]
.\output\program.exe test_func_redef.txt 2^>^&1 | findstr /C:"SCOPE ANALYSIS" /C:"FunctionPrototype" /C:"passed" /C:"failed"
echo.

echo [Test 5: Valid Program]
.\output\program.exe test_simple.txt 2^>^&1 | findstr /C:"SCOPE ANALYSIS" /C:"passed" /C:"SYMBOL"
echo.

echo ========================================
echo All tests completed!
echo ========================================
