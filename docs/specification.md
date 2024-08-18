# A SPECIFICATION OF YORUBA-BASED PROGRAMMING LANGUAGE 

###    Abstract

This is a basic outline of the specification of the Yoruba programming language. The language aims to provide a syntactic and semantic framework integrating Yoruba keywords and lexicon to form a programming language making programming more intuitive for Yoruba speaker. The Yoruba programming language is a simple interpreted lightweight language. It support aspects of procedural programming like functions, expressions, and statements. 

### 1. Lexical Conventions
A program in the language is divided into logical lines. Logical lines are terminated using the token NEWLINE `'\n'` `'\r\n'` or a semicolon `';'`.  A statement cannot be terminated into multiple lines unless if the lines are ended with a '\'. The language is also case sensitive. Therefore ati is different from Ati in the language.

 -  **Identifier:** Identifiers are formed by a letter  followed by a  sequences of letters or digit. Letters can include Yoruba-specific characters such as `ẹ`, `ọ`, and `ṣ`. An Identifier cannot be a reserved keyword.
      - Examples: `aṣoju`, `ise`, `ọjọ`
      
 - **Keywords:** The following words are reserved:
    ```
   tabi   ati    pari    nigbati	
    ise    se     fi      bibeeko
    dogba  si     pada    agbegbe
    ooto   iro    ko      ita
    nigba
    ```
    The following strings denotes other tokens 
	```
	+ (plus)  - (subtract)  * (multiply)  / (divide)
	% (modulus) < (LT)   <= (LTEQ)  == (equals)	
	>= (GTEQ)  > (GT)  ^(exponent)
	```
	
- **Comments**: Comments and white space (space tab) are by default discarded from the program by the lexical analyzer. A comment follows lua convention for denoting comments in lua, using \-\- for a single line comment and \-\-\[\[ \]\] for  mulitlines comments.

- **Data Types:** 
	- **Basic Types:**
		- **noomba**: Integer and floating points number.
		- **oro:** String of characters
		- **ooto:** a boolean type of true
		- **iro:**   a boolean type of false
	- **Composite Types:**
		The language support just a single composite type **apeere** (which is an array representation).
		
- **Literals**: Literals are constants that can be either a string of character **oro** or numbers (Integers and floating point number) **noomba**.

	
### Expressions:

Expressions yield a value and can be used as an operands of operators unless they differ in types and the operands does not support the types.
The basic expression are:
```
expr:    noomba
    | 	 ooro
    |    variable
    |    function (arg)
    |    expr binop expr
    |    unop expr
    |    ( expr )
```
	
`binop` refers to binary operations such as arithmetic and comparison operators. `unop` are unary operators which for now, is only the `'-'` negate operator.

### 3. Syntax
- **Assignment:**
	A variable is a container for storing values.  A variable can be declared with
	```
	<var> = <expr>
	```
	Or using
	[Experimental Features](#experimental-features)
	```
	Fi <expr> si <var>
	```
	A variable declared in a function by default is local to the function. But a variable can be made global in a function by specifying it using:
	```
	agbegbe <var>: ita
	```
- **Control Structures:**

- **If Statement:**
		The basic if-else statement is supported for control structures. The condition in the statement is evaluated and branched to if the evaluation is true.
	```
	ti <cond> se
		...
	pari ise
	```
	it can also have supporting else statement written 
	```
	ti <cond> se
		...
	bibeeko 
		...
	pari ise
	```
	both statement can be combined to form multiple if-else statement
	```
	ti <cond> se
		...
	bibeeko ti <cond>
		...
	bibeeko ti <cond>
		...
	pari ise
	```
-	**Loop:**
	There are two syntax flavours of loops:
	- The first is a type of while loop
		```
		nigbati <cond> se
		...
		pari ise
		```
	- The other type of loop has a similar syntax with the for loop
		```
		fun <var> lati <start> si <end> ipele <step> se
			...
		pari ise
		```
		
-	**Function**
	The syntax for defining function is 
	```
	ise <func_name>(parameters) se
		...
	pari ise
	```
	A function is an expression that can either return a value or not. Function has a keyword ***pada*** which can only be used in a function to return a value or to make an early exit from the function.
	The following examples show how to use the ***pada*** keyword.
	```
	ise aropo(x, y) se
		pada: x + y
	pari ise
	```
	
	```
	ise ikinni(oruko) se
		ko("Bawo ni" + oruko)
	pari ise
	```
	Variables defined in a function are local to the function unless it is stated to be global
	
- **Operators**
	The following arithmetic operators are supported:

		> +: addition
		> -: subtraction
		> *: multiplication 
		> /: float division 
		> //: floor division 
		> % : modulo 
		> ^: exponentiation
		> -: unary minus
		
	**Logical Operators:**
	The logical operators are ```ati``` ```tabi``` and they return ```ooto``` (true) or ```iro``` (false) based on the evaluation of the expression. Here are some example of usage:
	```
	fi 20 si x
	x >= 20 ati x <= 30										--ooto
	fi "omolola" si oruko					
	oruko dogba "daniel" tabi oruko doba "joseph"			--iro
	```
	**Relational Operators:**
	```
	The following relational operators are supported:
	 \>=	Greater than or equals to
		\> Greater than
		\<= Less than or equals to 
	 < Less than
	 == equals to
	 != not equal
	```
	
	>[Experimental Features](#experimental-features)	
	
	> dogba (equals to)
	
	> ko dogba (not equal)

**Bitwise Operator:**
> `|` Bitwise or 

> `&` Bitwise and

**Concatenation:**
A string can be concatenated with other strings using the ```+``` operator. Strings can only be concatenated with other string. Concatenation with other data types leads to an error.

### Example programs 
```

```



### Grammar Reference
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
               | "fi" <expression> "si" <identifier>

<if_statement> ::= "ti" <expression> "se" <statement_list> "pari" "ise"
                 | "ti" <expression> "se" <statement_list> "bibeeko" <statement_list> "pari" "ise"
                 | "ti" <expression> "se" <statement_list> ("bibeeko" "ti" <expression> "se" <statement_list>)* "pari" "ise"

<while_statement> ::= "nigba" "ti" <expression> "se" <statement_list> "pari" "ise"

<for_statement> ::= "fun" <identifier> "nigba" <expression> "si" <expression> ("ka" <expression>)? "se" <statement_list> "pari" "ise"

<function_definition> ::= "ise" <identifier> "(" <parameter_list>? ")" "se" <statement_list> "pari" "ise"

<parameter_list> ::= <identifier>
                  | <identifier> "," <parameter_list>

<expression_statement> ::= <expression>

<return_statement> ::= "pada:" <expression>

<expression> ::= <noomba>
              | <oro>
              | <identifier>
              | <function_call>
              | <expression> <binary_operator> <expression>
              | <unary_operator> <expression>
              | "(" <expression> ")"

<function_call> ::= <identifier> "(" <argument_list>? ")"

<argument_list> ::= <expression>
                 | <expression> "," <argument_list>

<binary_operator> ::= "+" | "-" | "*" | "/" | "%" | "^" | ">" | "<" | "=="
                   |  ">=" | "<=" | "ati" | "tàbí"pe

```


## **Experimental Features**
The following features are experimental and are create to test the incorporation of Yoruba words in common programming syntatic sugar
```
Fi <expr> si <var>  		--assignment
x dogba y					--equal comparison
x ko dogba y				--not equal comparison
```
More experimental features will be added to test the how intuitive the usability of the language for a Yoruba speaker
	