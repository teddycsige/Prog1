#include "Simple_window.h"
#include "Graph.h"

double one(double x)
{
	return 1;
}

double slope(double x)
{
	return x/2;
}

double square(double x)
{
	return x*x;
}

double sloping_cos(double x)
{
	return cos(x)+slope(x);
}

int main()
{
	using namespace Graph_lib;
	
	int xmax = 600;
	int ymax = 400;
	
	int x_orig = xmax/2;
	int y_orig = ymax/2;
	
	int rmin = -11;
	int rmax= 11;
	
	int n_points=400;
	
	Simple_window win {Point{100,100},xmax,ymax, "Canvas"};
	
	Point origo {x_orig, y_orig};
	
	int xlength = xmax - 40;
	int ylength = ymax - 40;
	
	int xscale = 30;
	int yscale = 30;
	
	Function s(one, rmin, rmax, origo, n_points, xscale, yscale);
	Function sl(slope, rmin, rmax, origo, n_points, xscale, yscale);
	Function sq(square, rmin, rmax, origo, n_points, xscale, yscale);
	Function sl_cos(sloping_cos, rmin, rmax, origo, n_points, xscale, yscale);
	
	Axis x{Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y{Axis::y, Point{x_orig, ylength +20}, ylength, ylength/yscale, "y"};
	
	x.set_color(Color::red);
	y.set_color(Color::red);
	
	win.attach(s);
	win.attach(sl);
	win.attach(sq);
	win.attach(sl_cos);
	win.attach(x);
	win.attach(y);
	
	win.wait_for_button();
}
