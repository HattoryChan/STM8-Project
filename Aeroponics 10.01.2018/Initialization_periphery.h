#include "iostm8s003f3.h"

void InitPeriph();
// 0 - second, 1 - minutes, 2 - hour
int TIM_GetTime(int SecMinHour);
void TIM_Second_Set(int Value);
void TIM_Minute_Set(int Value);
void TIM_Hour_Set(int Value);