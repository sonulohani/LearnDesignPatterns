/*
Containment
-----------------------------------------------------------
If to inner class member functions, we made aware about the
reference of an object of outer class, then its possible to
access private members of out class directly.

However, vice versa is not true.
*/

class B
{
public:
	class A
	{
	public:
		void f( B *pb )
		{
			pb->i = 1; // can access private member of outer class
		}
	private:
		int j;
	};

public:
	//void g( A *pa )
	//{
	//	pa->j = 1; // connot access private member of inner class
	//}
private:
	int i;
};

//Association - use and throw
//class A
//{
//public:
//	void f( B *pb )
//	{
//		pb->i = 1; // can access private member of outer class
//	}
//private:
//	int j;
//};

int main()
{
	B b;
	B::A a;
	a.f(&b);

	return 0;
}