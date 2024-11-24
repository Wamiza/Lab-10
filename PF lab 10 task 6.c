#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

float calculateDistance(struct Point p1, struct Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

int isPointWithinRectangle(struct Point p, struct Point bottomLeft, struct Point topRight) {
    return (p.x >= bottomLeft.x && p.x <= topRight.x && p.y >= bottomLeft.y && p.y <= topRight.y);
}

int main() {
    struct Point p1, p2, bottomLeft, topRight;

    printf("Enter coordinates of first point (x1 y1): ");
    scanf("%f %f", &p1.x, &p1.y);
    printf("Enter coordinates of second point (x2 y2): ");
    scanf("%f %f", &p2.x, &p2.y);

    float distance = calculateDistance(p1, p2);
    printf("Distance between points: %.2f\n", distance);

    printf("Enter bottom-left corner of rectangle (x y): ");
    scanf("%f %f", &bottomLeft.x, &bottomLeft.y);
    printf("Enter top-right corner of rectangle (x y): ");
    scanf("%f %f", &topRight.x, &topRight.y);

    printf("Enter point to check (x y): ");
    scanf("%f %f", &p1.x, &p1.y);

    if (isPointWithinRectangle(p1, bottomLeft, topRight)) {
        printf("The point lies within the rectangle.\n");
    } else {
        printf("The point does not lie within the rectangle.\n");
    }

    return 0;
}