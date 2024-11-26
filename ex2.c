/******************
Name: shaked weizman	
ID: 318794823
Assignment: ex2
*******************/

#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to reverse a number
int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

// Function to sum squares of digits
int sumOfSquares(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
    }
    return sum;
}

// Function to check if a number is a happy number
int isHappy(int num) {
    int slow = num, fast = num;
    do {
        slow = sumOfSquares(slow);
        fast = sumOfSquares(sumOfSquares(fast));
        if (fast == 1) return 1;
    } while (slow != fast);
    return 0;
}

// Function to print the Happy Face
void happyFace() {
    char eye, nose, mouth;
    int size;

    printf("Enter symbols for the eyes, nose, and mouth:\n");
    scanf(" %c %c %c", &eye, &nose, &mouth);

    while (1) {
        printf("Enter face size:\n");
        scanf("%d", &size);

        if (size > 0 && size % 2 != 0) break;
        printf("The face's size must be an odd and positive number, please try again:\n");
    }

    int spaces = (size+1) / 2;
    // Print the face
    
    printf("%c", eye);
    for (int i = 0; i < size ; i++) {
        printf(" ");
    }
    printf("%c\n", eye);

    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
    printf("%c\n", nose);

    printf("\\");
    for (int i = 0; i < size; i++) {
        printf("%c", mouth);
    }
    printf("/\n");
}

// Function to check if a number is balanced
void balancedNumber() {
    int num;
    printf("Enter a number:\n");
    while (1) {
        scanf("%d", &num);
        if (num > 0) break;
        printf("Only positive number is allowed, please try again:\n");
    }

    int digits[10], count = 0, temp = num;

    while (temp > 0) {
        digits[count++] = temp % 10;
        temp /= 10;
    }

    int leftSum = 0, rightSum = 0;
    int mid = count / 2;

    for (int i = 0; i < mid; i++) leftSum += digits[i];
    for (int i = mid + (count % 2); i < count; i++) rightSum += digits[i];

    if (leftSum == rightSum) {
        printf("This number is balanced and brings harmony!\n");
    } else {
        printf("This number isn't balanced and destroys harmony.\n");
    }
}

// Function to check if a number is generous (Abundant)
void generousNumber() {
    int num;
    printf("Enter a number:\n");
    while (1) {
        scanf("%d", &num);
        if (num > 0) break;
        printf("Only positive number is allowed, please try again:\n");
    }

    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) sum += i;
    }

    if (sum > num) {
        printf("This number is generous!\n");
    } else {
        printf("This number does not share.\n");
    }
}

// Function to check if a number is part of the Circle of Joy
void circleOfJoy() {
    int num;
    printf("Enter a number:\n");
    while (1) {
        scanf("%d", &num);
        if (num > 0) break;
        printf("Only positive number is allowed, please try again:\n");
    }

    if (isPrime(num) && isPrime(reverseNumber(num))) {
        printf("This number completes the circle of joy!\n");
    } else {
        printf("The circle remains incomplete.\n");
    }
}

// Function to display happy numbers up to n
void happyNumbers() {
    int n;
    printf("Enter a number:\n");
    while (1) {
        scanf("%d", &n);
        if (n > 0) break;
        printf("Only positive number is allowed, please try again:\n");
    }

    printf("Between 1 and %d only these numbers bring happiness: ", n);
    for (int i = 1; i <= n; i++) {
        if (isHappy(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function for the Festival of Laughter task
void festivalOfLaughter() {
    int smileNum, cheerNum, maxNum;
    printf("Enter a smile and cheer number:\n");
    while (1) {
        if (scanf("smile: %d , cheer: %d", &smileNum, &cheerNum) == 2 && smileNum > 0 && cheerNum > 0 && smileNum != cheerNum) {
            break;
        } else {
            printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
            while (getchar() != '\n');  // clear buffer
        }
    }

    printf("Enter maximum number for the festival:\n");
    while (1) {
        scanf("%d", &maxNum);
        if (maxNum > 0) break;
        printf("Only positive maximum number is allowed, please try again:\n");
    }

    for (int i = 1; i <= maxNum; i++) {
        if (i % smileNum == 0 && i % cheerNum == 0) {
            printf("Festival! ");
        } else if (i % smileNum == 0) {
            printf("Smile! ");
        } else if (i % cheerNum == 0) {
            printf("Cheer! ");
        } else {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("Choose an option:\n");
        printf("\t1. Happy Face\n");
        printf("\t2. Balanced Number\n");
        printf("\t3. Generous Number\n");
        printf("\t4. Circle Of Joy\n");
        printf("\t5. Happy Numbers\n");
        printf("\t6. Festival Of Laughter\n");
        printf("\t7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                happyFace();
                break;
            case 2:
                balancedNumber();
                break;
            case 3:
                generousNumber();
                break;
            case 4:
                circleOfJoy();
                break;
            case 5:
                happyNumbers();
                break;
            case 6:
                festivalOfLaughter();
                break;
            case 7:
                printf("Thank you for your journey through Numeria!\n");
                break;
            default:
                printf("This option is not available, please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
