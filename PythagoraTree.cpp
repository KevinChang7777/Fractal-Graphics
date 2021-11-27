//unfinished
#include<graphics.h>
#include<cmath>
#include<conio.h>
#include<iostream>
#define pi 3.1415926536
struct point {
	double x;
	double y;
}a,b,c,d,e;
//返回b绕a旋转angle弧度的坐标
point rotate(point a, point b, double angle) {
	point c;
	c.x = a.x +(b.x-a.x) * cos(angle) + (b.y-a.y) * sin(angle);
	c.y = a.y +(b.y-a.y) * cos(angle) - (b.x-a.x) * sin(angle);
	return c;
}
//得到a,b的中点
point zoom(point a, point b) {
	point c;
	c.x = (a.x + b.x) / 2;
	c.y = (a.y + b.y) / 2;
	return c;
}
void draw(point a, point b) {  
	
	if((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y)>  10){
		d = rotate(a, b, -pi / 2);
		c = rotate(b, a, pi / 2);
		line(a.x, a.y, b.x, b.y);
		line(a.x, a.y, d.x, d.y);
		line(b.x, b.y, c.x, c.y);
		line(c.x, c.y, d.x, d.y);
	    e = zoom(rotate(c, d, pi / 3), c);
		draw(e, c);
	}
	if ((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) > 10) {
		d = rotate(a, b, -pi / 2);
		c = rotate(b, a, pi / 2);
		line(a.x, a.y, b.x, b.y);
		line(a.x, a.y, d.x, d.y);
		line(b.x, b.y, c.x, c.y);
		line(c.x, c.y, d.x, d.y);
		e = zoom(rotate(c, d, pi / 3), c);
		draw(e, d);
	}

}
int main() {

	initgraph(1000, 600);
	point p1 = { 100,20 };
	point p2 = { 300,20 };
	draw(p1, p2);
	_getch();
	closegraph();
}


