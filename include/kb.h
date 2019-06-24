#ifndef  KEYBOARD_H
#define KEYBOARD_H

string readkb(int *x, int *y, unsigned char *v){
  string strbuff = "";
  int i = 0;
  int reading = 1;
  while(reading){
    if(inport(0x64) & 0x1){
      switch(inport(0x60)){
          case 16:
                  printc('q',0x07, x, y, v);
                  strbuff[i] = 'q';
                  i++;
                  break;
          case 17:
                  printc('w',0x07, x, y, v);
                  strbuff[i] = 'w';
                  i++;
                  break;
          case 18:
                  printc('e',0x07, x, y, v);
                  strbuff[i] = 'e';
                  i++;
                  break;
          case 19:
                  printc('r',0x07, x, y, v);
                  strbuff[i] = 'r';
                  i++;
                  break;
          case 20:
                  printc('t',0x07, x, y, v);
                  strbuff[i] = 't';
                  i++;
                  break;
          case 21:
                  printc('y',0x07, x, y, v);
                  strbuff[i] = 'y';
                  i++;
                  break;
          case 22:
                  printc('u',0x07, x, y, v);
                  strbuff[i] = 'u';
                  i++;
                  break;
          case 23:
                  printc('i',0x07, x, y, v);
                  strbuff[i] = 'i';
                  i++;
                  break;
          case 24:
                  printc('o',0x07, x, y, v);
                  strbuff[i] = 'o';
                  i++;
                  break;
          case 25:
                  printc('p',0x07, x, y, v);
                  strbuff[i] = 'p';
                  i++;
                  break;
          case 26:
                  printc('[',0x07, x, y, v);
                  strbuff[i] = '[';
                  i++;
                  break;
          case 27:
                  printc(']',0x07, x, y, v);
                  strbuff[i] = ']';
                  i++;
                  break;
          case 28:
                  reading = 0;
                  strbuff[i] = '\0';
                  break;
          case 30:
                  printc('a',0x07, x, y, v);
                  strbuff[i] = 'a';
                  i++;
                  break;
          case 31:
                  printc('s',0x07, x, y, v);
                  strbuff[i] = 's';
                  i++;
                  break;
          case 32:
                  printc('d',0x07, x, y, v);
                  strbuff[i] = 'd';
                  i++;
                  break;
          case 33:
                  printc('f',0x07, x, y, v);
                  strbuff[i] = 'f';
                  i++;
                  break;
          case 34:
                  printc('g',0x07, x, y, v);
                  strbuff[i] = 'g';
                  i++;
                  break;
          case 35:
                  printc('h',0x07, x, y, v);
                  strbuff[i] = 'h';
                  i++;
                  break;
          case 36:
                  printc('j',0x07, x, y, v);
                  strbuff[i] = 'j';
                  i++;
                  break;
          case 37:
                  printc('k',0x07, x, y, v);
                  strbuff[i] = 'k';
                  i++;
                  break;
          case 38:
                  printc('l',0x07, x, y, v);
                  strbuff[i] = 'l';
                  i++;
                  break;
          case 39:
                  printc(';',0x07, x, y, v);
                  strbuff[i] = ';';
                  i++;
                  break;
       /* case 42:                                 Left shift
                  printc('q');
                  strbuff[i] = 'q';
                  i++;
                  break;
          case 43:                                 \ (< for somekeyboards)
                  printc((char)92);
                  strbuff[i] = 'q';
                  i++;
                  break;*/
          case 44:
                  printc('z',0x07, x, y, v);
                  strbuff[i] = 'z';
                  i++;
                  break;
          case 45:
                  printc('x',0x07, x, y, v);
                  strbuff[i] = 'x';
                  i++;
                  break;
          case 46:
                  printc('c',0x07, x, y, v);
                  strbuff[i] = 'c';
                  i++;
                  break;
          case 47:
                  printc('v',0x07, x, y, v);
                  strbuff[i] = 'v';
                  i++;
                  break;
          case 48:
                  printc('b',0x07, x, y, v);
                  strbuff[i] = 'b';
                  i++;
                  break;
          case 49:
                  printc('n',0x07, x, y, v);
                  strbuff[i] = 'n';
                  i++;
                  break;
          case 50:
                  printc('m',0x07, x, y, v);
                  strbuff[i] = 'm';
                  i++;
                  break;
          case 51:
                  printc(',',0x07, x, y, v);
                  strbuff[i] = ',';
                  i++;
                  break;
          case 52:
                  printc('.',0x07, x, y, v);
                  strbuff[i] = '.';
                  i++;
                  break;
          case 53:
                  printc('/',0x07, x, y, v);
                  strbuff[i] = '/';
                  i++;
                  break;
          case 54:
                  printc('.',0x07, x, y, v);
                  strbuff[i] = '.';
                  i++;
                  break;
          case 55:
                  printc('/',0x07, x, y, v);
                  strbuff[i] = '/';
                  i++;
                  break;
        /*case 56:
                  printc(' ');           Right shift
                  strbuff[i] = ' ';
                  i++;
                  break;*/
          case 57:
                  printc(' ',0x07, x, y, v);
                  strbuff[i] = ' ';
                  i++;
                  break;
      }
    }
  }
  return strbuff;
}


#endif /* end of include guard: KEYBOARD_H */
