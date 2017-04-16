#ifndef SENSOR_H_SEEN
#define SENSOR_H_SEEN

#define HECTO_2_IOM 33.863886929

/*
struct THGN801 {
        const char *name = "THGN801";
        float temperature;
        int humidity;
};

struct WGR800 {
        const char *name = "WGR800";
        int direction;
        float currentSpeed;
        float averageSpeed;
};

struct PCR800 {
        const char *name = "PCR800";
        float rate;
        float total;
};
*/

typedef enum {
    ERR, THG, WGR, PCR, BMP, VIN
} SENSORTYPE;

struct osSensor {
  SENSORTYPE sType;
  time_t sampTime;
  int id;
  int chan;
  int flag;
  char *name;
  float temperature;
  int humidity;
  int direction;
  const char *windDir;
  float currentSpeed;
  float averageSpeed;
  float pressure;
  float vinVoltage;
  float rainRate;
  float rainTotal;
  };

// meters/second to miles/hr
#define MPS_MPR 2.2369362921

// mm to in
#define MM_IN 0.03937007874

// each element is the size of the field, position starts at zero
// and is the sum of the sizes of the previous fields
/*
#define CHAN_POS 1 // start buffer [ 4 ]
#define UNK_POS 2 // start at 5
#define FLAG_POS 3 // starts at 7
*/

SENSORTYPE getSensorType();
struct osSensor * decodeOS(unsigned char *, int);
int parseOsSensor(struct osSensor *);
void showResult(struct osSensor *, int);
float getTHG_Temperature();
int getTHG_Humidity();
float getFloat(int, int);
float cel2far(float);
void showBuffer(unsigned char [], int len);
void readBuffer(unsigned char *buffer, unsigned char *dest, int len);
float getWGR_currentSpeed();
float getWGR_averageSpeed();
int getWGR_windDirection();
int getInt(unsigned char *, int);
float getPCR_rainRate();
float getPCR_rainTotal();
float getBMP_Pressure();
float getBMP_Temperature();
float getVIN_Voltage();

SENSORTYPE getSensorType();
//int decodeOS(unsigned char *, int);
struct osSensor * decodeOS(unsigned char *, int);
int parseOsSensor(struct osSensor *);
void showResult(struct osSensor *, int);
float getTHG_Temperature();
int getTHG_Humidity();
float getFloat(int, int);
float cel2far(float);
void showBuffer(unsigned char [], int len);
void readBuffer(unsigned char *buffer, unsigned char *dest, int len);
float getWGR_currentSpeed();
float getWGR_averageSpeed();
int getWGR_windDirection();
int getInt(unsigned char *, int);
float getPCR_rainRate();
float getPCR_rainTotal();
float getBMP_Pressure();
float getBMP_Temperature();
float getVIN_Voltage();

#endif
