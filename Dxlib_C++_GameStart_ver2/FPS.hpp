/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* fps.hpp     																					   */
/* FPS(Flame Per Second)クラス																	   */
/* 一つのインスタンスのみにする																	   */

#pragma once

//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"

//########## クラスの定義 ##########
class FPS
{
private:
	int			value;					//FPS値
	double		drawValue;				//DrawするときのFPS値
	DWORD		calcStartTime;			//0フレーム目の開始時刻
	DWORD		calcEndTime;			//設定したフレームの終了時刻
	DWORD		flameCount;				//フレームのカウント
	double		calcAverage; 			//FPSを計算するための平均サンプル数

	int			TotalFlameCnt;			//現在の総フレーム数

public:

	//コンストラクタ
	//引　数：int　：FPS値
	FPS(int);

	//指定したFPSになるように待つ
	VOID Wait(VOID);

	//画面更新の時刻を取得する
	VOID Update(VOID);

	//FPSの値を表示する
	//引　数：int　：値を表示するX位置
	//引　数：int　：値を表示するY位置
	VOID Draw(int, int);

	//FPS値を取得する
	int Getvalue(VOID);

	//総フレームを取得する
	int GetTotalFlameCnt(VOID);

	//デストラクタ
	virtual ~FPS();
};

//########## 外部オブジェクト ##########
extern FPS *fps;