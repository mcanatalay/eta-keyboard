#ifndef READER_H
#define READER_H

#include <QXmlStreamReader>
#include <QStringList>
#include <QObject>
#include <QFile>
#include <QString>
#include <QDebug>

/* This is an basic xmlReader class. It uses xmlStream to read xmlData.
 * This class has lack of efficiency. However, it allows us a easier usage.
 * Since there is a lot of deallocation an allocation it is not recommended for big data sets.
 * This class takes main 3 argument in setXML function. It can be used in any basic xml.
 * Define your table and cell names and then give field names you want to store.
 * This class render this data into simpler form, and this can cause over memory usage.
 * To use query function, you should give one field_number(starts from 0), and desired text as second argument.
*/

class Reader : public QObject{
  Q_OBJECT
private:
  QXmlStreamReader * xmlStream;
  QFile * xmlFile;
  QStringList *field_names;
  QString table;
  QString cell;
  
  int number_of_rows;
  int number_of_field;
  bool xStatus;
  void flush();
  void processTable(); //This function process each table
public:
  QStringList * rows; //Just temporary data storage.
  QStringList * qrows;
  Reader(QString,QObject *parent=0);
  int rowLength();
  int queryLength();
  void read(); //Reads whole data
  void query(int,QString);
  void query(int,QString,int,QString);
  void open(QString); //This function only for re open xml file.
  void setXML(const QString&, const QString&, const QStringList& fields); //Sets xml
  virtual ~Reader();
};

#endif // xmlreader_H
