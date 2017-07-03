#pragma once
#include "stdafx.h"
#include <Overlay\Overlay.h>

namespace Overlay
{
	class CD3D9Overlay : public IOverlay
	{
	private:
		IDirect3D9Ex		*m_pDirect3D9Ex;
		IDirect3DDevice9Ex	*m_pDirect3D9Device;
		HWND 				m_hWindow;
	private:
		HRESULT StartupD3D9Components( HWND hWindow );

	public:
		CD3D9Overlay( void );
		~CD3D9Overlay( void );
		bool				Create( const HWND hWindow );
		bool				Render( void );
		void				Shutdown( void );
	};
}