// lab7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


using namespace std;

class vector3d

{
public:
	vector3d();
	~vector3d();
	void SetVector(const char * const caption);
	void display(const char * const caption);
	void summ(vector3d& vec1, vector3d& vec2);
	void razn(vector3d& vec1, vector3d& vec2);
	void dlina(vector3d& vec1);
	void scalar(vector3d& vec1, vector3d& vec2);

	static float cosinus(vector3d &vec1, vector3d &vec2);
	vector3d& operator= (vector3d& val);
	vector3d& operator= (float val);
	vector3d operator+ (vector3d& val);
	vector3d operator+ (float val);
	vector3d operator- (vector3d& val);
	vector3d operator- (float val);
private:
	int x, y, z;
};

vector3d::vector3d()
{
	x = 0;
	y = 0;
	z = 0;
}

vector3d::~vector3d()
{
}

vector3d& vector3d::operator= (vector3d& val)
{
	x = val.x;
	y = val.y;
	z = val.z;
	return *this;
}

vector3d& vector3d::operator= (float val)
{
	x = val;
	y = val;
	z = val;
	return *this;
}


vector3d vector3d::operator+ (vector3d& val)
{
	vector3d result;
	result.x = x + val.x;
	result.y = y + val.y;
	result.z = z + val.z;
	return result;
}

vector3d vector3d::operator+ (float val)
{
	vector3d result;
	result.x = x + val;
	result.y = y + val;
	result.z = z + val;
	return result;
}

vector3d vector3d::operator- (vector3d& val)
{
	vector3d result;
	result.x = x - val.x;
	result.y = y - val.y;
	result.z = z - val.z;
	return result;
}

vector3d vector3d::operator- (float val)
{
	vector3d result;
	result.x = x - val;
	result.y = y - val;
	result.z = z - val;
	return result;
}

void vector3d::SetVector(const char * const caption)
{
	cout << caption << endl;
	cout << "X = ";
	cin >> x;
	cout << "Y = ";
	cin >> y;
	cout << "Z = ";
	cin >> z;
}

void vector3d::summ(vector3d& vec1, vector3d& vec2)
{
	x = vec1.x + vec2.x;
	y = vec1.y + vec2.y;
	z = vec1.z + vec2.z;
}

void vector3d::razn(vector3d& vec1, vector3d& vec2)
{
	x = vec1.x - vec2.x;
	y = vec1.y - vec2.y;
	z = vec1.z - vec2.z;
}

void vector3d::dlina(vector3d& vec1)
{
	cout << "Длина вектора:" << endl;
	float u = sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y) + (vec1.z * vec1.z));
	cout << u << endl;
}

void vector3d::scalar(vector3d& vec1, vector3d& vec2)
{
	float dot = (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
	cout << "Результат скалярного произведения векторов:" << endl
		<< dot << endl;
}

float  vector3d::cosinus(vector3d& vec1, vector3d& vec2)
{
	float dot = (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
	float u = sqrt((vec1.x * vec1.x) + (vec1.y * vec1.y) + (vec1.z * vec1.z));
	float u2 = sqrt((vec2.x * vec2.x) + (vec2.y * vec2.y) + (vec2.z * vec2.z));
	float cos = (dot / (u * u2));

	return cos;
	/*

	это лишнее,
	надо вне класса это выводить, иначе нормальные математические выражения вроде cos(a + b - c) не напишешь
	cout << "Косинус угла между векторами:" << endl
	<< cos << endl;
	*/
}

void vector3d::display(const char * const caption)
{
	cout << caption << endl
		<< "Вектор с координатами:" << endl
		<< "X = " << x << endl
		<< "Y = " << y << endl
		<< "Z = " << z << endl;
}
int main(int argc, char *argv[])
{
	locale::global(locale(""));
	vector3d vector1;
	vector3d vector2;
	vector3d result_vector;

	int p;
	while (true)
	{
		cout << "------------------------Menu-------------------------" << endl
			<< "\t1 - Сложение двух векторов" << endl
			<< "\t2 - Разность двух векторов" << endl
			<< "\t3 - Высчитать длину вектра" << endl
			<< "\t4 - Скалярное произведение векторов" << endl
			<< "\t5 - Косинус угла между векторами" << endl
			<< "\t0 - Выход из программы" << endl
			<< "-----------------------------------------------------" << endl;
		cin >> p;
		system("cls");
		switch (p)
		{
		case 1:
			vector1.SetVector("Введите координаты вектора 1:");
			vector2.SetVector("Введите координаты вектора 2:");
			result_vector.summ(vector1, vector2);
			result_vector.display("-----------Result----------");
			break;
		case 2:
			vector1.SetVector("Введите координаты вектора 1:");
			vector2.SetVector("Введите координаты вектора 2:");
			result_vector.razn(vector1, vector2);
			result_vector.display("-----------Result----------");
			break;
		case 3:
			vector1.SetVector("Введите координаты вектора:");
			result_vector.dlina(vector1);
			break;
		case 4:
			vector1.SetVector("Введите координаты вектора 1:");
			vector2.SetVector("Введите координаты вектора 2:");
			result_vector.scalar(vector1, vector2);
			break;
		case 5:
			vector1.SetVector("Введите координаты вектора 1:");
			vector2.SetVector("Введите координаты вектора 2:");
			result_vector.cosinus(vector1, vector2);
			break;
		case 0:
			exit(0);
			break;
		}
	}
	system("PAUSE");
	return 0;
}
