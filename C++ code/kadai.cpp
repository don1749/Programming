/********************************************/
/*	                                        */
/*               人間情報工学				*/
/*	        課題用サンプルプログラム        */
/*                                          */
/*	          担当教官：前田太郎			*/
/*	 プログラム作成：前田研究室 津田明憲	*/
/*	e-mail:tsuda.akinori@ist.osaka-u.ac.jp	*/
/*											*/
/********************************************/

/*
課題用のサンプルプログラムです．
わかりづらいプログラムで申し訳ありません．
使用プログラムはVisual C++ 2008 Express Editionです．
無料で使用することができるので，そちらを使ってください．


このままでも最低限の試行は行えると思いますが、あくまでサンプルです。
自分なりの工夫を『必ず』入れてください。
たとえば
・このままでは文字の出現が一様乱数であるので、YesとNoの出現率が1:1になるようにする
・アルファベットの大文字と小文字がサイズで判断できてしまうので、サイズを調節する
などが考えられます。
試行回数は10回としていますが、これが多いか少ないかを自分で考察して回数も変更してください。

yesの場合はyを，noの場合はuを押させるようにしています．
フォントの大きさなどは変更できるようにしているので，
これを参考に，うまく実験のプログラムを作ってください．

（参考文献 猫でもわかるWindowsプログラミング(ソフトバンクパブリッシング)）
*/


// サンプル使用法
/*
新しいプロジェクトで空のプロジェクトを作成
ソースにsample.cppを追加
プロジェクトにWinMM.libを追加
（プロジェクト名を右クリック→追加→既存の項目
c:program files\Microsoft SDKs\Windows\v6.0A\Lib内）
*/

// 補足
/*
Windows GUI プログラムですが，プログラムを分かりやすくするため，
CallBack関数をできるだけ使用していません．そのため，
ウインドウを移動したりボタンを押し続けるような動作には対応していません．
*/


// 5/18追加補足
/*
VisualStudioの文字列の互換の問題で，
printfなどの関数を使用するためにはオプションを変更する必要があります．

プロジェクトのオプション　→　構成プロパティ
を選択し，文字セットの部分を
【Unicode文字セットを使用する】から
【マルチバイト文字セットを使用する】に
変更してください．
*/

// 5/21　コメント追加
/*
課題についての質問がいくつかありましたが，
このプログラムは完成形ではありませんので，
課題について考え，場合によってはプログラムを変更する必要があります．

調べたいことのためには，どのような課題を設定すればよいのか，
自身で考察をし，プログラム内容を変更してください．

前田先生いわく，実験結果が優れていることよりも，
実験課題の設定理由がきちんと述べられていることが重要だとのことです．

----------------------
未解決の外部シンボルがあるというエラーが出るときは，
.libに対するリンクが正しくない可能性があります．
VC++のヘルプを参考に，関数ごとに必要となるlibを検索し，
WinMMと同じようにプロジェクトに追加してください．
*/


#include <stdio.h>
#include <windows.h>
#include <time.h>


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void RePaint(HWND hWnd, char* szMondai, char* szMoji1, char* szMoji2, char* szCheck, char* szTime);
int TypeStart(HWND);
BOOL MyGets(void);
HFONT MyCreateFont(int nHeight, DWORD dwCharSet, LPCTSTR lpName);

char szClassName[] = "Sample";	// ウィンドウクラス
char szMondai[32], szMoji1[16], szMoji2[16], szCheck[32], szTime[32];
DWORD dwStart, dwEnd;
BOOL bStart = FALSE, bWeit = FALSE;
int mode,chart;
BOOL kaitou,kotae;
BOOL CallEnd=FALSE, ShutDown=FALSE;
char tmp_char;
int n1,n2;
HFONT hFont1,hFont2,hFont3;
FILE *fp;

char str1[2][2] = {"a",""};//課題１用
char str23[20][2] = {"a","b","c","d","e","f","g","h","i","j",/*"k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",*/
					"A","B","C","D","E","F","G","H","I","J"/*,"K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"*/};//課題２，３用
char str4[25][2] = {"a","b","c","d","e","f","g","h","i","j",
					"A","B","C","D","E","F","G","H","I","J",
					"!","#","$","%","&"};//課題４用


int WINAPI WinMain(HINSTANCE hCurInst, HINSTANCE hPrevInst,
				   LPSTR lpsCmdLine, int nCmdShow)
{
	HWND hWnd;
	MMTIME mm;
	DWORD dwStart, dwEnd;
	char str2[100];
	int j=0;

	//---------------------------------------------
	//ウィンドウクラスの登録
	//(ここは特に書き換える必要はないと思います)
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;	//プロシージャ名
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hCurInst;//インスタンス
	wc.hIcon = NULL;
	wc.hCursor = (HCURSOR)LoadImage(NULL,
		MAKEINTRESOURCE(IDC_ARROW),
		IMAGE_CURSOR,
		0,
		0,
		LR_DEFAULTSIZE | LR_SHARED);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;	 // メニュー名
	wc.lpszClassName = (LPCSTR)szClassName;
	wc.hIconSm = NULL;

	if(!RegisterClassEx(&wc))
		return FALSE;

	//ウィンドウの生成
	hWnd = CreateWindow(szClassName,
			"猫でもわかるキー入力", //タイトルバーにこの名前が表示されます
			WS_OVERLAPPEDWINDOW, //ウィンドウの種類
			CW_USEDEFAULT,	//Ｘ座標
			CW_USEDEFAULT,	//Ｙ座標
			240,	//幅
			180,	//高さ
			NULL, //親ウィンドウのハンドル、親を作るときはNULL
			NULL, //メニューハンドル、クラスメニューを使うときはNULL
			hCurInst, //インスタンスハンドル
			NULL);
	if (!hWnd)
		return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//----------------------------------------------------------------
	//ここまでがウインドウ作成の準備

	//フォントの作成（フォントを作成したら，DeleteObjectで削除）
	hFont1 = MyCreateFont(40, SHIFTJIS_CHARSET, "MS Pゴシック");
	hFont2 = MyCreateFont(40, SHIFTJIS_CHARSET, "MS Pゴシック");
	hFont3 = MyCreateFont(15, SHIFTJIS_CHARSET, "MS Pゴシック");


	//文字入力
	//表示位置については，RePaint関数内で決定
	wsprintf(szMondai, "Modeを選択してください(1-4)");
	wsprintf(szMoji1,"");
	wsprintf(szMoji2,"");
	wsprintf(szCheck,"");
	wsprintf(szTime,"");

	//ウインドウの再描画
	//表示を更新したいとき，この関数を実行
	RePaint(hWnd, szMondai, szMoji1, szMoji2, szCheck, szTime);


	//文字入力を待つ（tmp_charに格納）
	//1-4の文字が入力されたらループを抜ける
	while(1){
		if(!MyGets()) return FALSE;
		if(tmp_char == '1' || tmp_char == '2' || tmp_char == '3' || tmp_char == '4'){
			break;
		}
	}
	mode = atoi(&tmp_char);



	wsprintf(str2,"result%d.csv",mode);//ファイル名の設定(result"課題番号".csvというファイルが同じフォルダに作成される)
	fp = fopen(str2,"w");
	fprintf(fp,"試行回数, 表示1, 表示2, 回答, 時間\n");


	for(j=0;j<10;j++){

		wsprintf(szMondai, "Mode %d  %d回目",mode ,j+1);
		wsprintf(szMoji1,"");
		wsprintf(szMoji2,"");
		wsprintf(szCheck,"");
		wsprintf(szTime,"");

		RePaint(hWnd, szMondai, szMoji1, szMoji2, szCheck, szTime);

		Sleep(1000);
		MessageBeep(MB_OK); //音を鳴らす

		//ランダムに待ち時間を設定
		Sleep(1000+(rand()%50)*100);

		//文字を表示
		TypeStart(hWnd);
		RePaint(hWnd, szMondai, szMoji1, szMoji2, szCheck, szTime);

		//時間計測開始
		timeGetSystemTime(&mm, sizeof(MMTIME));
		dwStart = mm.u.ms;

		while(1){
			if(!MyGets()) return FALSE;
			if(tmp_char == 'y' || tmp_char == 'u'){
				break;
			}
		}

		//時間計測終了
		timeGetSystemTime(&mm, sizeof(MMTIME));
		dwEnd = mm.u.ms;

		if(tmp_char == 'y') {wsprintf(szCheck, "あなたの回答 Yes");}
		else{wsprintf(szCheck, "あなたの回答 No");}

		wsprintf(szTime, "反応時間[%d]ms",dwEnd - dwStart);
		RePaint(hWnd, szMondai, szMoji1, szMoji2, szCheck, szTime);

		//結果のファイルへの書き込み
		if(mode==1) fprintf(fp,"%d, %s, "", %c, %d\n",j+1,str1[n1], tmp_char, dwEnd-dwStart);
		else if(mode==2||mode==3) fprintf(fp,"%d, %s, %s, %c, %d\n",j+1,str23[n1], str23[n2], tmp_char, dwEnd-dwStart);
		else if(mode==4) fprintf(fp,"%d, %s, %s, %c, %d\n",j+1,str4[n1], str4[n2], tmp_char, dwEnd-dwStart);
		
		Sleep(3000);

	}

	//自作の論理フォントの削除
	DeleteObject(hFont1);
	DeleteObject(hFont2);
	DeleteObject(hFont3);

	//fprintf(fp,"ファイルを閉じましたend\n");
	fclose(fp);

	return TRUE;

}



//画面情報を更新する
//文字の表示位置などを指定する
void RePaint(HWND hWnd, char* szMondai, char* szMoji1, char* szMoji2, char* szCheck, char* szTime){
	PAINTSTRUCT ps;
	HDC hdc;

	InvalidateRect(hWnd, NULL, TRUE);
	hdc = BeginPaint(hWnd, &ps);
	TextOut(hdc, 0, 0, szMondai, (int)strlen(szMondai));	//２，３の引数でx,y座標を決定
	SelectObject(hdc,hFont1);								//自作の論理フォントに変更
	TextOut(hdc, 40, 30, szMoji1, (int)strlen(szMoji1));			
	SelectObject(hdc,hFont2);
	TextOut(hdc, 100, 30, szMoji2, (int)strlen(szMoji2));
	SelectObject(hdc,hFont3);
	TextOut(hdc, 0, 80, szCheck, (int)strlen(szCheck));
	TextOut(hdc, 0, 100, szTime, (int)strlen(szTime));
	EndPaint(hWnd, &ps);
}


//文字入力用の関数
//文字入力されるまで待機（callback関数が呼び出される）
//tmp_charに格納
BOOL MyGets(void){
	MSG msg;
	BOOL bRet;

	CallEnd = FALSE;
	
	while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0) {
		if(ShutDown == TRUE){
			return FALSE;
		}
		else if (bRet == -1 || CallEnd == TRUE) {
			break;
		} else {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return TRUE;
}


int TypeStart(HWND hWnd)
{
	//表示する文字の決定

	if(mode == 1){
		n1 = 0;
		wsprintf(szMoji1, "%s", str1[n1]);
	}
	else if(mode == 2 || mode == 3){
		n1 = rand()%20;
		wsprintf(szMoji1, "%s", str23[n1]);
		n2 = rand()%20;
		wsprintf(szMoji2, "%s", str23[n2]);
	}
	else{
		n1 = rand()%25;
		wsprintf(szMoji1, "%s", str4[n1]);
		n2 = rand()%25;
		wsprintf(szMoji2, "%s", str4[n2]);
	}

	return 0;
}


//論理フォントの作成
HFONT MyCreateFont(int nHeight, DWORD dwCharSet, LPCTSTR lpName)
{
	return(	CreateFont(nHeight, 0, 0, 0,
				FW_DONTCARE,
				FALSE, FALSE, FALSE,
				dwCharSet,
				OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS,
				DEFAULT_QUALITY,
				DEFAULT_PITCH | FF_DONTCARE,
				lpName));
}


//ウィンドウプロシージャ
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch(msg){
		case WM_CHAR:
			tmp_char = wp;
			CallEnd = TRUE;
			break;
		case WM_DESTROY:
			ShutDown = TRUE;
			//自作の論理フォントの削除
			DeleteObject(hFont1);
			DeleteObject(hFont2);
			DeleteObject(hFont3);
			//fprintf(fp,"ファイルを閉じましたpostquit\n");
			fclose(fp);
			PostQuitMessage(0);
			break;
		default:
			return (DefWindowProc(hWnd, msg, wp, lp));
	}
	return 0;
}