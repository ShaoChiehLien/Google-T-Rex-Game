#ifndef SOUND_H_
#define SOUND_H_

void genWave (void);
void initDAC(void);
void initDMA(void);
void initTIM15(void);

int16_t wavetable[256];

#endif /* SOUND_H_ */
