//21812009 ������
#include <iostream> //Ű����, ������� ������� ����ϴ� iostream Ŭ������ �ҷ���.
#include <string> //���ڿ� �����͸� ����ϱ� ���� string Ŭ����(�Ǵ� ���̺귯�� �����)�� �ҷ���.
#include <fstream> //���� �����(�б�, ����)�� ����ϴ� fstream Ŭ������ �ҷ���.

using namespace std;

void readImage(string fname, unsigned char* a, unsigned char* b, int* c, int* d, int* e) //�Է��� call-by-value. ����� pointer ���. 
{
	//������ �б�
	ifstream inFile(fname, ios::binary);

	/*
	���� �б⸦ ����ϴ� Ŭ���� : ifstream(input file stream)
	������ �б����� ���� �Է�(�б�)�� ����ϴ� Ŭ������ ifstreamŬ������ inFile ��ü�� �����ϰ�, ������ ����(fname)�� ������.
	����ϴ� ������ ���������̹Ƿ� ios::binary��� flag�� �־� binary�� �д´ٴ� ���� �˷���� �ȴ�.
	*/

	//===============================================================================================================================================

	//�ڿ��� ��� �б� 

	/*����ó���� ����) �޸������� ����κ��� Ȯ���� ���
	P5
	600  677
	255
	=> �ȼ������� �о���� ���� ���� ����� �о�;ߵȴ�!
	*/

	string inputLine; //ù��° ������ �� ���� �о���� ����, string Ŭ������ ����� ���ڿ��� �޴� ��ü inputLine�� ����.
	getline(inFile, inputLine); //inFIle�κ��� �� ��(\n����)�� �о inputLine�� ������.
	cout << inputLine << endl;
	int numCols, numRows;
	inFile >> numCols >> numRows; //inFile���� 600 677���� �а�, numCols numRows ������ �־���. (�������� �Է� ����)
	*c = numRows; //������ ���� c�� numRows�� �����Ŵ. 
	*d = numCols; //������ ���� d�� numCols�� �����Ŵ.
	cout << *d << ' ' << *c << endl;

	int maxValue;
	inFile >> maxValue; //inFile�κ��� 255�� �о��.
	*e = maxValue; //������ ���� e�� maxValue�� �����Ŵ.
	cout << maxValue << endl;

	//===============================================================================================================================================
	
	//���ȼ������� �о RAM����(���� �޸� �Ҵ��� ������) ��������
	inFile.read(reinterpret_cast<char*>(a), numCols * numRows * sizeof(unsigned char));

	/*
	����(inFile)���� file pointer�� ����Ű�� �ִ� �ּҷ� ���� numCols * numRows * sizeof(unsigned char)bytes��ŭ�� �����͸� ���� ����,
	a�� ����Ű�� �ּҷ� copy����.

	reinterpret_cast<char*>(a)
	=> RAM���� �����ִ� pointer�� inFile���� �����ִ� file pointer�� ȣȯ�ǰ��ϱ����ؼ�, ����ȯ�� ����.
	*/

	inFile.close(); //������ �� ���� ����, close()�Լ��� ���.
	//usage counter�� 0���� �ٲ��ִ� ������ ��, �ٸ� ������� ������ �� ������ �˷���.
}

void imageProcessInversion(unsigned char* a, unsigned char* b, int numRows, int numCols)
{
	//�ڿ���ó�� : ����
	for (int row = 0; row < numRows; row++) //0<=row<677�� ������ �����ϸ� �ݺ��� ����. 677�� �ݺ�.
	{
		for (int col = 0; col < numCols; col++) //0<=col<600�� ������ �����ϸ� �ݺ��� ����. 600�� �ݺ�.
		{
			b[row * numCols + col] = 255 - a[row * numCols + col];
		}
	}
}

void imageProcessBinarization(unsigned char* a, unsigned char* b, int numRows, int numCols)
{
	//�ڿ���ó�� : ����ȭ
	for (int row = 0; row < numRows; row++) //0<=row<677�� ������ �����ϸ� �ݺ��� ����. 677�� �ݺ�.
	{
		for (int col = 0; col < numCols; col++) //0<=col<600�� ������ �����ϸ� �ݺ��� ����. 600�� �ݺ�.
		{
			if (a[row * numCols + col] > 128)
				b[row * numCols + col] = 255;
			else
				b[row * numCols + col] = 0;
		}
	}
}

void writeImage(string fname, unsigned char* b, int numRows, int numCols, int maxValue)
{
	//�ڿ���ó�� �� ������ .pgm���Ϸ� �����ϱ�.
	ofstream outFile;

	/*
	������ �����ϱ� ���� Ŭ���� : ofstream
	������ �����ϱ� ���� ofstream Ŭ������ �̿��� outFile��ü�� ����.
	*/

	outFile.open(fname, ios::binary);

	//���� ����(outFile)�� ������ ����(fname)�� ��������. �������Ϸ� �����ϹǷ�, ios::binary��� flag�� ������.

	//===============================================================================================================================================

	//������ ���� ���� Ȯ��
	//������ �����ϴµ� ������ �ִ��� Ȯ���ϱ� ����!

	if (!outFile) //outFile�̶�� ��ü�� 0�� �ƴ� ���� return�ؾ� �������� ��! outFile�� 0�� return�ϸ� ������ �����ϴ� �Ϳ� ������ ����.
	{
		cout << "���� ���� ����." << endl; //������ ������ �� ������ ������ ����.
		exit(1); //error�� �˷��ְ�, ���α׷� ����.
	}
	cout << "������ ���� ���� ���� ���� ����." << endl; //������ ������ �� ������ ������ ����.

	//===============================================================================================================================================
	
	//������ ����
	//������ ���µ� ������ ������ ����.

	//������ ���� : ��� �κ� �ۼ�
	//ó���� �о��� ����κа� ���� �ۼ��ϸ� �ȴ�!
	outFile << "P5" << endl; //outFile ��ü�� 'P5' �Է�.
	outFile << numCols << ' ' << numRows << endl; 
	outFile << maxValue << endl;

	//������ ���� : �ȼ� �����Ͱ� �ۼ� 
	outFile.write(reinterpret_cast<const char*> (b), numCols * numRows * sizeof(unsigned char));

	/*
	RAM������ b �ּҺ��� �����ؼ� numCols * numRows * sizeof(unsigned char)bytes ��ŭ �о outFile�� ����.
	reinterpret_cast<const char*>(b)
	=> RAM���� �����ִ� pointer�� outFile���� �����ִ� file pointer�� ȣȯ�ǰ��ϱ����ؼ� ����ȯ�� ����. const�� RAM�� �ִ� �����͸� �״�� �о��������(read only)
	*/

	outFile.close(); //���� ���⸦ �Ϸ��� ��� close()�Լ��� �̿��� ������ �ݾ��ֱ�. 
}

int main()
{
	cout << "21812009 ������" << endl;

	string ifname; //����ó���� ���ϸ��� �Է¹ޱ� ���� string class�� ����Ͽ� ��ü�� ����.
	cout << "����ó���� ���ϸ��� �Է����ּ��� (�� : test.pgm) : ";
	getline(cin, ifname); //����ڷκ��� �Է��� ���� ���� �� ��(\n����)�� �о ifname�� ������.

	//���� �޸� �Ҵ�
	unsigned char* a = new unsigned char[600 * 677 * sizeof(unsigned char)]; //readImage�Լ��� ����� ����ó���� ���Ϸκ��� ���� �ȼ����� ���� ������ ����.
	unsigned char* b = new unsigned char[600 * 677 * sizeof(unsigned char)]; //inversion �Ǵ� binarization�� ������ ��� �ȼ����� ������ ������ ����.

	int rows, cols, max;
	readImage(ifname, a, b, &rows, &cols, &max); //������ �а� ���ִ� �Լ� readImage�� ȣ��
	
	int input;

	cout << "����ó���� ������ �������ּ���. (1 : Inversion, 2 : Binarization) : ";
	cin >> input;

	if (input == 1)
	{
		imageProcessInversion(a, b, rows, cols);
	}

	else if (input == 2)
	{
		imageProcessBinarization(a, b, rows, cols);
	}

	else
	{
		cout << "��ȿ���� ���� ����ó�� ����Դϴ�. ���α׷��� �ٽ� �������ּ���." << endl;
		exit(1);
	}

	string ofname; //����ó���� ������ ������ �� ������ �̸��� �Է¹ޱ� ���� string class�� ����Ͽ� ��ü�� ����.
	cout << "������ ���ϸ��� �Է����ּ��� (��  : test.pgm) : ";
	cin.ignore(); //buffer pointer�� \n�� ����Ű�� ���� cin.ignore()�� ����Ͽ� �����Ͱ� ���� ������ ����Ű�� ����.
	getline(cin, ofname); //����ڷκ��� �Է��� ���� ���� �� ��(\n����)�� �о ofname�� ������.
	writeImage(ofname, b, rows, cols, max); //������ ���� ���ִ� �Լ� writeImage�� ȣ��.

	delete[] a;
	delete[] b; //���� �޸𸮸� �Ҵ����ذ��� �׻� delete�� �����ߵȴ�.

	return 0;
}