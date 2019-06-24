const int w = 80;
const int h = 25;

#include "include/types.h"
#include "include/sys.h"
#include "include/screen.h"
#include "include/kb.h"

kmain()
{
  unsigned char *video = (unsigned char *)0xB8000;
  int cursorX = 0;
  int cursorY = 0;
  cls(video);

  while(1){
    prints("DOS>", &cursorX, &cursorY, video);
    string s = readkb(&cursorX, &cursorY, video);
    if(strEql(s, "create")){
      //createfile();
      prints("\nCreated file", &cursorX, &cursorY, video);
    }else if(strEql(s, "read")){
      //readFile();
    }else{
      prints("\nAcces denied", &cursorX, &cursorY, video);
    }
    printc('\n',0x07, &cursorX, &cursorY, video);
  }

}
