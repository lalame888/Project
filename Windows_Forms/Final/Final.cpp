// Final.cpp: 主要專案檔。

#include "stdafx.h"

#include "GameForm.h"
using namespace System;
using namespace Final;




int main(array<System::String ^> ^args)
{
    
	
	GameForm ^game = gcnew GameForm;
	game->ShowDialog();
	//about->ShowDialog();
    return 0;
}
