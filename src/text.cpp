#include "text.hpp"

#include<iostream>
#include<cstring>
#include<string>

using namespace std;


// Defining the public color and styles constants character
// array declared inside text.hpp header file.

const char* Text::TRANSPARENT_BG = "49";

const char* Text::MAGENTA_BG = "45";
const char* Text::MAGENTA_FG = "35";

const char* Text::YELLOW_BG = "43";
const char* Text::YELLOW_FG = "33";

const char* Text::WHITE_BG = "107";
const char* Text::WHITE_FG = "97";

const char* Text::BLACK_BG = "40";
const char* Text::BLACK_FG = "30";

const char* Text::GREEN_BG = "42";
const char* Text::GREEN_FG = "32";

const char* Text::BLUE_BG = "44";
const char* Text::BLUE_FG = "34";

const char* Text::RED_BG = "41";
const char* Text::RED_FG = "31";

const char* Text::BLINK_SLOW = "5";
const char* Text::UNDERLINE = "4";
const char* Text::ITALIC = "3";
const char* Text::BOLD = "1";
const char* Text::NONE = "0";

// Defining the private static member variables declared
// inside the text.hpp header file.

char* Text::style   = strcpy(new char[1],Text::NONE);
char* Text::bgColor = (char*) Text::TRANSPARENT_BG;
char* Text::fgColor = (char*) Text::WHITE_FG;

bool Text::allow = true;

// Defining the setStyle method declared inside the
// text.hpp header file.

void Text::setStyle(const char* cstrings [],int len){
  free();
  // Computing length for final cstring.
  int final_length = 0;
  for(int j = 0;j<len;++j)
    final_length+=strlen(cstrings[j]);
  final_length *=2;
  // Allocating memory for final string.
  style = new char [final_length];
  for(int j = 0;j<len;++j){
    strcat(style,cstrings[j]);
    strcat(style,";");
  }
  style[final_length-1] = '\0';
}

// Defining stream insertion and extraction operators
// declared inside the text.hpp header file.

ostream& operator<<(ostream& os,const Text& text){
  // Discriminating response depending on whether the
  // allow flag has been enabled.
  if(Text::allow){
    os<<"\033["<<Text::fgColor<<";"
       <<Text::bgColor<<";"<<Text::style<<"m"
    <<text.content<<"\033[0m";
  }
  else os<<text.content;
  // returning ostream reference for purposes of
  // chaining.
  return os;
}

// Defining the assignment operators declared inside
// text.hpp header file.

const string& Text::operator=(const string& nstring){
  // De-allocating memory case content was not NULL
  // before.
  if(content != NULL)
    delete [] content;
  // Copying newString into content.
  const int length = nstring.length()+1;
  content = strcpy(new char[length],nstring.c_str());
  // returning string for cascaded assignment.
  return nstring;
}

const char* Text::operator=(const char* cstring){
  // De-allocating memory case content was not NULL
  // before.
  if(content != NULL)
    delete [] content;
    // Copying newString into content.
  const int length = strlen(cstring)+1;
  content = strcpy(new char[length],cstring);
  // returning string for cascaded assignment.
  return cstring;
}

const Text& Text::operator=(const Text& text){
  // De-allocating memory case content was not NULL
  // before.
  if(content != NULL)
    delete [] content;
  // Copying newString into content.
  const int length = strlen(text.content);
  content = strcpy(new char[length],text.content);
  // returning string for cascaded assignment.
  return *this;
}

// Defining the setter methods for the fgColor and
// bgColor private static members.

void Text::setFgColor(const char* newFg){
   // casting passed const char* which is defined
   // inside  text.hpp
   Text::fgColor = (char*) newFg;
}

void Text::setBgColor(const char* newBg){
   // casting passed const char* which is defined
   // inside  text.hpp
   Text::bgColor = (char*) newBg;
}

// Defining the constructors declared inside in the
// text.hpp header file.

Text::Text(const string& nstring){
  // Extracting length of newString and allocating
  // memory.
  const int length = nstring.length()+1;
  // Copying newString into content.
  content = strcpy(new char[length],nstring.c_str());
}

Text::Text(const char* cstring){
  // Getting length of cstring and allocating memory.
  const int length = strlen(cstring)+1;
  // Copying cstring into content.
  content = strcpy(new char[length],cstring);
}

Text::Text():content(NULL){}

// Defining the enable/disable methods for the color
// and styling methods.

void Text::toggleColors(){
  Text::allow = !Text::allow;
}

// Defining the freeStyle method declared inside the
// text.hpp header file.

void Text::free(){
  if(Text::style != NULL)
    delete [] Text::style;
}

// Defining the destuctor declared inside text.hpp
// header file.

Text::~Text(){
  // De-allocating memory for content member
  // variable.
  delete [] content;
}
