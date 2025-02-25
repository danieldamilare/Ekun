![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

# Yoruba Programming Language  

## Overview  
Yoruba is a work-in-progress programming language designed to be intuitive for Yoruba speakers. It aims to make programming more accessible by using familiar Yoruba syntax and keywords.  

The goal is to create a language that is both powerful and easy to learn for those who are more comfortable with Yoruba than traditional programming languages.  

### Example Code:  
```yoruba
pe(sope, "E kabọ Ayé")

ise(ikinni, apeere) 
    fun i lati 0 de 2 se
        pe(sope, "E káàárọ̀", apeere[i])
    pari
pari

pe(ikinni, ["Damilare", "Daniel", "Olúṣẹ́gun"])
```  

## Features  
✅ **Yoruba Syntax** – Uses Yoruba-based keywords and structure for easier learning.  
✅ **Simple Data Types** – Supports integers, floating-point numbers, and strings.  
✅ **Extensibility** – Includes a Visual Studio Code extension and WebAssembly support.  
✅ **Online IDE** – [Try it in your browser](https://danieldamilare.github.io/Ekun).  

## Building and Running  
### Prerequisite
- GCC/Clang compiler
- Make build system
-
To build the project locally, follow these steps:  


### Clone the Repository  
```sh
git clone https://github.com/danieldamilare/Ekun.git
```  
Navigate into the project and build it:  
```sh
cd Ekun && make
```  
To compile the WebAssembly   
```sh
make wasm
```  

## Getting Started  
If you are new to the language and want to see how it works, you can try it online [here](https://danieldamilare.github.io/Ekun).  

To learn more about the language, read the [Specification](./docs/specification.md).  

---

## To-Do List  
🔹 **Character Encoding** – Ensure full UTF-8 support for Yoruba characters.  
🔹 **Error Handling** – Provide clear error messages in Yoruba where possible.  
🔹 **Standard Library Extensions** – Expand the language with useful built-in functions.  
🔹 **Performance Optimizations** – Implement optimizations like computed `goto` and NaN-boxing.  
🔹 **Extended Data Types** – Support additional types like hash tables, objects, and classes.  
🔹 **Garbage Collection** – Implement memory management for optimized performance.  
🔹 **Development Tools** – Provide syntax highlighters, linters, and debuggers for better support.  

---

