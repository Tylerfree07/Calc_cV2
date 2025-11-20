#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

char showMainMenuAndGetChoice(void) {
    char choice;

    printf("Select one of the following operations:\n"
           "B) Binary Mathematical Operations, such as addition and subtraction.\n"
           "U) Unary Mathematical Operations, such as square root, and log.\n"
           "A) Advanced Mathematical Operations, using variables, arrays.\n"
           "V) Define variables and assign them values.\n"
           "E) Exit\n");
    scanf(" %c", &choice);

    return choice;
}


void binaryOperations(int n1, int n2, char operation) {
    float floatResult;
    
    switch (operation) {
        case '+':
            floatResult = (float)n1 + (float)n2;
            printf("The sum of %d and %d is %f\n", n1, n2, floatResult);
            break;
        case '-':
            floatResult = (float)n1 - (float)n2;
            printf("The difference of %d and %d is %f\n", n1, n2, floatResult);
            break;
        case '*':
            floatResult = (float)n1 * (float)n2;
            printf("The product of %d and %d is %f\n", n1, n2, floatResult);
            break;
        case '/':
            if (n2 == 0) {
                printf("Cannot divide by zero\n");
            } else {
                floatResult = (float)n1 / (float)n2;
                printf("The quotient of %d and %d is %f\n", n1, n2, floatResult);
            }
            break;
        case '%':
            floatResult = (float)(n1 % n2);
            printf("The remainder of %d and %d is %f\n", n1, n2, floatResult);
            break;
        case 'p':
        case 'P':    
            floatResult = (float)pow(n1, n2);
            printf("The power of %d and %d is %f\n", n1, n2, floatResult);
            break;
        case 'x':
        case 'X':    
            floatResult = (float)((n1 > n2) ? n1 : n2);
            printf("The maximum of %d and %d is %f\n", n1, n2, floatResult);
            break;
        case 'i':
        case 'I':    
            floatResult = (float)((n1 < n2) ? n1 : n2);
            printf("The minimum of %d and %d is %f\n", n1, n2, floatResult);
            break;
        default:
            printf("Invalid operator\n");
            break;
    }
}
void UnaryOperations(int num1, char operation) {
    float floatResult;
    switch (operation) {
        case 'S':
        case 's':
            // Check for negative number
            if (num1 < 0) {
                printf("Error: Cannot take square root of negative number.\n");
            } else {
                floatResult = sqrt(num1);
                printf("The square root of %.2d is %.2lf\n", num1, floatResult);
            }
            break;
        case 'L':
        case 'l':
            floatResult = log((float) num1);
            printf("The log of %d is %f\n", num1, floatResult);
            break;
        case 'E':
        case 'e':
            floatResult = exp((float) num1);
            printf("The exponential of %d is %f\n", num1, floatResult);
            break;
        case 'c':
        case 'C':
            floatResult = ceil((float) num1);
            printf("The ceiling of %d is %f\n", num1, floatResult);
            break;
        case 'f':
        case 'F':
            floatResult = floor((float) num1);
            printf("The floor of %d is %f\n", num1, floatResult);
            break;
        default:
            printf("Invalid operator\n");
            break;
    }
}

int exitprogram(void) {
   printf("Thank you for using my simple calculator\n");
    printf("Exiting...");
    return EXIT_SUCCESS;
}

int main(void) {
     // Program information
    const char *DEVELOPER = "Tyler Freeman";
    const char *VERSION = "2";
    const char *DATE = "11/3/2025";

    // Print welcome message
    printf("Welcome to my Command-Line calculator!!\n");
    printf(" Developer: %s\n", DEVELOPER);
    printf(" version: %s\n", VERSION);
    printf(" Development Date: %s\n", DATE);
    printf("----------------------------------------\n\n");

    // Main program loop - runs until user exits
    while (true) {
        // Declare all variables needed for calculator
        char operation, choice, var;
        int num1, num2, result, valid = 0;
        float floatResult;
        double vars[5] = {0,0,0,0,0};  // a = vars[0], b = vars[1], ... e = vars[4]
        double value, n1, n2;

        // Show main menu
       choice = showMainMenuAndGetChoice();
        // Process user's menu choice
        switch (choice) {
            case 'B':
            case 'b':
                // Binary operations (two numbers)

                // Get first number with input validation
                while (!valid) {
                    printf("Please enter the 1st integer: ");
                    if (scanf("%d", &num1) == 1) {
                        valid = 1; // Input was a valid number
                    } else {
                        printf("Error: Invalid input. Please enter a valid number.\n");
                    }
                    while (getchar() != '\n'); // Clear input buffer
                }
                valid = 0;

                // Get the operation
                printf("Please enter the operator(+,-,*,/):\n");
                scanf(" %c", &operation);

                // Get second number with input validation
                while (!valid) {
                    printf("Please enter the second integer: ");
                    if (scanf("%d", &num2) == 1) {
                        valid = 1; // Input was a valid number
                    } else {
                        printf("Error: Invalid input. Please enter a valid number.\n");
                    }
                    while (getchar() != '\n'); // Clear input buffer
                }
                valid = 0;
                binaryOperations(num1, num2, operation);
                
                break;

            case 'U':
            case 'u':
                // Unary operations (one number)

                // Get the operation type
                printf("Please enter the operator(sqrt,log):\n");
                scanf(" %c", &operation);

                // Get the number with input validation
                while (!valid) {
                    printf("Please enter the value: ");
                    if (scanf("%d", &num1) == 1) {
                        valid = 1; // Input was a valid number
                    } else {
                        printf("Error: Invalid input. Please enter a valid number.\n");
                    }
                    while (getchar() != '\n'); // Clear input buffer
                }
                valid = 0;

                // Perform the selected unary operation
                UnaryOperations(num1, operation);
                break;

            case 'A':
            case 'a':
                // Get sub-menu choice
                printf("input choice(B,U,E): ");
                scanf(" %c", &choice);

                switch (choice) {
                    case 'B':
                    case 'b':
                        // Binary operation with variables

                        // Get first operand (variable or number)
                        printf("Please enter the first number or variable (a-e): ");
                        if (scanf(" %c", &var) == 1) {
                            // Check if user entered a variable (a-e)
                            if ((var >= 'a' && var <= 'e') || (var >= 'A' && var <= 'E')) {
                                // Get value from the chosen variable
                                switch (var) {
                                    case 'a':
                                    case 'A': n1 = vars[0];
                                        break;
                                    case 'b':
                                    case 'B': n1 = vars[1];
                                        break;
                                    case 'c':
                                    case 'C': n1 = vars[2];
                                        break;
                                    case 'd':
                                    case 'D': n1 = vars[3];
                                        break;
                                    case 'e':
                                    case 'E': n1 = vars[4];
                                        break;
                                }
                            } else if ((var >= '0' && var <= '9') || var == '-' || var == '.') {
                                // User entered a number, put it back and read full number
                                ungetc(var, stdin);
                                scanf("%lf", &n1);
                            } else {
                                // Invalid input
                                printf("Error: '%c' is not a valid variable (use a-e or a number).\n", var);
                                return 0;
                            }
                        }

                        // Get the operation
                        printf("please enter the operation(+, -, *, /): ");
                        scanf(" %c", &operation);

                        // Get second operand (variable or number)
                        printf("Please enter the second number or variable (a-e): ");
                        if (scanf(" %c", &var) == 1) {
                            // Check if user entered a variable (a-e)
                            if ((var >= 'a' && var <= 'e') || (var >= 'A' && var <= 'E')) {
                                // Get value from the chosen variable
                                switch (var) {
                                    case 'a':
                                    case 'A': n2 = vars[0];
                                        break;
                                    case 'b':
                                    case 'B': n2 = vars[1];
                                        break;
                                    case 'c':
                                    case 'C': n2 = vars[2];
                                        break;
                                    case 'd':
                                    case 'D': n2 = vars[3];
                                        break;
                                    case 'e':
                                    case 'E': n2 = vars[4];
                                        break;
                                    default: printf("Invalid variable\n");
                                        break;
                                }
                            } else if ((var >= '0' && var <= '9') || var == '-' || var == '.') {
                                // User entered a number, put it back and read full number
                                ungetc(var, stdin);
                                scanf("%lf", &n2);
                            } else {
                                // Invalid input
                                printf("Error: '%c' is not a valid variable (use a-e or a number).\n", var);
                                return 0;
                            }
                        }

                        // Perform the selected operation on the two operands
                        binaryOperations(n1, n2, operation);

                    case 'u':
                    case 'U':
                        // Unary operation with variables

                        // Get the operation type
                        printf("Please enter the operator(sqrt,log):\n");
                        scanf(" %c", &operation);

                        // Get the operand (variable or number)
                        printf("Please enter the first number or variable (a-e): ");
                        if (scanf(" %c", &var) == 1) {
                            // Check if user entered a variable (a-e)
                            if ((var >= 'a' && var <= 'e') || (var >= 'A' && var <= 'E')) {
                                // Get value from the chosen variable
                                switch (var) {
                                    case 'a':
                                    case 'A': n1 = vars[0];
                                        break;
                                    case 'b':
                                    case 'B': n1 = vars[1];
                                        break;
                                    case 'c':
                                    case 'C': n1 = vars[2];
                                        break;
                                    case 'd':
                                    case 'D': n1 = vars[3];
                                        break;
                                    case 'e':
                                    case 'E': n1 = vars[4];
                                        break;
                                    default: printf("Invalid variable\n");
                                        break;
                                }
                            } else {
                                // User entered a number, put it back and read full number
                                ungetc(var, stdin);
                                scanf("%lf", &n1);
                            }
                        }
                        valid = 0;

                        // Perform the selected unary operatio
                        UnaryOperations(n1, operation);
                        break;


                    case 'E':
                    case 'e':
                        printf("Exiting...");
                        break;
                }


                break;

            case 'V':
            case 'v':
                printf("Define or change a variable (a-e): ");
                scanf(" %c", &operation);

                // get value
                while (!valid) {
                    printf("Enter value: ");
                    if (scanf("%lf", &value) == 1) valid = 1;
                    else printf("Invalid input.\n");

                    while (getchar() != '\n');
                }
                valid = 0;

                // assign using array
                switch (operation) {
                    case 'a': case 'A': vars[0] = value; break;
                    case 'b': case 'B': vars[1] = value; break;
                    case 'c': case 'C': vars[2] = value; break;
                    case 'd': case 'D': vars[3] = value; break;
                    case 'e': case 'E': vars[4] = value; break;
                    default:
                        printf("Invalid variable.\n");
                }

                break;


            case 'E':
            case 'e':
                // Exit the program
               exit(exitprogram());

            default:
                // Invalid menu choice
                printf("Invalid choice\n");
        }
    }
    return 0;
}