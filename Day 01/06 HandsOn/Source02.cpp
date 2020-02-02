#include <vector>
using namespace std;

class A
{
private:
	typedef vector<int> _collection;
	typedef _collection::iterator _iterator;

public:
	class B
	{
	private:
		_iterator it;
	};
private:
	_collection data;
};

int main()
{
	return 0;
}