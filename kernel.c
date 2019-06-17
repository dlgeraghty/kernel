const int w = 80;
const int h = 25;

typedef char * string;

void printc(char l, char c, int *x, int *y, unsigned char *v){
  int cursorX = *x;
  int cursorY = *y;
  switch(l){
    case ('\n'):
        *x = 0;
        *y+=2;
        break;
    default:
        v[(cursorY*w + cursorX)] = l;
        v[(cursorY*w + cursorX)+1] = c;
        *x+=2;
        break;
  }

  printcursor(*x,*y);

}

void cls(unsigned char *v){
  for (int i = 0; i < w*h*2; i++) {
    v[i] = 0x0;
  }
}

void prints(char *p, int *x, int *y, unsigned char *v){
  for(int i = 0; p[i] != '\0'; ++i){
    printc(p[i], 0x09, x, y, v);
  }
}

int inport(unsigned short port){
  int rv;
  __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (port));
  return rv;
}

void outport(unsigned short port, unsigned short data){
  __asm__ __volatile__ ("out %1, %0" : : "dN" (port), "a" (data));
}

void printcursor(int x,int y){
  outport(0x3D4, 14);
  outport(0x3D5, (y*w + x) >> 8);
  outport(0x3D4, 15);
  outport(0x3D5, (y*w + x));
}

void nextLine(){
  string vidmem = (string)0xb8000;
  for(int i = 0; i < w*(h-1)*2; i++){
    vidmem[i] = vidmem[i + w*2];
  }
}

int strlength(string s){
  int l = 0;
  while(s[l] != '\0') l++;
  return l;
}

int strEql(string a, string b){
  int l = strlength(a);
  if(l == strlength(b)){
    for(l; l > 0; l--){
      if(a[l] != b[l]) return 0;
    }return 1;
  }else{
    return 0;
  }
}

string readkb(int *x, int *y, unsigned char *v){
  string strbuff;
  int i = 0;
  int reading = 1;
  while(reading){
    if(inport(0x64) & 0x1){
      switch(inport(0x60)){
        case 16:
          printc('Q',0x07, x, y, v);
          strbuff[i] = 'Q';
          i++;
          break;
        case 28:
          reading = 0;
          strbuff[i] = '\0';
          break;
      }
    }
  }
  return strbuff;
}

int kmain()
{
  unsigned char *video = (unsigned char *)0xB8000;
  int cursorX = 0;
  int cursorY = 0;
  cls(video);
  string p = "Ola amigos, welcome al (prueba de salto de linea) \nLibreOS>\nPrueba de strEql";
  prints(p, &cursorX, &cursorY, video);
  //printc(strEql("ola","olo")+'0', 0x07, &cursorX, &cursorY, video);
  while(1){
    prints("DOS>", &cursorX, &cursorY, video);
    string s = readkb(&cursorX, &cursorY, video);
    if(strEql(s, "Q")){
      prints("Correct", &cursorX, &cursorY, video);
    }else{
      prints("Acces denied", &cursorX, &cursorY, video);
    }
    printc('\n',0x07, &cursorX, &cursorY, video);
  }
  return 0; 
}
