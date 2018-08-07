#include <vector>

class cuadricula
{

private:
	int width_;
	int height_;
	vector<vector<int> > grid_;
public:
	cuadricula(int width, int height);
	~cuadricula();
	
	int get(int x, int y);
	void set(int x, int y, int colour);
};