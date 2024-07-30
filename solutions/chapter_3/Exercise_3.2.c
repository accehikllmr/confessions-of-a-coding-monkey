#include <stdio.h>
#include <string.h>

//building number up using three digits
void synthesis();
//decomposing number into its three digits
void analysis();

int main() {
    //run only one of the functions at a time
    synthesis();
    //analysis();
    return 0;
}

void synthesis() {

    int intSum, a, b, c;

    //loop only for single digit numbers since we use up to three digits to make up a number less than 100 (no space for two digit numbers)
    for (a = 0; a < 10; a++) {
        for (b = 0; b < 10; b++) {
            for (c = 0; c < 10; c++) {
                intSum = (a * a * a) + (b * b * b) + (c * c * c);
                //any sums larger than 999 are not considered, since we are only working with three digits (a, b and c)
                if (intSum > 999) {
                    break;
                } else {
                    //subtracting hundreds, tens and units from sum according to digit in corresponding position, gives zero if Armstrong number
                    if (intSum - 100 * a - 10 * b - 1 * c == 0) {
                        printf("a = %d, b = %d, c = %d, sum = %d\n", a, b, c, intSum);
                    }
                }
            }
            if (intSum > 999) {
                break;
            }
        }
    }
}

void analysis() {

    int i;
    for (i = 0; i < 1000; i++) {
        //size of array must be four to allow for three elements (our three digits) to be held within them (not so in W3schools lessons...)
        char number[4];

        int a, b, c;
        /*converts given data type to a string, in this case, integer i is converted to a string and placed in the array number, but additional conditions
        to add zeroes in front single and double digit numbers*/
        if (i < 10) {
            sprintf(number, "%c%c%d", '0', '0', i);
        /*following condition could not be read as (9 < i < 100) since it carried an extra '0' to three digit numbers, so switched to have separate
        conditions combined with AND*/
        } else if (i > 9 && i < 100) {
            sprintf(number, "%c%d", '0', i);
        } else {
            sprintf(number, "%d", i);
        }
        /*converts char data type to int data type, where '0' is the ASCII value for integer 0, finding the difference yields the order which corresponds
        with integer numbers (example : '2' - '0' = 50 - 48 = 2)*/
        a = number[0] - '0';
        b = number[1] - '0';
        c = number[2] - '0';
        if ((a * a * a) + (b * b * b) + (c * c * c) == i) {
            printf("a = %d, b = %d, c = %d, sum = %d\n", a, b, c, i);
        }
    }
}
