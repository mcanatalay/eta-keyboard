#include "reader.h"
using namespace std;

Reader::Reader(QString file_in, QObject *parent) : QObject(parent){
  field_names = NULL;
  rows = NULL;
  qrows = NULL;
  xmlStream = NULL;

  number_of_field = 0;
  number_of_rows = 0;
    
  xmlFile = new QFile;
  xmlFile->setFileName(file_in);
}

void Reader::open(QString file_in){
  flush();
  
  delete xmlFile;
  xmlFile = new QFile;
  xmlFile->setFileName(file_in);
}

void Reader::setXML(const QString& table_in, const QString& cell_in, const QStringList& fields){
  if(xStatus)
    xmlFile->close();
  xStatus = xmlFile->open(QIODevice::ReadOnly);
  if(!xStatus)
    exit(EXIT_SUCCESS);
  
  flush();
  
  xmlStream = new QXmlStreamReader;
  xmlStream->setDevice(xmlFile);
  
  table = table_in;
  cell = cell_in;
  number_of_field = fields.size();
  
  field_names = new QStringList;
  rows = new QStringList[number_of_field];
  
  for(int i = 0; number_of_field > i; i++)
    field_names->append(fields[i]);
}

void Reader::read(){
  if(xmlStream->readNextStartElement() && xmlStream->name() == table){
    processTable();
    number_of_rows = rows->size();
  }
    
  if (xmlStream->tokenType() == QXmlStreamReader::Invalid)
    xmlStream->readNext();
}

void Reader::query(int field, QString query_in){
  if(qrows != NULL)
    delete[] qrows;
  qrows = new QStringList[number_of_field];
  for(int i = 0; number_of_rows > i; i++){
    if(rows[field][i] == query_in){
      for(int k = 0; number_of_field > k; k++)
	qrows[k].append(rows[k][i]);
    }
  }
}

void Reader::query(int field1, QString query_in1, int field2, QString query_in2){
  if(qrows != NULL)
    delete[] qrows;
  qrows = new QStringList[number_of_field];
  for(int i = 0; number_of_rows > i; i++){
    if(rows[field1][i] == query_in1 && rows[field2][i] == query_in2){
      for(int k = 0; number_of_field > k; k++)
	qrows[k].append(rows[k][i]);
    }
  }
}

void Reader::processTable(){
  while(xmlStream->readNextStartElement()){
    if(xmlStream->name() == cell){
      while(xmlStream->readNextStartElement()){
	for(int i = 0 ; number_of_field > i; i++){
	  if(xmlStream->name() == field_names->at(i)){
	    rows[i].append(xmlStream->readElementText());
	    break;
	  } else if(i == number_of_field-1){ //Skip undesired tags
	    xmlStream->readElementText();
	  }
	}
      }
    }
    else
      xmlStream->skipCurrentElement();
  }
}

int Reader::rowLength(){
  return number_of_rows;
}

int Reader::queryLength(){
  if(qrows != NULL)
    return qrows->size();
  else
    return -1;
}

void Reader::flush(){
  if(rows != NULL)
    delete[] rows;
  if(field_names != NULL)
    delete field_names;
  if(xmlStream != NULL)
    delete xmlStream;
  field_names = NULL;
  rows = NULL;
  xmlStream = NULL;
};

Reader::~Reader(){
  if(rows != NULL)
    delete[] rows;
  if(field_names != NULL)
    delete field_names;
  if(xmlStream != NULL)
    delete xmlStream;
  field_names = NULL;
  rows = NULL;
  xmlStream = NULL;
  if(qrows != NULL)
    delete[] qrows;
  delete xmlFile;
}

#include "reader.moc"