#pragma once
#include "MatrixI.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>
using  namespace std;
class Map : public MatrixI
{
public:

	char answer[80];
	


	Map(int r = 10, int c = 8, char msg[80] = "null" ) : MatrixI(r, c) { }
	~Map() { }
	//�������� ĭ�� �����Է�
	void random_char() {
		for (int i = 0; i < 8; i++) {
			int rannum;

			rannum = rand() % 10;
			switch (rannum) {
			case 0: { word2 = "�꼺��"; word_count++; break; }
			case 1: { word2 = "�����"; word_count++; break; }
			case 2: { word2 = "������"; word_count++; break; }
			case 3: { word2 = "����"; word_count++; break; }
			case 4: { word2 = "�����"; word_count++; break; }
			case 5: { word2 = "�̱Թ�"; word_count++; break; }
			case 6: { word2 = "�����"; word_count++; break; }
			case 7: { word2 = "������"; word_count++; break; }
			case 8: { word2 = "�ѱ��"; word_count++; break; }
			case 9: { word2 = "�ʱ���"; word_count++; break; }
			}

			int rannum_cols = rand() % 8;
			mat[i][rannum_cols] = word2;

		}
	}
	// ���ο� �ٿ� �Է��� �ܾ �������� �����ϴ� �Լ�
	char* random_char_re() {
		int rannum;
		rannum = rand() % 16;
		switch (rannum) {
		case 0: { word2 = "�꼺��"; word_count++;  return word2;  break; }
		case 1: { word2 = "�����"; word_count++;  return word2;  break; }
		case 2: { word2 = "������"; word_count++;  return word2;  break; }
		case 3: { word2 = "����"; word_count++;  return word2;  break; }
		case 4: { word2 = "______"; return word2;  break; }
		case 5: { word2 = "______"; return word2;  break; }
		case 6: { word2 = "______"; return word2;  break; }
		case 7: { word2 = "______"; return word2;  break; }
		case 8: { word2 = "______"; return word2;  break; }
		case 9: { word2 = "______"; return word2;  break; }
		case 10: { word2 = "______"; return word2;  break; }
		case 11: { word2 = "______"; return word2;  break; }
		case 12: { word2 = "______"; return word2;  break; }
		case 13: { word2 = "______"; return word2;  break; }
		case 14: { word2 = "______"; return word2;  break; }
		case 15: { word2 = "______"; return word2;  break; }
		}
	}
	//����Լ�
	void print() {
		for (int i = 0; i < rows - 1; i++) {
			printf("\n\n");
			for (int j = 0; j < cols; j++)
				printf("%s   ", mat[i][j]);
		}
	}

	//�����Է��Լ�
	void scan_char() {
		printf("\n\n*********************************************************************");
		printf("\n                      �Է� : ");
		cin >> answer;
		int i;
		int j;
		for (i = 9 - 1; i > -1; i--)
			for (j = 0; j < cols; j++) {
				if (strcmp(mat[i][j], "______")) {
					if (!strcmp(mat[i][j], answer)) {
						mat[i][j] = "______";
						printf("����");
						word_count--;
						return;
					}
					else {
						fail_count++;
						printf("Ʋ��");
					}
				}
			}
	}
	// �� �����̴� �Լ� : �ּڰ���ü�� ���� �迭�� �̵���Ŵ
	// duration�� ���� �����̴� �ټ� ����
	void move(int mrows) {
		switch (mrows) {
		case 0:
			break;
		case 1:
			for (int i = 10; i > 0; i--) {
				//for (int j = 0; j < cols; j++)
				mat[i] = mat[i - 1];
			}
			break;
		case 2:
			for (int i = 10; i > 1; i--)
				//for (int j = 0; j < cols; j++)
				mat[i] = mat[i - 2];
			break;
		}
	}
	// 10��° �� �Ѿ �� word_count �ٿ��ֱ�
	void dec_word_count(int mrows) {
		switch (mrows) {
		case 0:
			break;
		case 1:
			for (int i = 0; i < 8; i++) {
				if (strcmp(mat[9][i], "______")) {
					word_count--;
				}
			}
			break;
		case 2:
			for (int i = 0; i < 8; i++)
			{
				if (strcmp(mat[9][i], "______")) word_count--;
			}
			for (int i = 0; i < 8; i++)
			{
				if (strcmp(mat[8][i], "______")) {
					word_count--;

				}
			}
			break;
		}
	}
	// ���ο� 0��° �� ���� �Լ� : �ּڰ��� ���Ҵ����ϰ� ���ο� �ܾ� �Է�
	void new_rows(int mrows) {
		switch (mrows) {
			int i;
		case 0:
			break;
		case 1:

			mat[0] = new char*[cols];
			for (i = 0; i < cols; i++) {
				mat[0][i] = random_char_re();
			}
			break;
		case 2:
			mat[0] = new char*[cols];
			mat[1] = new char*[cols];
			for (i = 0; i < cols; i++) {
				mat[0][i] = random_char_re();
			}
			for (i = 0; i < cols; i++) {
				mat[1][i] = random_char_re();
			}
			break;
		}
	}
	// �����Է� �ð� �����ϴ� �Լ�
	double duration(clock_t start, clock_t finish) {
		double duration;
		duration = double(finish - start) / CLOCKS_PER_SEC;
		//start = 0;
		//finish = 0;
		return duration;
	}

	// ���� �����̴��� ���ϰ� �ϴ� �Լ�
	int move_duration(double duration) {
		if (duration > 2) return 1;
		else if (duration > 1) return 1;
		else return 0;
	}
	//���� �����Ǵ� ��Ʈ�� fail_count�˻縦 ��ġ�� �����Ƿ� ���� �߰�.
	void inc_fail_count() {
		for (int i = 0; i < cols; i++) {
			if (strcmp(mat[0][i], "______"))
				fail_count++;
		}
	}
	
	
	




	//��� �� ������� Ȯ���ϴ� �Լ�
	/*bool problem_check() {
	for (int i = 0; i<rows; i++)
	for (int j = 0; j < cols; j++)
	{
	if (mat[i][j] == "______") return true;
	}
	return true;
	}*/

	//_____�����̽� Ȯ������

	/*void print_rows() {
	n++;
	for (int i = 0; i < rows - 1; i++) {
	printf("\n\n");
	for (int j = 0; j < cols; j++) {
	printf("%s   ", mat[i + n][j]);
	}
	}
	}

	void print_zero() {
	for (int i = 0; i < 8; i++)
	{
	printf("%s   ", mat[0][i]);
	}
	}
	*/

};

