# Yoruba Programming Language

### Overview
Yoruba is a work-in-progress programming language designed to be intuitive for Yoruba speakers. It aims to bring programming closer to the native language, offering a unique approach by using familiar Yoruba syntax and keywords.

The goal is to create a language that’s not only powerful but also easy to learn for those who are more comfortable with Yoruba than traditional programming languages.
```
   pe(sope, "E kabbo Aye")

   ise(ikinni, apeere) 
      fun i lati 0 de 2 se
          pe(sope, "Ekaaro", apeere[i])
      pari
   pari

   pe(ikinni, ["Damilare", "Daniel", "Olusegun"])
```


## Features
- **Yoruba Syntax**: Keywords and syntax are based on the Yoruba language, making it easier for Yoruba speakers to learn and use.
- **Simple Data Types**: Supports basic data types such as integers, floating-point numbers, and strings.
- **Extensibility**: Includes extensions for Visual Studio Code and support for building WebAssembly.
- **Online IDE**: Features a simple IDE that can be access [here](https://danieldamilare.github.io/Ekun)

### Building and Running
To build the project locally, follow these steps:

1. Clone the Repository
```bash
 git clone https://github.com/danieldamilare/Ekun.git
```
2. Navigate into the project and build it:
```
 cd Ekun && make
```
3. To build the web assembly
```bash
make clean
```
###Getting Started
If you are new too the language and want to see how to it. You can try it  [online](https://danieldamilare.github.io/Ekun)
To know more about the languages read the [Specification](./docs/specifications.md)

### TO DO

1. **Character Encoding**: Use UTF-8 to properly support Yoruba-specific characters.

2. **Error Handling**: provide clear error messages in Yoruba where possible.

3. **Standard Library Extensions**: Add Standard Library to extend the language.

4. **Performance Considerations**: Add optimization features like computed Goto, Nan-boxing.

5.  **Extend Data Types**: Add more data types like Hash Table, Object and Class

6. **Garbage Collection**:  Add support for garbage collection and optimized resource management

5. **Development Tools**: Consider providing tools such as syntax highlighters, linters, debuggers that support the language.
