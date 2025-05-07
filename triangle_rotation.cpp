#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

// Function to rotate a point around origin
void rotatePoint(int x, int y, double angleRad, int &xr, int &yr) {
    xr = round(x * cos(angleRad) - y * sin(angleRad));
    yr = round(x * sin(angleRad) + y * cos(angleRad));
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define triangle vertices (relative to origin)
    int x1 = 100, y1 = 100;  // Point A
    int x2 = 200, y2 = 100;  // Point B
    int x3 = 150, y3 = 200;  // Point C

    double angleDeg;
    cout << "Enter rotation angle in degrees (anticlockwise): ";
    cin >> angleDeg;

    double angleRad = angleDeg * M_PI / 180.0;

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 10, "Original triangle");

    // Rotate each point
    int rx1, ry1, rx2, ry2, rx3, ry3;
    rotatePoint(x1, y1, angleRad, rx1, ry1);
    rotatePoint(x2, y2, angleRad, rx2, ry2);
    rotatePoint(x3, y3, angleRad, rx3, ry3);

    // Shift origin to center of screen
    int cx = getmaxx() / 2;
    int cy = getmaxy() / 2;

    // Draw rotated triangle
    setcolor(RED);
    line(cx + rx1, cy - ry1, cx + rx2, cy - ry2);
    line(cx + rx2, cy - ry2, cx + rx3, cy - ry3);
    line(cx + rx3, cy - ry3, cx + rx1, cy - ry1);

    outtextxy(cx + rx1, cy - ry1 - 10, "Rotated triangle");

    getch();
    closegraph();
    return 0;
}

