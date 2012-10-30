#pragma once

#include "StdAfx.h"

namespace GwaArx
{
	namespace Util
	{
		namespace _misc
		{
			void verifyBarDia( unsigned dia );	

			enum sysvar_bit
			{	
				setNULL			= 0,
				setOSMODE		= 1 << 0,
				setSNAPMODE		= 1 << 1,
				setORTHOMODE	= 1 << 2,
				setALL			= setOSMODE | setSNAPMODE | setORTHOMODE
			};

			class CursorStatusAutoRecorver
			{
			public:
				typedef short int_type;

				enum // OSMODE bits
				{
					osNULL	= 0,		// �� 
					osEND 	= 1,		// END���˵㣩 
					osMID 	= 2,		// MID���е㣩 
					osCEN 	= 4,		// CEN��Բ�ģ�
					osNOD 	= 8,		// NOD���ڵ㣩
					osQUA 	= 16,		// QUA�����޵㣩
					osINT	= 32,		// INT�����㣩
					osINS 	= 64,		// INS������㣩
					osPER 	= 128,		// PER�����㣩
					osTAN 	= 256,		// TAN���е㣩
					osNEA 	= 512,		// NEA������㣩
					osCLR 	= 1024,		// ������ж���׽
					osAPP 	= 2048,		// APP����۽��㣩
					osEXT 	= 4096,		// EXT�����죩
					osPAR	= 8192		// PAR��ƽ�У�
				};



			public:
				CursorStatusAutoRecorver( const sysvar_bit which );
				~CursorStatusAutoRecorver();

			private:
				sysvar_bit		m_which;
				int_type 	m_osMode;
				int_type 	m_snapMode;
				int_type 	m_orthoMode;
				
			};

			class FreeCursorAWhile : public CursorStatusAutoRecorver
			{
			public:
				FreeCursorAWhile( const sysvar_bit & which );
				~FreeCursorAWhile();
			};
		}
	}
}