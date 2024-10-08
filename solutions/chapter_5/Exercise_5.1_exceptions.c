#include <stdio.h>
//library needed to use exception handling functions
//below strategy is most relevant when working with functions within functions, but want to check error handle at the upper level
#include <setjmp.h>

int main(void)
{
    int num, den, mod;
    //declaring variable for exception handling, not a data type but something else written prior, sort of like a checkpoint / warp / rapid-travel
    //to get from longjmp call to setjmp call (stored in env)
    jmp_buf env;

    scanf("%d%d", &num, &den);

    //function always called first, when it returns a value of zero (its default value) it continues reading the code since there are no exceptions to handle
    if (setjmp(env) == 0)
    {
        if (den == 0)
        {
            //exception has occurred and this function calls setjmp again, but this time setjmp will not return a value of zero and thus not continue reading
            //the code, 3 is the value to be returned by setjmp when it gets called anew, but the number could be anything (other than 0)
            longjmp(env, 3);
        }
        else
        {
            mod = num % den;
            printf("remainder = %d\n", mod);
        }
    }
    else
    {
        printf("Exception : Cannot divide by zero.\n");
    }

    return 0;
}
