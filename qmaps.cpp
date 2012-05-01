#include "qmaps.h"

Maps::Maps(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}

void Maps::setupUI()
{
    QGridLayout *layout = new QGridLayout( this );

    //
    // Buttons
    //
    QPushButton *btnLeft = new QPushButton( "Left", this );
    QPushButton *btnRight = new QPushButton( "Right", this );
    QPushButton *btnUp = new QPushButton( "Up", this );
    QPushButton *btnDown = new QPushButton( "Down", this );
    QPushButton *btnHome = new QPushButton( "Home", this );

    connect( btnLeft, SIGNAL(clicked()), this, SLOT(goLeft()) );
    connect( btnRight, SIGNAL(clicked()), this, SLOT(goRight()) );
    connect( btnUp, SIGNAL(clicked()), this, SLOT(goUp()) );
    connect( btnDown, SIGNAL(clicked()), this, SLOT(goDown()) );
    connect( btnHome, SIGNAL(clicked()), this, SLOT(goHome()) );

    layout->addWidget( btnLeft, 3, 1 );
    layout->addWidget( btnRight, 3, 3 );
    layout->addWidget( btnUp, 2, 2 );
    layout->addWidget( btnDown, 4, 2 );
    layout->addWidget( btnHome, 3, 2 );

    //
    // Embedded webpage
    //
    mView = new QWebView( this );
    mView->settings()->setAttribute( QWebSettings::JavascriptEnabled, true );
    QString fileName = qApp->applicationDirPath() + "/map.html";
    if( !QFile(fileName).exists() ) {
        qDebug() << "File not found:" << fileName;
    }

    QUrl url = QUrl::fromLocalFile( fileName );
    mView->load( url );

    layout->addWidget( mView, 1, 4, 5, 1 );
}
