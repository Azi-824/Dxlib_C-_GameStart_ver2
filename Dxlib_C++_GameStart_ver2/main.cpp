//main.cpp

//#################### ヘッダファイル読み込み #######################
#include "main.hpp"
#include "GAMEMANEGER.hpp"

//########## グローバルオブジェクト ##########
GAMEMANEGER *gamemaneger = new GAMEMANEGER();	//gamemaneger生成

//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//指定の数値で画面を表示する

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);				//タイトルバーあり

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//タイトルの文字

	SetAlwaysRunFlag(TRUE);										//非アクティブに設定

	if (DxLib_Init() == -1) { return -1; }						//ＤＸライブラリ初期化処理

	SetDrawScreen(DX_SCREEN_BACK);								//Draw系関数は裏画面に描画

	//ゲームデータの読み込み開始
	if (gamemaneger->Load() == false) { return -1; }			//ゲームデータ読み込み失敗

	//ゲームのメインループ
	while (gamemaneger->GameMainLoop())
	{
		/*
		ループ内で異常が発生するまで無限ループ
		ゲーム終了やエラー等が発生したらループ終了
		*/
	}


	Delete_Class();			//使用したクラスを破棄

	DxLib_End();			//ＤＸライブラリ使用の終了処理

	return 0;
}

//ゲーム内で使用したクラスを削除する処理
void Delete_Class()
{

	delete gamemaneger;		//gamemaneger破棄

	return;
}
