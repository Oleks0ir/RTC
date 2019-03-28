/*
 * DS3231.cpp - Library to set & get time from RTC DS3231
 * Created by Manjunath CV. July 08, 2017, 02:18 AM
 * Released into the public domain.
 */

#ifndef RtcLibrarry.h

//define all the rtc clocks.
#define DS1307_H
#define DS3231_H
#define PCF8563_H

#include <time.h>
#include <Arduino.h>
#include <Wire.h>

#define DS1307_ADDR 0x68

#define CLOCK_H24 0
#define CLOCK_H12 1

#define HOUR_AM 0
#define HOUR_PM 1
#define HOUR_24 2

#define SQW001Hz 10
#define SQW04kHz 14
#define SQW08kHz 18
#define SQW32kHz 32

class DS1307
{
    public:
        bool begin();

        bool isRunning(void);
        void startClock(void);
        void stopClock();

        void setHourMode(uint8_t h_mode);
        uint8_t getHourMode();

        void setMeridiem(uint8_t meridiem);
        uint8_t getMeridiem();

        void setSeconds(uint8_t second);
        void setMinutes(uint8_t minute);
        void setHours(uint8_t hour);
        void setDay(uint8_t day);
        void setWeek(uint8_t week);
        void setMonth(uint8_t month);
        void setYear(uint16_t year);

        void setDate(uint8_t day, uint8_t month, uint16_t year);
        void setTime(uint8_t hour, uint8_t minute, uint8_t second);

        void setDateTime(char* date, char* time);

        uint8_t getSeconds();
        uint8_t getMinutes();
        uint8_t getHours();
        uint8_t getDay();
        uint8_t getWeek();
        uint8_t getMonth();
        uint16_t getYear();

        void setEpoch(time_t epoch);
        time_t getEpoch();

        void setOutPin(uint8_t mode);
        bool isOutPinEnabled();
        bool isSqweEnabled();

    private:
        uint8_t bin2bcd (uint8_t val);
        uint8_t bcd2bin (uint8_t val);
};

class NVRAM
{
    public:
        bool begin();
        uint8_t read(uint8_t address);
        void write(uint8_t address, uint8_t value);
        uint8_t length = 56;
    private:
};

#define DS3231_ADDR 0x68

#define TIME_H12 0
#define TIME_H24 1

class DS3231 {

    public:
      bool begin();

      void setSecond(uint8_t second);
      void setMinute(uint8_t minute);
      void setHour(uint8_t hour);
      void setDay(uint8_t day);
      void setMonth(uint8_t month);
      void setYear(uint16_t year);

      void setWeek(uint8_t week);

      void setDate(uint8_t day, uint8_t month, uint16_t year);
      void setTime(uint8_t hour, uint8_t minute, uint8_t second);

      void setEpoch(time_t epoch, time_t e_year, int16_t offset);

      void setDateTime(char* date, char* time);

      uint16_t getYear();
      uint8_t getMonth();
      uint8_t getDay();
      uint8_t getSecond();
      uint8_t getMinute();
      uint8_t getHour();

      uint8_t getWeek();

      time_t getEpoch();

      void enableAlarmPin();
      void enableAlarm1();
      void enableAlarm2();

      void disableAlarm1();
      void disableAlarm2();

      void setAlarm1();
      void setAlarm1(uint8_t second);
      void setAlarm1(uint8_t minute, uint8_t second);
      void setAlarm1(uint8_t hour, uint8_t minute, uint8_t second);
      void setAlarm1(uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);

      void setAlarm2();
      void setAlarm2(uint8_t minute);
      void setAlarm2(uint8_t hour, uint8_t minute);
      void setAlarm2(uint8_t day, uint8_t hour, uint8_t minute);

      bool isAlarm1Tiggered();
      bool isAlarm2Tiggered();

      bool lostPower();
      void StartClock();
      float getTemp();

      //uint8_t getRegister(uint8_t reg);
      //void setRegister(uint8_t reg, uint8_t data);

    private:
      uint8_t bin2bcd (uint8_t val);
      uint8_t bcd2bin (uint8_t val);

};

//Instantiate class DS3231 as RTC

static DS3231 RTC;

//Instantiate class DS1307 as RTC

static DS1307 RTC;
static NVRAM NVRAM;

#define PCF8563_ADDR 0x51

#define SQW001Hz 10
#define SQW04kHz 14
#define SQW08kHz 18
#define SQW32kHz 32

class PCF8563
{
    public:
        bool begin();

        bool isRunning(void);
        void startClock();
        void stopClock();

        void setSeconds(uint8_t second);
        void setMinutes(uint8_t minute);
        void setHours(uint8_t hour);
        void setDay(uint8_t day);
        void setWeek(uint8_t week);
        void setMonth(uint8_t month);
        void setYear(uint16_t year);

        void setDate(uint8_t day, uint8_t month, uint16_t year);
        void setTime(uint8_t hour, uint8_t minute, uint8_t second);


        void setDateTime(char* date, char* time);

        uint8_t getSeconds();
        uint8_t getMinutes();
        uint8_t getHours();
        uint8_t getDay();
        uint8_t getWeek();
        uint8_t getMonth();
        uint16_t getYear();


        void setEpoch(time_t epoch);
        time_t getEpoch();
        //void outPin(uint8_t mode);

        //void enableAlarm();
        void disableAlarm();
        void clearAlarm();

        bool isAlarmEnabled();
        bool isAlarmTriggered();

        void setAlarmHours(uint8_t hours);
        void setAlarmMinutes(uint8_t minutes);
        //setAlarmTime();
        //setAlarmDay();

        uint8_t getAlarmHours();
        uint8_t getAlarmMinutes();
        //getAlarmTime();
        //getAlarmDay();

        //void setOutPin(uint8_t mode);
        //bool isOutPinEnabled();
        //bool isSqweEnabled();

    private:
        uint8_t bin2bcd (uint8_t val);
        uint8_t bcd2bin (uint8_t val);
};



//Instantiate class PCF8563 as RTC

static PCF8563 RTC;

#endif 