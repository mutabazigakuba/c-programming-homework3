# c-programming-homework3

Undergraduates & Graduate Students:
For this assignment, you will be writing a single C program. You will create a folder which contains the program and then zip the folder for submission to blackboard. Please be sure to document your program appropriately. You must rename the file using your last name followed by your first name followed by a dash followed by the assignment name (For instance, this is homework3, so I’d turn it in as RuthMichael- Homework3.zip)
You will write a program which asks for a text file and a offset and encrypts/decrypts the given file using the given offset (Caesar Cypher).
1. (10%) Your program should always operate in a loop, continually asking if the user wishes to continue until the user enters “no”, “No”, “n”, or “N.
2. (10%) If the user doesn’t wish to quit, your program should ask the user if they want to encrypt or decrypt a file. The user should enter either “encrypt” or “decrypt” (anything else, and you ask again.)
3. (40%) if the user wishes to encrypt:
a. (5%)
b. (5%)
c. (5%)
d. (5%)
Ask the user for the file name
Ask the user for an offset (offset)
Ask the user for the output file name
Encrypt the input text file using the following scheme:
i. Select a random number between 0 and 25 (offset2)
ii. In the output file, write the random offset using the character code that represents
the random number (‘a’ -> 0, ‘b’ -> 1 and so on) on a line by itself.
iii. Now loop through the file, line by line, character by character, replacing characters
using the following scheme:
1. If the character is an alphabetic character (a-z or A-Z), alternate between the
two offsets offset (given) and offset2 replacing each character with the character offset
a. If your offset is a 3 and the current character is ‘a’, then ‘a’ + 3 = ‘d’ so you’d
replace ‘a’ with ‘d’.
b. Hint: don’t forget to wrap around 26 characters. IE, ‘z’ + 1 = ‘a’.
2. If the character is NOT an alphabetic character (a-z or A-Z), leave the character alone (IE, no replacement).
iv. Close the input and output files.
4. (40%) if the user wishes to decrypt (decode):
a. (5%)
b. (5%)
c. (5%)
d. (5%)
Ask the user for the file name
Ask the user for an offset (offset)
Ask the user for the output file name
Decrypt the input text file using the following scheme:
i. Read the input text’s first line and the character on the line to determine offset2.
ii. Now loop through the file, line by line, character by character, replacing characters
using the following scheme:
1. If the character is an alphabetic character (a-z or A-Z), alternate between the two offsets offset (given) and offset2 replacing each character with the character offset
a. If your offset is a 3 and the current character is ‘a’, then ‘d’ - 3 = ‘a’ so you’d
replace ‘d’ with ‘a’.
b. Hint: don’t forget to wrap around 26 characters. IE, ‘a’ - 1 = ‘z’.
2. If the character is NOT an alphabetic character (a-z or A-Z), leave the character alone (IE, no replacement).
iii. Close the input and output files.
Graduate Students (& Undergraduate students for extra credit +50):
 (50%) In the encryption and decryption processes, offer the user a choice between a Caesar cipher
(above) and a Random replacement cipher (below):
o o
o
Note:
  
 
(10%) If the user selects “decrypt” or “encrypt”, you must ask whether you want Caesar or Random
(20%) Encrypt (for Random Replacement):
1) Create an array consisting of letters ‘a’ through ‘z’
2) Shuffle them (randomly replace the characters in the array 26*4 times)
3) Write them to output file using the offset given (still need the offset) on a line by
themselves.
4) Now, as you read through the input file, replace each character (only if alphabetic) with
the letter corresponding with its position. (for instance if our array consists of ‘sdfk...’ and
the letter to replace is ‘a’, ‘a’ -> 0, so array[0] which is ‘s’; (in this case)
(20%) Decrypt (for Random Replacement):
1) Read the first line of the input file and using the given offset store the array of characters.
2) Now, as you read through the input file, replace each character (only if alphabetic) with the letter corresponding with its position. (for instance if our array consists of ‘sdfk...’ and
the letter to replace is ‘s’, ‘s’ is at position 0, so we replace ‘s’ with ‘a’; (in this case)
If you don’t turn in the file in the correct format (ZIP), I will take 10 points off the total score. If you don’t name the files or methods correctly, I will take 10 points off the total score.
You SHOULD NOT need to use material learned outside this class. If you choose to do so, you will earn NO points on this homework.
If someone else turns in your homework, you both get a zero whether or NOT you know each other.
Do NOT try to do this last minute!
