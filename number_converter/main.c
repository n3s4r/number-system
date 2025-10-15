/**
 * @file number_converter.c
 * @brief A C program for converting numbers between different bases (Binary, Decimal, Octal, Hexadecimal).
 *
 * This program provides a command-line menu for users to select the type
 * of conversion they want to perform. It includes functions for all
 * direct conversions between these number systems.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

// --- Function Prototypes ---

// Conversion Functions
long long binaryToDecimal(char binary[]);
void decimalToBinary(long long decimal, char result[]);
void binaryToHexadecimal(char binary[], char result[]);
void hexadecimalToBinary(char hex[], char result[]);
void binaryToOctal(char binary[], char result[]);
void octalToBinary(char octal[], char result[]);
long long hexadecimalToDecimal(char hex[]);
void decimalToHexadecimal(long long decimal, char result[]);
long long octalToDecimal(char octal[]);
void decimalToOctal(long long decimal, char result[]);

// Helper function to reverse a string
void reverseString(char *str);

// --- Main Function ---

int main() {
    int choice;
    char binaryInput[65], hexInput[17], octalInput[23];
    char binaryOutput[65], hexOutput[17], octalOutput[23];
    long long decimalInput, decimalOutput;

    while (1) {
        // Display the menu
        printf("\n--- Number System Converter ---\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Binary to Hexadecimal\n");
        printf("4. Hexadecimal to Binary\n");
        printf("5. Binary to Octal\n");
        printf("6. Octal to Binary\n");
        printf("7. Decimal to Hexadecimal\n");
        printf("8. Hexadecimal to Decimal\n");
        printf("9. Decimal to Octal\n");
        printf("10. Octal to Decimal\n");
        printf("11. Hexadecimal to Octal\n");
        printf("12. Octal to Hexadecimal\n");
        printf("0. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");

        // Get user choice
        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        // Process the choice
        switch (choice) {
            case 1:
                printf("Enter a binary number: ");
                scanf("%s", binaryInput);
                printf("Decimal: %lld\n", binaryToDecimal(binaryInput));
                break;
            case 2:
                printf("Enter a decimal number: ");
                scanf("%lld", &decimalInput);
                decimalToBinary(decimalInput, binaryOutput);
                printf("Binary: %s\n", binaryOutput);
                break;
            case 3:
                printf("Enter a binary number: ");
                scanf("%s", binaryInput);
                binaryToHexadecimal(binaryInput, hexOutput);
                printf("Hexadecimal: %s\n", hexOutput);
                break;
            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexInput);
                hexadecimalToBinary(hexInput, binaryOutput);
                printf("Binary: %s\n", binaryOutput);
                break;
            case 5:
                printf("Enter a binary number: ");
                scanf("%s", binaryInput);
                binaryToOctal(binaryInput, octalOutput);
                printf("Octal: %s\n", octalOutput);
                break;
            case 6:
                printf("Enter an octal number: ");
                scanf("%s", octalInput);
                octalToBinary(octalInput, binaryOutput);
                printf("Binary: %s\n", binaryOutput);
                break;
            case 7:
                 printf("Enter a decimal number: ");
                scanf("%lld", &decimalInput);
                decimalToHexadecimal(decimalInput, hexOutput);
                printf("Hexadecimal: %s\n", hexOutput);
                break;
            case 8:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexInput);
                printf("Decimal: %lld\n", hexadecimalToDecimal(hexInput));
                break;
            case 9:
                printf("Enter a decimal number: ");
                scanf("%lld", &decimalInput);
                decimalToOctal(decimalInput, octalOutput);
                printf("Octal: %s\n", octalOutput);
                break;
            case 10:
                printf("Enter an octal number: ");
                scanf("%s", octalInput);
                printf("Decimal: %lld\n", octalToDecimal(octalInput));
                break;
            case 11: // Hexadecimal to Octal (via Binary)
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexInput);
                hexadecimalToBinary(hexInput, binaryOutput);
                binaryToOctal(binaryOutput, octalOutput);
                printf("Octal: %s\n", octalOutput);
                break;
            case 12: // Octal to Hexadecimal (via Binary)
                printf("Enter an octal number: ");
                scanf("%s", octalInput);
                octalToBinary(octalInput, binaryOutput);
                binaryToHexadecimal(binaryOutput, hexOutput);
                printf("Hexadecimal: %s\n", hexOutput);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// --- Function Definitions ---

/**
 * @brief Reverses a given string in place.
 * @param str The string to be reversed.
 */
void reverseString(char *str) {
    int length = strlen(str);
    int i, j;
    char temp;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}


/**
 * @brief Converts a binary string to its decimal equivalent.
 * @param binary The input binary string.
 * @return The decimal equivalent as a long long.
 */
long long binaryToDecimal(char binary[]) {
    long long decimal = 0;
    int length = strlen(binary);
    int power = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

/**
 * @brief Converts a decimal number to its binary string equivalent.
 * @param decimal The input decimal number.
 * @param result The output character array to store the binary string.
 */
void decimalToBinary(long long decimal, char result[]) {
    int index = 0;
    if (decimal == 0) {
        strcpy(result, "0");
        return;
    }
    while (decimal > 0) {
        result[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    result[index] = '\0';
    reverseString(result);
}

/**
 * @brief Converts a hexadecimal character to its integer value.
 * @param c The hexadecimal character.
 * @return The integer value (0-15).
 */
int hexCharToInt(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1; // Invalid character
}

/**
 * @brief Converts an integer (0-15) to its hexadecimal character.
 * @param n The integer value.
 * @return The hexadecimal character ('0'-'9', 'A'-'F').
 */
char intToHexChar(int n) {
    if (n >= 0 && n <= 9) return n + '0';
    return n - 10 + 'A';
}


/**
 * @brief Converts a hexadecimal string to its decimal equivalent.
 * @param hex The input hexadecimal string.
 * @return The decimal equivalent as a long long.
 */
long long hexadecimalToDecimal(char hex[]) {
    long long decimal = 0;
    int length = strlen(hex);
    int power = 0;
    for (int i = length - 1; i >= 0; i--) {
        decimal += hexCharToInt(hex[i]) * pow(16, power);
        power++;
    }
    return decimal;
}

/**
 * @brief Converts a decimal number to its hexadecimal string equivalent.
 * @param decimal The input decimal number.
 * @param result The output character array to store the hexadecimal string.
 */
void decimalToHexadecimal(long long decimal, char result[]) {
    int index = 0;
    if (decimal == 0) {
        strcpy(result, "0");
        return;
    }
    while (decimal > 0) {
        result[index++] = intToHexChar(decimal % 16);
        decimal /= 16;
    }
    result[index] = '\0';
    reverseString(result);
}

/**
 * @brief Converts an octal string to its decimal equivalent.
 * @param octal The input octal string.
 * @return The decimal equivalent as a long long.
 */
long long octalToDecimal(char octal[]) {
    long long decimal = 0;
    int length = strlen(octal);
    int power = 0;
    for (int i = length - 1; i >= 0; i--) {
        decimal += (octal[i] - '0') * pow(8, power);
        power++;
    }
    return decimal;
}

/**
 * @brief Converts a decimal number to its octal string equivalent.
 * @param decimal The input decimal number.
 * @param result The output character array to store the octal string.
 */
void decimalToOctal(long long decimal, char result[]) {
    int index = 0;
     if (decimal == 0) {
        strcpy(result, "0");
        return;
    }
    while (decimal > 0) {
        result[index++] = (decimal % 8) + '0';
        decimal /= 8;
    }
    result[index] = '\0';
    reverseString(result);
}


/**
 * @brief Converts a hexadecimal string to its binary string equivalent.
 * @param hex The input hexadecimal string.
 * @param result The output character array to store the binary string.
 */
void hexadecimalToBinary(char hex[], char result[]) {
    result[0] = '\0'; // Start with an empty string
    for (int i = 0; hex[i] != '\0'; i++) {
        switch (toupper(hex[i])) {
            case '0': strcat(result, "0000"); break;
            case '1': strcat(result, "0001"); break;
            case '2': strcat(result, "0010"); break;
            case '3': strcat(result, "0011"); break;
            case '4': strcat(result, "0100"); break;
            case '5': strcat(result, "0101"); break;
            case '6': strcat(result, "0110"); break;
            case '7': strcat(result, "0111"); break;
            case '8': strcat(result, "1000"); break;
            case '9': strcat(result, "1001"); break;
            case 'A': strcat(result, "1010"); break;
            case 'B': strcat(result, "1011"); break;
            case 'C': strcat(result, "1100"); break;
            case 'D': strcat(result, "1101"); break;
            case 'E': strcat(result, "1110"); break;
            case 'F': strcat(result, "1111"); break;
            default: printf("Invalid hexadecimal digit %c\n", hex[i]); return;
        }
    }
}

/**
 * @brief Converts a binary string to its hexadecimal string equivalent.
 * @param binary The input binary string.
 * @param result The output character array to store the hexadecimal string.
 */
void binaryToHexadecimal(char binary[], char result[]) {
    int binLen = strlen(binary);
    int hexIndex = 0;
    int padding = binLen % 4;
    if (padding != 0) {
        padding = 4 - padding;
    }

    char paddedBin[binLen + padding + 1];
    for (int i = 0; i < padding; i++) {
        paddedBin[i] = '0';
    }
    strcpy(paddedBin + padding, binary);

    for (int i = 0; i < strlen(paddedBin); i += 4) {
        char group[5];
        strncpy(group, paddedBin + i, 4);
        group[4] = '\0';

        if (strcmp(group, "0000") == 0) result[hexIndex++] = '0';
        else if (strcmp(group, "0001") == 0) result[hexIndex++] = '1';
        else if (strcmp(group, "0010") == 0) result[hexIndex++] = '2';
        else if (strcmp(group, "0011") == 0) result[hexIndex++] = '3';
        else if (strcmp(group, "0100") == 0) result[hexIndex++] = '4';
        else if (strcmp(group, "0101") == 0) result[hexIndex++] = '5';
        else if (strcmp(group, "0110") == 0) result[hexIndex++] = '6';
        else if (strcmp(group, "0111") == 0) result[hexIndex++] = '7';
        else if (strcmp(group, "1000") == 0) result[hexIndex++] = '8';
        else if (strcmp(group, "1001") == 0) result[hexIndex++] = '9';
        else if (strcmp(group, "1010") == 0) result[hexIndex++] = 'A';
        else if (strcmp(group, "1011") == 0) result[hexIndex++] = 'B';
        else if (strcmp(group, "1100") == 0) result[hexIndex++] = 'C';
        else if (strcmp(group, "1101") == 0) result[hexIndex++] = 'D';
        else if (strcmp(group, "1110") == 0) result[hexIndex++] = 'E';
        else if (strcmp(group, "1111") == 0) result[hexIndex++] = 'F';
    }
    result[hexIndex] = '\0';
}

/**
 * @brief Converts an octal string to its binary string equivalent.
 * @param octal The input octal string.
 * @param result The output character array to store the binary string.
 */
void octalToBinary(char octal[], char result[]) {
    result[0] = '\0';
    for (int i = 0; octal[i] != '\0'; i++) {
        switch (octal[i]) {
            case '0': strcat(result, "000"); break;
            case '1': strcat(result, "001"); break;
            case '2': strcat(result, "010"); break;
            case '3': strcat(result, "011"); break;
            case '4': strcat(result, "100"); break;
            case '5': strcat(result, "101"); break;
            case '6': strcat(result, "110"); break;
            case '7': strcat(result, "111"); break;
            default: printf("Invalid octal digit %c\n", octal[i]); return;
        }
    }
}


/**
 * @brief Converts a binary string to its octal string equivalent.
 * @param binary The input binary string.
 * @param result The output character array to store the octal string.
 */
void binaryToOctal(char binary[], char result[]) {
    int binLen = strlen(binary);
    int octIndex = 0;
    int padding = binLen % 3;
    if (padding != 0) {
        padding = 3 - padding;
    }

    char paddedBin[binLen + padding + 1];
    for (int i = 0; i < padding; i++) {
        paddedBin[i] = '0';
    }
    strcpy(paddedBin + padding, binary);

    for (int i = 0; i < strlen(paddedBin); i += 3) {
        char group[4];
        strncpy(group, paddedBin + i, 3);
        group[3] = '\0';

        if (strcmp(group, "000") == 0) result[octIndex++] = '0';
        else if (strcmp(group, "001") == 0) result[octIndex++] = '1';
        else if (strcmp(group, "010") == 0) result[octIndex++] = '2';
        else if (strcmp(group, "011") == 0) result[octIndex++] = '3';
        else if (strcmp(group, "100") == 0) result[octIndex++] = '4';
        else if (strcmp(group, "101") == 0) result[octIndex++] = '5';
        else if (strcmp(group, "110") == 0) result[octIndex++] = '6';
        else if (strcmp(group, "111") == 0) result[octIndex++] = '7';
    }
    result[octIndex] = '\0';
}
