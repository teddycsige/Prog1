//A kód nem működik. Töltöttem vele időt, de időszűkében sajnos csak ilyen állapotban tudtam leadni.

#include "GUI.h"
#include "Lines_window.h"
#include "Graph.h"
#include <iostream>

using namespace Graph_lib;

struct L_window : Window
{
	L_window(Point xy, int w, int h, const string& title);
	
	Poen_polyline lines;
	Menu color_menu;
	Menu style_menu;
	Button color_button;
	Button style_button;
	
	static void cb_red(Adress, Adress);	
	static void cb_blue(Adress, Adress);
	static void cb_black(Adress, Adress);
	
	void red_pressed() {change(Color::red);}
	void blue_pressed() {change(Color::blue);}
	void black_pressed(){change(Color::black);}
	
	void change(Color c) {lines.set_color(c);}
	void style(Line_style l) { lines.set_style(l);}
	
	void hide_color() { color_menu.hide(); color_button.show(); }
	void hide_style() { style_menu.hide(); style_button.show(); }

    	void red_pressed() { change_c(Color::red); hide_color(); }
    	void blue_pressed() { change_c(Color::blue); hide_color(); }
    	void black_pressed() { change_c(Color::black); hide_color(); }

   	void dot_pressed() { change_s(Line_style::dot); hide_style(); }
    	void dash_pressed() { change_s(Line_style::dash); hide_style(); }
    	void solid_pressed() { change_s(Line_style::solid); hide_style(); }

    	void color_pressed() { color_button.hide(); color_menu.show(); }
    	void style_pressed() { style_button.hide(); style_menu.show(); }
    	void next();
    	void quit();


};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);
    
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "red",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).red_pressed();
        }
    });
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "blue",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).blue_pressed();
        }
    });
    color_menu.attach(new Button{Point{0, 0}, 0, 0, "black",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).black_pressed();
        }
    });
    style_menu.attach(new Button{Point{0, 0}, 0, 0, "dot",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).dot_pressed();
        }
    });
    style_menu.attach(new Button{Point{0, 0}, 0, 0, "dash",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).dash_pressed();
        }
    });
    style_menu.attach(new Button{Point{0, 0}, 0, 0, "solid",
        [](Address, Address pw) {
            reference_to<Lines_window>(pw).solid_pressed();
        }
    });
    attach(color_menu);
    attach(style_menu);
    color_menu.hide();
    style_menu.hide();
    attach(color_button);
    attach(style_button);
}

}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

int main()
{
	try
	{
		Lines_window win {Point{100,100}, 600, 400, "lines"};
		return gui_main();
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
