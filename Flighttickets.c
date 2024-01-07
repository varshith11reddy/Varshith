#include <stdio.h>
#define ROWS 10
#define COLS 6
void displaySeats(char flightSeats[][COLS]) {
printf("\nFlight Seat Reservation System\n");
printf(" \n");
for (int i = 0; i < ROWS; i++) {
printf("Row %d:\t", i + 1);
for (int j = 0; j < COLS; j++) {
printf("%c ", flightSeats[i][j]);
}
printf("\n");
}
}
void reserveSeat(char flightSeats[][COLS]) {
int row, col;
printf("\nEnter the seat row (1-%d): ", ROWS);
scanf("%d", &row);
if (row < 1 || row > ROWS) {
printf("Invalid row number. Please try again.\n");
return;
10
}
printf("Enter the seat column (1-%d): ", COLS);
scanf("%d", &col);
if (col < 1 || col > COLS) {
printf("Invalid column number. Please try again.\n");
return;
}
if (flightSeats[row - 1][col - 1] == 'X') {
printf("Seat already reserved. Please choose another seat.\n");
} else {
flightSeats[row - 1][col - 1] = 'X';
printf("Seat reserved successfully!\n");
}
}
void cancelReservation(char flightSeats[][COLS]) {
int row, col;
printf("\nEnter the seat row (1-%d): ", ROWS);
scanf("%d", &row);
if (row < 1 || row > ROWS) {
printf("Invalid row number. Please try again.\n");
return;
}
printf("Enter the seat column (1-%d): ", COLS);
11
scanf("%d", &col);
if (col < 1 || col > COLS) {
printf("Invalid column number. Please try again.\n");
return;
}
if (flightSeats[row - 1][col - 1] == 'O') {
printf("Seat not reserved. Please enter a reserved seat.\n");
} else {
flightSeats[row - 1][col - 1] = 'O';
printf("Reservation canceled successfully!\n");
}
}
int main() {
char flightSeats[ROWS][COLS];
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
flightSeats[i][j] = 'O';
}
}
int choice;
do {
displaySeats(flightSeats);
printf("\nFlight Reservation Menu\n");
printf("1. Reserve a Seat\n");
12
printf("2. Cancel Reservation\n");
printf("3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
reserveSeat(flightSeats);
break;
case 2:
cancelReservation(flightSeats);
break;
case 3:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 3);
return 0;
}
