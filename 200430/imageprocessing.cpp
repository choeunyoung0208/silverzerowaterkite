#include <iostream> //for cin, cout
#include <string> //for string handling
#include <fstream> //for file read write

using namespace std;

int main()
{
	//Read data from an image file
	//파일을 읽기를 위한 클래스 : ifstream(input file stream)
	ifstream inFile("C:\\deep.pgm", ios::in | ios::binary);
	//실행해서 동작하면, 파일이 읽힌것.

	//Read 1st line (P5)
	string inputLine;
	getline(inFile, inputLine); //inFIle에서 한 줄(\n까지)을 읽어서 inputLine에 저장함.
	cout << inputLine << endl;

	//어떤 경우는 # ---라는 안내 문구가 들어가는 경우가 있음. 이 경우에는 한 줄 더 읽어내야됨.
	//파일을 메모장에 넣어보고 알기.
	//getline(inFile, inputLine);

	//Read 2nd line (1000, ***)
	int numCols, numRows;
	inFile >> numCols >> numRows;
	//int가 4bytes이므로, 4bytes(disk memory의? 4칸?)을 읽어서 숫자(정수형)로 바꾼 다음에 numCols와 numRows에 넣어줌
	cout << numCols << ' ' << numRows << endl;

	//Read 3rd line (max value)
	//max value는 bit data가 픽셀당 8bits인지 16bits인지 알려주는 중요한 지표.
	int maxValue;
	inFile >> maxValue; //inFile에서 읽는데, 공백으로 다음 글자를 구분.
	//그래서, 다음 공백까지 읽어낸 다음(=/= disk memory의 4칸..?) 에 바꿔서 maxValue로 넣어줌 들어가야 될 공간이 int이기 때문에, 이렇게 알아서 바꿔줌. '>>' 얘가!
	cout << maxValue;

	//End of header

	//prepare dynamic memory to store image data (RAM space의 HEAP? 영역에다가 필요한 용량 만큼 할당)
	//RAM 영역에다가 저장해야 될 공간을 미리 확보해놓음.
	unsigned char* data1D = new unsigned char[numCols * numRows * sizeof(unsigned char)]; //동적 메모리 할당..? C++에서는 new함수를 사용함.
	//포인터를 초기화를 하기 위해 new라는 함수를 사용 => 시작주소를 return 해주는 것이 data1D에 저장됨
	//[] 안의 단위는 byte => new가 numCols * numRows * sizeof(unsigned char)bytes를 확보함..

	//Read raw data
	inFile.read(reinterpret_cast<char*>(data1D), numCols * numRows * sizeof(unsigned char));
	//file pointer가 가리키고 있는 주소(파일 메모리?)로 가서 numCols * numRows * sizeof(unsigned char)bytes만큼을 읽은 다음, data1D주소(RAM 메모리?)로 copy해줌..

	//end of file
	inFile.close(); //decrease file counter to 0

	//RAM으로 갖고왔음====================================================

	//image processing: binarization
	//2차원 배열 형태로 읽어냄
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			//cout << '(' << row << ',' << col << ')' << int(data1D[row * numCols + col]);
			//data1D[row*numCols+col]이렇게 읽은게 byte이므로, 이걸 int형으로 바꿈.

			//여기는 왜 int가 아니지?
			//data1D[row*numCols+col] : data1D의 row*numCols+col번지의 데이터 값일텐데,이 자체는 data1D의 datatype이 char이므로, 문자로 출력됨? 숫자로 나와도 숫자=/=문자?
			if (data1D[row * numCols + col] > 100) //binarization (gray : 8bits, binary : 1bit)
				data1D[row * numCols + col] = 255;
			else
				data1D[row * numCols + col] = 0;
		}
		//cout << row << endl;
	}
	cout << "Processed!" << endl;

	//Save the result into pgm image
	//파일을 저장하기 위한 클래스 : ofstream
	ofstream outFile;
	outFile.open("processed.pgm", ios::binary);

	//check the file
	//쓰기가 문제없는지 확인
	if (!outFile) //outFile이라는 객체가 0이 아닌걸 return해야 정상적인거. 1이면 실행하는 것 같음..
	{
		cout << "Cannot open" << endl;
		exit(1); //..?
	}
	cout << "File opened to write" << endl;

	//Write head
	outFile << "P5" << endl; //outFile이라는 객체에다가 '<<' 해주면 P5라는 문자열이 써짐.
	outFile << numCols << " " << numRows << endl;
	outFile << maxValue << endl;
	cout << "Finished to write header" << endl;

	outFile.write(reinterpret_cast<char*>(data1D), numCols * numRows * sizeof(unsigned char));
	//data1D 주소부터 시작해서 numCols * numRows * sizeof(unsigned char)bytes 만큼 읽어서 outFile에 쓰기.
	//RAM에서 쓰고있는 pointer와 outFile에서 쓰고있는 file pointer를 호환되게하기위해서, 형변환 해줌. data1D =>  reinterpret_cast<char*>(data1D)

	//파일을 쓰기위해서 열고, 다 끝냈으면 닫아야됨..그래야 읽어볼 수 있음.....
	outFile.close(); //파일 닫기

	cout << "Finished" << endl;

}