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
	//랜덤으로 칸에 문제입력
	void random_char() {
		for (int i = 0; i < 8; i++) {
			int rannum;

			rannum = rand() % 10;
			switch (rannum) {
			case 0: { word2 = "산성비"; word_count++; break; }
			case 1: { word2 = "손재락"; word_count++; break; }
			case 2: { word2 = "김지헌"; word_count++; break; }
			case 3: { word2 = "백상목"; word_count++; break; }
			case 4: { word2 = "배민주"; word_count++; break; }
			case 5: { word2 = "이규민"; word_count++; break; }
			case 6: { word2 = "경민종"; word_count++; break; }
			case 7: { word2 = "한정혁"; word_count++; break; }
			case 8: { word2 = "한기대"; word_count++; break; }
			case 9: { word2 = "너구리"; word_count++; break; }
			}

			int rannum_cols = rand() % 8;
			mat[i][rannum_cols] = word2;

		}
	}
	// 새로운 줄에 입력할 단어를 랜덤으로 생성하는 함수
	char* random_char_re() {
		int rannum;
		rannum = rand() % 16;
		switch (rannum) {
		case 0: { word2 = "산성비"; word_count++;  return word2;  break; }
		case 1: { word2 = "손재락"; word_count++;  return word2;  break; }
		case 2: { word2 = "김지헌"; word_count++;  return word2;  break; }
		case 3: { word2 = "백상목"; word_count++;  return word2;  break; }
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
	//출력함수
	void print() {
		for (int i = 0; i < rows - 1; i++) {
			printf("\n\n");
			for (int j = 0; j < cols; j++)
				printf("%s   ", mat[i][j]);
		}
	}

	//정답입력함수
	void scan_char() {
		printf("\n\n*********************************************************************");
		printf("\n                      입력 : ");
		cin >> answer;
		int i;
		int j;
		for (i = 9 - 1; i > -1; i--)
			for (j = 0; j < cols; j++) {
				if (strcmp(mat[i][j], "______")) {
					if (!strcmp(mat[i][j], answer)) {
						mat[i][j] = "______";
						printf("맞음");
						word_count--;
						return;
					}
					else {
						fail_count++;
						printf("틀림");
					}
				}
			}
	}
	// 줄 움직이는 함수 : 주솟값자체를 다음 배열로 이동시킴
	// duration에 의해 움직이는 줄수 변경
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
	// 10번째 줄 넘어갈 때 word_count 줄여주기
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
	// 새로운 0번째 줄 생성 함수 : 주솟값을 재할당을하고 새로운 단어 입력
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
	// 정답입력 시간 측정하는 함수
	double duration(clock_t start, clock_t finish) {
		double duration;
		duration = double(finish - start) / CLOCKS_PER_SEC;
		//start = 0;
		//finish = 0;
		return duration;
	}

	// 몇줄 움직이는지 정하게 하는 함수
	int move_duration(double duration) {
		if (duration > 2) return 1;
		else if (duration > 1) return 1;
		else return 0;
	}
	//새로 생성되는 매트는 fail_count검사를 거치지 않으므로 따로 추가.
	void inc_fail_count() {
		for (int i = 0; i < cols; i++) {
			if (strcmp(mat[0][i], "______"))
				fail_count++;
		}
	}
	
	
	




	//모든 답 맞췄는지 확인하는 함수
	/*bool problem_check() {
	for (int i = 0; i<rows; i++)
	for (int j = 0; j < cols; j++)
	{
	if (mat[i][j] == "______") return true;
	}
	return true;
	}*/

	//_____스페이스 확인하자

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

