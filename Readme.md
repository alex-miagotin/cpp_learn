### Instalation
1. Install conan and cpp compilator
2. Install `gdb` for debug
3. `./scripts/conan_build.sh`
4. `./scripts/buid`

### Base steps
![alt text](images/image.png)
| source code | build | output |
|----------- | ----------- | ----------- |
| .cpp .h .hpp .cxx(cpp23 modules) |  `preprocessing` -> `compilation` -> `linking` | .exe .lib .dll |

---
## Build steps
| preprocessing | compilation | linking |
|----------- | ----------- | ----------- |
| Delete comments. Hanle macroses. Add all includes. Simple copy past. | (`analysis` (front-end) -> `synthesis` (back-end)) Translate code to machine code | link all libs |

## Preprocessing
![alt text](images/image-1.png)

## Compilation
![alt text](images/image-2.png)
### `Analysis` (front-end)
1. Lexical Analysis (`lexems` -> `tokens`)
2. Syntax Analysis (`Abstract syntax tree (AST)` -> `symbols table`)
3. Semantic Analysis (Check types)

### `Synthesis` (back-end)
1. Intermediate code generation. ( Intermediate Representation (IR) -> Three-address code (TAC) -> Static Single Assignment (SSA) )
2. `Optimization` (`/Od` disabled; `/O1` minimum size code; `/O2` maximum speed)
3. Target code generation -> `.obj`

##### `Optimization`
1. Common Optimization
2. Function inlining (`inline`)
3. Constexpr (`constexp`)
4. Data structure alignment (Memory view)

## Linking
![alt text](images/image-3.png)
1. `ODR` - one definition rule


## static/dynamic library
1. Precompiled header files (PCH)
2. Include-What-You-Use (IWYU)
3. /MP (Vuild with multiple processes)
4. Unity (JUMBO) build
5. Static libraries
6. Dynamic libraries

## Build tools
![alt text](images/image.png)

## CMAKE