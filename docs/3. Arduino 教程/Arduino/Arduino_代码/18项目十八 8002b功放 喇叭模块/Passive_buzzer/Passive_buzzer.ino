/*
 * 名称   : Passive Buzzer
 * 功能   : 喇叭播放音乐
 * 作者   : http://www.keyes-robot.com/ 
*/
#define AUDIO_PIN 4  // 音频输出引脚

// 音符频率定义 (Hz)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_REST 0   // 休止符

// 《小星星》简谱
int melody[] =
{
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,
  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

// 每个音符的持续时间 (ms)
int noteDurations[] = 
{
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800
};

void setup() 
{
  pinMode(AUDIO_PIN, OUTPUT);
}

void loop() 
{
  playMelody();
  delay(2000); // 播放完后等待2秒再重复
}

//遍历乐谱数组，依次播放每个音符
void playMelody() 
{
  int numNotes = sizeof(melody) / sizeof(melody[0]);
  for (int i = 0; i < numNotes; i++) 
  {
    int noteDuration = noteDurations[i];
    if (melody[i] == NOTE_REST)
    {
      delay(noteDuration); // 休止符
    } 
    else 
    {
      playTone(melody[i], noteDuration);
    }
    // 音符间短暂间隔
    delay(noteDuration * 0.3);
  }
}

//生成指定频率的方波信号
void playTone(int frequency, int duration) 
{
  if (frequency == 0) return;
  long period = 1000000L / frequency; // 周期(微秒)
  long elapsedTime = 0;
  while (elapsedTime < duration * 1000L) 
  {
    digitalWrite(AUDIO_PIN, HIGH);
    delayMicroseconds(period / 2); // 半周期高电平
    digitalWrite(AUDIO_PIN, LOW);
    delayMicroseconds(period / 2); // 半周期低电平 
    elapsedTime += period;
  }
}