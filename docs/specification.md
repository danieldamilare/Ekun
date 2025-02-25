# A SPECIFICATION OF YORUBA-BASED PROGRAMMING LANGUAGE

## Abstract

This document outlines the specification of the Yoruba programming language, a lightweight interpreted language that integrates Yoruba keywords and lexicon to create a programming environment that is intuitive for Yoruba speakers. The language supports fundamental aspects of procedural programming including functions, expressions, and statements, while maintaining cultural relevance through its syntax and vocabulary.

## 1. Introduction

The Yoruba programming language aims to bridge the gap between programming concepts and natural language for Yoruba speakers. By using familiar words and expressions from the Yoruba language, it creates a more accessible entry point to programming for native speakers while preserving the logical structure common to programming languages.

## 2. Lexical Conventions

### 2.1 Program Structure

A program in the Yoruba language is divided into logical lines. Each logical line represents a statement or part of a statement. Logical lines are terminated by a newline character (`\n`, `\r\n`) or a semicolon (`;`). 

A statement can be continued across multiple lines by ending the line with a backslash (`\`) character.

The language is case-sensitive; identifiers with different capitalization are treated as distinct (e.g., `ati` is different from `Ati`).

### 2.2 Identifiers

Identifiers are used to name variables, functions, and other program elements. An identifier must begin with a letter followed by a sequence of letters or digits. Letters can include Yoruba-specific characters such as `ẹ`, `ọ`, and `ṣ`.

An identifier cannot be a reserved keyword.

Examples of valid identifiers:
- `aṣoju`
- `ise`
- `ọjọ`
- `orukọ1`

### 2.3 Keywords

The following words are reserved as keywords and cannot be used as identifiers:

```
tabi    ati     pari    nigbati
ise     se      fi      bibeeko
dogba   si      pada    agbegbe
ooto    iro     ko      ita
de      ifikun  nigba   pe
lati     ti
```

### 2.4 Operators and Special Tokens

The following strings denote operators and other special tokens:

```
+   Addition
-   Subtraction
*   Multiplication
/   Float division
//  Floor division
%   Modulus
^   Exponentiation
<   Less than
<=  Less than or equal to
==  Equal to
>=  Greater than or equal to
>   Greater than
!=  Not equal
|   Bitwise OR
&   Bitwise AND
[]  Array indexing
()  Function calls, grouping
```

### 2.5 Comments

Comments are text that is ignored by the compiler/interpreter and serves as documentation for humans reading the code.

- Single-line comments begin with `--` and continue to the end of the line.
- Multi-line comments are enclosed between `(*` and `*)`.

Examples:
```
-- This is a single-line comment

(* This is a
   multi-line comment *)
```

## 3. Data Types

### 3.1 Basic Types

The Yoruba language supports the following basic data types:

- **noomba**: Represents numeric values, including both integers and floating-point numbers.
  - Examples: `42`, `3.14`, `-10`

- **oro**: Represents a sequence of characters (string).
  - Examples: `"Bawo ni"`, `"Yoruba"`

- **ooto**: Represents the boolean value true.

- **iro**: Represents the boolean value false.

### 3.2 Composite Types

The language supports a single composite type:

- **apeere**: Represents an ordered collection of values (array/list).
  - Example: `[1, 2, 3, 4]`, `["a", "b", "c"]`

## 4. Literals

Literals are fixed values that appear directly in the source code:

- **noomba literals**: Numeric values written directly in code.
  - Examples: `42`, `3.14`, `-10`

- **oro literals**: Character strings enclosed in double quotes.
  - Examples: `"Bawo ni"`, `"Yoruba"`

- **Boolean literals**: The keywords `ooto` (true) and `iro` (false).

- **Array literals**: Comma-separated expressions enclosed in square brackets.
  - Example: `[1, 2, 3, 4]`, `["a", "b", "c"]`

## 5. Expressions

Expressions yield values and can be used as operands of operators. The basic expression forms are:

```
expr:    noomba             -- Numeric literal
    |    oro                -- String literal
    |    ooto               -- Boolean true
    |    iro                -- Boolean false
    |    variable           -- Variable reference
    |    "[" exprlist "]"   -- Array literal
    |    pe(function, args) -- Function call
    |    variable "[" expr "]" -- Array indexing
    |    expr binop expr    -- Binary operation
    |    unop expr          -- Unary operation
    |    "(" expr ")"       -- Parenthesized expression
```

### 5.1 Operators

#### 5.1.1 Arithmetic Operators

- `+`: Addition
- `-`: Subtraction
- `*`: Multiplication
- `/`: Float division
- `//`: Floor division
- `%`: Modulus
- `^`: Exponentiation
- `-` (unary): Negation

#### 5.1.2 Relational Operators

- `<`: Less than
- `<=`: Less than or equal to
- `==`: Equal to
- `>=`: Greater than or equal to
- `>`: Greater than
- `!=`: Not equal
- `dogba`: Equal to (Experimental)
- `ko dogba`: Not equal (Experimental)

#### 5.1.3 Logical Operators

- `ati`: Logical AND
- `tabi`: Logical OR

#### 5.1.4 Bitwise Operators

- `|`: Bitwise OR
- `&`: Bitwise AND

### 5.2 String Operations

Strings can be concatenated using the `+` operator. Both operands must be strings; concatenation with other data types will result in an error.

Example:
```
"Bawo " + "ni"  -- Results in "Bawo ni"
```

### 5.3 Operator Precedence

Operators are evaluated in the following order of precedence (from highest to lowest):

1. Parentheses `()`
2. Unary operators `-` (negation)
3. Exponentiation `^`
4. Multiplication, division, modulus `*`, `/`, `//`, `%`
5. Addition, subtraction `+`, `-`
6. Relational operators `<`, `<=`, `==`, `>=`, `>`, `!=`, `dogba`, `ko dogba`
7. Bitwise AND `&`
8. Bitwise OR `|`
9. Logical AND `ati`
10. Logical OR `tabi`

## 6. Statements

### 6.1 Assignment

#### 6.1.1 Variable Assignment

Variables are containers for storing values. A variable can be declared and assigned in two ways:

Standard assignment:
```
<var> = <expr>
```

Alternative assignment (Experimental):
```
fi <expr> si <var>
```

Example:
```
oruko = "Olaoluwa"
fi 42 si ojo_ibi
```

#### 6.1.2 Array Element Assignment

Array elements can be assigned using indexing:
```
<array>[<index>] = <expr>
```

Or with the alternative syntax:
```
fi <expr> si <array>[<index>]
```

Example:
```
awon_eniyan[0] = "Ade"
fi "Bola" si awon_eniyan[1]
```

#### 6.1.3 Scope Declaration

By default, variables declared in a function are local to that function. To declare a variable as global within a function:

```
agbegbe <var>: ita
```

### 6.2 Control Structures

#### 6.2.1 If Statement

The if statement evaluates a condition and executes code based on whether the condition is true.

Basic if statement:
```
ti <condition> se
    <statements>
pari
```

If-else statement:
```
ti <condition> se
    <statements>
bibeeko se
    <statements>
pari
```

If-else if-else statement:
```
ti <condition1> se
    <statements>
bibeeko ti <condition2> se
    <statements>
bibeeko se
    <statements>
pari
```

Example:
```
ti ojo > 18 se
    pe(sope, "O ti dagba")
bibeeko se
    pe(sope, "O ko i dagba")
pari
```

#### 6.2.2 Loops

##### While Loop

Executes statements as long as a condition is true:
```
nigbati <condition> se
    <statements>
pari
```

Example:
```
fi 1 si i
nigbati i <= 10 se
    pe(sope, i)
    fi i + 1 si i
pari
```

##### For Loop

Iterates over a range of values:
```
fun <var> lati <start> de <end> (ifikun <step>) se
    <statements>
pari
```

The `ifikun <step>` part is optional and defaults to 1 if omitted.

Example:
```
fun i lati 1 de 10 se
    pe(sope, i)
pari

fun j lati 10 de 1 ifikun -1 se
    pe(ko_oro, j)
pari
```

### 6.3 Functions

#### 6.3.1 Function Definition

Functions are defined using the following syntax:
```
ise(<name>, <param1>, <param2>, ...) se
    <statements>
pari
```

Example:
```
ise(kede_oruko, oruko) se
    pe(sope, "Oruko mi ni " + oruko)
pari
```

#### 6.3.2 Function Call

Functions are called using the `pe` keyword:
```
pe(<function_name>, <arg1>, <arg2>, ...)
```

Example:
```
pe(kede_oruko, "Olaoluwa")
```

#### 6.3.3 Return Statement

The `pada:` keyword is used to return a value from a function or to exit a function early:
```
pada: <expression>
```

Example:
```
ise(ka_mejeeji, a, b) se
    pada: a + b
pari
```

## 7. Built-in Function

The Yoruba programming language includes a basic standard library with the following built-in functions:

### 7.1 Input/Output

- `sope`: Prints the value of the expression to the standard output with a newline.
- `ka`, `gba_oro`: Reads a line from standard input.

### 7.2 Type Conversion

- `si_noomba(<expression>)`: Converts the expression to a number.

### 7.3 Miscellaneous
- `igba` : get unix epoch time 



## 8. Experimental Features

The following features are experimental and designed to test the incorporation of Yoruba words in common programming syntactic patterns:

```
fi <expr> si <var>          -- alternative assignment
x dogba y                   -- equals comparison
x ko dogba y                -- not equals comparison
```

More experimental features will be added to test the intuitiveness of the language for Yoruba speakers.

## 9. Example Programs

### 9.1 Hello World
```
ko("E kaabo si Yoruba Programming!")
```

### 9.2 Fizzbuzz Program
```
-- Fizzbuzz program in Yoruba
ise(fizzbuzz, n)
   fi 1 si i
   nigbati i <= n  se
        ti i % 15 == 0 se 
           pe(sope, "fizzbuzz")
        bibeeko ti i % 5 == 0 se
           pe(sope, "buzz")
        bibeeko ti i % 3 == 0 se
           pe(sope, "fizz")
        bibeeko 
           pe(sope, i)
        pari 
        i = i+  1
     pari
pari 

pe(fizzbuzz, 20)
```

### 9.3 Factorial Function
```
-- Calculate factorial using recursion
ise(factorial, n) 
    ti n dogba 1 se
        pada: 1
    pari 
    pada: n * pe(factorial, n-1)
pari

-- Test the factorial function
fun i lati 1 de 10 ifikun 1 se
    pe(sope, "factorial" ,i , "je" , pe(factorial, i))
pari
```

### 9.4 Array Manipulation
```
   fi [1, 2, 3, 4] si array
   pe(sope, array)
   -- change a value
   fi 20 si array[2]
   pe(sope, array)
```

## 10. Grammar Reference

```
<program> ::= <statement_list>

<statement_list> ::= <statement>
                  | <statement> <statement_list>

<statement> ::= <assignment>
              | <if_statement>
              | <while_statement>
              | <for_statement>
              | <function_definition>
              | <expression_statement>
              | <return_statement>

<assignment> ::= <identifier> "=" <expression>
               | <expression>"["<expression>"]" "=" <expression>
               | "fi" <expression> "si" <identifier>
               | "fi" <expression> "si" <expression>"["<expression>"]"

<if_statement> ::= "ti" <expression> "se" <statement_list> "pari" 
                 | "ti" <expression> "se" <statement_list> "bibeeko" "se" <statement_list> "pari" 
                 | "ti" <expression> "se" <statement_list> ("bibeeko" "ti" <expression> "se" <statement_list>)* "pari" 

<while_statement> ::= "nigbati" <expression> "se" <statement_list> "pari" 

<for_statement> ::= "fun" <identifier> "lati" <expression> "de" <expression> ("ifikun" <expression>)? "se" <statement_list> "pari" 

<function_definition> ::= "ise" "(" <identifier> ("," <identifier>)* ")" "se" <statement_list> "pari" 

<expression_statement> ::= <expression>

<return_statement> ::= "pada:" <expression>

<expression> ::= <noomba>
              | <oro>
              | <ooto>
              | <iro>
              | <identifier>
              | <expression>"["<expression>"]"
              | <function_call>
              | <expression> <binary_operator> <expression>
              | <unary_operator> <expression>
              | "(" <expression> ")"

<function_call> ::= "pe" "(" <identifier> ("," <expression>)* ")"

<binary_operator> ::= "+" | "-" | "*" | "/" | "//" | "%" | "^" | ">" | "<" | "=="
                   | ">=" | "<=" | "!=" | "ati" | "tabi" | "dogba" | "ko" "dogba"
                   | "|" | "&"

<unary_operator> ::= "-"
```

## 11. TODO

This specification defines the syntax and semantics of the Yoruba programming language. Implementations should consider the following. The Following are other things to add to the language in future:

1. **Character Encoding**: Use UTF-8 to properly support Yoruba-specific characters.

2. **Error Handling**: provide clear error messages in Yoruba where possible.

3. **Standard Library Extensions**: Add Standard Library to extend the language.

4. **Performance Considerations**: Add optimization features like computed Goto, Nan-boxing.

5.  **Extend Data Types**: Add more data types like Hash Table, Object and Class

6. **Garbage Collection**:  Add support for garbage collection and optimized resource management

5. **Development Tools**: Consider providing tools such as syntax highlighters, linters, debuggers that support the language.
