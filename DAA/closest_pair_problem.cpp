#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool sortByX(const Point &a, const Point &b) {
    return a.x < b.x;
}

bool sortByY(const Point &a, const Point &b) {
    return a.y < b.y;
}

double calcDistance(const Point &a, const Point &b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double bruteForceClosest(vector<Point> &points, int left, int right) {
    double minDist = DBL_MAX;
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j < right; ++j) {
            double dist = calcDistance(points[i], points[j]);
            if (dist < minDist)
                minDist = dist;
        }
    }
    return minDist;
}

double closestInStrip(vector<Point> &strip, double d) {
    sort(strip.begin(), strip.end(), sortByY);
    double minDist = d;

    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            double dist = calcDistance(strip[i], strip[j]);
            if (dist < minDist)
                minDist = dist;
        }
    }
    return minDist;
}

double findClosestUtil(vector<Point> &pointsSortedByX, int left, int right) {
    if (right - left <= 3) {
        return bruteForceClosest(pointsSortedByX, left, right);
    }

    int mid = (left + right) / 2;
    Point midPoint = pointsSortedByX[mid];

    double distLeft = findClosestUtil(pointsSortedByX, left, mid);
    double distRight = findClosestUtil(pointsSortedByX, mid, right);
    double minDist = min(distLeft, distRight);

    vector<Point> strip;
    for (int i = left; i < right; ++i) {
        if (abs(pointsSortedByX[i].x - midPoint.x) < minDist) {
            strip.push_back(pointsSortedByX[i]);
        }
    }

    return min(minDist, closestInStrip(strip, minDist));
}

double findClosestPair(vector<Point> &points) {
    sort(points.begin(), points.end(), sortByX);
    return findClosestUtil(points, 0, points.size());
}

int main() {
    vector<Point> points = {
        {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}
    };

    cout << "The smallest distance is " << findClosestPair(points) << endl;
    return 0;
}
