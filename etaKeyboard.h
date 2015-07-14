#ifndef etaKeyboard_H
#define etaKeyboard_H

// #include <QtGui/QLabel>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QString>
#include "reader.h"
#include <QDebug>
#include <iostream>
#include <QLabel>
#include <X11/XKBlib.h>
#include <qx11info_x11.h>
#include <X11/extensions/XTest.h>

class etaButton;
class etaLanguage;

class etaKeyboard : public QMainWindow{
  Q_OBJECT
private:
  QString state; //This holds current state of keyboard
  int blank; //This value determines the blank size(height of blank) in keyboard
  int height,width; //This values determines form size of keyboard
  int btn_height,btn_width; //This values determines unit size of button
  QLabel *text; //This label is preview of each word.
  bool upper,symbol; //This booleans stores state of keyboard
  QStringList *tmp; //This tmp QStringList stores tags of xml which wanted to read
  Reader *key_file,*setting_file; //Key_File stores Language XML file setting_file stores Setting XML
  int row; //Row stores number of levels(rows) in keyboard //TODO it should be dynamitize
  int *column; //Column is a array which stores number of keys in each level.
  int *last; //Last is a array which stores last X position value in each level. (To position it)
  etaButton *btns; //This button array stores all buttons which will set later
  etaButton *s1,*s2,*s3; //This buttons pointers just stores special buttons. We wont allocate memory for them.
  etaLanguage *menu;//Menu pointer stores etaLanguage which is menu for changing language.
  /* TODO This four about draging keyboard and it should be enchance... */
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  int m_nMouseClick_X_Coordinate;
  int m_nMouseClick_Y_Coordinate;
public:
  etaKeyboard(QMainWindow *parent=0);
  virtual ~etaKeyboard();
public Q_SLOTS:
  void toggle();
  void special1(); //Symbol buttons function
  void special2(); //Upper-Lower buttons function
  void special3(); //Language Menu buttons function
  void keyPushed(etaButton*); //This function will be called when key pressed
  void keyPulled(etaButton*); //This function will be called when key released
  void readLanguage(QString); //This function will accept take Language name and initialize readlanguage
  void readKeys(); //Read keys will read all buttons into keyboard from XML.
signals:
  void openLanguageMenu(); //This signal will emitted when language button clicked.
};

class etaLanguage : public QWidget{
  Q_OBJECT
private:
  etaKeyboard *board; //This pointer will point given keyboard
  etaButton *keys; //This is array of buttons which stores languages. This languages will be readed on settings.xml
public:
  etaLanguage(int x=0, int y=0, int w=0, int h=0, etaKeyboard *board_in=0, QWidget *parent=0); //Consturactor will take position of main(x,y), Width and Height of language button(w,h), etaKeyboards adress.
public slots:
  void changeLanguage(etaButton*); //This will called when clicked emitted. This will take etaButton and will use its interior data.
};

class etaButton : public QPushButton{
 Q_OBJECT
private:
  int value; //This will store value which will pressed. X11 Value.
  int depend; //This will store depend value. If it is not -1 it will pressed before value.
public:
  void sticked(bool); //This will toggle sticky.
  int getValue(); //This will return value.
  int getDepend(); //This will return depend.
  int getSize(); //This will return size ratio number.
  etaButton(QWidget *parent=0); //Consturactor
  void set(QString,int,int,int,int,int,int); //Setter function,it will accept as follow Button name, value, depend, x, y, w, h.
public slots:
  void buttonClicked(); //This will listed pushbuttons clicked signal and emit clicked(etaButton*)
  void buttonPushed(); //This will listen pushbuttons pressed signal and emit pushed(etaButton*)
  void buttonPulled(); //This will listen pushbuttons released signal and emit released(etaButton*)
signals:
  void clicked(etaButton*); //These three of them will give buttons adress
  void pulled(etaButton*);
  void pushed(etaButton*);
};

#endif // etaKeyboard_H
