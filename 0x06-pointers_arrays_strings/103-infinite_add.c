#include "holberton.h"
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r) {
    int carry = 0;
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int max_len = (len1 > len2) ? len1 : len2;
    
    if (max_len + 1 > size_r) {
        // Not enough space in r to store the result
        return 0;
    }
    
    r[max_len + 1] = '\0'; // Set the null terminator at the end of the result string
    
    for (int i = 0; i < max_len; i++) {
        int d1 = (i < len1) ? n1[len1 - 1 - i] - '0' : 0; // Get the i-th digit from n1 (from the right)
        int d2 = (i < len2) ? n2[len2 - 1 - i] - '0' : 0; // Get the i-th digit from n2 (from the right)
        int sum = d1 + d2 + carry;
        carry = sum / 10;
        r[max_len - i] = (sum % 10) + '0'; // Set the i-th digit of the result (from the right)
    }
    
    if (carry) {
        // There's a carry left after the loop
        if (max_len + 2 > size_r) {
            // Not enough space in r to store the result with the carry
            return 0;
        }
        r[0] = carry + '0'; // Set the leftmost digit of the result to the carry
        return &r[0];
    }
    
    return &r[1]; // Return a pointer to the result, skipping the leftmost 0 (if any)
}

