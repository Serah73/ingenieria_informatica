class hormiga
{
private:
	int x_;
	int y_;
	char orientation_;
public:
	hormiga(int x, int y);
	~hormiga();
	
	void right();
	void left();
	void up();
	void down();

	char get_orientation();
	int get_x();
	int get_y();

	void set_orientation(char orientation);
	void set_x(int x);
	void set_y(int y);
};