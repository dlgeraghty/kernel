
typedef char * string;

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
