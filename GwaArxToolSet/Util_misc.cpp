#include "StdAfx.h"

#include "Util_misc.h"
#include "Configurable.h"

#include <strsafe.h>

void GwaArx::Util::_misc::verifyBarDia( unsigned dia )
{	
	if (!GwaArx::Configurations::CGwaDataSheet::IsValidBarDia(dia))
	{
		throw std::invalid_argument(
			"��Ч�ĸֽ�ֱ��, ֻ���� { 10, 12, 16, 20, 25, 32, 40 }");
	}	
}

