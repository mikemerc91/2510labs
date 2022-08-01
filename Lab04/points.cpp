// lab4 exercise 1.1-1.7
#include "../std_lib_facilities.h"

struct Point {
    int x,y;

    friend istream &operator>>(istream &input, Point &p) 
    {
        input >> p.x >> p.y;
        return input;
    }
    friend bool operator==(const Point &a, const Point &b) 
    {
        return a.x==b.x && a.y==b.y;
    }
    friend bool operator!=(const Point &a, const Point &b)
    {
        return !(a==b);
    }
};

int main()
{
    int x,y;
    vector<Point> original_points;
    for (int i=0; i<7; ++i) {
        Point temp;
        cout << "Enter an x y pair: " << endl;
        cin >> temp;
        original_points.push_back(temp);
    }
    
    ofstream ost{"mydata.txt"};
    for (int i=0; i<original_points.size(); ++i) {
        ost << original_points[i].x << " " << original_points[i].y << endl;
    }
    ost.close();
    ifstream ist{"mydata.txt"};
    if (!ist) error("Can't open input file.");
    vector<Point> processed_points;
    while (ist >> x >> y) {
        processed_points.push_back(Point{x,y});
    }
    ist.close();

    cout << "Original Points:\n";
    for (int i=0; i<original_points.size(); ++i) {
        cout << original_points[i].x << ", " << original_points[i].y << endl;
    }

    cout << "Processed Points:\n";
    for (int i=0; i<processed_points.size(); ++i) {
        if (original_points.size()!=processed_points.size() ||
        original_points[i]!=processed_points[i]) error("Something's wrong!");
        
        cout << processed_points[i].x << ", " << processed_points[i].y << endl;
    }




} 