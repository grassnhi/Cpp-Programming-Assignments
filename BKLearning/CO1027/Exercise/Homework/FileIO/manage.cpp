/*
Write a function void manage(string library, string book, string author) 
that reads into 3 files library.txt and book.txt and author.txt.

In there:

The file library.txt contains information about the libraries, including: 
the first line contains a positive integer N which is the number of libraries surveyed. 
The next N lines each contain 6 values ​​separated by a space. For each row, 
the first value is the name of the Library (the name of the Library is unique), 
the other 5 values ​​are 5 positive integers, which are the IDs of the 5 books in that library.
     
Example:
          3

          LA 1 2 3 4 5

          LB 5 3 1 2 4

          LC 4 1 5 2 3

The file book.txt contains information about the books, including: 
the first line contains a positive integer M which is the number of titles in all libraries. 
The next M lines each contain 3 values ​​(separated by a space) that have the following meaning: 
the first value is a positive integer representing Book Number (ID - ID is unique), 
the 2nd value is the year of manufacture and the last value is the category.
    
Example:
          5

          1 2000 A

          2 2001 B

          3 1993 D

          4 1997 A

          5 1995 C

The author.txt file contains information about the authors, including: 
the first line contains a positive integer P which is the number of all the authors of 
the books in the library (assuming a book is authored by only one author. fake). 
The next P lines each contain the following values ​​(values ​​are separated by a space): 
the first value is the Author's Name, the remaining values ​​are the IDs of the books 
that the author has read. that was composed.
     
Example:
          3

          David 1 5

          John 3

          Henry 2 4

Determines if Library L contains any works by Author A, if so, outputs "True" to the screen, 
otherwise outputs "False". With L and A entered from the keyboard.

Input:
    The 3 variables "library", "book" and "author" contain the names of the 3 files 
    "library.txt" and "book.txt" and "author.txt" respectively.

Output:
    "True" or "False" for the input.
*/