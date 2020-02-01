#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <graphics.h>
using namespace std;

double EPS = 1e-9;

struct point {
  double x, y;
};

struct LineType { //struct line in the form ax+by+c = 0
  double a, b, c; };

struct vec {
  double x, y;  // struct for vector
};

void pointsToLine(point p1, point p2, LineType &l) {
  if (fabs(p1.x - p2.x) < EPS) {              // vertical line is fine
    l.a = 1.0;   l.b = 0.0;   l.c = -p1.x;           // default values
  } else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;              // IMPORTANT: we fix the value of b to 1.0
    l.c = -(double)(l.a * p1.x) - p1.y;
  }
}

bool areParallel(LineType l1, LineType l2) {       // check coefficients a & b
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(LineType l1, LineType l2, point &p) {
  if (areParallel(l1, l2)) return false;            // no intersection
  // solve system of 2 linear algebraic equations with 2 unknowns
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  // special case: test for vertical line to avoid division by zero
  if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
  else                  p.y = -(l2.a * p.x + l2.c);

  return true;
}

vec toVec(point a, point b) {       // convert 2 points to vector a->b
  vec res;
  res.x = b.x - a.x;
  res.y = b.y - a.y;
  return res;
}

point translate(point p, vec v) {        // translate p according to v
  point res;
  res.x = p.x + v.x;
  res.y = p.y + v.y;
  return res;
}

// convert point and gradient/slope to line
void pointSlopeToLine(point p, double m, LineType &l) {
  l.a = -m;                                               // always -m
  l.b = 1;                                                 // always 1
  l.c = -((l.a * p.x) + (l.b * p.y));                 // compute this
}

void closestPoint(LineType l, point p, point &ans) {
  LineType perpendicular;         // perpendicular to l and pass through p
  if (fabs(l.b) < EPS) {              // special case 1: vertical line
    ans.x = -(l.c);   ans.y = p.y;      return; }

  if (fabs(l.a) < EPS) {            // special case 2: horizontal line
    ans.x = p.x;      ans.y = -(l.c);   return; }

  pointSlopeToLine(p, 1 / l.a, perpendicular);          // normal line
  // intersect line l with this perpendicular line
  // the intersection point is the closest point
  areIntersect(l, perpendicular, ans);
}

// returns the reflection of point on a line
void reflectionPoint(LineType l, point p, point &ans) {
  point b;
  b.x = 0;
  b.y = 0;
  closestPoint(l, p, b);                     // similar to distToLine
  vec v = toVec(p, b);                             // create a vector
  ans = translate(translate(p, v), v);         // translate p twice
}

int main() {


  int command;
  double ax,ay,bx,by,cx,cy,px,py,qx,qy;
  point A,B,C,P,Q,AA,BB,CC,DD;
  LineType reflex;

  cout <<"Masukkan koordinat titik sudut segitiga (A, B, dan C)" <<endl;
  cout <<"A : "; cin >>ax >>ay;
  A.x = ax;
  A.y = ay;

  cout <<"B : "; cin >>bx >>by;
  B.x = bx;
  B.y = by;

  cout <<"C : "; cin >>cx >>cy;
  C.x = cx;
  C.y = cy;


  initwindow(360,480,"Test");
  line(A.x,A.y,B.x,B.y);
  line(B.x,B.y,C.x,C.y);
  line(C.x,C.y,A.x,A.y);

  cout <<"Masukkan titik sumbu refleksi (P dan Q)" <<endl;
  cout <<"P : "; cin >>px >>py;
  P.x = px;
  P.y = py;

  cout <<"Q : "; cin >>qx >>qy;
  Q.x = qx;
  Q.y = qy;

  line(P.x,P.y,Q.x,Q.y); //gambar garis sumbu refleksi

  pointsToLine(P,Q,reflex);
  reflectionPoint(reflex, A, AA);
  reflectionPoint(reflex, B, BB);
  reflectionPoint(reflex, C, CC);

  line(AA.x,AA.y,BB.x,BB.y);
  line(BB.x,BB.y,CC.x,CC.y);
  line(CC.x,CC.y,AA.x,AA.y);

  system("pause");
  return 0;
}
