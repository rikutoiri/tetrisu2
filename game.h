#pragma once

#define TILE_SIZE 12
#define MAP_WIDTH  14               // �t�B�[���h�̕�
#define MAP_HEIGHT 25               // �t�B�[���h�̍���

//bool put(int x, int y, byte t, int a, bool test)
//{
//	for (int j = 0; j < 4; j++) {
//		for (int i = 0; i < 4; i++) {
//			int p[] = { i,3 - j,3 - i,j };
//			int q[] = { j,i,3 - j,3 - i };
//			if (mBlock[t][ q[a]][ p[a]] == 0) {
//				continue;
//			}
//
//			byte v = t;
//			if (!s) {
//				v = 7
//			}
//			else if (mField[y + j][x + i] != 7) {
//				return(false);
//			}
//			if (!test) {
//				mField[y + j][ x + i] = v;
//			}
//		}
//	}
//	return(true);
//}



void Game_Initialize();//������
void Game_Finalize();//�I������
void Game_Update();//�X�V
void Game_Draw();//�`��

void Timer();		//����