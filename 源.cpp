#include<graphics.h>		
#include<conio.h>
#include<cmath>
#include<iostream>
#define pi 3.1415926535
#define angle1 pi/3.0
#define angle2 -pi/3.0 
using namespace std;
struct point {
	double  x;
	double  y;
};
//旋转正角度
//水平时向下画
void kochdown(int n, point a, point b) {
	if (n == 1) {
		line(a.x, a.y, b.x, b.y);
		return;
	}
	else {
		point s, t, u;
		s.x = (b.x + 2 * a.x) / 3;//     u
		s.y = (b.y + 2 * a.y) / 3;//a  s   t  b
		t.x = (2 * b.x + a.x) / 3;
		t.y = (2 * b.y + a.y) / 3;
		u.x = (t.x-s.x) * cos(angle1) - (t.y-s.y) * sin(angle1)+s.x;//利用旋转矩阵
		u.y = (t.x - s.x) *sin(angle1) +(t.y - s.y) * cos(angle1) + s.y;
		kochdown(n - 1, a, s);
		kochdown(n - 1, s, u);
		kochdown(n - 1, u, t);
		kochdown(n - 1, t, b);
	}
}
//旋转负角度
//水平时向上画
void kochup(int n, point a, point b) {
	if (n == 1) {
		line(a.x, a.y, b.x, b.y);
		return;
	}
	else {
		point s, t, u;
		s.x = (b.x + 2 * a.x) / 3;
		s.y = (b.y + 2 * a.y) / 3;
		t.x = (2 * b.x + a.x) / 3;
		t.y = (2 * b.y + a.y) / 3;
		u.x = (t.x - s.x) * cos(angle2) - (t.y - s.y) * sin(angle2) + s.x;
		u.y = (t.x - s.x) * sin(angle2) + (t.y - s.y) * cos(angle2) + s.y;
		kochup(n - 1, a, s);
		kochup(n - 1, s, u);
		kochup(n - 1, u, t);
		kochup(n - 1, t, b);
	}
}
int main()
{
	int n;
	cin >> n;
	initgraph(600, 600);
	point a, b,c,d;           //  a   b
	a.x = 200; a.y =200 ;
	b.x = 400; b.y =200 ;
	c.x =400; c.y =400;       //  d   c
	d.x = 200; d.y = 400;
	kochup(n, a, b);
	kochdown(n, d, c);
	kochdown(n, a, d);
	kochup(n, b, c);
	_getch();
	closegraph();
	return 0;
	
}

