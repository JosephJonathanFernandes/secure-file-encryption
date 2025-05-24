Secure File Encryption
A simple C program that encrypts and decrypts files using a combination of Caesar Cipher and XOR Cipher for enhanced security.

 Features
- Encrypt text files using Caesar and XOR ciphers combined.
- Decrypt files encrypted with this tool.
- Command-line interface for easy user interaction.
- Supports large text files up to 1024 characters per line.
- Customizable keys for both ciphers.

 How It Works

1. Caesar Cipher shifts each alphabetical character by a user-defined key (1-25).
2. XOR Cipher applies a bitwise XOR operation with a user-defined single-character key.
3. Encryption applies Caesar Cipher first, then XOR Cipher.
4. Decryption reverses XOR Cipher first, then applies the inverse Caesar Cipher.

 Requirements

- C compiler such as GCC
- Terminal or command prompt
- Basic knowledge of using command line
- Compilation Instructions

To compile the program, run the following command in your terminal:
gcc secure_file.c -o secure_file.exe

Usage Instructions
Run the compiled program:
./secure_file.exe

Example usage:
Secure File System using Caesar + XOR Encryption

1. Encrypt a File
2. Decrypt a File
Enter your choice: 1
Enter input filename: sample.txt
Enter output filename: encrypted.txt
Enter Caesar Cipher key (1-25): 4
Enter XOR key (single character): k
File processed successfully! Output: encrypted.txt

Do you want to continue (y/n)? n
Thank you for using the Secure File System.

Notes
Make sure the input file exists in the working directory or provide the full path.

The program only shifts alphabetical characters during Caesar encryption; other characters remain unchanged.

Keep the keys safe as you will need the same keys for decryption.

The maximum line size is 1024 characters due to buffer size.

Handles errors like file not found gracefully.

How to Contribute
Contributions are welcome! Feel free to:

Report bugs

Request new features

Fork the repo and submit pull requests

License
This project is licensed under the MIT License.

Author
Joseph Fernandes

Email: josephfernandes273@gmail.com

GitHub: JosephJonathanFernandes

Acknowledgments
Inspired by classic cryptographic techniques.
Thanks to all open source contributors who help beginners learn encryption and C programming.
Generative AI for helping with settling issues with errors in code

