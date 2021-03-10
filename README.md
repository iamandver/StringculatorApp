# Stringculator
A calculator console app that takes a simple math equation, and returns the answer.

Knows bugs:
- a syntax error causes the stored result to be overwritten by 0

ToDo:
- implementing the recognition of parenthesis


A brief explanation of components:

Calculator
Nothing more than a wrapper that gets receives the input from the user and delegates it to other translation units.

InputParser
Responsible for parsing the input string. Its main purpose is to separate numbers from math operations and wrap them each into an EquationNode. Meanwhile it also gets rid of spaces and any other unrecognised characters.

EquationNode
A wrapper for the individual components of the input equation. It has getter and setter member functions and also a few bools for determining whether it is a number or a mathematical operation.

OperationMapper.h
A char / function matrix. Responsible for delegating the correct mathematical algorithm to EquationNodes that function as operations by taking a char and returning a function.

EquationTree
This is the main algorithm that builds the tree structure based on the EquationNode values, and computes the result. It uses a special kind of unbalanced tree structure that grows in various directions based on the order of precedence.
