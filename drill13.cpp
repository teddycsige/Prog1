/*
	g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill1.cpp `fltk-contig--ldflogs --use --inages` a2.out
*/

#include "Simple_window.h"
#include "Graph.h"

#include <iostream>
#include <string>

using namespace Graph_lib;
int main()
{
	try
	{
		Point t1(300,50);
		Simple_window win(t1, 1000, 800, "My window");
		win.wait_for_button();
		
		Lines grid;
		int x_size=800;
		int y_size=800;
		for(int i=100; i<=x_size;i+=100)
		{
			grid.add(Point(i,0), Point(i, y_size));
			grid.add(Point(0,i),Point(x_size, i));
		}
		win.attach(grid);
		win.wait_for_button();
		
		
		
		Vector_ref<Rectangle> vr;
		for(int i =0; i <8; i++)
		{
			vr.push_back(new Rectangle {Point (i*100, i*100),101,101});
			vr[vr.size()-1].set_fill_color(Color::red);
			win.attach(vr[vr.size()-1]);
		}
		win.wait_for_button();
		
		Image badge1(Point(200,0),"badge.jpg");
		badge1.set_mask(Point(200,0),200,200);
		win.attach(badge1);
		
		Image badge2(Point(500,200),"badge.jpg");
		badge2.set_mask(Point(200,0),200,200);
		win.attach(badge2);
		
		Image badge3(Point(100,500),"badge.jpg");
		badge3.set_mask(Point(200,0),200,200);
		win.attach(badge3);
		win.wait_for_button();

		Image badge4(Point(0,0),"kepecske.jpg");
		badge4.set_mask(Point(0,0),100,100);
		win.attach(badge4);
		
		int px=0;
		int py=0;
		int rx=0;
		int ry=0;
		
		while(true)
		{
			rx=(rand() % 7 + 1)*100;
			ry=(rand() % 7 + 1)*100;
			win.wait_for_button();
			badge4.move(rx-px,ry-py);
			px=rx;
			py=ry;
			
		}
		
		win.wait_for_button();
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
	catch(exception& e)
	{
		cerr << "exeption: " << e.what() << endl;
		return 1;
	}
	catch(...)
	{
		cerr << "error\n";
		return 2;
	}
}
