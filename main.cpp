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
		std::cout << "Попробуйте ещё раз -> ";
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
	if (x<0)return false;
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
	
	
	std::vector<int> next(n, -1);  //массив восстановления пути
	std::vector<int> used(n, 0);  //массив уже пройденных вершин
	std::vector<int> dist(n);    //массив длины пути от начальной вершины
	
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
	--a; --b;         //уменьшаем на единицу для удобности
	bool ok = false; //дошли ли до искомой вершины
	std::queue<int> d;   //очередь для обхода в глубину
	d.push(a);     //начальная вершина для обхода
	dist[a] = 0;  //длина от начальной до начальной - 0
	while (!d.empty() && !ok) //пока не пройдем по всем вершинам или не найдем нужную
	{
		int w = d.front(); //временная переменная, чтобы проще обращаться к нашей текущей вершине
		used[w] = 1;      //помечаем нашу вершину посещенной, чтобы не зацикливаться
		for (int i = 0; i < n; ++i)
		{
			if (g[w][i] && !used[i]) //если есть ребро из нашей вершины в i-тую и мы в ней не были
			{
				dist[i] = dist[w] + 1; //длина пути до i-той вершины - длина пути текущей вершины + 1
				next[w] = i; //следующая для нашего пути вершина - i-тая
				if (i == b) //если i-тая вершина конечная
					ok = true; //выход
				else
					d.push(i); //иначе - обходим и ее тоже
			}
		}
		d.pop(); //удаляем уже пройденную вершину
	}
	if (ok) //если мы вышли, потому что дошли до искомой
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
		std::cout << "Поробуйте еще раз -> ";
		std::cin >> y;
	}
	return y;
}


void main()
{
	setlocale(LC_ALL, "rus");
	int n;
	std::cout << "Введите количество вершин -> ";
	n = input();
	std::vector<int> next(n, -1);  //массив восстановления пути
	std::vector<int> used(n, 0);  //массив уже пройденных вершин
	std::vector<int> dist(n);    //массив длины пути от начальной вершины
	std::vector< std::vector<int> > g(n, std::vector<int>(n)); //матрица смежности
	std::cout << "Введите матрицу " << n << "x" << n << std::endl;
	for (int i = 0; i < n; ++i) //n столбцов матрицы
		for (int j = 0; j < n; ++j) //n строк матрицы
			std::cin >> g[i][j]; //считывание матрицы смежности - 1 = ребро, 0 = ребра нет
	int a, b;  //начало и конец пути
	std::cout << "Стартовая вершина -> "; //считываем начальную и конечную точки
	a = InputTop(n);
	std::cout << "Конечная вершина -> ";
	b = InputTop(n);
	--a; --b;         //уменьшаем на единицу для удобности
	bool ok = false; //дошли ли до искомой вершины
	std::queue<int> d;   //очередь для обхода в глубину
	d.push(a);     //начальная вершина для обхода
	dist[a] = 0;  //длина от начальной до начальной - 0
	while (!d.empty() && !ok) //пока не пройдем по всем вершинам или не найдем нужную
	{
		int w = d.front(); //временная переменная, чтобы проще обращаться к нашей текущей вершине
		used[w] = 1;      //помечаем нашу вершину посещенной, чтобы не зацикливаться
		for (int i = 0; i < n; ++i)
		{
			if (g[w][i] && !used[i]) //если есть ребро из нашей вершины в i-тую и мы в ней не были
			{
				dist[i] = dist[w] + 1; //длина пути до i-той вершины - длина пути текущей вершины + 1
				next[w] = i; //следующая для нашего пути вершина - i-тая
				if (i == b) //если i-тая вершина конечная
					ok = true; //выход
				else
					d.push(i); //иначе - обходим и ее тоже
			}
		}
		d.pop(); //удаляем уже пройденную вершину
	}
	if (ok) //если мы вышли, потому что дошли до искомой
	{

		std::cout << "Длина пути " << dist[b] << std::endl;  //длина пути
		std::cout << "Путь между вершинами ";
		for (int i = a; i != -1; i = next[i])
			std::cout << i + 1 <<" "; //выводим все вершины в порядке прохождения
		std::cout << std::endl;;
	}
	else
		std::cout << "Путь не найден" << std::endl; //если мы так и не дошли до искомой - выводим сообщение 

	system("pause");
}