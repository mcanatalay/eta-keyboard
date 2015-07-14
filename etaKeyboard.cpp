#include "etaKeyboard.h"

/* This is consturoctor of etaLanguage widget */

etaLanguage::etaLanguage(int x, int y, int w, int h, etaKeyboard *board_in,QWidget *parent) : QWidget(parent){
  int last=0;  //We will set last(last y value to deploy buttons)
  board = board_in;
  
  QStringList tmp; //We will set xml tags
  tmp.append("name");
  tmp.append("file");
  
  Reader *language = new Reader("settings.xml");
  language->setXML("settings","language",tmp); //Set xml standarts. We are currently taking all language names
  language->read(); //Store whole data
  
  setStyleSheet("background-color: #010101;"); //TODO this background color should be taken from settings.xml
  setWindowFlags(Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint);
  setGeometry(x-w,y,w,h*language->rowLength()); //This is where we deploy this widget
  
  keys = new etaButton[language->rowLength()]; //We allocate buttons for taken languages
  
  for(int i; language->rowLength() > i; i++){
    keys[i].set(language->rows[0][i],0,0,0,last,w,h);
    last += h; //Give last h
    keys[i].setParent(this);
    connect(&keys[i], SIGNAL(clicked(etaButton*)), this, SLOT(changeLanguage(etaButton*)));
  }
  delete language; //We wont need setting xml from now on.
}

void etaLanguage::changeLanguage(etaButton *newLanguage){ //Calls readLanguage which change keyboard
  board->readLanguage(newLanguage->text());
  board->special3();
}


/*Language  Selection Widget now ends. We will see main Keyboard member functions */
/* This is main class which handle whole graphical interface of keyboard */

etaKeyboard::etaKeyboard(QMainWindow *parent) : QMainWindow(parent){
  QDesktopWidget dw; //We will take physical values to parse them
  int sw = dw.screenGeometry(dw.primaryScreen()).width();
  int sh = dw.screenGeometry(dw.primaryScreen()).height();
  
  tmp = new QStringList; //This will used for whole xml sets.
  
  setting_file = new Reader("settings.xml"); //Create setting_file xml
  tmp->append("name");
  setting_file->setXML("settings","default",*tmp); //We will take default languages name first
  setting_file->read();
  
  /* Now we will set initials */
  row = 4;        //TODO this should be dynamitize
  upper = false;
  symbol = false;
  
  key_file = NULL;
  btns = NULL;
  
  width = sw/2;
  height = sh/4;
  blank = height/7;
  btn_width = width/26;
  btn_height = width/15;
  
  last = new int[row];
  column = new int[row]; 
  
  state = "lower";
  
  setGeometry((sw-width)/2,(sh-height)/2,width,height); //This is important for position but we will resize it since we dont know number of buttons.
  
  setWindowFlags(Qt::FramelessWindowHint | Qt::X11BypassWindowManagerHint);
  setStyleSheet("background-color: #010101;"); //TODO this should be in settings.xml which I indicated before
  readLanguage(setting_file->rows[0][0]); //This rows gives name of default language and we will red it.
  menu = new etaLanguage(this->geometry().x(),this->geometry().y(),s3->getSize(),btn_height,this);
  
  text = new QLabel(this); //We will initialize guessing label
  text->setGeometry(0,0,width,blank);
  text->setStyleSheet("QLabel{color: white; qproperty-alignment: AlignCenter;}");
}

void etaKeyboard::readLanguage(QString name){ //We will take name of given language
  if(key_file != NULL)
    delete key_file;

  tmp->clear();
  tmp->append("name");
  tmp->append("file");
  setting_file->setXML("settings","language",*tmp);
  setting_file->read();
  setting_file->query(0,name);
  
  key_file = new Reader(setting_file->qrows[1][0]); //We are giving name to xml and taking path of file, and reading it.

  tmp->clear();
  tmp->append("command"); //We will read command tag in xml and pass its value to system.
  key_file->setXML("keys","setting",*tmp);
  key_file->read();
  system(key_file->rows[0][0].toUtf8().data()); //We pass it.
  
  tmp->clear();
  tmp->append("level");
  tmp->append("size");
  tmp->append("name");
  tmp->append("code");
  tmp->append("depend");
  tmp->append("type");

  key_file->setXML("keys","key",*tmp); //We will read key values. First we will read whole into memory then we will query it.
  key_file->read();

  readKeys();
}

void etaKeyboard::readKeys(){
  if(btns == NULL){ //If it is not initialized it will create it.
    btns = new etaButton[42]; //TODO This 42 should be dynamitize! NOTE You can use key_file->queryLength() !!!!
    
  }
  
  int btn_number=0; //Since we are using linear type but multi layering it we will store it.(Like i in for)
  
  for(int y = 0; row > y; y++){
    key_file->query(0,QString::number(y),5,state); //Q it. How? -> 0 means level.Give given level which is row which is y in our case.
                                                  //Then Query 5 which is type and give type(lower in default) to it. And take whole data to qdata.
    last[y] = 0; //Whole buttons will start at 0 point at x.
    column[y] = key_file->queryLength(); //We will give number of button in given level to column.
    for(int x = 0; column[y] > x; x++, btn_number++){ //We will change button in every itteration.
      btns[btn_number].set(key_file->qrows[2][x],key_file->qrows[3][x].toInt(),key_file->qrows[4][x].toInt(),last[y],btn_height*y+blank,btn_width*key_file->qrows[1][x].toInt(),btn_height); //Set button.
      btns[btn_number].setParent(this); //This is important to show button
      btns[btn_number].show(); //Show it
      last[y] += btn_width*key_file->qrows[1][x].toInt(); //Give last position to last.
      
      disconnect(&btns[btn_number], 0, this, 0);
      
      
      if(btns[btn_number].getValue() == 0) //Value 0 means change to symbol we wont connect it at this stage
	s1 = &btns[btn_number];
      else if(btns[btn_number].getValue() == 3) //Value 3 means caps lock we will change keyboard addition to its orginal purpose.
	s2 = &btns[btn_number];
      else if(btns[btn_number].getValue() == 1) //Value 1 means change language we wont connect it at this stage
	s3 = &btns[btn_number];
      else{
	disconnect(&btns[btn_number], SIGNAL(pushed(etaButton*)), this, SLOT(keyPushed(etaButton*)));
	disconnect(&btns[btn_number], SIGNAL(pulled(etaButton*)), this, SLOT(keyPulled(etaButton*)));
	connect(&btns[btn_number],SIGNAL(pushed(etaButton*)), this, SLOT(keyPushed(etaButton*)));
	connect(&btns[btn_number],SIGNAL(pulled(etaButton*)), this, SLOT(keyPulled(etaButton*)));
      }
    }
  }
  resize(last[0],btn_height*row+blank); //Resize form to fit.
  disconnect(s1, 0, this, 0);
  disconnect(s2, 0, this, 0);
  disconnect(s3, 0, this, 0);
  disconnect(s1, SIGNAL(clicked(etaButton*)), this, SLOT(special1()));
  disconnect(s2, SIGNAL(clicked(etaButton*)), this, SLOT(special2()));
  disconnect(s3, SIGNAL(clicked(etaButton*)), this, SLOT(special3()));
  connect(s1, SIGNAL(clicked(bool)), this, SLOT(special1()));
  connect(s2, SIGNAL(clicked(bool)), this, SLOT(special2()));
  connect(s3, SIGNAL(clicked(bool)), this, SLOT(special3()));
}

void etaKeyboard::keyPushed(etaButton *button){
  if(button->getValue() == 65 || button->getValue() == 36 || button->getValue() == 23) //Control if it is space enter or tab if it is clear guess text label
    text->clear();
  else if(button->getValue() == 22){ //If it is backspace only delete 1 character
    QString tmp;
    tmp = text->text();
    tmp.truncate(tmp.size()-1);
    text->setText(tmp);
  }
  else if(button->getValue() != 0 && button->getValue() != 1 && button->getValue() != 3) //If it is not special button add text of button to guess text label
    text->setText(text->text() + button->text());

  if(button->getDepend() == -1 && button->getValue() != 0 && button->getValue() != 1 && button->getValue() != 3){ //If it is not depended just initialize x11.
    XTestFakeKeyEvent(QX11Info::display(), button->getValue(), true, 0);
    XSync(QX11Info::display(), False);
  } else if(button->getValue() != 0 && button->getValue() != 1) { //If it is depend first initialize depend
    XTestFakeKeyEvent(QX11Info::display(), button->getDepend(), true, 0);
    XSync(QX11Info::display(), False);
    XTestFakeKeyEvent(QX11Info::display(), button->getValue(), true, 0);
    XSync(QX11Info::display(), False);
  }
}

void etaKeyboard::keyPulled(etaButton *button){
  if(button->getDepend() == -1 && button->getValue() != 0 && button->getValue() != 1){ //If it is not depend just destroy x11
    XTestFakeKeyEvent(QX11Info::display(), button->getValue(), false, 0);
    XSync(QX11Info::display(), False);
  } else if(button->getValue() != 0 && button->getValue() != 1) { //If it is depend first destroy depend
    XTestFakeKeyEvent(QX11Info::display(), button->getValue(), false, 0);
    XSync(QX11Info::display(), False);
    XTestFakeKeyEvent(QX11Info::display(), button->getDepend(), false, 0);
    XSync(QX11Info::display(), False);
  }
}

void etaKeyboard::special1(){ //Symbol, Toggle symbol
  if(!symbol){
    symbol = true;
    state = "symbol";
    s2->setEnabled(false);
    readKeys(); //We will query symbol types
  } else {
    symbol = false;
    state = "lower";
    s2->setEnabled(true);
    readKeys();
  }
}

void etaKeyboard::special2(){ //Capital, Toggle capital
  if(!upper && !symbol){
    upper = true;
    state = "upper";
    s2->sticked(true); //Sticked button
    readKeys(); //We will query upper types
  } else if(!symbol) {
    upper = false;
    state = "lower";
    s2->sticked(false);
    readKeys();
  }
}

void etaKeyboard::special3(){
  if(menu->isHidden()){
    s3->sticked(true);
    menu->show();
  } else{
    s3->sticked(false);
    menu->hide();
  }
}

void etaKeyboard::toggle(){ //Toggle keyboard's hidden state
  if(this->isHidden())
    show();
  else
    hide();
}

/* These are made form dragable TODO more proper solution */
void etaKeyboard::mousePressEvent(QMouseEvent *event) {
  m_nMouseClick_X_Coordinate = event->x();
  m_nMouseClick_Y_Coordinate = event->y();
}

void etaKeyboard::mouseMoveEvent(QMouseEvent *event) {
  int x,y;
  x = event->globalX()-m_nMouseClick_X_Coordinate;
  y = event->globalY()-m_nMouseClick_Y_Coordinate;
  setGeometry(x,y,last[0],btn_height*row+blank); //Set mains position
  menu->setGeometry(x-btn_width*2,y,btn_width*2,btn_height*2); //Set menu's position TODO it should be revized.
}

etaKeyboard::~etaKeyboard(){ //Free
  delete text;
  delete key_file;
  delete setting_file;
  delete column;
  delete last;
}



/* NOTE: Here we start our key funcions */


etaButton::etaButton(QWidget *parent) : QPushButton(parent){
  setStyleSheet(QString("QPushButton{color: #A6A5A9;background-color: #2F2F36; border-style: solid;border-radius: 0px;border: 2px solid #010101;}")          //Style of normal button TODO it should be import to settings.xml
		  +QString("QPushButton:hover{color: #A6A5A9;background-color: #606165; border-style: solid;border-radius: 0px;border: 2px solid #010101;}")  //Hovered button
		  +QString("QPushButton:pressed{color: #3A4040;background-color: #FDFFFE; border-style: solid;border-radius: 0px;border: 2px solid #010101;}")); //Pressed button
  value = 0;
  connect(this, SIGNAL(pressed()), this, SLOT(buttonPushed()));
  connect(this, SIGNAL(released()), this, SLOT(buttonPulled()));
  connect(this, SIGNAL(clicked(bool)), this, SLOT(buttonClicked()));
};

void etaButton::sticked(bool sticky){
  if(!sticky){
  setStyleSheet(QString("QPushButton{color: #A6A5A9; background-color: #2F2F36; border-style: solid;border-radius: 0px;border: 2px solid #010101;}")
		  +QString("QPushButton:hover{color: #A6A5A9;background-color: #606165; border-style: solid;border-radius: 0px;border: 2px solid #010101;}")
		  +QString("QPushButton:pressed{color: #3A4040;background-color: #FDFFFE; border-style: solid;border-radius: 0px;border: 2px solid #010101;}"));
  } else {
  setStyleSheet(QString("QPushButton{color: #3A4040;background-color: #FDFFFE; border-style: solid;border-radius: 0px;border: 2px solid #010101;}"));
  }
}


void etaButton::buttonPushed(){
  emit pushed(this); //Passes adress of button
}

void etaButton::buttonPulled(){
  emit pulled(this);
}

void etaButton::buttonClicked(){
  emit clicked(this);
}

int etaButton::getValue(){
  return value;
}

int etaButton::getDepend(){
  return depend;
}

int etaButton::getSize(){
  return width();
}

void etaButton::set(QString text_in, int value_in, int depend_in, int x_in, int y_in, int w_in , int h_in){
  this->setText(text_in);
  value = value_in;
  depend = depend_in;
  this->setGeometry(x_in,y_in,w_in,h_in);
}


#include "etaKeyboard.moc"
