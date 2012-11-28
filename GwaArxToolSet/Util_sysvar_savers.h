#pragma once

#include "StdAfx.h"

#define  SUPRESS_ORTHO_SNAP_MODE_A_WHILE GwaArx::Util::FreeCursorAWhile \
_close_ortho_snap_mode_a_while_ (static_cast<GwaArx::Util::sysvar_bit>(\
	GwaArx::Util::setORTHOMODE | \
	GwaArx::Util::setSNAPMODE))

#define  SUPRESS_ORTHO_SNAP_OS_MODE_A_WHILE GwaArx::Util::FreeCursorAWhile \
_close_os_snap_ortho_mode_a_while_ (static_cast<GwaArx::Util::sysvar_bit>(\
	GwaArx::Util::setORTHOMODE | \
	GwaArx::Util::setSNAPMODE | \
	GwaArx::Util::setOSMODE))

namespace GwaArx
{
	namespace Util
	{
		namespace _sysvar_savers
		{
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