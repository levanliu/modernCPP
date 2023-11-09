#### Regular Expression

##### Special Character

| Symbol | Description                                                                                                                                                                                                                                                                                  |
| :----- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| $      | Matches the end position of the input string.                                                                                                                                                                                                                                                |
| (,)    | Marks the start and end of a subexpression. Subexpressions can be obtained for later use.                                                                                                                                                                                                    |
| *      | Matches the previous subexpression zero or more times.                                                                                                                                                                                                                                       |
| +      | Matches the previous subexpression one or more times.                                                                                                                                                                                                                                        |
| .      | Matches any single character except the newline character \n.                                                                                                                                                                                                                                |
| [      | Marks the beginning of a bracket expression.                                                                                                                                                                                                                                                 |
| ?      | Matches the previous subexpression zero or one time, or indicates a non-greedy qualifier.                                                                                                                                                                                                    |
| \      | Marks the next character as either a special character, or a literal character, or a backward reference, or an octal escape character. For example, n Matches the character n. \n matches newline characters. The sequence \\ Matches the '\' character, while \( matches the '(' character. |
| ^      | Matches the beginning of the input string, unless it is used in a square bracket expression, at which point it indicates that the set of characters is not accepted.                                                                                                                         |
| {      | Marks the beginning of a qualifier expression.                                                                                                                                                                                                                                               |
| \|     | Indicates a choice between the two.                                                                                                                                                                                                                                                          |



##### Quantifiers

| Symbol | Description                                                                                                                                                                                                                                                                                 |
| :----- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| *      | matches the previous subexpression zero or more times. For example, foo* matches fo and foooo. * is equivalent to {0,}.                                                                                                                                                                     |
| +      | matches the previous subexpression one or more times. For example, foo+ matches foo and foooo but does not match fo. + is equivalent to {1,}.                                                                                                                                               |
| ?      | matches the previous subexpression zero or one time. For example, Your(s)? can match Your in Your or Yours. ? is equivalent to {0,1}.                                                                                                                                                       |
| {n}    | n is a non-negative integer. Matches the determined n times. For example, o{2} cannot match o in for, but can match two o in foo.                                                                                                                                                            |
| {n,}   | n is a non-negative integer. Match at least n times. For example, o{2,} cannot match o in for, but matches all o in foooooo. o{1,} is equivalent to o+. o{0,} is equivalent to o*.                                                                                                          |
| {n,m}  | m and n are non-negative integers, where n is less than or equal to m. Matches at least n times and matches up to m times. For example, o{1,3} will match the first three o in foooooo. o{0,1} is equivalent to o?. Note that there can be no spaces between the comma and the two numbers. |



