#include <iostream>
using namespace std;

struct Point {
    int x, y;

    int distance(Point p) {
        int dx = (p.x - x) * (p.x - x);
        int dy = (p.y - y) * (p.y - y);
        int dist = 0;
        for (int i = 1; i <= dx + dy; i++) {
            if (i * i == dx + dy) {
                dist = i;
                break;
            }
        }
        return dist;
    }

    bool isCollinear(Point p1, Point p2) {
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