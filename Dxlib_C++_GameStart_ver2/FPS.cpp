/*--+----1----+----2----+----3----+----4----+----5-----+----6----+----7----+----8----+----9----+---*/
/* fps.cpp     																					   */
/* FPS(Flame Per Second)クラス																	   */
/* 一つのインスタンスのみにする																	   */

//########## ヘッダーファイル読み込み ##########
#include "FPS.hpp"

//########## クラスの定義 ##########

//コンストラクタ
FPS::FPS(int fps_value)
{
	this->value = fps_value;
	this->drawValue = 0;
	this->calcStartTime = 0;
	this->calcEndTime = 0;
	this->flameCount = 0;
	this->calcAverage = (double)value;

	this->TotalFlameCnt = 0;

	return;
}

//指定したFPSになるように待つ
VOID FPS::Wait(VOID)
{
	//現在の時刻をミリ秒で取得
	DWORD nowTime = GetTickCount();

	//1フレーム目から実際にかかった時間を計算
	DWORD keikaTime = nowTime - this->calcStartTime;

	//ゼロ除算対策
	if (this->value > 0)
	{
		//待つべき時間 = フレーム数ごとにかかるべき時間 - 実際にかかった時間;
		int wait_tm = (this->flameCount * 1000 / this->value) - (keikaTime);

		//待つべき時間があった場合
		if (wait_tm > 0)
		{
			//ミリ秒分、処理を中断する
			Sleep(wait_tm);
		}
	}

	//総フレームをカウント
	TotalFlameCnt++;

	return;
}

//画面更新の時刻を取得する
VOID FPS::Update(VOID)
{
	//1フレーム目なら時刻を記憶
	if (this->flameCount == 0)
	{
		//Windowsが起動してから現在までの時刻をミリ秒で取得
		this->calcStartTime = GetTickCount();
	}

	//指定フレームの最後のフレームなら、平均を計算する
	if (this->flameCount == this->calcAverage)
	{
		//Windowsが起動してから現在までの時刻をミリ秒で取得
		this->calcEndTime = GetTickCount();

		//平均的なFPS値を計算
		this->drawValue = 1000.0f / ((this->calcEndTime - this->calcStartTime) / this->calcAverage);

		//次のFPS計算の準備
		this->calcStartTime = this->calcEndTime;

		//カウント初期化
		this->flameCount = 0;
	}

	//フレーム数カウントアップ
	this->flameCount++;

	return;
}

//FPSの値を表示する
VOID FPS::Draw(int drawX, int drawY)
{
	//文字列を描画
	DrawFormatString(drawX, drawY, GetColor(255, 255, 255), "FPS:%.1f", this->drawValue);
	return;
}

//FPS値を取得する
int FPS::Getvalue(VOID)
{
	return this->value;
}

//総フレームを取得する
int FPS::GetTotalFlameCnt(VOID)
{
	return this->TotalFlameCnt;
}

//デストラクタ
FPS::~FPS()
{
	return;
}