const int w = 50;
const int h = 20;

typedef char * string;

int cursor = 0;

void printc(char l, char c, int *o, unsigned char *v){
  v[*o] = l;
  v[*(o)+1] = c;
  *o+=2;
  cursor++;
  printcursor();

}

void cls(unsigned char *v){
  int x = 0;
  while(x < w * h * 2){
    printc(' ', 0x07 , &x, v);
  }
  cursor = 0;
}

void prints(char *p, int *o, unsigned char *v){
  for(int i = 0; p[i] != '\0'; ++i){
    printc(p[i], 0x09, o, v);
  }
}

int inport(unsigned short port){
  int rv;
  __asm__ __volatile__ ("in %1, %0" : "=a" (rv) : "dN" (port));
  return rv;
}

void outport(unsigned short port, unsigned short data){
  __asm__ __volatile__ ("out %1, %0" : : "dN" (port), "a" (data));
}

void printcursor(){
  outport(0x3D4, 14);
  outport(0x3D5, cursor >> 8);
  outport(0x3D4, 15);
  outport(0x3D5, cursor);
}

void nextLine( int *o, unsigned char *v){
  int a = w-((*o)/2);
  printc(*(o)/2 + 48, 0x07, o, v);
  for(int i = 0; i < a; i++){
    printc(i+48, 0x07, o, v);
  }
}

kmain()
{
  unsigned char *video = (unsigned char *)0xB8000;
  int offset = 0;
  cls(video);
  string a = "OLA";
  prints(a, &offset, video);
  //nextLine(&offset, video);
  string p = "LibreOS>";
  prints(p, &offset, video);
}
