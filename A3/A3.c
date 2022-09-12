/*
Introduction...

Pseudo code for Assignment_3a:
    level 1:
        Get number from user.
        Sum numbers form 1 to number.
        Print number.

    level 2:
        Set n to 1.
        Set sum to 0.
        Get input from user.

        If input is 0:
            Close Program.

        If input is not a number:
            Print error message.
            Close program.

        If number is less than 0:
            set number to -1*number.

            While n is less than or equal to the value of number:
                Set sum to sum + n.
                Increment n by 1.

            set sum to -1*sum + 1

        If number is greater than 0:

            While n is less than or equal to the value of number:
                Set sum to sum + n.
                Increment n by 1.

        Print sum to screen.

Pseudo code for Assignment_3b:
    Level 1:
        set counter to 1.
        Generate a random number (rand_n) from 0 to 100.
        Get a number (guess) from 0 to 100 from user.
        
        while guess and rand_n are not equal:
            Increment counter by 1.
            Inform user whether number is greater than, less than or equal to rand_n.
            Get a new guess from user.
        
        Print the value of counter to screen.

    level 2:



*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void clear_stdin(void);

int program_select(void);
int assignment_3a(void);
int assignment_3b(void);
int get_int(char prompt_str[1000], int MIN, int MAX);

    int main(void)
{

    // variable declarations
    int program = 0, res = 0, counter = 0;

    // Print welcome message.
    puts("Welcome to Assignment_3!\n");
    
    // Select program.
    program = program_select();

    while (program != -1) 
    {
        switch (program) {
            case 1: {
                // Print welcome message when program is entered. 
                if (counter == 0) {
                    puts("\nWelcome to Assignment_3a!\n");
                    counter = 1;
                }

                // call assignment_3a.
                res = assignment_3a();

                // Close program if non-numeric input is detected. 
                if (res == 1) {
                    program = -1;
                    break;
                }

                // Exit assignment_3a 
                if (res ==2) {
                    puts("");
                    program = program_select(); // Select new program.
                    counter = 0; // Reset counter.
                }
                break;
            }

            case 2:
                // Print welcome message when program is entered.
                if (counter == 0)
                {
                    puts("\nWelcome to Assignment_3b!\n");
                    counter = 1;
                }

                assignment_3b();
                program = -1;
                break;
        }
    }

    puts("Program closing...");

    return 0;
}

// Function definitions.


void clear_stdin() { // This function was found on the internet.
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int program_select() {
    int input = 0;
    do
    {
        printf("Please input number to select program (1: Assignment_3a, 2: Assignment_3b, -1: quit): ");
        // Scan standard input for int.
        scanf("%d", &input);

        // If input is not int do this.
        if (input == 0)
        {
            clear_stdin();
            printf("\nInput error!!!\n");
        }

        // If input is not 1 or 2 or -1, do this.
        else
        {
            if (!(input == 1 || input == 2 || input == -1))
            {
                input = 0;
                printf("\nInput error!!!\n");
            }
        }
    } while (input == 0); 

    return input;
}

int assignment_3a() {
    /* 
        A program that sums numbers from 0 to n.
    */
    
    // variable initialization.
    long sum = 0, number = 0, scanned = 0;
    
    // Prompt user for input.
    printf("Enter whole number (0 to exit Assignment_3a): ");
    scanned = scanf("%d", &number);
    
    // If user input not an int, do this.
    if (scanned == 0) {
        clear_stdin();  // clear stadin buffer.
        printf("\nInput Error!!!\n");
        printf("Non-numeric input detected.\n");
        return 1; 
    }
    
    // If user input is 0, do this.
    if (number == 0) {
        return 2;
    }

    // If user input is negative, do this.
    if (number < 0) {
        for (int n = 0; n <= -1*number; n++) {
            sum += n;
        }
        sum = -1*sum + 1;
    } 
    // I user input is positive, do this.
    else {
        for (int n = 1; n <= number; n++) {
            sum += n;
        }
        sum = sum;
    }
    
    // Print sum.
    printf("Sum of numbers in the range [1, %d] is: %d\n\n", number, sum);
    // Reset sum to 0.
    sum=0; 

    return 0;
    

}

int assignment_3b() {
    // Variable declarations.
    int guess = 0, secrete = 0, counter = 0, lower_limit = 0, upper_limit = 0;
    //char prompt_str[1000];
    // Seed random number generator with current time.
    srand(time(0));
    
    while(1) {

        printf("Counter is: %d\n", counter);
        printf("Lower is: %d\n", lower_limit);
        printf("Secret is: %d\n", secrete);
        printf("Upper is: %d\n", upper_limit);

        // Generate random number between upper_limit and lower_limit.
        if (counter == 0) {
            lower_limit = get_int("Enter lower bound (Number should be between 0 and 1000): ",0,10000);
            upper_limit = get_int("Enter upper bound (Number should be between 0 and 1000): ", 0, 10000);
            while (lower_limit >= upper_limit) {
                printf("\nFORMAT ERROR!!! Upper bound must be larger than lower bound.\n\n");
                upper_limit = get_int("Enter upper bound (Number should be between 0 and 1000): ", 0, 10000);
            }

            //prompt_str = sprintf("Enter number from ")

            printf("Generating secrete number...\n\n");
            secrete = (rand() % (upper_limit - lower_limit + 1) + lower_limit);  // Explain this to yourself.....

            printf("Secret is : %d\n", secrete);


        }

        // Get guess.
        guess = get_int("Enter guess: ", lower_limit, upper_limit);

        // Step counter.
        counter++;
        
        // If user guessed correct, do this.
        if (guess == secrete) {
            printf("\nCongratulations!!! You guessed the secrete number on attempt %d.\n", counter);

            // Ask user to play again or close program.
            if (get_int("Enter 1 to play again. Enter 0 to close program: ",0,1) == 1) {
                counter = 0;

                puts("");
                continue;
            } 
            else {
                break;
            }
        }

        // If guess is to large, do this.
        if (guess > secrete) {
            printf("\nINCORRECT!!! Your guess is LARGER than the secrete number, try again.\n");

        }
        // If user guess is to low, do this
        else {
            printf("\nINCORRECT!!! Your guess is LOWER than the secrete number, try again.\n");
        }

    }

}



// Helper functions.

int get_int(char str[1000], int MIN, int MAX)
{
    int input, scanned, dummy;

    while (1)
    {
        printf(str);
        scanned = scanf("%d", &input);

        if (scanned == 0)
        {
            printf("\nFORMAT ERROR!!! Non-numeric input detected.\n\n");

            while ((dummy = getchar()) != '\n' && dummy != EOF)
            {
            }

            continue;
        }

        if (!(input >= MIN && input <= MAX))
        {
            printf("\nFORMAT ERROR!!! Number is out of range.\n\n");
            while ((dummy = getchar()) != '\n' && dummy != EOF)
            {
            }

            continue;
        }
        break;
        return input;
    }
}
