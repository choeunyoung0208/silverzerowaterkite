//21812009 ������

#include <iostream>
#include <fstream>
#include <string>
#include "imageData.h"

using namespace std;

int main()
{
	string input_name; //����ó���� ���ϸ��� �����ϱ����� string class�� �̿��� ��ü ����.
	string output_name; //����ó�� ����� ���Ϸ� �����ϱ����� string class�� �̿��� ��ü ����.
	int mode; //����ڷκ��� ���ϴ� ����ó�� ����� �Է¹��� ���� ������ ���� ����.

	cout << "21812009 ������" << endl;

	cout << "����ó���� ���ϸ��� �Է����ּ���. (�� : test.pgm) : ";
	getline(cin, input_name); //����ڷκ��� �Է¹��� ���ڿ��� input_name�� ����.

	imageData imageprocessing(input_name); //imageData class�� ����� ��ü ����. 
	//input_name�� ������ �Լ� imageData�� argument.

	cout << "����ó���� ������ �������ּ���. (0 : Binarization, 1 : Inversion, 2 : My image processing method) : ";
	cin >> mode; //����ڷκ��� �Է¹��� ���� mode�� ����.
	imageprocessing.imageProc(mode); //���� ���� ��ü�� ����Լ��� ����Ͽ� ����ó��. 
	//mode�� imageProce�� argument.

	cout << "������ ���ϸ��� �Է����ּ���. (�� : test.pgm) : ";
	cin.ignore(); 
	//buffer pointer�� \n�� ����Ű�� ���� cin.ignore()�� ����Ͽ� �����Ͱ� ���� ������ ����Ű�� ����.
	getline(cin, output_name); //����ڷκ��� �Է¹��� ���ڿ��� output_name�� ����.
	imageprocessing.imageWrite(output_name); //���� ���� ��ü�� ����Լ��� ����Ͽ� ���� ����.
	//output_name�� imageWrite�� argument.

	return 0;
}
