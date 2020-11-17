#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "maze.h"

int X = 4, Y = 3; //��ǥ��.
int test, checker, helper, helper2;
 
void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void gotoxy(int x, int y) { // Ŀ�� �̵� 
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int keeper(int(*map)[36], int X, int Y) { //2���� �迭�� ��ǥ�� �޽��ϴ�.

	int checker;

	if (*(*(map + Y) + X) == 0) { // ������ �˻縸 �ϸ� �ǰڳ׿�? �׷���?
		checker = 1;
	} //��ǥ�κ��� �ʰ��� 0�̸� 1�� ��ȯ�ϰ�
	else if (*(*(map + Y) + X) == 2) {
		checker = 1;
	}
	else { checker = 0; } //0�� �ƴϸ� �����ٴϸ� �ȵȴٴµ����� 0�� ��ȯ��ų����. 

	return checker;
}

int main() {
	// console ũ�� 
	system("mode con cols=37 lines=24"); 

	gotoxy(4, 1);
	textcolor(15); 
	printf("�ڡ�  �� �� ã �� �� ��  �ڡ�");
	gotoxy(0, 2); // ���������� ���� 
		
	for (helper = 0; helper < 20; helper++) {  //���� for������ ���� ����غ��ϴ�.
		for (helper2 = 0; helper2 < 36; helper2++) {
			if (map[helper][helper2] == 1) {
				textcolor(8); // gray
				printf("��");
			}
			else if (map[helper][helper2] == 2) {
				textcolor(12); // red
				printf("��");
			}
			else if (map[helper][helper2] == 0) { // 2ĭ 
				printf("  ");
			}
		//0�� ��� ��ĭ�� ����մϴ�.
		//��ĭ�� �ݵ�� �������� �մϴ� 
		//�׷��� ���ϴ� ��ġ�� ���ϴ� ���ڸ� ��½�ų�� �ֽ��ϴ�.
		}
		printf("\n"); //���� ����� �Ŀ��� �ݵ�� ����־�� ��Ű�� �ʽ��ϴ�.
	}
	textcolor(14); 
	gotoxy(X, Y + 2);
	printf("��");
	
	while (1) {
		test = _getch(); // Ű���� �Է� �޴´� 
		textcolor(14);

		switch (test) {

			case UP: 
				gotoxy(X, Y + 2);
				printf("  ");//�ϴ� ����� �����մϴ�.
				Y -= 1;//��ǥ�� �̵����Ѻ��ڿ�

				checker = keeper(map, X, Y); 
				//map�迭 �ּҿ� ��ǥ�� �Ѱ��� ���ô�
				if (checker == 1) {
					gotoxy(X, Y + 2);
					printf("��");//�������� �ȴٸ� ���ڸ��� ������ְ�
					break;
				}
				else if (checker == 0)
				{
					Y += 1;//�������̸� ��ǥ�� �ٽ� �ǵ����Ŀ�
					gotoxy(X, Y + 2);
					printf("��");//�ٽ� ������ݴϴ�.
					break;
				}

			case DOWN: 
				gotoxy(X, Y + 2);
				printf("  ");
				Y += 1;
				checker = keeper(map, X, Y);
				if (checker == 1) {
					gotoxy(X, Y + 2);
					printf("��");
					break;
				}
				else if (checker == 0)
				{
					Y -= 1;
					gotoxy(X, Y + 2);
					printf("��");
					break;
				}

			case LEFT: 
				gotoxy(X, Y + 2);
				printf("  ");
				X -= 2;

				checker = keeper(map, X, Y);
				if (checker == 1) {

					gotoxy(X, Y + 2);
					printf("��");
					break;
				}
				else if (checker == 0)
				{
					X += 2;
					gotoxy(X, Y + 2);
					printf("��");
					break;
				}

			case RIGHT:   
				gotoxy(X, Y + 2);
				printf("  ");
				X += 2;

				checker = keeper(map, X, Y);
				if (checker == 1) {

					gotoxy(X, Y + 2);
					printf("��"); 
					break;
				}
				else if (checker == 0)
				{
					X -= 2;
					gotoxy(X, Y + 2);
					printf("��");
					break;
				}

		} //switch����

		if ((X == 32 && Y == 3) || (X == 33 && Y == 3)) { break; }
		else { continue; } 

	}// while ���� 

	system("cls"); // ȭ�� �����ֱ� 

	for (helper = 0; helper <= 15; helper++) {
		gotoxy(10, 11); 
		textcolor(helper); //�� �¸��ߴٰ� ����ָ� �������ǰ���?
		printf("�ڽ¸��߽��ϴ�!��");
		Sleep(100);
	}
	
	system("pause>nul");
	fflush(stdin);
	system("cls");
	gotoxy(0, 11); 
	textcolor(15);

	return 0;
}
