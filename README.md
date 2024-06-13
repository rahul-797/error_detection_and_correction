
# ISBN Validator and Auto-Correction Tools

![License](https://img.shields.io/badge/license-MIT-blue.svg)

## Table of Contents

- [Features](#features)
- [Usage](#usage)
  - [Validating ISBN-10](#validating-isbn-10)
  - [Generating Corrected ISBN-11](#generating-corrected-isbn-11)
  - [Correcting ISBN-11](#correcting-isbn-11)

## Features

- **ISBN-10 Validation**: Verify the validity of an ISBN-10 number using `checkISBN.cpp`.
- **ISBN-11 Generation**: Create an ISBN-11 from an ISBN-10 with an added error-detecting digit using `generateISBN.cpp`.
- **Error Detection and Correction**: Detect and correct single-digit errors in an ISBN-11 with `correctISBN.cpp`.

## Usage

### Validating ISBN-10

Use `checkISBN` to validate an ISBN-10 number.

```bash
./checkISBN
Enter ISBN-10 code: 0471958697
```

Replace `0471958697` with the ISBN-10 you want to validate. The program will output whether the ISBN is valid or not.

### Generating ISBN with correction codes

Use `generateISBN` to create an ISBN from a valid ISBN-10.

```bash
./generateISBN
Enter ISBN-10 code: 0471958697
```

Replace `0471958697` with the ISBN-10 you want to convert. The program will output the new ISBN with an added error-detecting digit.

### Correcting ISBN

Use `correctISBN` to correct a single-digit error in the newly created ISBN.

```bash
./correctISBN
Enter ISBN code: 04719586973
```

Replace `04719586973` with the ISBN generated by ./generateISBN that may contain an error. The program will correct the ISBN and return the original ISBN-10.



