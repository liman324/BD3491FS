#include <Wire.h> 
#include <BD3491FS.h>
BD3491FS bd; 

void setup(){
   Wire.begin();
   audio();
}

void loop(){}

void audio(){
    bd.setSelect(0);// int 0...7 === A B C D E F INPUT_SHORT INPUT_MUTE
    bd.setIn_gain(0); // int 0...7 === 0...20 dB    
    bd.setVol_1(0); // int 0...87 === 0...-87 dB
    bd.setVol_2(0); // int 0...87 === 0...-87 dB
    bd.setBass(0); // int -7...0...+7 === -14...+14 dB
    bd.setTreb(0); // int -7...0...+7 === -14...+14 dB
    bd.setSurround(1); // int 0...3 === OFF LOW MIDDLE HIGH
  }
