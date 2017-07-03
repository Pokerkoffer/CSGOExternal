#pragma once
namespace Overlay
{
	class Color
	{
	private:
		int				m_Color[ 4 ];

	public:
		Color( void );
		Color( int r, int g, int b, int a = 255 );
		Color( unsigned long hex_color );
		Color			operator = ( const Color &color );
		int				&operator [] ( int iIndex );
		int				&operator () ( int iIndex );
		int				r( void ) const;
		int				g( void ) const;
		int				b( void ) const;
		int				a( void ) const;
		unsigned long	GetHex( void ) const;
		void			Set( int r, int g, int b, int a = 255 );
		void			Set( unsigned long hex_color );
	};
}