# Compiler Construction — Parser Project

This repository contains a small compiler-construction / parser project. It includes a lexer, parser, scope analyzer, and a set of test programs.

## Quick overview

- Language: C++ (C/C++ sources present)
- Primary purpose: parse a small sample language and run scope analysis tests
- Location: repository root contains the source files and test data

## Important files

- `main.cpp` — program entry point / driver
- `lexer.cpp`, `lexer.h`, `lexer_wrapper.cpp` — lexer implementation and wrapper
- `parser.y`, `parser.tab.c`, `parser.tab.h`, `parser.cpp`, `parser.h` — parser sources (Bison/Yacc output included)
- `scope_analyzer.cpp`, `scope_analyzer.h` — scope analysis logic
- `token.cpp`, `token.h` — token structures used by the parser
- `stack.hh` — small stack helper
- `ast_printer.h` — AST printing support (header)
- `run_scope_tests.bat` — batch script to run scope tests on Windows
- `sample_program.txt` — an example input program
- Test files: `test_*.txt` (e.g. `test_valid_program.txt`, `test_undeclared_var.txt`, etc.)

There is also a `build/Debug/output` area where compiled artifacts may be placed by local builds or IDEs.

## Build (recommended, Windows / PowerShell)

These instructions assume you have a working C++ toolchain installed. Common choices on Windows:
- MSYS2 / MinGW-w64 (g++)
- Visual Studio (MSVC)

Option A — Build with g++ (MinGW/MSYS2):

Open PowerShell that has access to `g++` (for example, MinGW/MSYS2 or WSL). From the repository root run:

```powershell
# Compile all .cpp and .c files in the repo root to an executable named main.exe
g++ -std=c++17 -O2 -I. .\main.cpp .\lexer.cpp .\lexer_wrapper.cpp .\parser.tab.c .\parser.cpp .\scope_analyzer.cpp .\token.cpp -o main.exe
```

Notes:
- Adjust the file list if you add/remove source files. The command above lists the main sources present in this repo.
- If you generate `parser.tab.c`/`.h` from `parser.y`, you may need Bison (see Option C).

Option B — Build with Visual Studio (MSVC)

- Create a new Visual Studio Console project, add the `.cpp` and `.h` files from the repository.
- Ensure the code is compiled with C++17 or later.

Option C — Regenerate parser (if you change `parser.y`)

If you edit `parser.y` and need to regenerate parser sources, use Bison/Yacc and (optionally) Flex for the lexer:

```powershell
# example (requires bison and flex installed in PATH)
bison -d parser.y    # produces parser.tab.c and parser.tab.h
# if a lexer .l exists, run flex to produce lex.yy.c
# flex lexer.l
# then compile generated files with g++ as above
```

## Run

- If you built `main.exe` as above, run it from PowerShell:

```powershell
# run the program and pass an input file (if the binary reads files)
.\main.exe sample_program.txt
```

- There is a convenience batch script to run scope tests on Windows:

```powershell
# run tests using the provided script (PowerShell can call it)
.\run_scope_tests.bat
```

## Tests / Sample inputs

The repository contains a number of sample test files you can use to exercise the parser and scope analyzer:
- `test_program.txt`, `test_valid_program.txt`, `test_undeclared_var.txt`, `test_var_redef.txt`, `test_block_scope.txt`, `test_for_scope.txt`, `test_shadowing.txt`, `test_complex_valid.txt`, etc.

Use `run_scope_tests.bat` to run the built-in test harness. You can also feed each file to the compiled `main.exe` manually.

## Scope analysis notes

See `SCOPE_ANALYSIS_README.md` and `SCOPE_ANALYSIS_SUMMARY.md` for details on the scope analysis design, symbol table layout, and known limitations.

## How to contribute / extend

- If you add grammar rules, regenerate parser outputs (`parser.tab.c/.h`) from `parser.y` using Bison.
- If you change tokens, update `lexer.cpp`/`lexer_wrapper.cpp` accordingly.
- Consider adding a small `build.ps1` or `Makefile` to automate compilation across environments.

## Troubleshooting

- If `g++` is not found: install MSYS2 or MinGW-w64 and ensure `g++` is in PATH.
- If Bison/Flex are needed: install them via MSYS2 pacman or another package manager.
- If you see linker errors about missing symbols: ensure all necessary `.cpp` files are part of the compile command.

## License

No license file included. If you intend to publish or share this code, consider adding an appropriate LICENSE file.

---

If you'd like, I can:
- Add a `build.ps1` PowerShell script to automate the g++ build command.
- Run a quick build in this environment to validate the command (if you want me to attempt compilation here).
- Expand the README with examples of expected input/output from `sample_program.txt`.

Tell me which of the above you'd like next.