#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Needed for character case conversion
#include <math.h>

// Define a struct to represent a point with a label and coordinates
typedef struct 
{
    char letter;
    float x, y;
} Point;

// Function to calculate the distance between two points
float distance(Point point1, Point point2)
{
    return sqrt(pow((point2.x - point1.x), 2) + pow((point2.y - point1.y), 2));
}

int main()
{
    int i;
    float AB, AC, BC;
    Point p[3];

    system("CHCP 1253 > NUL"); // Optional, sets Greek encoding — you can remove this

    for (i = 0; i < 3; i++)
    {
        printf("%dst POINT\n-------------\n", i + 1);
        printf("\tEnter the label of point %d: ", i + 1);
        scanf(" %c", &p[i].letter); // Notice the space before %c to consume leftover newline

        printf("\tEnter x of point %d: ", i + 1);
        scanf("%f", &p[i].x);

        printf("\tEnter y of point %d: ", i + 1);
        scanf("%f", &p[i].y);

        printf("\n");
        getchar(); // Consume newline character
    }

    system("CLS"); // Clears the screen (Windows only)

    AB = distance(p[0], p[1]);
    AC = distance(p[0], p[2]);
    BC = distance(p[1], p[2]);

    // If all distances are zero -> all points are the same
    if (AB == 0 && AC == 0 && BC == 0)
    {
        printf("\nYou created the POINT: %c(%.1f, %.1f)\n\n", toupper(p[0].letter), p[0].x, p[0].y);
    }

    // Triangle: if all distances are non-zero and the points are NOT colinear
    else if ((AB != 0 && AC != 0 && BC != 0) &&
             ((p[0].y - p[1].y) / (p[0].x - p[1].x) != (p[0].y - p[2].y) / (p[0].x - p[2].x)))
    {
        printf("\nYou created a TRIANGLE with vertices: ");
        for (i = 0; i < 3; i++)
            printf("\n%c(%.1f, %.1f)", toupper(p[i].letter), p[i].x, p[i].y);

        printf("\n\nand side lengths:\n");
        printf("(%c%c): %.2f units\n", toupper(p[0].letter), toupper(p[1].letter), AB);
        printf("(%c%c): %.2f units\n", toupper(p[0].letter), toupper(p[2].letter), AC);
        printf("(%c%c): %.2f units\n", toupper(p[1].letter), toupper(p[2].letter), BC);
    }

    // Otherwise, it's a line segment
    else
    {
        printf("\nYou created a STRAIGHT LINE SEGMENT with endpoints: ");

        // If not all 3 points are colinear, just 2 of them coincide
        if ((p[0].y - p[1].y) / (p[0].x - p[1].x) != (p[0].y - p[2].y) / (p[0].x - p[2].x))
        {
            if (AB == 0)
            {
                printf("\n%c(%.1f, %.1f)", toupper(p[1].letter), p[1].x, p[1].y);
                printf("\n%c(%.1f, %.1f)", toupper(p[2].letter), p[2].x, p[2].y);
                printf("\nLength (%c%c): %.2f units.\n\n", toupper(p[1].letter), toupper(p[2].letter), (AC + BC) / 2);
            }
            else if (AC == 0)
            {
                printf("\n%c(%.1f, %.1f)", toupper(p[1].letter), p[1].x, p[1].y);
                printf("\n%c(%.1f, %.1f)", toupper(p[2].letter), p[2].x, p[2].y);
                printf("\nLength (%c%c): %.2f units.\n\n", toupper(p[0].letter), toupper(p[2].letter), (AB + BC) / 2);
            }
            else if (BC == 0)
            {
                printf("\n%c(%.1f, %.1f)", toupper(p[0].letter), p[0].x, p[0].y);
                printf("\n%c(%.1f, %.1f)", toupper(p[2].letter), p[2].x, p[2].y);
                printf("\nLength (%c%c): %.2f units.\n\n", toupper(p[0].letter), toupper(p[2].letter), (AB + AC) / 2);
            }
        }
        // If all 3 points are colinear
        else
        {
            if (AB >= AC && AB >= BC)
            {
                printf("\n%c(%.1f, %.1f)", toupper(p[0].letter), p[0].x, p[0].y);
                printf("\n%c(%.1f, %.1f)", toupper(p[1].letter), p[1].x, p[1].y);
                printf("\nLength (%c%c): %.2f units.\n\n", toupper(p[0].letter), toupper(p[1].letter), AB);
            }
            else if (BC >= AB && BC >= AC)
            {
                printf("\n%c(%.1f, %.1f)", toupper(p[1].letter), p[1].x, p[1].y);
                printf("\
