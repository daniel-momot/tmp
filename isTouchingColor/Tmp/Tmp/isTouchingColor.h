#include <vector>

//////////////////////////////////////////////////////

// dependencies

typedef unsigned short color; // rgba
enum colors {
	black = 0x00000000,
	white = 0xFFFFFF00,
	red =   0xFF000000
};

struct point {
	color clr;
	unsigned short x;
	unsigned short y;
};

struct Drawable {
private:
	std::vector<point> points;
	bool is_visible;
public:
	Drawable(bool is_visible) : is_visible(is_visible) {}
	Drawable(bool is_visible, std::vector<point>&& points) : is_visible(is_visible), points(std::move(points)) {}
};

//////////////////////////////////////////////////////

class Environment {
	std::vector<Drawable*> objects;
public:

	void AddDrawable(const Drawable& drwbl) { 
		Drawable* _drwbl = new Drawable(drwbl);
		objects.push_back(_drwbl);
	}

	~Environment() {
		for (const Drawable* drwbl : objects)
			delete drwbl;
	}

	// TODO implement
	bool isTouchingColor(size_t drawable_number, color clr) {	
		return false;
	}
};

void isTouchingColor_fulltest();
