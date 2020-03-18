#include<iostream>
#include<string>

using namespace std;

class Text{

  private:

      // member variables will house foreground & background colors
      // of stuff that is being is being displayed on console.
      static char* fgColor, *bgColor;

      // member variable will house all the style attributes that
      // will be applied to content member variable inside a dynamic
      // array.
      static char* style;

      // static member variable is used to determine if the coloring
      // and styling is to be enabled, initially set to true.
      static bool allow;

      // member variable will house the text that will be printed
      // out to console, inside a dynamic array.
      char* content;

  public:

      // method will be used to extract content from console using
      // the instance of istream passed to it.
      friend istream& operator>>(istream&,const Text&);

      // method will be used to diplay the stored content using
      // instance of ostream that is passed to it.
      friend ostream& operator<<(ostream&,const Text&);

      // method overloads the assignment operator that overwrites
      // the characters inside the content array.
      const string& operator=(const string&);
      const Text& operator=(const Text&);
      const char* operator=(const char*);

      // methods are used to set the private static members
      // housing foreground, background colors and style.

      // style.
      static void setStyle(const char* [],int);

      // colors.
      static void setFgColor(const char*);
      static void setBgColor(const char*);

      // method is used to release dynamic memory for the private
      // style member.
      static void free();

      // Overloaded constructors have been defined to provided
      // flexibility ensuring instance of Text can be created
      // using std:string or cstring.
      Text(const string&);
      Text(const char*);
      Text();

      // method to enable/disable all styling and coloring once
      // called.
      static void toggleColors();

      // Defining destructor to free memory of char* content
      // member.
      ~Text();

      // we store the required styles and colors as static const
      // char*, at present we are housing only a few and will
      // expand it to contain more.

      // Transparent.
      static const char* TRANSPARENT_BG;

      // Styles.
      static const char* BLINK_SLOW;
      static const char* UNDERLINE;
      static const char* ITALIC;
      static const char* BOLD;
      static const char* NONE;

      // Magenta.
      static const char* MAGENTA_BG;
      static const char* MAGENTA_FG;

      // Yellow.
      static const char* YELLOW_BG;
      static const char* YELLOW_FG;

      // White.
      static const char* WHITE_BG;
      static const char* WHITE_FG;

      // Black.
      static const char* BLACK_BG;
      static const char* BLACK_FG;

      // Green.
      static const char* GREEN_BG;
      static const char* GREEN_FG;

      // Blue.
      static const char* BLUE_BG;
      static const char* BLUE_FG;

      // Red.
      static const char* RED_BG;
      static const char* RED_FG;
};
