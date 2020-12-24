/*
 * Hydrogen
 * Copyright(c) 2002-2008 by Alex >Comix< Cominu [comix@users.sourceforge.net]
 *
 * http://www.hydrogen-music.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef WAVE_DISPLAY
#define WAVE_DISPLAY

#include <QtGui>
#include <QtWidgets>

#include <core/Object.h>

namespace H2Core
{
	class InstrumentLayer;
}

class WaveDisplay : public QWidget, public H2Core::Object
{
    H2_OBJECT
	Q_OBJECT

	public:
		explicit WaveDisplay(QWidget* pParent);
		~WaveDisplay();

		virtual void	updateDisplay( H2Core::InstrumentLayer *pLayer );

		void			paintEvent( QPaintEvent *ev );
		void			resizeEvent( QResizeEvent * event );
		void			mouseDoubleClickEvent(QMouseEvent *ev);
		
		void			setSampleNameAlignment(Qt::AlignmentFlag flag);

	signals:
		void doubleClicked(QWidget *pWidget);

	protected:
		Qt::AlignmentFlag			m_SampleNameAlignment;
		QPixmap						m_Background;
		QString						m_sSampleName;
		int *						m_pPeakData;
		
		/*
		 * Used to re-initialise m_pPeakData if width has changed
		 */
		
		int							m_nCurrentWidth;
		
		H2Core::InstrumentLayer *	m_pLayer;
};

inline void WaveDisplay::setSampleNameAlignment(Qt::AlignmentFlag flag)
{
	m_SampleNameAlignment = flag;
}

#endif
