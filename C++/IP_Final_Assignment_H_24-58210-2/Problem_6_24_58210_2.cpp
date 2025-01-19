#include <iostream>
#include <cmath>
using namespace std;
struct Point {
    double x, y;

    double distance(const Point& other) {
        int dx = x - other.x;
        int dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    bool isCollinear(Point p1, Point p2) {
        // (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)
        return (p2.y - p1.y) * (p1.x - x) == (p1.y - y) * (p2.x - p1.x);
    }
};
int main() {
    Point p1, p2, p3;

    cout << "Enter coordinates of Point 1 (x1 y1): ";
    cin >> p1.x >> p1.y;

    cout << "Enter coordinates of Point 2 (x2 y2): ";
    cin >> p2.x >> p2.y;

    cout << "Distance between Point 1 and Point 2: " << p1.distance(p2) << endl;

    cout << "Enter coordinates of Point 3 (x3 y3): ";
    cin >> p3.x >> p3.y;

    if (p3.isCollinear(p1, p2)) {
        cout << "Point 3 lies on the line formed by Point 1 and Point 2." << endl;
    } else {
        cout << "Point 3 does not lie on the line formed by Point 1 and Point 2." << endl;
    }
    return 0;
}