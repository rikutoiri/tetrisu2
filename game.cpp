#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"

int Tile[11]; //�^�C��
int s;	//�T�C�Y
int v;	//
int x;	//x��
int y;	//y��
int i;	//�Y����
int j;	//�Y����

int mX, mY, mA, mWait;

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�

int mBlock[7][4][4] = {
	{
		{0,0,0,0},		//�ԃu���b�N
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//�I�����W�u���b�N
		{0,1,1,1},
		{0,1,0,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//���F�u���b�N
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//�΃u���b�N
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//���F�u���b�N
		{1,1,1,0},
		{0,1,0,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//�u���b�N
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//�s���N�u���b�N
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0},
	},
};

int mField[MAP_HEIGHT][MAP_WIDTH] = {	//�t�B�[���h
	{9,9,9,9,7,7,7,7,7,7,9,9,9,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,7,7,7,7,7,7,7,7,7,7,8,9},
	{9,8,8,8,8,8,8,8,8,8,8,8,8,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

//bool put(int x, int y, int t, int a, bool s, bool test)	//�u���b�N���o��
//{
//	for (int j = 0; j < 4; j++) {
//		for (int i = 0; i < 4; i++) {
//			int p[] = { i,3 - j,3 - i,j };
//			int q[] = { j,i,3 - j,3 - i };
//			if (mBlock[t][q[a]][p[a]] == 0) {
//				continue;
//			}
//
//			v = t;
//			if (!s) {
//				v = 7;
//			}
//			else if (mField[y + j][x + i] != 7) {
//				return(false);
//			}
//			if (!test) {
//				mField[y + j][x + i] = v;
//			}
//		}
//	}
//	return(true);
//}
bool put(int x, int y, int t, int a)	//�u���b�N���o��  t=type a=angle
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int p[] = { j,3 - i,3 - j,i };	//{0�x,90�x,180�x,270�x}
			int q[] = { i,j,3 - i,3 - j };	//{0�x,90�x,180�x,270�x}
			if (mBlock[t][q[a]][p[a]] == 0) {
				continue;
			}
			v = t;		//�^�C���̃^�C�v��n���i�F�ύX�j
			if (!1) {
				v = 7;
			}
			else{
				mField[y + i][x + j] = v;
			}
		}
	}
	return(true);
}
// 
//������
void Game_Initialize() {
	//mImageHandle = LoadDivGraph("images/tile.png");

	WaitTimer(500);
}
//�I������
void Game_Finalize() {
	DeleteGraph(mImageHandle); //�摜�̉��
}
//�X�V
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}
}
//
//void Timer() {
//
//}

//�`��
void Game_Draw() {

	LoadDivGraph("images/tile.png", 11, 11, 1, TILE_SIZE, TILE_SIZE, Tile);	//�摜����
	//LoadDivGraph(mImageHandle, 11, 11, 1, TILE_SIZE, TILE_SIZE, Tile);	//�摜����

	
	for (i = 0; i < 7; i++) {
		//put(5, 2 + i * 3, i, 0, true, false);	//�����Ƀu���b�N
		put(5, 2 + i * 3, i, 0);	//�����Ƀu���b�N
	}

	s = TILE_SIZE * 2;		//�^�C���̃T�C�Y2�{
	for (/*int*/ y = 0; y < MAP_HEIGHT; y++) {		//�t�B�[���h
		for (/*int */x = 0; x < MAP_WIDTH; x++) {
			DrawExtendGraph(x * s, y * s, x * s + s, y * s + s, Tile[mField[y][x]], FALSE);	//// �摜����ʂ����ς��ɕ`��
			
		}
	}

	//DrawGraph(0, 0, mImageHandle, TRUE);//����
}
