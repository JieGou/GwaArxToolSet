#include "StdAfx.h"

#include "Util_Misc.h"
#include "BeanLengthCheck.h"
#include "Configurable.h"

#include <strsafe.h>

void GwaArx::Util::_misc::VerifyBarDia( unsigned dia )
{	
	if (!GwaArx::Configurations::CGwaDataSheet::IsValidBarDia(dia))
	{
		throw std::invalid_argument(
			"��Ч�ĸֽ�ֱ��, ֻ���� { 10, 12, 16, 20, 25, 32, 40 }");
	}	
}

ads_real * GwaArx::Util::_misc::asAdsPoint( AcGePoint3d & p3d )
{
	return reinterpret_cast<ads_real *>(&p3d);
}

const ads_real * GwaArx::Util::_misc::asAdsPoint( const AcGePoint3d & p3d )
{
	return reinterpret_cast<const ads_real *>(&p3d);
}
