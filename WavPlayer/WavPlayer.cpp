#include "framework.h"
#include "WavPlayer.h"

int APIENTRY _tWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPTSTR cmdLine, int cdShow)
{
	if (cmdLine && cmdLine[0])
	{
		// 引数で与えられた wav ファイルを再生する。

		TCHAR wavFileName[MAX_PATH] = {};
		::StringCbCopy(wavFileName, sizeof(wavFileName), cmdLine);
		::PathUnquoteSpaces(wavFileName);
		::PlaySound(wavFileName, 0, SND_FILENAME | SND_SYNC);
	}
	else
	{
		// 引数なしで実行されたのでメッセージボックスを表示する。

		::PlaySound(_T("SystemHand"), 0, SND_ALIAS | SND_ASYNC | SND_LOOP);
		::MessageBox(0, _T("このメッセージボックスを表示したまま、音量ミキサーで音量を調整してください"), _T("WavPlayer"), MB_OK | MB_SYSTEMMODAL);
		::PlaySound(0, 0, 0);
	}

	return 0;
}
