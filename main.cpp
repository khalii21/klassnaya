#include <iostream>
#include <limits>
bool isPyth(unsigned a, unsigned b, unsigned c)
{
bool p = a*a==b*b+c*c;
p = p || (b*b==a*a+c*c);
p = p || (c*c==a*a+b*b);
return p;
}
unsigned max_u()
{
	using namespace std;
	using u_limit = numeric_limits< unsigned >;
	return u_limit::max();
}
bool perepolnenie(unsigned a, unsigned b, unsigned c)
{
bool p = a*a > max_u() - b*b;
p = p || b*b > max_u() - c*c;
p = p || a*a > max_u() - c*c;
return p;
}
int main()
{
	using u_t = unsigned;
	u_t a = 0;
	u_t b =0;
	u_t c = 0;
	std::cin >> c >> b;
	size_t count = 0;
	while (std::cin >> a)
		{
		count+=isPyth(a,b,c) ? 1:0;
		c = b;
		b = a;
		}
	if (std::cin.eof())
		{
		std::cout << count;
		std::cout << "\n";
		}
	else if (perepolnenie(a,b,c))
		{
		std::cerr << "overflow\n";
		return 2;
		}
	else if (std::cin.fail())
		{
		std::cerr << "not a sequency\n";
		return 1;
		}
}
