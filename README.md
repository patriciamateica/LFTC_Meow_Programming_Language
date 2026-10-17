# Meow Programming Language


Meow programming language is a small, domain-specific, language that describes how a cat parent would take care of their cat pet. Its primary use case is to allow the cat parent to record information about their cats (like age, weight, how hungry they are, how many treats they earned etc.) and reports are printed, using the cat themed keywords.

The datatypes used are: the number (keyword: treats). It is a non-negative integer that can show hunger level, age or treat count. The list is defined as the keyword "friend" which contains an ordered collection of numbers (e.g. the number of cats in one's household).

Mention: strings are not a datatype here. The letters are only used for writing text between double quotes inside `meow` and `zoomies`. They cannot be stored in a variable or a list right now.


**Statements and their keywords**

| Statement          | Keyword             | Category                | Role                               |
| ------------------ | ------------------- | ----------------------- | ---------------------------------- |
| List declaration   | `friend`            | declaration             | Creates the user-defined type      |
| Number declaration | `treats`            | declaration             | Creates the simple type            |
| Assignment         | `=`                 | assignment (required)   | Changes a number or a list element |
| Input              | `adopt`             | input (required)        | Reads a value from the owner       |
| Output             | `meow`              | output (required)       | Prints messages and values         |
| Conditional        | `sniff` / `hiss`    | conditional (required)  | Chooses between two actions        |
| Loop               | `biscuits ... made` | loop (required)         | Visits every element of a list     |
| Append             | `paw`               | list operation          | Adds an element                    |
| Map                | `cuddle`            | list operation          | Transforms every element           |
| Filter             | `scratch`           | list operation          | Keeps only matching elements       |
| Sort               | `purr`              | list operation          | Orders the list                    |
| Unique             | `baby`              | list operation          | Removes duplicates                 |
| Join               | `zoomies`           | list operation / output | Prints the list with a separator   |
| Size               | `chunky`            | list operation          | Measures the size of a list        |
