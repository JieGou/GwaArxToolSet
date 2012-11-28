#pragma once

#include "StdAfx.h"

#include "Util.h"

#include "OverKill.h"

void JustaTest( void )
{
	using namespace GwaArx::Util;

 	ads_name name;
 	ads_point ignore;
 	ret_RTNORM(::acedEntSel(TEXT("ѡһ��ֱ�ߣ�"), name, ignore));
	
 	BOOST_AUTO(line, name2sp<AcDbLine>(name));
 	if (line)
 	{
		xssert(line.unique());
 		line.reset();		

		GwaArx::OverKill::okLine(name2id(name));
 	}	
 	else
 	{
 		acutPrintf(TEXT("*��Ҫһ��ֱ��"));
 	}
}

