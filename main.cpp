#include <iostream>
bool isPyth(unsigned a, unsigned b, unsigned c)
{
bool p = a*a==b*b+c*c;
p = p || (b*b==a*a+c*c);
p = p || (c*c==a*a+b*b);
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

	else if (std::cin.fail()) 
		{
		std::cerr << "not a sequency";
		return 1;
		} 
}
