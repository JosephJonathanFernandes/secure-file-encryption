#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

// Caesar Cipher Encryption/Decryption
void caesarCipher(char *text, int key) {
    for (int i = 0; text[i]; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((text[i] - 'a' + key) % 26) + 'a';
    }
}

// XOR Cipher Encryption/Decryption
void xorCipher(char *text, char key) {
    for (int i = 0; text[i]; i++) {
        if (text[i] != '\n') // Preserve newlines
            text[i] ^= key;
    }
}

void processFile(const char *input, const char *output, int caesarKey, char xorKey, int isEncrypt) {
    FILE *in = fopen(input, "r");
    if (!in) {
        printf("Error opening input file.\n");
        return;
    }

    FILE *out = fopen(output, "w");
    if (!out) {
        printf("Error creating output file.\n");
        fclose(in);
        return;
    }

    char buffer[MAX];
    while (fgets(buffer, MAX, in)) {
        if (isEncrypt) {
            caesarCipher(buffer, caesarKey);
            xorCipher(buffer, xorKey);
        } else {
            xorCipher(buffer, xorKey);
            caesarCipher(buffer, 26 - caesarKey);
        }
        fputs(buffer, out);
    }

    fclose(in);
    fclose(out);
    printf("File processed successfully! Output: %s\n", output);
}

int main() {
    int choice, caesarKey;
    char inputFile[100], outputFile[100], xorKey;
    char cont = 'y';

    printf("🔐 Secure File System using Caesar + XOR Encryption 🔐\n");

    while (cont == 'y' || cont == 'Y') {
        printf("\n1. Encrypt a File\n2. Decrypt a File\nEnter your choice: ");
        scanf("%d", &choice);

        printf("Enter input filename: ");
        scanf("%s", inputFile);

        printf("Enter output filename: ");
        scanf("%s", outputFile);

        do {
            printf("Enter Caesar Cipher key (1-25): ");
            scanf("%d", &caesarKey);
        } while (caesarKey < 1 || caesarKey > 25);

        printf("Enter XOR key (single character): ");
        scanf(" %c", &xorKey);

        if (choice == 1) {
            processFile(inputFile, outputFile, caesarKey, xorKey, 1);
        } else if (choice == 2) {
            processFile(inputFile, outputFile, caesarKey, xorKey, 0);
        } else {
            printf("Invalid choice!\n");
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &cont);
    }

    printf("Thank you for using the Secure File System.\n");
    return 0;
}
