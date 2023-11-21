#include "toprow.h"

bool toprow(const char s[])
{
    bool res = true;
    const char row[] = "qwertyuiopQWERTYUIOP";
    int ptr = 0;

    while (s[ptr++] != '\0') {
        if (strchr(row, s[ptr]) != NULL) {
            // character is in the string
            ;
        } else {
            // character is not in the string
            res = false;
            break;
        }
    }

    return res;
}
