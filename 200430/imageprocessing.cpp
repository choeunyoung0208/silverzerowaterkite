#include <iostream> //for cin, cout
#include <string> //for string handling
#include <fstream> //for file read write

using namespace std;

int main()
{
	//Read data from an image file
	//������ �б⸦ ���� Ŭ���� : ifstream(input file stream)
	ifstream inFile("C:\\deep.pgm", ios::in | ios::binary);
	//�����ؼ� �����ϸ�, ������ ������.

	//Read 1st line (P5)
	string inputLine;
	getline(inFile, inputLine); //inFIle���� �� ��(\n����)�� �о inputLine�� ������.
	cout << inputLine << endl;

	//� ���� # ---��� �ȳ� ������ ���� ��찡 ����. �� ��쿡�� �� �� �� �о�ߵ�.
	//������ �޸��忡 �־�� �˱�.
	//getline(inFile, inputLine);

	//Read 2nd line (1000, ***)
	int numCols, numRows;
	inFile >> numCols >> numRows;
	//int�� 4bytes�̹Ƿ�, 4bytes(disk memory��? 4ĭ?)�� �о ����(������)�� �ٲ� ������ numCols�� numRows�� �־���
	cout << numCols << ' ' << numRows << endl;

	//Read 3rd line (max value)
	//max value�� bit data�� �ȼ��� 8bits���� 16bits���� �˷��ִ� �߿��� ��ǥ.
	int maxValue;
	inFile >> maxValue; //inFile���� �дµ�, �������� ���� ���ڸ� ����.
	//�׷���, ���� ������� �о ����(=/= disk memory�� 4ĭ..?) �� �ٲ㼭 maxValue�� �־��� ���� �� ������ int�̱� ������, �̷��� �˾Ƽ� �ٲ���. '>>' �갡!
	cout << maxValue;

	//End of header

	//prepare dynamic memory to store image data (RAM space�� HEAP? �������ٰ� �ʿ��� �뷮 ��ŭ �Ҵ�)
	//RAM �������ٰ� �����ؾ� �� ������ �̸� Ȯ���س���.
	unsigned char* data1D = new unsigned char[numCols * numRows * sizeof(unsigned char)]; //���� �޸� �Ҵ�..? C++������ new�Լ��� �����.
	//�����͸� �ʱ�ȭ�� �ϱ� ���� new��� �Լ��� ��� => �����ּҸ� return ���ִ� ���� data1D�� �����
	//[] ���� ������ byte => new�� numCols * numRows * sizeof(unsigned char)bytes�� Ȯ����..

	//Read raw data
	inFile.read(reinterpret_cast<char*>(data1D), numCols * numRows * sizeof(unsigned char));
	//file pointer�� ����Ű�� �ִ� �ּ�(���� �޸�?)�� ���� numCols * numRows * sizeof(unsigned char)bytes��ŭ�� ���� ����, data1D�ּ�(RAM �޸�?)�� copy����..

	//end of file
	inFile.close(); //decrease file counter to 0

	//RAM���� �������====================================================

	//image processing: binarization
	//2���� �迭 ���·� �о
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			//cout << '(' << row << ',' << col << ')' << int(data1D[row * numCols + col]);
			//data1D[row*numCols+col]�̷��� ������ byte�̹Ƿ�, �̰� int������ �ٲ�.

			//����� �� int�� �ƴ���?
			//data1D[row*numCols+col] : data1D�� row*numCols+col������ ������ �����ٵ�,�� ��ü�� data1D�� datatype�� char�̹Ƿ�, ���ڷ� ��µ�? ���ڷ� ���͵� ����=/=����?
			if (data1D[row * numCols + col] > 100) //binarization (gray : 8bits, binary : 1bit)
				data1D[row * numCols + col] = 255;
			else
				data1D[row * numCols + col] = 0;
		}
		//cout << row << endl;
	}
	cout << "Processed!" << endl;

	//Save the result into pgm image
	//������ �����ϱ� ���� Ŭ���� : ofstream
	ofstream outFile;
	outFile.open("processed.pgm", ios::binary);

	//check the file
	//���Ⱑ ���������� Ȯ��
	if (!outFile) //outFile�̶�� ��ü�� 0�� �ƴѰ� return�ؾ� �������ΰ�. 1�̸� �����ϴ� �� ����..
	{
		cout << "Cannot open" << endl;
		exit(1); //..?
	}
	cout << "File opened to write" << endl;

	//Write head
	outFile << "P5" << endl; //outFile�̶�� ��ü���ٰ� '<<' ���ָ� P5��� ���ڿ��� ����.
	outFile << numCols << " " << numRows << endl;
	outFile << maxValue << endl;
	cout << "Finished to write header" << endl;

	outFile.write(reinterpret_cast<char*>(data1D), numCols * numRows * sizeof(unsigned char));
	//data1D �ּҺ��� �����ؼ� numCols * numRows * sizeof(unsigned char)bytes ��ŭ �о outFile�� ����.
	//RAM���� �����ִ� pointer�� outFile���� �����ִ� file pointer�� ȣȯ�ǰ��ϱ����ؼ�, ����ȯ ����. data1D =>  reinterpret_cast<char*>(data1D)

	//������ �������ؼ� ����, �� �������� �ݾƾߵ�..�׷��� �о �� ����.....
	outFile.close(); //���� �ݱ�

	cout << "Finished" << endl;

}