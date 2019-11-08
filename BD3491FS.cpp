#include <Arduino.h>
#include <Wire.h>
#include "BD3491FS.h"

BD3491FS::BD3491FS(){
	Wire.begin();
}

void BD3491FS::setSelect(int in){
     writeWire(INPUT_SELECT, in); 
}

void BD3491FS::setIn_gain(int in_gain){
     switch(in_gain){
       case 0: in_gain = 0b00000000;break;
       case 1: in_gain = 0b00000010;break;
       case 2: in_gain = 0b00000100;break;
       case 3: in_gain = 0b00000110;break;
       case 4: in_gain = 0b00001000;break;
       case 5: in_gain = 0b00001100;break;
       case 6: in_gain = 0b00010000;break;
       case 7: in_gain = 0b00010100;break;
}
     writeWire(INPUT_GAIN, in_gain); 
}

void BD3491FS::setVol_1(int vol_1){
     writeWire(VOLUME_GAIN_1, vol_1 + 0b10000000); 
}

void BD3491FS::setVol_2(int vol_2){
     writeWire(VOLUME_GAIN_2, vol_2 + 0b10000000); 
}

void BD3491FS::setBass(int bass){
     switch(bass){
       case 0: bass = 0b00000000;break;
       case 1: bass = 0b00000010;break;
       case 2: bass = 0b00000100;break;
       case 3: bass = 0b00000110;break;
       case 4: bass = 0b00001000;break;
       case 5: bass = 0b00001010;break;
       case 6: bass = 0b00001100;break;
       case 7: bass = 0b00001110;break;
       case -1: bass = 0b10000010;break;
       case -2: bass = 0b10000100;break;
       case -3: bass = 0b10000110;break;
       case -4: bass = 0b10001000;break;
       case -5: bass = 0b10001010;break;
       case -6: bass = 0b10001100;break;
       case -7: bass = 0b10001110;break;
}
     writeWire(BASS_GAIN, bass); 
}

void BD3491FS::setTreb(int treb){
     switch(treb){
       case 0: treb = 0b00000000;break;
       case 1: treb = 0b00000010;break;
       case 2: treb = 0b00000100;break;
       case 3: treb = 0b00000110;break;
       case 4: treb = 0b00001000;break;
       case 5: treb = 0b00001010;break;
       case 6: treb = 0b00001100;break;
       case 7: treb = 0b00001110;break;
       case -1: treb = 0b10000010;break;
       case -2: treb = 0b10000100;break;
       case -3: treb = 0b10000110;break;
       case -4: treb = 0b10001000;break;
       case -5: treb = 0b10001010;break;
       case -6: treb = 0b10001100;break;
       case -7: treb = 0b10001110;break;
}
     writeWire(TREBLE_GAIN, treb); 
}

void BD3491FS::setSurround(int sur){
     switch(sur){
       case 0: sur = 0b10000000;break;
       case 1: sur = 0b10000101;break;
       case 2: sur = 0b10001010;break;
       case 3: sur = 0b10001111;break;
}
     writeWire(SURROUND, sur); 
}

void BD3491FS::writeWire(char a, char b){
  Wire.beginTransmission(BD3491FS_address);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
