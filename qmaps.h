#ifndef QMAPS_H
#define QMAPS_H

#include <QtGui>
#include <QtCore>
#include <QtWebKit/QtWebKit>

class Maps : public QWidget
{
    Q_OBJECT
    
public:
    Maps(QWidget *parent = 0);

public slots:
    void goLeft() {
        moveDxDy(-10, 0);
    }

    void goRight() {
        moveDxDy(+10, 0);
    }

    void goUp() {
        moveDxDy(0, -10);
    }

    void goDown() {
        moveDxDy(0, +10);
    }

    void goHome() {
        mView->page()->mainFrame()->evaluateJavaScript( "map.panTo(myLatlng);" );
    }

private:
    void setupUI();

    void moveDxDy( int dx, int dy ) {
        mView->page()->mainFrame()->evaluateJavaScript( QString("map.panBy(%1, %2);").arg(dx).arg(dy) );
    }


    QWebView *mView;
};

#endif // QMAPS_H
