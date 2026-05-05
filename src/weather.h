#ifndef futura_weather_redux_weather_h
#define futura_weather_redux_weather_h

#include "pebble.h"

typedef struct TCW_Weather {
	time_t last_update_time;
	int temperature;
	int conditions;
	char name[40];
	char country[40];
	int temperature0;
	int conditions0;
	time_t time0;
	int temperature6;
	int conditions6;
	time_t time6;
	int temperature12;
	int conditions12;
	time_t time12;
	int temperature18;
	int conditions18;
	time_t time18;
} TCW_Weather;

TCW_Weather* weather_load_cache();
bool weather_save_cache(TCW_Weather *weather);

void weather_set(TCW_Weather *weather, DictionaryIterator *iter);
bool weather_needs_update(TCW_Weather *weather, time_t update_freq);
void weather_request_update(int8_t set, int8_t cnt, char *type, int8_t period );

int weather_convert_temperature(int kelvin_temperature, TempFormat format);

#endif