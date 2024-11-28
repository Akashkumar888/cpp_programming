#include <limits.h>
#include <string.h>
#include <ctype.h>

int myAtoi(char *s) {
    int n = strlen(s);
    int sign = 1;
    long ans = 0;
    int i = 0;

    // Step 1: Ignore leading whitespace or underscores
    while (i < n && isspace(s[i])) i++;

    // Step 2: Check for '+' or '-' sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Step 3: Process numeric characters
    while (i < n && isdigit(s[i])) {
        ans = ans * 10 + (s[i] - '0');

        // Step 4: Clamp the result if overflow is detected
        if (sign == 1 && ans > INT_MAX) return INT_MAX;
        if (sign == -1 && -ans < INT_MIN) return INT_MIN;

        i++;
    }

    // Step 5: Return the final integer
    return (int)(sign * ans);
}
