//21812009 ������
//class ������

#include "imageData.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

imageData::imageData(string fname)
{
	ifstream inFile(fname, ios::binary);


	//�ڿ��� ��� �б�

	getline(inFile, a);
	inFile >> cols >> rows;
	inFile >> maxvalue;


	//�ڵ��� �޸� �Ҵ�
	pixelValues = new unsigned char[rows * cols * sizeof(unsigned char)]; 
	pixelProcessed = new unsigned char[rows * cols * sizeof(unsigned char)]; 

	inFile.read(reinterpret_cast<char*>(pixelValues), rows * cols * sizeof(unsigned char));
}

int imageData::imageProc(int Mode)
{
	switch (Mode)
	{
	case 0: //image binarization
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				if (pixelValues[row * cols + col] > 128)
					pixelProcessed[row * cols + col] = 255;
				else
					pixelProcessed[row * cols + col] = 0;
			}
		}
		break;

	case 1: //image inversion
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				pixelProcessed[row * cols + col] = 255 - pixelValues[row * cols + col];
			}
		}
		break;

	case 2: //my image processing method

		unsigned char b=0;

		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				pixelProcessed[row * cols + col] = pixelValues[row * cols + col]/2;
				//���� ������ ������ ���� ��� 2�� ���� ���� ���󺸴� �� ��ο� ������ ����ϰ� ��.
			}
		}

		break;
	}

	return 0;
}

int imageData::imageWrite(string fname)
{
	ofstream outFile(fname, ios::binary);
	outFile << a << endl;
	outFile << cols << ' ' << rows << endl;
	outFile << maxvalue << endl;

	outFile.write(reinterpret_cast<const char*>(pixelProcessed), rows * cols * sizeof(unsigned char));

	outFile.close();

	cout << "���� ���� �Ϸ�." << endl;

	return 0;
}

imageData::~imageData(void)
{
	delete[] pixelValues;
	delete[] pixelProcessed;
}