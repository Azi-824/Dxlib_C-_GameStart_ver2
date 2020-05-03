//GAMEMANEGER.hpp
//ゲームのシステムを管理するクラス

#pragma once

//############### ヘッダファイル読み込み ##################
#include "DxLib.h"
#include "FPS.hpp"
#include "KEYDOWN.hpp"

//############### マクロ定義 ################
#define GAME_FPS_SPEED					   60

//テキスト関係
#define LOAD_TEXT	"NowLoading…"		//ロード画面のテキスト
#define PUSH_TEXT	"PushEnter"			//エンターキーを押す、のテキスト
#define TITLE_TEXT	"NowTitle"			//タイトル画面のテキスト
#define PLAY_TEXT	"NowPlay"			//プレイ画面のテキスト
#define END_TEXT	"NowEnd"			//エンド画面のテキスト

//座標関係
#define TEST_TEXT_X	30					//テスト用のテキスト描画X位置
#define TEST_TEXT_Y	30					//テスト用のテキスト描画Y位置

//############### 列挙型 ################
enum GAME_SCENE
{
	SCENE_LOAD,			//ロードシーン
	SCENE_TITLE,		//タイトルシーン
	SCENE_PLAY,			//プレイシーン
	SCENE_END			//エンドシーン
};

//############### クラス定義 ################
class GAMEMANEGER
{

private:

	FPS *fps;					//fps
	KEYDOWN *keydown;			//キーボード関係

	int NowScene;				//現在のシーン
	bool IsLoad;				//読み込みが終わったか

public:

	GAMEMANEGER();				//コンストラクタ
	~GAMEMANEGER();				//デストラクタ

	bool Load();				//ゲームに使用するデータの読み込み処理
	bool GameMainLoop();		//ゲームのメインループ

	bool ProcesScene();			//各シーンの処理


	//****************** シーン関係 *************************
	bool Scene_Load();			//ロード画面の処理
	void Draw_Scene_Load();		//ロード画面の描画処理

	void Scene_Title();			//タイトル画面の処理
	void Draw_Scene_Title();	//タイトル画面の描画処理

	void Scene_Play();			//プレイ画面の処理
	void Draw_Scene_Play();		//プレイ画面の描画処理

	void Scene_End();			//エンド画面の処理
	void Draw_Scene_End();		//エンド画面の描画処理



};
