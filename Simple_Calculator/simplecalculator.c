#include <stdio.h>  // For input-output functions like printf and scanf
#include <stdlib.h> // For general function like exit
#include <unistd.h> //For sleep function on Linux/Nix

#ifdef _WIN32
#include <windows.h>  // For sleep function (on Windows)
#define SLEEP(sec) Sleep((sec) *1000)  // define SLEEP in milliseconds for windows
#else
#define SLEEP(sec) sleep(sec)  // Use regular sleep() for Linux/Unix
#endif

void welcome_message()
{
    printf("\033[4mWelcome to my C Calculator\033[0m\n"); // For styling the welcome message
}

void loading_message()
{
    printf(".\n");
    SLEEP(1);
    printf(".\n");
    SLEEP(1);
    printf(".\n");
    SLEEP(1);

    printf("Calculating, Please wait");
    for(int i=0; i<4; i++)
    {
        printf(".");
        fflush(stdout);   // Forces printing of buffer (for dots)
        SLEEP(1);       //  Wait 1 second
    }
    printf("\n\n");
}

int main()
{
    welcome_message();

    int choice;
    double num1, num2, result;
    char another_operation;


    do {
        printf("\nSelect an operation to perform:\n");
        printf(" 1. Additon\n 2. Subtraction\n 3. Multiplication\n 4. Division\n 5. Modulus\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        printf("Enter first number: ");
        scanf("%lf", &num1);

        printf("Enter second Number: ");
        scanf("%lf", &num2);
        loading_message();

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3: 
                result = num1* num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                if(num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("Error: Division by Zero is undefined.\n");
                }
                break;
            case 5:
                if((int)num2 !=0){
                    result = (int)num1 % (int) num2;
                    printf("Result: %d %% %d = %d\n", (int)num1, (int)num2, (int)result);
                }
                else {
                    printf("Error: Modulus by zero is undefined.\n");
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                //continue;
    }

    
        printf("\nWould you like to perform another Operation?: (Y/N)  ");
        scanf(" %c", &another_operation);

    } 
    while (another_operation == 'Y' || another_operation == 'y');
    
    printf("Thank you for using the Calculator. Goodbye!\n");
    return 0;
}