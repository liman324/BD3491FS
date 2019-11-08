// ALEXSANDER LIMAN
// liman324@yandex.ru
// rcl-radio.ru
// 08.11.2019

#ifndef BD3491FS_H
#define BD3491FS_H

#define BD3491FS_address 0b1000001 

#define INPUT_SELECT        0x04
#define INPUT_GAIN          0x06
#define VOLUME_GAIN_1       0x21
#define VOLUME_GAIN_2       0x22
#define BASS_GAIN           0x51
#define TREBLE_GAIN         0x57
#define SURROUND            0x78

#include <Arduino.h>
class BD3491FS
{
  public:
    BD3491FS();
    void setSelect(int in);// int 0...7 === A B C D E F INPUT_SHORT INPUT_MUTE
    void setIn_gain(int in_gain); // int 0...7 === 0...20 dB    
    void setVol_1(int vol_1); // int 0...87 === 0...-87 dB
    void setVol_2(int vol_2); // int 0...87 === 0...-87 dB
    void setBass(int bass); // int -7...0...+7 === -14...+14 dB
    void setTreb(int treb); // int -7...0...+7 === -14...+14 dB
    void setSurround(int sur); // int 0...3 === OFF LOW MIDDLE HIGH
	
  private:
	void writeWire(char a, char b);
};
	
#endif //BD3491FS_H
