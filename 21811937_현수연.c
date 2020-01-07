수정수정
#include <stdio.h>     // 기본 헤더파일
#include <time.h>     // 날짜와 시간에 관한 헤더파일
#include <malloc.h>     // malloc 함수 사용을 위한 헤더파일

void swap(int* a, int* b)     // 포인터 변수 이용, 출력이 없는 경우라 void로 함수 선언, swap할 매개변수 2개 선언
{
	int temp;     // temp 변수 선언 (임시 저장해둘 변수)
	temp = *a;     // temp 변수에 포인터 변수 a의 실제 값 대입 (temp에 a값 저장)
	*a = *b;     // 포인터 변수 a의 실제 값에 포인터 변수 b의 실제 값 대입 (a에 b값을 옮김)
	*b = temp;     // 포인터 변수 b의 실제 값에 temp 변수 값 대입 (b에 아까 저장해둔 a값을 옮김)
}     // swap 함수 선언 (두 변수의 값을 바꿔주는 함수)

void sorting(int* arr, int N)     // 포인터 변수 이용, 출력이 없는 경우라 void로 함수 선언, 정렬할 배열과 배열의 크기에 대한 매개변수 선언
{
	for (int i = 0; i < N - 1; i++)     // for문 이용, 범위는 배열의 크기 - 1 (맨 마지막은 확인 필요 X)
	{
		for (int j = 0; j < N - 1 - i; j++)     // 이중 for문 이용 , 범위는 배열의 크기 - 1 - i (n회차 할 시에 이미 정렬된 제일 큰 수를 빼줘야 하기 때문에 - i)
		{
			if (*(arr + j) > *(arr + j + 1))     // 조건문 if 사용, 이어져 있는 두 값을 비교하여 왼쪽의 값이 더 클 경우
				swap(arr + j, arr + j + 1);       // swap 함수 이용 (두 변수의 값을 바꿔주는 함수)
		}     // 버블 정렬을 1회차 이용할 경우 제일 큰 수가 맨 오른쪽에 위치하게 된다. 따라서 매 회차마다 맨 이미 정렬이 되어 위치하는 맨 오른쪽 수를 빼서 비교를 해주는 것이다.
	}
}     // 정렬 함수 선언 (버블 정렬, 크기가 작은 순으로 나열해주는 함수)

int IsPrime(int x)     // 소수 판별을 받을 매개변수 선언
{
	for (int i = 2;i < x;i++)     // for문 이용, 범위는 2부터 매개변수까지
	{
		if (x % i == 0)     // 2부터 매개변수까지의 수 중 매개변수에 나눴을 때 0일 경우 (i가 x의 약수일 경우)
			return 0;     // 0을 출력 (소수가 아님)
	}
	return 1;     // 2부터 매개변수까지의 수 중 매개변수에 나눴을 때 0인 것이 발견되지 않으면 1을 출력 (소수)
}     // 소수 판별기 함수 선언 (소수일 경우 1을 출력, 아닐경우 0을 출력하는 함수)

void program1(void)     // 입력과 출력이 없는 경우라 void로 함수 선언, 매개변수 void로 입력
{
	int i, select, a, b;
	/*
	정의한 변수들
	i : for문 변수
	select : 메뉴 입력 변수
	a, b : 피연산자 변수
	*/

	printf("\n\n");     // 줄바꿈 2번
	for (i = 0;i < 40;i++)     // for문 이용, 40번 반복
	{
		printf("*");     // * 출력
	}
	printf("\n");     // 줄바꿈
	for (i = 0;i < 15;i++)     // for문 이용, 15번 반복
	{
		if (i == 7)      // if 조건문 이용, i가 7일 경우
			printf(" 1. 사칙연산 계산기입니다 ");      // 해당하는 문자 출력
		else     // 조건에 해당하지 않은 경우
			printf("*");      // * 출력
	}
	printf("\n");     // 줄바꿈
	for (i = 0;i < 40;i++)     // for문 이용, 40번 반복
	{
		printf("*");     // * 출력
	}
	printf("\n\n");     // 줄바꿈 2번
	// => 해당 프로그램을 이용 시 출력되는 문구 (사칙연산 계산기입니다)

	while (1)     // 반복문 while 이용, 조건문에 1을 넣으므로서 항상 반복하도록 설정
	{
		printf("\n");     // 줄바꿈
		for (i = 0;i < 35;i++)     // for문 이용, 35번 반복
		{
			if (i == 17)      // if 조건문 이용, i가 17일 경우
				printf(" 메뉴 ");     // 해당하는 문자 출력
			else     // 조건에 해당하지 않은 경우
				printf("*");      // * 출력
		}
		printf("\n");     // 줄바꿈
		printf("1. 덧셈\n2. 뺄셈\n3. 곱셈\n4. 나눗셈\n0. 이전 메뉴로 돌아가기\n");    // 해당하는 문자 출력
		for (i = 0;i < 40;i++)     // for문 이용, 40번 반복
		{
			printf("*");     // * 출력
		}
		printf("\n메뉴를 선택해주세요 : ");     // 해당하는 문자 출력
		// => 메뉴 선택 문구 출력
		scanf_s("%d", &select);     // scanf_s 이용, select 변수에 입력을 받음

		if (select == 0)     // if 조건문 이용, select 값이 0일 경우
		{
			printf("\n[ 사칙연산 계산기를 종료합니다 ]\n");    // 해당하는 문자 출력
			break;     // while문 탈출
		}
		else if (select < 5 && select > 0)     // else if 조건문 이용, select 값이 1부터 4까지 일 경우
		{
			printf("두 피연산자를 입력하세요 : ");     // 해당하는 문자 출력
			scanf_s("%d%d", &a, &b);     // scanf_s 이용, a, b 변수에 입력을 받음
			if (select == 4 && b == 0)     // if 조건문 이용, select 값이 4이고 b값이 0일 경우
				printf("0으로 나눌 수 없습니다\n");     // 해당하는 문자 출력
			else     // 조건에 해당하지 않은 경우
			{
				printf("결과는 다음과 같습니다\n");     // 해당하는 문자 출력
				switch (select)     // 다중 조건문 switch 이용, 조건 변수 select 입력
				{
				case 1: printf("[ %d + %d ] = %d\n", a, b, a + b); break;     // select값이 1일 경우 / 해당하는 문자 출력 (덧셈) / switch문 탈출
				case 2: printf("[ %d - %d ] = %d\n", a, b, a - b); break;     // select값이 2일 경우 / 해당하는 문자 출력 (뺄셈) / switch문 탈출
				case 3: printf("[ %d * %d ] = %d\n", a, b, a * b); break;     // select값이 3일 경우 / 해당하는 문자 출력 (곱셈) / switch문 탈출
				case 4: printf("[ %d / %d ] = %.2f\n", a, b, a / (double)b); break;     // select값이 4일 경우 / 해당하는 문자 출력 (나눗셈), 정수 변수를 실수 변수로 나타내기 위해 형 변환 / switch문 탈출
				}
			}
		}
		else     // 조건에 해당하지 않은 경우
			printf("잘못 입력했습니다\n");     // 해당하는 문자 출력
	}// => 입력 변수에 따라 이용되는 사칙연산 기능 출력과 반복
}// 사칙연산 계산기 프로그램

void program2(void)     // 입력과 출력이 없는 경우라 void로 함수 선언, 매개변수 void로 입력
{
	int i, n;
	/*
	정의한 변수들
	i : for문 변수
	n : 판별할 입력 변수
	*/

	printf("\n\n");     // 줄바꿈 2번
	for (i = 0;i < 40;i++)     // for문 이용, 40번 반복
	{
		printf("*");     // * 출력
	}
	printf("\n");     // 줄바꿈
	for (i = 0;i < 15;i++)     // for문 이용, 15번 반복
	{
		if (i == 7)     // if 조건문 이용, i가 7일 경우
			printf(" 2. 소수 판별기 입니다 ");     // 해당하는 문자 출력
		else     // 조건에 해당하지 않은 경우
			printf("*");     // * 출력
	}
	printf("\n");     // 줄바꿈
	for (i = 0;i < 40;i++)     // for문 이용, 40번 반복
	{
		printf("*");     // * 출력
	}
	printf("\n\n");     // 줄바꿈 2번
	// => 해당 프로그램을 이용 시 출력되는 문구 (소수 판별기 입니다)
	
	while (1)     // 반복문 while 이용, 조건문에 1을 넣으므로서 항상 반복하도록 설정
	{
		printf("\n1보다 큰 자연수를 입력하세요 (0. 이전 메뉴로 돌아가기) : ");     // 해당하는 문자 출력 (자연수 입력 문구 출력)
		scanf_s("%d", &n);     // scanf_s 이용, n 변수에 입력을 받음

		if (n == 0)     // if 조건문 이용, n값이 0일 경우
		{
			printf("\n[ 소수 판별기를 종료합니다 ]\n");     // 해당하는 문자 출력
			break;     // while문 탈출
		}
		else if (n == 1 || n < 0)     // else if 조건문 이용, n값이 1이거나 음수일 경우
			printf("잘못 입력했습니다\n");     // 해당하는 문자 출력
		else     // 조건에 해당하지 않은 경우
		{
			if (IsPrime(n) == 0)     // IsPrime 함수 이용, if 조건문 이용, IsPrime(n) 출력 값이 0일 경우
				printf("[ 자연수 %d ]는(은) 소수가 아닙니다\n", n);     // 해당하는 문자 출력
			else     // 조건에 해당하지 않은 경우
				printf("[ 자연수 %d ]는(은) 소수입니다\n", n);     // 해당하는 문자 출력
		}
	}// => 입력 변수에 따라 이용되는 소수 판별 기능 출력과 반복
}// 소수 판별기 프로그램

void program3(void)     // 입력과 출력이 없는 경우라 void로 함수 선언, 매개변수 void로 입력
{
	srand(time(NULL));     // 난수 형성 (날짜와 시간에 대한 함수를 통한)

	int i, select, *arr , N = 6, max = 45, index = 0, temp;
	/*
	정의한 변수들
	i : for문 변수
	select : 프로그램 입력 변수
	*arr : 로또 배열 포인터 변수
	N : 로또 번호 개수
	max : 최대 범위
	index : 번호 생성 유무 인덱스
	temp : 임시 저장 변수
	*/
	arr = (int*)malloc(sizeof(int) * N);    // 동적 메모리 할당, 필요한 만큼만 메모리를 할당

	printf("\n\n");     // 줄바꿈 2번
	for (i = 0;i < 40;i++)     // for문 이용, 40번 반복
	{
		printf("*");     // * 출력
	}
	printf("\n");     // 줄바꿈
	for (i = 0;i < 14;i++)     // for문 이용, 14번 반복
	{
		if (i == 5)     // if 조건문 이용, i가 5일 경우
			printf(" 3. 로또 번호 생성기입니다 ");     // 해당하는 문자 출력
		else     // 조건에 해당하지 않은 경우
			printf("*");     // * 출력
	}
	printf("\n");     // 줄바꿈
	for (i = 0;i < 40;i++)     // for문 이용, 40번 반복
	{
		printf("*");     // * 출력
	}
	printf("\n\n");     // 줄바꿈 2번
	// => 로또 번호 생성기 문구 출력

	while (1)     // 반복문 while 이용, 조건문에 1을 넣으므로서 항상 반복하도록 설정
	{
		printf("\n");     // 줄바꿈
		for (i = 0;i < 9;i++)     // for문 이용, 9번 반복
		{
			if (i == 4)     // if 조건문 이용, i가 4일 경우
				printf(" [%d of %d]로또 번호를 생성하시겠습니까? ", N, max);     // 해당하는 문자 출력, 번호 개수와 최대값 표시
			else     // 조건에 해당하지 않은 경우
				printf("-");     // - 출력
		}
		printf("\n");     // 줄바꿈
		printf("1. 생성하기\n2. 생성된 번호 정렬하기\n3. 로또 번호 최대 범위 변경\n4. 당첨 번호 갯수 변경\n0. 이전 메뉴로 돌아가기\n"); // 해당하는 문자 출력
		for (i = 0;i < 48;i++)     // for문 이용, 48번 반복
		{
			printf("-");     // - 출력
		}
		printf("\n메뉴를 선택해주세요 : ");     // 해당하는 문자 출력
		// => 메뉴 선택 문구 출력
		scanf_s("%d", &select);     // scanf_s 이용, select 변수에 입력을 받음

		if (select == 0)     // if 조건문 이용, select값이 0일 경우
		{
			printf("\n[ 로또 번호 생성기를 종료합니다 ]\n");     // 해당하는 문자 출력
			break;     // while문 탈출
		}
		switch (select)     // 다중 조건문 switch 이용, 조건 변수 select 입력
		{
		case 1:     // select값이 1일 경우
			printf("\n<<로또 번호를 생성합니다>> : ");     // 해당하는 문자 출력
			for (i = 0;i < N;i++)     // for문 이용, N번 반복
			{
				*(arr + i) = rand() % max + 1;     // 난수 형성후 배열에 대입, 난수의 최대 범위가 max가 되도록 설정
				printf("%d ", *(arr + i));     // 난수가 입력된 배열 출력
			}
			printf("\n");     // 줄바꿈
			index++;     // index의 값 1 증가 (로또 번호가 생성되었음을 확인해주는 인덱스)
			break;     // switch문 탈출
		case 2:     // select값이 2일 경우
			if (index == 0)     //index값이 0일 경우 (로또 번호가 생성되지 않은 경우)
			{
				printf("\n<<생성된 로또 번호가 없습니다>>\n");     // 해당하는 문자 출력
				break;     // switch문 탈출
			}
			else     // 조건에 해당하지 않은 경우
			{
				printf("\n<<번호 정렬>> : ");     // 해당하는 문자 출력
				sorting(arr, N);     // 정렬 함수 이용, 로또 번호 배열 변수와 로또 번호 개수 변수 대입
				for (i = 0;i < N;i++)     // for문 이용, N번 반복
				{
					printf("%d ", *(arr + i));     // sorting 함수로 정렬이 된 배열 출력
				}
				printf("\n");     // 줄바꿈
				break;     // switch문 탈출
			}
		case 3:     // select값이 3일 경우
			while (1)     // 반복문 while 이용, 조건문에 1을 넣으므로서 항상 반복하도록 설정
			{
				printf("\n<<새로운 최대 범위를 입력하세요 (%d이상 100이하)>> : ", N);     // 해당하는 문자 출력
				scanf_s("%d", &temp);     // scanf_s 이용, temp 변수에 입력을 받음
				if (temp < N || temp > 100)     // if 조건문 이용, temp값이 N보다 작거나 100보다 클 경우
					printf("잘못된 입력입니다.\n");     // 해당하는 문자 출력
				else     // 조건에 해당하지 않은 경우
				{
					max = temp;     // max 변수 값에 temp 변수 값 대입
					index = 0;     // 새로운 범위로 인해 정렬 인덱스 리셋
					break;     // while문 탈출
				}
			}
			break;     // switch문 탈출
		case 4:     // select값이 4일 경우
			while (1)     // 반복문 while 이용, 조건문에 1을 넣으므로서 항상 반복하도록 설정
			{
				printf("\n<<새로운 당첨 번호 개수를 입력하세요 (1이상 %d이하)>> : ", max);     // 해당하는 문자 출력
				scanf_s("%d", &temp);     // scanf_s 이용, temp 변수에 입력을 받음
				if (temp < 1 || temp > max)     // if 조건문 이용, temp값이 1보다 작거나 max보다 클 경우
					printf("잘못된 입력입니다.\n");     // 해당하는 문자 출력
				else     // 조건에 해당하지 않은 경우
				{
					free(arr);     // 메모리 해제 함수, 동적 메모리 할당 이용이 끝마쳐서 할당을 해제, 
					N = temp;     // 입력받은 temp 값을 N 값에 대입
					arr = (int*)malloc(arr, sizeof(int) * N);    // 동적 메모리 할당, 필요한 만큼만 메모리를 할당
					index = 0;     // 새로운 범위로 인해 정렬 인덱스 리셋
					break;     // while문 탈출
				}
			}
			break;     // switch문 탈출
		}
	}
	free(arr);     // 메모리 해제 함수, 동적 메모리 할당 이용이 끝마쳐서 할당을 해제
	// => 입력 변수에 따라 이용되는 로또 번호 생성기 여러 기능 출력과 반복
}// 로또 번호 생성기 프로그램

void program4(void)     // 입력과 출력이 없는 경우라 void로 함수 선언, 매개변수 void로 입력
{
	int i, j, k , num, height;
	/*
	정의한 변수들
	i, j, k : for문 변수
	num : 단의 개수 변수
	height : 단의 높이 변수
	*/

	printf("\n\n");     // 줄바꿈 2번
	for (i = 0;i < 40;i++)     // for문 이용, 40번 반복
	{
		printf("*");     // * 출력
	}
	printf("\n");     // 줄바꿈
	for (i = 0;i < 7;i++)     // for문 이용, 7번 반복
	{
		if (i == 3)     // if 조건문 이용, i가 3일 경우
			printf(" 4. 크리스마스 트리 그리기 입니다 ");     // 해당하는 문자 출력
		else     // 조건에 해당하지 않은 경우
			printf("*");     // * 출력
	}
	printf("\n");     // 줄바꿈
	for (i = 0;i < 40;i++)     // for문 이용, 40번 반복
	{
		printf("*");     // * 출력
	}
	printf("\n\n");     // 줄바꿈 2번
	// => 크리스마스 트리 그리기 문구 출력

	while (1)     // 반복문 while 이용, 조건문에 1을 넣으므로서 항상 반복하도록 설정
	{
		printf("\n트리의 단 개수를 입력하세요 (0. 이전 메뉴로 돌아가기) : ");     // 해당하는 문자 출력
		scanf_s("%d", &num);     // scanf_s 이용, num 변수에 입력을 받음

		if (num == 0)     // if 조건문 이용, num값이 0일 경우
		{
			printf("\n[ 크리스마스 트리 그리기를 종료합니다 ]\n");     // 해당하는 문자 출력
			break;     // while문 탈출
		}
		else if (num < 3)     // else if 조건문 이용, num값이 3보다 작을 경우
			printf("트리는 3단 이상이어야 합니다\n");     // 해당하는 문자 출력
		else     // 조건에 해당하지 않은 경우
		{
			printf("트리의 단 높이를 입력하세요 : ");     // 해당하는 문자 출력
			scanf_s("%d", &height);     // scanf_s 이용, height 변수에 입력을 받음

			if (height < 3)     // if 조건문 이용, height값이 3보다 작을 경우
				printf("트리의 단 높이는 3 이상이어야 합니다\n");     // 해당하는 문자 출력
			else     // 조건에 해당하지 않은 경우
			{
				for (i = 0;i < num;i++)     // for문 이용, num번 반복
				{
					for (j = 0;j < height;j++)     // 이중 for문 이용, height번 반복
					{
						for (k = 1;k <= (num - i - 1) * (height - 2) + (height - j - 1);k++)     // 삼중 for문 이용, (num - i - 1) * (height - 2) + (height - j - 1) - 1 번 반복
						{
							printf(" ");     // 빈칸 출력
						}
						for (k = 1;k <= i * (height - 2) * 2 + 1 + j * 2;k++)     // 삼중 for문 이용, i * (height - 2) * 2 + j * 2번 반복
						{
							printf("*");     // * 출력
						}
						printf("\n");     // 줄바꿈
					}
				}// => 트리 잎 부분 출력
				for (i = 0;i < 2;i++)     // for문 이용, 2번 반복
				{
					for (j = 0;j < num * (height - 2);j++)     // 이중 for문 이용, num * (height - 2)번 반복
					{
						printf(" ");     // 빈칸 출력
					}
					printf("| |\n");     // 기둥 모양 출력
				}// => 트리 기둥 부분 출력
			}
		}
	}// => 입력 변수에 따라 크리스마스 트리 출력과 반복
}// 크리스마스 트리 프로그램

int main()     // 메인 프로그램 선언
{
	int i, select;
	/*
	정의한 변수들
	i : for문 변수
	select : 메인 프로그램 입력 변수
	*/

	for (i = 0;i < 40;i++)     // for문 이용, 40번 반복
	{
		printf("#");     // # 출력
	}
	printf("\n");     // 줄바꿈
	for (i = 0;i < 25;i++)     // for문 이용, 25번 반복
	{
		if (i == 12)      // if 조건문 이용, i가 12일 경우
			printf(" 환 영 합 니 다 ");     // 해당하는 문자 출력
		else     // 조건에 해당하지 않은 경우
			printf("#");     // # 출력
	}
	printf("\n");     // 줄바꿈
	for (i = 0;i < 40;i++)     // for문 이용, 40번 반복
	{
		printf("#");     // # 출력
	}
	printf("\n\n");     // 줄바꿈 2번
	// => 메인 프로그램 작동 시 문구 출력 (환영합니다)
	
	while (1)     // 반복문 while 이용, 조건문에 1을 넣으므로서 항상 반복하도록 설정
	{
		printf("\n");     // 줄바꿈
		for (i = 0;i < 22;i++)     // for문 이용, 22번 반복
		{
			if (i == 10)      // if 조건문 이용, i가 10일 경우
				printf(" 프 로 그 램 메 뉴 ");     // 해당하는 문자 출력
			else     // 조건에 해당하지 않은 경우
				printf("=");     // = 출력
		}
		printf("\n");     // 줄바꿈
		printf("1. 사칙연산 계산기\n2. 소수 판별기\n3. 로또 번호 생성기\n4. 크리스마스 트리\n0. 프로그램 종료\n");     // 해당하는 문자 출력
		for (i = 0;i < 40;i++)     // for문 이용, 40번 반복
		{
			printf("=");     // = 출력
		}
		printf("\n메뉴를 선택해주세요 : ");     // 해당하는 문자 출력
		scanf_s("%d", &select);     // scanf_s 이용, select 변수에 입력을 받음
		// => 메뉴 선택 문구 출력

		if (select == 0)      // if 조건문 이용, select 값이 0일 경우
		{
			printf("전체 프로그램을 종료합니다\n");     // 해당하는 문자 출력
			break;     // while문 탈출
		}
		else     // 조건에 해당하지 않은 경우
		{
			switch (select)     // 다중 조건문 switch 이용, 조건 변수 select 입력
			{
			case 1: program1(); break;     // select값이 1일 경우 / program1 함수 실행 (사칙연산 계산기) / switch문 탈출
			case 2: program2(); break;     // select값이 2일 경우 / program2 함수 실행 (소수 판별기) / switch문 탈출
			case 3: program3(); break;     // select값이 3일 경우 / program3 함수 실행 (로또 번호 생성기) / switch문 탈출
			case 4: program4(); break;     // select값이 4일 경우 / program4 함수 실행 (크리스마스 트리 그리기) / switch문 탈출
			default: printf("잘못 입력했습니다\n"); break;     // 나머지 경우 / 해당하는 문자 출력 / switch문 탈출
			}
		}
	}// => 입력 변수에 따라 이용되는 프로그램 기능 출력과 반복
}
