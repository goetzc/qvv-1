/****************************************************************************
**
**  QVV Image Viewer
**  Copyright (c) 1999-2020 Vladi Belperchinov-Shabanski
**  <cade@bis.bg> <shabanski@gmail.com> <cade@cpan.org>
**  http://cade.datamax.bg/qvv/
**
****************************************************************************/

#include <QKeyEvent>
#include <QResource>

#include "qvv_help.h"

QvvHelpBrowser::QvvHelpBrowser()
  : QTextBrowser()
{
};

void QvvHelpBrowser::keyPressEvent ( QKeyEvent * e )
{
  if( e->modifiers() & Qt::ALT )
    {
    switch( e->key() )
      {
      default: QTextBrowser::keyPressEvent( e ); break;
      }
    }
  else
    {
    switch( e->key() )
      {
      case Qt::Key_Escape:
      case Qt::Key_Return:
      case Qt::Key_F4    : close(); break;

      default:
            if( e->text() == "" )
              QTextBrowser::keyPressEvent( e );
            else
              switch( e->text().toLatin1().at( 0 ) )
              {
              default: QTextBrowser::keyPressEvent( e ); break;
              }
      }
    }
};

QvvHelpBrowser *help_browser;

void display_help()
{
  if( help_browser == NULL )
    help_browser = new QvvHelpBrowser;
  help_browser->setHtml( QString( QVariant( (const char*)(QResource( ":/qvv_help.html" ).data()) ).toString() ) );

  help_browser->setObjectName( "QvvHelpWindow" );
  help_browser->setWindowTitle( "QVV/4 Help" );

  help_browser->resize( 640, 400 );
  help_browser->move( 100, 100 );

  help_browser->show();
};



