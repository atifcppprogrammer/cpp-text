#include "src/text.hpp"

#include<iostream>
#include<string>

using namespace std;

int main(int argc,char* argv[]){

  // Creating an instance of class Text since we
  // have not set the static coloring and styling
  // properties this line will just display show
  // standard text.
  Text text = "Just some standard text here !!!";
  cout<<text<<endl;

  // We now change the static color and styling
  // properties to display some bold and italic
  // red text.

  // Style.
  const char* style [] = {
    Text::ITALIC,
    Text::BOLD
  };
  Text::setStyle(style,2);

  // Color.
  Text::setFgColor(Text::RED_FG);
  Text another = text;
  another = "Some text in red and bold !!!";
  cout<<text<<endl;

  // We now change the properties to show some
  // green bold text that blinks yes you read
  // that right blinking. Check it out.

  // Style.
  const char* newStyle [] = {
    Text::BLINK_SLOW,
    Text::BOLD
  };
  Text::setStyle(newStyle,2);

  // Color.
  Text::setFgColor(Text::GREEN_FG);
  another = "Some bold green blinky action here !!!";
  cout<<another<<endl;

  // Last statment here needs to be called to
  // free up some memory being held by static
  // members of this class. You must call this
  //  when you are done with using this class.
  Text::free();

  return 0;
}
