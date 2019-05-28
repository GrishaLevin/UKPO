#include <iostream>
#include <queue>
#include <ctype.h>

int input()
{
	unsigned short int y;
	std::cin >> y;
	while (std::cin.fail() || std::cin.get() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "try again -> ";
		std::cin >> y;
	}
	return y;
}

bool checkmatrixnum(int x)
{
	if (x == 1) return true;
	if (x == 0) return true;
	else return false;
}

bool checktops(int x)
{
	if (x > 1 && x < 11) return true;
	if (x == 0) return false;
	if (x < 0) return false;
	else return false;
}

bool checkstartandendtops(int x, int y)
{
	if ((0 >= x) || (x > y)) return false;
	else return true;
}

bool control(int x, int y)
{
	if (x == y) return false;
	else return true;
}

bool finish(int n, int a,int b, int x)
{
	
	
	std::vector<int> next(n, -1);  
	std::vector<int> used(n, 0);  
	std::vector<int> dist(n);    
	
	std::vector< std::vector<int> > g(n, std::vector<int>(n));

	if (x==1)
	{ 
	g[0][0] = 0;
	g[0][1] = 1;
	g[0][2] = 1;
	g[1][0] = 1;
	g[1][1] = 0;
	g[1][2] = 1;
	g[2][0] = 1;
	g[2][1] = 1;
	g[2][2] = 0;
	}

	if (x==0)
		{
		g[0][0] = 0;
		g[0][1] = 0;
		g[0][2] = 0;
		g[1][0] = 0;
		g[1][1] = 0;
		g[1][2] = 1;
		g[2][0] = 0;
		g[2][1] = 1;
		g[2][2] = 0;

	}
	--a; --b;         
	bool ok = false; 
	std::queue<int> d;  
	d.push(a);     
	dist[a] = 0;  
	while (!d.empty() && !ok)
	{
		int w = d.front(); 
		used[w] = 1;     
		for (int i = 0; i < n; ++i)
		{
			if (g[w][i] && !used[i]) 
			{
				dist[i] = dist[w] + 1; 
				next[w] = i;
				if (i == b) 
					ok = true; 
				else
					d.push(i); 
			}
		}
		d.pop(); 
	}
	if (ok) 
	{

		return true;
	}
	else
		return false;

}

int InputTop(int n)
{
	unsigned short int y;
	std::cin >> y;
	while ((0 >= y) || (y > n))
	{
		std::cout << "try again -> ";
		std::cin >> y;
	}
	return y;
}

//--------------------------------------------------------------------------------------------------

bool CorrectInputTops()
{
	return checktops(5);
}

bool NegativeInputTops()
{
	return !checktops(-5);
}

bool ZeroInputTops()
{
	return !checktops(0);
}

bool InputOneMatrix()
{
	return checkmatrixnum(1);
}

bool InputZeroMatrix()
{
	return checkmatrixnum(0);
}

bool IncorrectInputMatrix()
{
	return !checkmatrixnum(5);
}

bool NegativeInputMatrix()
{
	return !checkmatrixnum(-5);
}

bool GoodWay()
{
	return checkstartandendtops(4, 10);
}

bool ZeroWay()
{
	return !checkstartandendtops(0, 10);
}

bool NegativeWay()
{
	return !checkstartandendtops(-5, 10);
}

bool BadWay()
{
	return !checkstartandendtops(5, 2);
}

bool GoodNumTop()
{
	return control(1, 5);
}

bool BadNumTop()
{
	return !control(3, 3);
}

bool GoodAns()
{
	return finish(3, 1, 3, 1);
}

bool BadAns()
{
	return !finish(3, 1, 3, 0);
}

int main()
{
	if (!NegativeInputTops()
		|| !ZeroInputTops()
		|| !InputOneMatrix()
		|| !InputZeroMatrix()
		|| !IncorrectInputMatrix()
		|| !NegativeInputMatrix()
		|| !GoodWay()
		|| !ZeroWay()
		|| !NegativeWay()
		|| !BadWay()
		|| !GoodNumTop()
		|| !BadNumTop()
		|| !GoodAns()
		|| !BadAns())
		return 1;
	return 0;
}
