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
		std::cout << "���������� ��� ��� -> ";
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
	
	
	std::vector<int> next(n, -1);  //������ �������������� ����
	std::vector<int> used(n, 0);  //������ ��� ���������� ������
	std::vector<int> dist(n);    //������ ����� ���� �� ��������� �������
	
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
	--a; --b;         //��������� �� ������� ��� ���������
	bool ok = false; //����� �� �� ������� �������
	std::queue<int> d;   //������� ��� ������ � �������
	d.push(a);     //��������� ������� ��� ������
	dist[a] = 0;  //����� �� ��������� �� ��������� - 0
	while (!d.empty() && !ok) //���� �� ������� �� ���� �������� ��� �� ������ ������
	{
		int w = d.front(); //��������� ����������, ����� ����� ���������� � ����� ������� �������
		used[w] = 1;      //�������� ���� ������� ����������, ����� �� �������������
		for (int i = 0; i < n; ++i)
		{
			if (g[w][i] && !used[i]) //���� ���� ����� �� ����� ������� � i-��� � �� � ��� �� ����
			{
				dist[i] = dist[w] + 1; //����� ���� �� i-��� ������� - ����� ���� ������� ������� + 1
				next[w] = i; //��������� ��� ������ ���� ������� - i-���
				if (i == b) //���� i-��� ������� ��������
					ok = true; //�����
				else
					d.push(i); //����� - ������� � �� ����
			}
		}
		d.pop(); //������� ��� ���������� �������
	}
	if (ok) //���� �� �����, ������ ��� ����� �� �������
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
		std::cout << "��������� ��� ��� -> ";
		std::cin >> y;
	}
	return y;
}


void main()
{
	setlocale(LC_ALL, "rus");
	int n;
	std::cout << "������� ���������� ������ -> ";
	n = input();
	std::vector<int> next(n, -1);  //������ �������������� ����
	std::vector<int> used(n, 0);  //������ ��� ���������� ������
	std::vector<int> dist(n);    //������ ����� ���� �� ��������� �������
	std::vector< std::vector<int> > g(n, std::vector<int>(n)); //������� ���������
	std::cout << "������� ������� " << n << "x" << n << std::endl;
	for (int i = 0; i < n; ++i) //n �������� �������
		for (int j = 0; j < n; ++j) //n ����� �������
			std::cin >> g[i][j]; //���������� ������� ��������� - 1 = �����, 0 = ����� ���
	int a, b;  //������ � ����� ����
	std::cout << "��������� ������� -> "; //��������� ��������� � �������� �����
	a = InputTop(n);
	std::cout << "�������� ������� -> ";
	b = InputTop(n);
	--a; --b;         //��������� �� ������� ��� ���������
	bool ok = false; //����� �� �� ������� �������
	std::queue<int> d;   //������� ��� ������ � �������
	d.push(a);     //��������� ������� ��� ������
	dist[a] = 0;  //����� �� ��������� �� ��������� - 0
	while (!d.empty() && !ok) //���� �� ������� �� ���� �������� ��� �� ������ ������
	{
		int w = d.front(); //��������� ����������, ����� ����� ���������� � ����� ������� �������
		used[w] = 1;      //�������� ���� ������� ����������, ����� �� �������������
		for (int i = 0; i < n; ++i)
		{
			if (g[w][i] && !used[i]) //���� ���� ����� �� ����� ������� � i-��� � �� � ��� �� ����
			{
				dist[i] = dist[w] + 1; //����� ���� �� i-��� ������� - ����� ���� ������� ������� + 1
				next[w] = i; //��������� ��� ������ ���� ������� - i-���
				if (i == b) //���� i-��� ������� ��������
					ok = true; //�����
				else
					d.push(i); //����� - ������� � �� ����
			}
		}
		d.pop(); //������� ��� ���������� �������
	}
	if (ok) //���� �� �����, ������ ��� ����� �� �������
	{

		std::cout << "����� ���� " << dist[b] << std::endl;  //����� ����
		std::cout << "���� ����� ��������� ";
		for (int i = a; i != -1; i = next[i])
			std::cout << i + 1 <<" "; //������� ��� ������� � ������� �����������
		std::cout << std::endl;;
	}
	else
		std::cout << "���� �� ������" << std::endl; //���� �� ��� � �� ����� �� ������� - ������� ��������� 

	system("pause");
}