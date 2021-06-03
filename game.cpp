#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"

int Tile[11]; //タイル
int s;	//サイズ
int v;	//
int x;	//x軸
int y;	//y軸
int i;	//添え字
int j;	//添え字

int mX, mY, mA, mWait;

static int mImageHandle; //画像ハンドル格納用変数

int mBlock[7][4][4] = {
	{
		{0,0,0,0},		//赤ブロック
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//オレンジブロック
		{0,1,1,1},
		{0,1,0,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//黄色ブロック
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//緑ブロック
		{1,1,0,0},
		{0,1,1,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//水色ブロック
		{1,1,1,0},
		{0,1,0,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//青ブロック
		{1,1,1,0},
		{0,0,1,0},
		{0,0,0,0},
	},{
		{0,0,0,0},		//ピンクブロック
		{0,1,1,0},
		{1,1,0,0},
		{0,0,0,0},
	},
};

int mField[MAP_HEIGHT][MAP_WIDTH] = {	//フィールド
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

//bool put(int x, int y, int t, int a, bool s, bool test)	//ブロックを出現
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
bool put(int x, int y, int t, int a)	//ブロックを出現  t=type a=angle
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int p[] = { j,3 - i,3 - j,i };	//{0度,90度,180度,270度}
			int q[] = { i,j,3 - i,3 - j };	//{0度,90度,180度,270度}
			if (mBlock[t][q[a]][p[a]] == 0) {
				continue;
			}
			v = t;		//タイルのタイプを渡す（色変更）
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
//初期化
void Game_Initialize() {
	//mImageHandle = LoadDivGraph("images/tile.png");

	WaitTimer(500);
}
//終了処理
void Game_Finalize() {
	DeleteGraph(mImageHandle); //画像の解放
}
//更新
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}
}
//
//void Timer() {
//
//}

//描画
void Game_Draw() {

	LoadDivGraph("images/tile.png", 11, 11, 1, TILE_SIZE, TILE_SIZE, Tile);	//画像分割
	//LoadDivGraph(mImageHandle, 11, 11, 1, TILE_SIZE, TILE_SIZE, Tile);	//画像分割

	
	for (i = 0; i < 7; i++) {
		//put(5, 2 + i * 3, i, 0, true, false);	//中央にブロック
		put(5, 2 + i * 3, i, 0);	//中央にブロック
	}

	s = TILE_SIZE * 2;		//タイルのサイズ2倍
	for (/*int*/ y = 0; y < MAP_HEIGHT; y++) {		//フィールド
		for (/*int */x = 0; x < MAP_WIDTH; x++) {
			DrawExtendGraph(x * s, y * s, x * s + s, y * s + s, Tile[mField[y][x]], FALSE);	//// 画像を画面いっぱいに描画
			
		}
	}

	//DrawGraph(0, 0, mImageHandle, TRUE);//試し
}
